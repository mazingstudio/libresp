# RESP (REdis Serialization Protocol) encoder and decoder for Arduino

This is a [RESP][1] encoder/decoder library I'm using to play with
Arduino-based thingies. [RESP][1] is standard C so it actually does not depend
on Arduino.

**Warning**: This project still lacks bechmarkis and it probably has some
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

## License

> Copyright (c) 2015 José Carlos Nieto, https://menteslibres.net/xiam
>
> Permission is hereby granted, free of charge, to any person obtaining
> a copy of this software and associated documentation files (the
> "Software"), to deal in the Software without restriction, including
> without limitation the rights to use, copy, modify, merge, publish,
> distribute, sublicense, and/or sell copies of the Software, and to
> permit persons to whom the Software is furnished to do so, subject to
> the following conditions:
>
> The above copyright notice and this permission notice shall be
> included in all copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
> EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
> MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
> NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
> LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
> OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
> WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

[1]: http://redis.io/topics/protocol
[2]: https://github.com/makerworkshop/libresp/archive/master.zip
[3]: http://www.arduino.cc/en/guide/libraries
