# CLST-MDL-ST-CITADEL

The Station Citadel - the first module to receive obfuscated requests from the Gate and orchestrate internal cluster processing.

- **Type**: Module - Station
- **Code**: CLST-MDL-ST-CITADEL

## Overview

Station Citadel is the cluster's front-line Station. It receives obfuscated requests from the Gate and delegates work to other Stations and Operators within the cluster. It is the **core module** required for any Inferos cluster to function.

## Tech Stack

- **Language**: C++
- **Crypto**: libsodium
- **I/O**: Boost.Asio
- **Logging**: spdlog
- **Host OS**: Alpine Linux

## Building

### Prerequisites (Alpine Linux)
```bash
apk add cmake g++ boost-dev libsodium-dev spdlog-dev pkgconfig
```

### Build
```bash
mkdir build && cd build
cmake ..
make
```

## Running

Set the port via environment variable:
```bash
export CITADEL_PORT=8888
./citadel
```

Default port is 8888 if `CITADEL_PORT` is not set.
