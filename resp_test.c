#include "resp.h"
#include <assert.h>
#include <ctype.h>

void memprint(char *buf, int len) {
	int i;
	for (i = 0; i < len; i++) {
		if (isprint(buf[i])) {
			printf("%c", buf[i]);
		} else {
			printf("\\0x%02X", buf[i]);
		};
	};
	printf("\r\n");
}

int main() {
	char *buf;
  int offset;
	respObject *r;

	buf = (char *)malloc(sizeof(char)*255);

	r = createRespNil();
	assert(respEncode(r, buf) == 5);
	assert(memcmp(buf, "$-1\r\n\0", 6) == 0);
  freeRespObject(r);

	r = createRespString(RESP_OBJECT_STATUS, "OK\0");
	assert(respEncode(r, buf) == 5);
	assert(memcmp(buf, "+OK\r\n\0", 6) == 0);
  freeRespObject(r);

	r = createRespString(RESP_OBJECT_STATUS, "OK\0");
	assert(respEncode(r, buf) == 5);
	assert(memcmp(buf, "+OK\r\n\0", 6) == 0);
  freeRespObject(r);

	r = createRespString(RESP_OBJECT_ERROR, "Fail\0");
	assert(respEncode(r, buf) == 7);
	assert(memcmp(buf, "-Fail\r\n\0", 8) == 0);
  freeRespObject(r);

	r = createRespString(RESP_OBJECT_ERROR, "Fail\0");
	assert(respEncode(r, buf) == 7);
	assert(memcmp(buf, "-Fail\r\n\0", 8) == 0);
  freeRespObject(r);

	r = createRespBulk("Bulk\0String", 11);
	assert(respEncode(r, buf) == 18);
	assert(memcmp(buf, "$11\r\nBulk\0String\r\n\0", 19) == 0);
  freeRespObject(r);

	r = createRespInteger(1234);
	assert(respEncode(r, buf) == 7);
	assert(memcmp(buf, ":1234\r\n\0", 8) == 0);
  freeRespObject(r);

	r = createRespInteger(-5678);
	assert(respEncode(r, buf) == 8);
	assert(memcmp(buf, ":-5678\r\n\0", 9) == 0);
  freeRespObject(r);

	r = createRespArray(5);

	r->element[0] = createRespString(RESP_OBJECT_STATUS, "Hello\0");
	r->element[1] = createRespString(RESP_OBJECT_ERROR, "World\0");
	r->element[2] = createRespBulk("Again", 5);
	r->element[3] = createRespInteger(1234);
	r->element[4] = createRespNil();

	assert(respEncode(r, buf) == 43);
	assert(memcmp(buf, "*5\r\n+Hello\r\n-World\r\n$5\r\nAgain\r\n:1234\r\n$-1\r\n\0", 44) == 0);
  freeRespObject(r);

  /* Reading replies. */
  offset = 0;

  memcpy(buf, ":98765\r\n:432\r\n:-21\r\n", 21);
  offset = respDecode(&r, buf);

  assert(offset > 0);
  assert(r->type == RESP_OBJECT_INTEGER);
  assert(r->integer == 98765);

  offset += respDecode(&r, buf + offset);

  assert(offset > 0);
  assert(r->type == RESP_OBJECT_INTEGER);
  assert(r->integer == 432);

  offset += respDecode(&r, buf + offset);

  assert(offset > 0);
  assert(r->type == RESP_OBJECT_INTEGER);
  assert(r->integer == -21);

  freeRespObject(r);

  /* Status message */
  offset = 0;

  memcpy(buf, "+My status message\r\n", 20);
  offset = respDecode(&r, buf);

  assert(offset == 20);
  assert(r->type == RESP_OBJECT_STATUS);
  assert(strcmp(r->str, "My status message") == 0);

  freeRespObject(r);

  /* Error message */
  memcpy(buf, "-My error message\r\n", 19);
  offset = respDecode(&r, buf);

  assert(offset == 19);
  assert(r->type == RESP_OBJECT_ERROR);
  assert(strcmp(r->str, "My error message") == 0);

  freeRespObject(r);

  /* Bulk reply */
  memcpy(buf, "$13\r\nHello\0World\0!\r\n", 20);
  offset = respDecode(&r, buf);

  assert(offset == 20);
  assert(r->type == RESP_OBJECT_BINARY);
  assert(strncmp(r->str, "Hello\0World\0!", 13) == 0);

  freeRespObject(r);

  /* Array reply */
  memcpy(buf, "*3\r\n-Hello\r\n+World\r\n:1234\r\n", 27);
  offset = respDecode(&r, buf);

  assert(offset == 27);
  assert(r->type == RESP_OBJECT_ARRAY);
  assert(r->elements == 3);
  assert(r->element != NULL);

  assert(r->element[0]->type == RESP_OBJECT_ERROR);
  assert(strcmp(r->element[0]->str, "Hello") == 0);

  assert(r->element[1]->type == RESP_OBJECT_STATUS);
  assert(strcmp(r->element[1]->str, "World") == 0);

  assert(r->element[2]->type == RESP_OBJECT_INTEGER);
  assert(r->element[2]->integer == 1234);

  freeRespObject(r);

  return 0;
}
