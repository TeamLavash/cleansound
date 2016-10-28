#!/usr/bin/env bash

COMMIT=$(git rev-parse --short HEAD)
TAG=$(git tag)

rm -f version.cpp
echo "const char *APP_VERSION = \"$TAG-$COMMIT\";" >> version.cpp
