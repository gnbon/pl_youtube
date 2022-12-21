#!/bin/bash

echo "[!] Make build files using cmake.."
cmake -B build -DCMAKE_BUILD_TYPE=Release

echo "[!] Build using make.."
make -C build

echo "[!] Start binary.."
build/src/pl_youtube