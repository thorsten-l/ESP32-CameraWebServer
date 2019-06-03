#!/bin/sh
rm -f firmware.*
docker build --no-cache -t platformio .
