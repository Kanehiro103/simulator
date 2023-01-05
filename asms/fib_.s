       0: j 50
       1: j 0
       2: addi r251 r255 1
       3: blt r251 r0 2
       4: j 45
       5: subi r1 r0 1
       6: subi r251 r253 0
       7: sw r0 r251
       8: add r0 r255 r1
       9: subi r253 r253 1
      10: sw r252 r253
      11: subi r253 r253 1
      12: addi r252 r255 0
      13: slli r252 r252 8
      14: addi r252 r252 0
      15: slli r252 r252 8
      16: addi r252 r252 0
      17: slli r252 r252 8
      18: addi r252 r252 20
      19: j -17
      20: addi r253 r253 1
      21: lw r251 r253
      22: addi r253 r253 1
      23: add r252 r255 r251
      24: subi r251 r253 0
      25: lw r1 r251
      26: subi r1 r1 2
      27: subi r251 r253 1
      28: sw r0 r251
      29: add r0 r255 r1
      30: subi r253 r253 2
      31: sw r252 r253
      32: subi r253 r253 1
      33: addi r252 r255 0
      34: slli r252 r252 8
      35: addi r252 r252 0
      36: slli r252 r252 8
      37: addi r252 r252 0
      38: slli r252 r252 8
      39: addi r252 r252 41
      40: j -38
      41: addi r253 r253 1
      42: lw r251 r253
      43: addi r253 r253 2
      44: add r252 r255 r251
      45: subi r251 r253 1
      46: lw r1 r251
      47: add r0 r1 r0
      48: jr r252
      49: jr r252
      50: addi r252 r255 0
      51: slli r252 r252 8
      52: addi r252 r252 0
      53: slli r252 r252 8
      54: addi r252 r252 0
      55: slli r252 r252 8
      56: addi r252 r252 1
      57: addi r253 r255 1
      58: slli r253 r253 25
      59: subi r253 r253 1
      60: addi r254 r255 1
      61: slli r254 r254 30
      62: subi r254 r254 1
      63: addi r0 r255 10
      64: subi r253 r253 0
      65: sw r252 r253
      66: subi r253 r253 1
      67: addi r252 r255 0
      68: slli r252 r252 8
      69: addi r252 r252 0
      70: slli r252 r252 8
      71: addi r252 r252 0
      72: slli r252 r252 8
      73: addi r252 r252 75
      74: j -72
      75: addi r253 r253 1
      76: lw r251 r253
      77: addi r253 r253 0
      78: add r252 r255 r251
      79: j 1
      80: subi r247 r255 8
      81: lw r248 r247
      82: beq r248 r255 2
      83: j 2
      84: j -4
      85: subi r247 r255 12
      86: sw r0 r247
      87: j 1
      88: j -87
