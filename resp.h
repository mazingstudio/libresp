/*
 * Copyright (c) 2015 José Carlos Nieto, https://menteslibres.net/xiam
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define RESP_OBJECT_BINARY    1
#define RESP_OBJECT_ARRAY     2
#define RESP_OBJECT_INTEGER   3
#define RESP_OBJECT_NIL       4
#define RESP_OBJECT_STATUS    5
#define RESP_OBJECT_ERROR     6

#define RESP_ARRAY_MAX_LEN    255
#define RESP_STRING_MAX_LEN   255
#define RESP_LINE_MAX_LEN     1024

#define RESP_MAX_ITOA_LEN     7

/* respObject defines the structure of a RESP message. */
typedef struct respObject {
  /* Object type */
  int type;
  /* Value of RESP_OBJECT_INTEGER */
  int integer;
  /* Length of str buffer */
  int len;
  /* Buffer for status, error and bulk values */
  char *str;
  /* Number of elements in element array */
  size_t elements;
  /* Elements of RESP_OBJECT_ARRAY */
  struct respObject **element;
} respObject;

/* createRespObject allocates a new empty object of the given type. */
respObject *createRespObject(int type);

/* freeRespObject cleans the memory allocated by createRespObject going
 * recursive if necessarily. */
void freeRespObject(respObject *);

/* createRespArray allocates an array of the given length. */
respObject *createRespArray(size_t length);

/* createRespInteger creates a RESP object of type integer with the given
 * value. */
respObject *createRespInteger(int value);

/* createRespNil creates a nil RESP object. */
respObject *createRespNil();

/* createRespBulk creates a binary-safe RESP object with the given data. */
respObject *createRespBulk(char *data, int dataLength);

/* createRespString creates a string RESP object (delimited by \0) of the given
 * type, which must be either RESP_OBJECT_STATUS or RESP_OBJECT_ERROR. */
respObject *createRespString(int type, char *data);

/* respDecode reads the encoded RESP input from src and decodes it into dest.
 * */
int respDecode(respObject **dest, char *src);

/* respEncode encodes the src RESP object into dest. */
int respEncode(respObject *src, char *dest);

/* respItoa provides fast int to array of chars conversion. */
int respItoa(char *to, int from);

/* respAtoi provides fast array of chars to int conversion. */
int respAtoi(const char * from);