#ifndef SHA1_H_INCLUDED
#define SHA1_H_INCLUDED
#include <stdint.h>
#include <stdlib.h>

/** A hasher class for SHA1. */
class CSHA1
{
  private:
    uint32_t s[5];
    unsigned char buf[64];
    size_t bytes;

  public:
    static const size_t OUTPUT_SIZE = 20;

    CSHA1();
    CSHA1 &Write(const unsigned char *data, size_t len);
    void Finalize(unsigned char hash[OUTPUT_SIZE]);
    CSHA1 &Reset();
};
#endif // SHA1_H_INCLUDED
