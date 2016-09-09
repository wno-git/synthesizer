# synthesizer

[![Build Status](https://travis-ci.org/wno-git/synthesizer.svg?branch=master)](https://travis-ci.org/wno-git/synthesizer)

This is supposed to become a small music synthesizer program. The program will
output raw audio signal to `stdout` so you need to pipe it to a player eg.
`aplay`. It doesn't yet play anything other than some sine waves, though...

## Build

```
mkdir build
cd build
CXX=g++-5 cmake -G Ninja ..
ninja
```

## Run

```
cd build
src/syn ../data/sine1k.json | aplay -f cd -c 1
```
