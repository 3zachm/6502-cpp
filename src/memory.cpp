#include "memory.h"

Memory::Memory(unsigned int dataSize) {
  data = new unsigned char[dataSize];
  this->dataSize = dataSize;
}

Memory::Memory(unsigned int dataSize, unsigned char* data) {
  for (unsigned int i = 0; i < dataSize; i++) setByte(i, data[i]);
}

int Memory::getByte(unsigned short addr) {
  if (addr >= dataSize) throw(addr);
  return data[addr];
}

void Memory::setByte(unsigned short addr, unsigned char value) {
  if (addr >= dataSize) throw (addr);
  data[addr] = value;
}
