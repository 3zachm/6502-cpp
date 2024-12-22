#include <iostream>
#include <iomanip>
#include <fstream>
#include "memory.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Expected: " << argv[0] << " <object code file>" << std::endl;
    exit(1);
  }
  // construct ROM
  std::ifstream romFile(argv[1]);
  if (romFile.bad()) {
    std::cout << "Error: Could not open provided file path" << std::endl;
    exit(2);
  }

  Memory romChip(65536);
  for (unsigned int addr = 0; romFile.good(); addr++) {
    int newByte = romFile.get();
    // must check after getting rather than be a loop condition
    if (romFile.eof()) break;
    romChip.setByte(addr, newByte);
  }


  // debug print
  for (unsigned int row = 0; row < 16; row++) {
    std::cout << "0x" << std::setfill('0') << std::setw(8)
              << std::hex << std::uppercase << row * 8 << ": ";
    for (unsigned int byteOffset = 0; byteOffset < 16; byteOffset++) {
      std::cout << std::setfill('0') << std::setw(2)
                << std::hex << std::uppercase << romChip.getByte(row * 16 + byteOffset) << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
