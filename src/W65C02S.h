#ifndef W65C02S_H
#define W65C02S_H


#include "memory.h"

class W65C02S {
public:
private:
  // ROM
  Memory romChip;
  // pins
  unsigned short addr;
  char data;

  // Program counter
  unsigned short regPC;
  /** ## Processor State Bits
    - 0 CARRY
    - 1 ZERO
    - 2 IRQ DISABLE
    - 3 DECIMAL MODE
    - 4 BRK COMMAND
    - 5 UNUSED
    - 6 OVERFLOW
    - 7 NEGATIVE
  */
  char regP;
  // Accumulator
  char regA;
  // Stack pointer
  char regSp;
  // Index X
  char regX;
  // Index Y
  char regY;

};



#endif //W65C02S_H
