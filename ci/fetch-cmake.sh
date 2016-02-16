#!/bin/bash

set -euo pipefail

CMAKE_ARCHIVE="cmake-3.4.1-Linux-x86_64.tar.gz"
CMAKE_URL="https://cmake.org/files/v3.4/${CMAKE_ARCHIVE}"
CMAKE_SHA="ci/${CMAKE_ARCHIVE}.sha256"

TOOL_CACHE_DIR="tools_cache"
TOOL_DIR="tools"

mkdir -p ${TOOL_CACHE_DIR}

if [ ! -f "${TOOL_CACHE_DIR}/${CMAKE_ARCHIVE}" ]; then
# WORKAROUND: Travis has outdated certificates so SSL connection to cmake.org
# fails. The checksum of the archive is verified anyway, so we can disable the
# certificate verification for now.
    wget \
        --no-check-certificate \
        --directory-prefix="${TOOL_CACHE_DIR}" "${CMAKE_URL}"
fi

(
    cd ${TOOL_CACHE_DIR}
    sha256sum --check "../${CMAKE_SHA}"
)

mkdir -p ${TOOL_DIR}

tar -xaf "${TOOL_CACHE_DIR}/${CMAKE_ARCHIVE}" -C "${TOOL_DIR}"
