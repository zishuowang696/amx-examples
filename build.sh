#!/usr/bin/env bash
# 编译并运行 libamxc 示例。
# 用法：
#   ./build.sh
#   AMXC_DIR=/path/to/libamxc ./build.sh   # 复用已有源码
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
AMXC_DIR="${AMXC_DIR:-$ROOT/_libamxc}"
BUILD_DIR="$ROOT/build"

if [ ! -d "$AMXC_DIR" ]; then
  echo "== 克隆 libamxc =="
  git clone --depth 1 \
    https://gitlab.com/prpl-foundation/components/ambiorix/libraries/libamxc.git \
    "$AMXC_DIR"
fi

echo "== 编译 libamxc =="
make -C "$AMXC_DIR" -j"$(nproc)"

MACHINE="$(cc -dumpmachine)"
LIBDIR="$AMXC_DIR/output/$MACHINE"

mkdir -p "$BUILD_DIR"
echo "== 编译 examples =="
cc -I "$AMXC_DIR/include" "$ROOT/libamxc/examples.c" \
   -L "$LIBDIR" -lamxc -Wl,-rpath,"$LIBDIR" \
   -o "$BUILD_DIR/examples"

echo "== 运行 =="
"$BUILD_DIR/examples"
