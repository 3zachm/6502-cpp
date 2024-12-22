#ifndef MEMORY_H
#define MEMORY_H



class Memory {
public:
  Memory(unsigned int);
  Memory(unsigned int, unsigned char*);

  int getByte(unsigned short addr);
  void setByte(unsigned short addr, unsigned char value);
private:
  unsigned char* data;
  int dataSize;
};



#endif //MEMORY_H
