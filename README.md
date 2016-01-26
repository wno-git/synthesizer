# synthesizer

[![Build Status](https://travis-ci.org/wno-git/synthesizer.svg?branch=master)](https://travis-ci.org/wno-git/synthesizer)

This is supposed to become a small music synthesizer program. The program will
output signal to `stdout` so you need to pipe it to some player eg. `aplay`.

## Build

```
mkdir build
cd build
CXX=g++-5 cmake -G Ninja ..
ninja
```

## Run

```
src/syn | aplay -f S16_LE -c 1 -r 44100 -V mono
```
