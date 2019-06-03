FROM ubuntu:18.04

RUN apt-get update && apt-get install -y --no-install-recommends wget unzip git make \
 srecord bc xz-utils gcc python curl python-pip python-dev build-essential \
 && python -m pip install --upgrade pip setuptools

RUN pip install -U platformio
RUN pio platform install espressif32@1.8.0 --with-package framework-arduinoespressif32
RUN pio platform install https://github.com/platformio/platform-espressif32.git#feature/stage --with-package framework-arduinoespressif32
RUN pio platform install espressif32 --with-package framework-arduinoespressif32

# Prebuild one project to install the complete environment
RUN git clone https://github.com/thorsten-l/ESP32-Arduino-Info.git
WORKDIR /ESP32-Arduino-Info
RUN cp lib/App/App.hpp.sample lib/App/App.hpp
RUN /usr/local/bin/platformio run -e lolin32lite
RUN rm -fr /ESP32-Arduino-Info

RUN mkdir /workdir
WORKDIR /workdir

# CMD ["/bin/bash"]
CMD [ "/usr/local/bin/platformio", "run" ]
