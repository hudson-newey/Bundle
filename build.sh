#!/bin/bash
# BUNDLER build file

rm ./build/bundler
if [ ! -d "build/" ]; then
    mkdir build
fi

g++ src/main.cpp -lyaml-cpp -o build/bundler
