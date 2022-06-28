class Solution {
public:
uint32_t reverseBits(uint32_t n) {
bitset<32>s(n);
string x=s.to_string();
reverse(x.begin(),x.end());
s=bitset<32>(x);
return s.to_ullong();
}
};

