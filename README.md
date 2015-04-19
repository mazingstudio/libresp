# RESP encoder/decoder in c

This is a [RESP][1] encoder/decoder library I'm using to play with some
embedded stuff...

This project still lacks bechmarking and probably has some security issues
regarding how strings are decoded, so maybe this is not a good time to use it
in production.

## How to install on Arduino

[Download][2] and uncompress the latest .ZIP, a folder named `libresp-master`
will be created, rename the uncompressed folder to `libresp` and place it into
your Arduino's libraries folder, on Linux this could be
`/usr/share/arduino/libraries/` and on Mac it should be
`Documents/Arduino/libraries/`.

See the Arduino's documentation on [importing libraries][3] for more
information.

[1]: http://redis.io/topics/protocol
[2]: https://github.com/makerworkshop/libresp/archive/master.zip
[3]: http://www.arduino.cc/en/guide/libraries
