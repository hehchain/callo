#ifndef SHA512_H_INCLUDED
#define SHA512_H_INCLUDED

#include <stdint.h>
#include <stdlib.h>

/** A hasher class for SHA-512. */
class CSHA512
{
  private:
    uint64_t s[8];
    unsigned char buf[128];
    size_t bytes;

  public:
    static const size_t OUTPUT_SIZE = 64;

    CSHA512();
    CSHA512 &Write(const unsigned char *data, size_t len);
    void Finalize(unsigned char hash[OUTPUT_SIZE]);
    CSHA512 &Reset();
};
#endif // SHA512_H_INCLUDED
