#!/bin/sh
docker build -t platformio .
(cd ..; docker run -it --rm -v `pwd`:/workdir --name platformio platformio )
