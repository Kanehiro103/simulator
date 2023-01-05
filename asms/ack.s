       0: j 36
       1: j 0
       2: addi r251 r255 0
       3: blt r251 r0 2
       4: j 30
       5: addi r251 r255 0
       6: blt r251 r1 2
       7: j 24
       8: subi r2 r0 1
       9: subi r1 r1 1
      10: subi r251 r253 0
      11: sw r2 r251
      12: subi r253 r253 1
      13: sw r252 r253
      14: subi r253 r253 1
      15: addi r252 r255 0
      16: slli r252 r252 8
      17: addi r252 r252 0
      18: slli r252 r252 8
      19: addi r252 r252 0
      20: slli r252 r252 8
      21: addi r252 r252 23
      22: j -20
      23: addi r253 r253 1
      24: lw r251 r253
      25: addi r253 r253 1
      26: add r1 r255 r0
      27: add r252 r255 r251
      28: subi r251 r253 0
      29: lw r0 r251
      30: j -28
      31: subi r0 r0 1
      32: addi r1 r255 1
      33: j -31
      34: addi r0 r1 1
      35: jr r252
      36: addi r252 r255 0
      37: slli r252 r252 8
      38: addi r252 r252 0
      39: slli r252 r252 8
      40: addi r252 r252 0
      41: slli r252 r252 8
      42: addi r252 r252 1
      43: addi r253 r255 1
      44: slli r253 r253 25
      45: subi r253 r253 1
      46: addi r254 r255 1
      47: slli r254 r254 30
      48: subi r254 r254 1
      49: addi r0 r255 3
      50: addi r1 r255 10
      51: subi r253 r253 0
      52: sw r252 r253
      53: subi r253 r253 1
      54: addi r252 r255 0
      55: slli r252 r252 8
      56: addi r252 r252 0
      57: slli r252 r252 8
      58: addi r252 r252 0
      59: slli r252 r252 8
      60: addi r252 r252 62
      61: j -59
      62: addi r253 r253 1
      63: lw r251 r253
      64: addi r253 r253 0
      65: add r252 r255 r251
      66: j 1
      67: subi r247 r255 8
      68: lw r248 r247
      69: beq r248 r255 2
      70: j 2
      71: j -4
      72: subi r247 r255 12
      73: sw r0 r247
      74: j 1
      75: j -74
