.section .text
.globl _start

_start:
  addi x1,x0,512
  addi x2,x0,50
  addi x3,x0,100
  add x4,x2,x3
  sw x4,0(x1)
  addi x5,x0,1
  sb x5,1(x1)
  lw x6,0(x1)
  lbu x8,1(x1)
  ebreak
