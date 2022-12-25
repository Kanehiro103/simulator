       0: j 2
       1: j 0
       2: subi r247 r255 14
       3: lw r248 r247
       4: beq r248 r255 2
       5: j 2
       6: j -4
       7: subi r247 r255 15
       8: lw r0 r247
       9: j 1
      10: subi r247 r255 14
      11: lw r248 r247
      12: beq r248 r255 2
      13: j 2
      14: j -4
      15: subi r247 r255 15
      16: lw r1 r247
      17: j 1
      18: subi r247 r255 8
      19: lw r248 r247
      20: beq r248 r255 2
      21: j 2
      22: j -4
      23: subi r247 r255 12
      24: fadd r0 r0 r1
      25: sw r0 r247
      26: j -25
