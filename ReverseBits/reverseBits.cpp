// Link to problem
// https://leetcode.com/problems/reverse-bits/description/?envType=daily-question&envId=2026-02-16
//

#include <vector>
#include <bitset>

class Solution {
public:
    int reverseBits(int n) {
        auto bits = std::vector<int>();
        for (int i = 0; i < 32; i++)
        {
            bits.push_back(n%2);
            n/=2;
        }
        int m = 0;
        int e = 1;
        for (int i = 31; i >= 0; i--)
        {
            m += e * bits[i];
            e *= 2;
        }
        return m;
    }

    int reverseBitsXOR(int n) {
        std::bitset<32> bits(n);

        for (int i = 0; i < 16; i++)
        {
            bits[i] = bits[i] ^ bits[31 - i];
            bits[31 - i] = bits[i] ^ bits[31 - i];
            bits[i] = bits[i] ^ bits[31 - i];
        }

        return bits.to_ulong();
    }

    int reverseBitsBO(int n) // BO -> Bit operation
    {
        int result = 0;

        for (int i = 0; i < 32; i++)
        {
            result <<= 1;
            result |= (n&1);
            n >>= 1;
        }

        return result;
    }

    int reverseBitsMask(int n)
    {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);

        return n;
    }
};