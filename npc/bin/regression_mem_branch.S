.section .text
.globl _start

_start:
  lui   ra, 0x80000
  addi  ra, ra, 512

  addi  sp, x0, 50
  addi  gp, x0, 100
  add   tp, sp, gp
  sw    tp, 0(ra)

  addi  t0, x0, 1
  sb    t0, 1(ra)

  lw    t1, 0(ra)
  addi  a1, x0, 406
  bne   t1, a1, bad

  lbu   s0, 1(ra)
  bne   s0, t0, bad

  jal   t2, jal_pass
after_jal:
  addi  a0, x0, 2
  ebreak

jal_pass:
  la    a3, after_jal
  bne   t2, a3, bad

  la    s1, jalr_pass
  jalr  t3, 0(s1)
after_jalr:
  addi  a0, x0, 3
  ebreak

jalr_pass:
  la    a4, after_jalr
  bne   t3, a4, bad

  addi  a0, x0, 0
  ebreak

bad:
  addi  a0, x0, 1
  ebreak
