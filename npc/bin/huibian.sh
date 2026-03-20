#!/bin/bash
set -euo pipefail

script_dir="$(cd "$(dirname "$0")" && pwd)"
input="${1:-test.S}"

if [[ "${input}" != *.S ]]; then
  input="${input}.S"
fi

if [[ "${input}" != /* ]]; then
  input="${script_dir}/${input}"
fi

stem="${input%.S}"

riscv64-elf-gcc -nostdlib -fno-builtin -march=rv32i -mabi=ilp32 -Ttext=0 -o "${stem}.elf" "${input}"
riscv64-elf-objcopy -O binary "${stem}.elf" "${stem}.bin"
riscv64-elf-objdump -d "${stem}.elf" > "${stem}.txt"
cat "${stem}.txt"
