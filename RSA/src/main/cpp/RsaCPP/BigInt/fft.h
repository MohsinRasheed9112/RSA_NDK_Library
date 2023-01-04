#include "BigInt.h"
#ifndef RSA_NDK_LIBRARY_BIGINT_H
#define RSA_NDK_LIBRARY_BIGINT_H

namespace Dodecahedron
{
    void __fft_mul(Bigint const& a, Bigint const& b, Bigint& c);
}
#include "fft.tcc"
#endif
