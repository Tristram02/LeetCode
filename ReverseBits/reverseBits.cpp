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
};