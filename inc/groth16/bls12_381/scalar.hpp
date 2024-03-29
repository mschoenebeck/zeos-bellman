#pragma once

#include <vector>
#include <json_struct.h>
#include "util.hpp"

using namespace std;

// equivalent of:
// pub struct Scalar(pub(crate) [u64; 4]);
// bls12_381-0.5.0/src/scalar.rs
class Scalar
{
    public:

        // constantslet cap = Scalar::CAPACITY;
        /// INV = -(q^{-1} mod 2^64) mod 2^64
        static const uint64_t INV;

        /// Constant representing the modulus
        /// q = 0x73eda753299d7d483339d80809a1d80553bda402fffe5bfeffffffff00000001
        static const Scalar MODULUS;
        // The number of bits needed to represent the modulus.
        static const uint32_t MODULUS_BITS;
        static const uint32_t NUM_BITS;
        static const uint32_t CAPACITY;

        static const Scalar R;
        static const Scalar ZERO;

        // members
        vector<uint64_t> data;
        JS_OBJ(data);

        Scalar();
        Scalar(const vector<uint64_t>& data);

        /// Converts an element of `Scalar` into a byte representation in
        /// little-endian byte order.
        vector<uint8_t> to_bytes() const;

        Scalar montgomery_reduce(const uint64_t& r0,
                                 const uint64_t& r1,
                                 const uint64_t& r2,
                                 const uint64_t& r3,
                                 const uint64_t& r4,
                                 const uint64_t& r5,
                                 const uint64_t& r6,
                                 const uint64_t& r7) const;

        static Scalar zero();

        static Scalar one();

        Scalar sub(const Scalar& rhs) const;

        Scalar operator - (const Scalar& rhs) const;

        Scalar add(const Scalar& rhs) const;

        Scalar operator + (const Scalar& rhs) const;

        Scalar dbl() const;
};
