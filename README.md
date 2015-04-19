# RESP (REdis Serialization Protocol) encoder and decoder for Arduino

This is a [RESP][1] encoder/decoder library I'm using to play with some
embedded stuff. It is standard C so it actually does not depend on Arduino.

**Warning**: This project still lacks bechmarking and probably has some
security issues regarding how strings are decoded, so maybe this is not a good
time to use it in production.

## How to install on Arduino

Create new a folder named `MakerWorkshop` within the Arduino's library folder.
If you're on Linux this could be `/usr/share/arduino/libraries/` and on Mac it
should be `Documents/Arduino/libraries/`. If that folder already exists you
don't need to create it again.

Download and uncompress the [latest .ZIP package][1], a folder named
`libresp-master` will be created, rename the uncompressed folder to just `resp`
and put it into your recently created `MakerWorkshop` folder.

See the Arduino's documentation on [importing libraries][3] for more
information.

[1]: http://redis.io/topics/protocol
[2]: https://github.com/makerworkshop/libresp/archive/master.zip
[3]: http://www.arduino.cc/en/guide/libraries
