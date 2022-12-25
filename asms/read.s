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
      10: subi r247 r255 8
      11: lw r248 r247
      12: beq r248 r255 2
      13: j 2
      14: j -4
      15: subi r247 r255 12
      16: addi r0 r0 1
      17: sw r0 r247
      18: j -17
