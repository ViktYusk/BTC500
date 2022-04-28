#include "ripemd160.h"

void ripemd160(unsigned char* input, unsigned char* output)
{
    unsigned chunk[16] = {0x00000000};
    for (int i = 0; i < 32; i++)
        chunk[i / 4] |= (unsigned)input[i] << i % 4 * 8;
    chunk[8] = 0x00000080;
    chunk[14] = 0x00000100;
    unsigned output_[5] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0 };
    unsigned aa = output_[0], bb = output_[1], cc = output_[2], dd = output_[3], ee = output_[4];
    unsigned aaa = output_[0], bbb = output_[1], ccc = output_[2], ddd = output_[3], eee = output_[4];
    FF(aa, bb, cc, dd, ee, chunk[0], 11) FF(ee, aa, bb, cc, dd, chunk[1], 14) 
    FF(dd, ee, aa, bb, cc, chunk[2], 15) FF(cc, dd, ee, aa, bb, chunk[3], 12) 
    FF(bb, cc, dd, ee, aa, chunk[4], 5) FF(aa, bb, cc, dd, ee, chunk[5], 8) 
    FF(ee, aa, bb, cc, dd, chunk[6], 7) FF(dd, ee, aa, bb, cc, chunk[7], 9) 
    FF(cc, dd, ee, aa, bb, chunk[8], 11) FF(bb, cc, dd, ee, aa, chunk[9], 13) 
    FF(aa, bb, cc, dd, ee, chunk[10], 14) FF(ee, aa, bb, cc, dd, chunk[11], 15) 
    FF(dd, ee, aa, bb, cc, chunk[12], 6) FF(cc, dd, ee, aa, bb, chunk[13], 7) 
    FF(bb, cc, dd, ee, aa, chunk[14], 9) FF(aa, bb, cc, dd, ee, chunk[15], 8) 
    GG(ee, aa, bb, cc, dd, chunk[7], 7) GG(dd, ee, aa, bb, cc, chunk[4], 6) 
    GG(cc, dd, ee, aa, bb, chunk[13], 8) GG(bb, cc, dd, ee, aa, chunk[1], 13) 
    GG(aa, bb, cc, dd, ee, chunk[10], 11) GG(ee, aa, bb, cc, dd, chunk[6], 9) 
    GG(dd, ee, aa, bb, cc, chunk[15], 7) GG(cc, dd, ee, aa, bb, chunk[3], 15) 
    GG(bb, cc, dd, ee, aa, chunk[12], 7) GG(aa, bb, cc, dd, ee, chunk[0], 12) 
    GG(ee, aa, bb, cc, dd, chunk[9], 15) GG(dd, ee, aa, bb, cc, chunk[5], 9) 
    GG(cc, dd, ee, aa, bb, chunk[2], 11) GG(bb, cc, dd, ee, aa, chunk[14], 7) 
    GG(aa, bb, cc, dd, ee, chunk[11], 13) GG(ee, aa, bb, cc, dd, chunk[8], 12) 
    HH(dd, ee, aa, bb, cc, chunk[3], 11) HH(cc, dd, ee, aa, bb, chunk[10], 13) 
    HH(bb, cc, dd, ee, aa, chunk[14], 6) HH(aa, bb, cc, dd, ee, chunk[4], 7) 
    HH(ee, aa, bb, cc, dd, chunk[9], 14) HH(dd, ee, aa, bb, cc, chunk[15], 9) 
    HH(cc, dd, ee, aa, bb, chunk[8], 13) HH(bb, cc, dd, ee, aa, chunk[1], 15) 
    HH(aa, bb, cc, dd, ee, chunk[2], 14) HH(ee, aa, bb, cc, dd, chunk[7], 8) 
    HH(dd, ee, aa, bb, cc, chunk[0], 13) HH(cc, dd, ee, aa, bb, chunk[6], 6) 
    HH(bb, cc, dd, ee, aa, chunk[13], 5) HH(aa, bb, cc, dd, ee, chunk[11], 12) 
    HH(ee, aa, bb, cc, dd, chunk[5], 7) HH(dd, ee, aa, bb, cc, chunk[12], 5) 
    II(cc, dd, ee, aa, bb, chunk[1], 11) II(bb, cc, dd, ee, aa, chunk[9], 12) 
    II(aa, bb, cc, dd, ee, chunk[11], 14) II(ee, aa, bb, cc, dd, chunk[10], 15) 
    II(dd, ee, aa, bb, cc, chunk[0], 14) II(cc, dd, ee, aa, bb, chunk[8], 15) 
    II(bb, cc, dd, ee, aa, chunk[12], 9) II(aa, bb, cc, dd, ee, chunk[4], 8) 
    II(ee, aa, bb, cc, dd, chunk[13], 9) II(dd, ee, aa, bb, cc, chunk[3], 14) 
    II(cc, dd, ee, aa, bb, chunk[7], 5) II(bb, cc, dd, ee, aa, chunk[15], 6) 
    II(aa, bb, cc, dd, ee, chunk[14], 8) II(ee, aa, bb, cc, dd, chunk[5], 6) 
    II(dd, ee, aa, bb, cc, chunk[6], 5) II(cc, dd, ee, aa, bb, chunk[2], 12) 
    JJ(bb, cc, dd, ee, aa, chunk[4], 9) JJ(aa, bb, cc, dd, ee, chunk[0], 15) 
    JJ(ee, aa, bb, cc, dd, chunk[5], 5) JJ(dd, ee, aa, bb, cc, chunk[9], 11) 
    JJ(cc, dd, ee, aa, bb, chunk[7], 6) JJ(bb, cc, dd, ee, aa, chunk[12], 8) 
    JJ(aa, bb, cc, dd, ee, chunk[2], 13) JJ(ee, aa, bb, cc, dd, chunk[10], 12) 
    JJ(dd, ee, aa, bb, cc, chunk[14], 5) JJ(cc, dd, ee, aa, bb, chunk[1], 12) 
    JJ(bb, cc, dd, ee, aa, chunk[3], 13) JJ(aa, bb, cc, dd, ee, chunk[8], 14) 
    JJ(ee, aa, bb, cc, dd, chunk[11], 11) JJ(dd, ee, aa, bb, cc, chunk[6], 8) 
    JJ(cc, dd, ee, aa, bb, chunk[15], 5) JJ(bb, cc, dd, ee, aa, chunk[13], 6) 
    JJJ(aaa, bbb, ccc, ddd, eee, chunk[5], 8) JJJ(eee, aaa, bbb, ccc, ddd, chunk[14], 9) 
    JJJ(ddd, eee, aaa, bbb, ccc, chunk[7], 9) JJJ(ccc, ddd, eee, aaa, bbb, chunk[0], 11) 
    JJJ(bbb, ccc, ddd, eee, aaa, chunk[9], 13) JJJ(aaa, bbb, ccc, ddd, eee, chunk[2], 15) 
    JJJ(eee, aaa, bbb, ccc, ddd, chunk[11], 15) JJJ(ddd, eee, aaa, bbb, ccc, chunk[4], 5) 
    JJJ(ccc, ddd, eee, aaa, bbb, chunk[13], 7) JJJ(bbb, ccc, ddd, eee, aaa, chunk[6], 7) 
    JJJ(aaa, bbb, ccc, ddd, eee, chunk[15], 8) JJJ(eee, aaa, bbb, ccc, ddd, chunk[8], 11) 
    JJJ(ddd, eee, aaa, bbb, ccc, chunk[1], 14) JJJ(ccc, ddd, eee, aaa, bbb, chunk[10], 14) 
    JJJ(bbb, ccc, ddd, eee, aaa, chunk[3], 12) JJJ(aaa, bbb, ccc, ddd, eee, chunk[12], 6) 
    III(eee, aaa, bbb, ccc, ddd, chunk[6], 9) III(ddd, eee, aaa, bbb, ccc, chunk[11], 13) 
    III(ccc, ddd, eee, aaa, bbb, chunk[3], 15) III(bbb, ccc, ddd, eee, aaa, chunk[7], 7) 
    III(aaa, bbb, ccc, ddd, eee, chunk[0], 12) III(eee, aaa, bbb, ccc, ddd, chunk[13], 8)
    III(ddd, eee, aaa, bbb, ccc, chunk[5], 9) III(ccc, ddd, eee, aaa, bbb, chunk[10], 11) 
    III(bbb, ccc, ddd, eee, aaa, chunk[14], 7) III(aaa, bbb, ccc, ddd, eee, chunk[15], 7) 
    III(eee, aaa, bbb, ccc, ddd, chunk[8], 12) III(ddd, eee, aaa, bbb, ccc, chunk[12], 7) 
    III(ccc, ddd, eee, aaa, bbb, chunk[4], 6) III(bbb, ccc, ddd, eee, aaa, chunk[9], 15) 
    III(aaa, bbb, ccc, ddd, eee, chunk[1], 13) III(eee, aaa, bbb, ccc, ddd, chunk[2], 11) 
    HHH(ddd, eee, aaa, bbb, ccc, chunk[15], 9) HHH(ccc, ddd, eee, aaa, bbb, chunk[5], 7) 
    HHH(bbb, ccc, ddd, eee, aaa, chunk[1], 15) HHH(aaa, bbb, ccc, ddd, eee, chunk[3], 11) 
    HHH(eee, aaa, bbb, ccc, ddd, chunk[7], 8) HHH(ddd, eee, aaa, bbb, ccc, chunk[14], 6) 
    HHH(ccc, ddd, eee, aaa, bbb, chunk[6], 6) HHH(bbb, ccc, ddd, eee, aaa, chunk[9], 14) 
    HHH(aaa, bbb, ccc, ddd, eee, chunk[11], 12) HHH(eee, aaa, bbb, ccc, ddd, chunk[8], 13) 
    HHH(ddd, eee, aaa, bbb, ccc, chunk[12], 5) HHH(ccc, ddd, eee, aaa, bbb, chunk[2], 14) 
    HHH(bbb, ccc, ddd, eee, aaa, chunk[10], 13) HHH(aaa, bbb, ccc, ddd, eee, chunk[0], 13) 
    HHH(eee, aaa, bbb, ccc, ddd, chunk[4], 7) HHH(ddd, eee, aaa, bbb, ccc, chunk[13], 5) 
    GGG(ccc, ddd, eee, aaa, bbb, chunk[8], 15) GGG(bbb, ccc, ddd, eee, aaa, chunk[6], 5) 
    GGG(aaa, bbb, ccc, ddd, eee, chunk[4], 8) GGG(eee, aaa, bbb, ccc, ddd, chunk[1], 11) 
    GGG(ddd, eee, aaa, bbb, ccc, chunk[3], 14) GGG(ccc, ddd, eee, aaa, bbb, chunk[11], 14) 
    GGG(bbb, ccc, ddd, eee, aaa, chunk[15], 6) GGG(aaa, bbb, ccc, ddd, eee, chunk[0], 14) 
    GGG(eee, aaa, bbb, ccc, ddd, chunk[5], 6) GGG(ddd, eee, aaa, bbb, ccc, chunk[12], 9) 
    GGG(ccc, ddd, eee, aaa, bbb, chunk[2], 12) GGG(bbb, ccc, ddd, eee, aaa, chunk[13], 9) 
    GGG(aaa, bbb, ccc, ddd, eee, chunk[9], 12) GGG(eee, aaa, bbb, ccc, ddd, chunk[7], 5) 
    GGG(ddd, eee, aaa, bbb, ccc, chunk[10], 15) GGG(ccc, ddd, eee, aaa, bbb, chunk[14], 8) 
    FFF(bbb, ccc, ddd, eee, aaa, chunk[12], 8) FFF(aaa, bbb, ccc, ddd, eee, chunk[15], 5) 
    FFF(eee, aaa, bbb, ccc, ddd, chunk[10], 12) FFF(ddd, eee, aaa, bbb, ccc, chunk[4], 9) 
    FFF(ccc, ddd, eee, aaa, bbb, chunk[1], 12) FFF(bbb, ccc, ddd, eee, aaa, chunk[5], 5) 
    FFF(aaa, bbb, ccc, ddd, eee, chunk[8], 14) FFF(eee, aaa, bbb, ccc, ddd, chunk[7], 6) 
    FFF(ddd, eee, aaa, bbb, ccc, chunk[6], 8) FFF(ccc, ddd, eee, aaa, bbb, chunk[2], 13) 
    FFF(bbb, ccc, ddd, eee, aaa, chunk[13], 6) FFF(aaa, bbb, ccc, ddd, eee, chunk[14], 5) 
    FFF(eee, aaa, bbb, ccc, ddd, chunk[0], 15) FFF(ddd, eee, aaa, bbb, ccc, chunk[3], 13) 
    FFF(ccc, ddd, eee, aaa, bbb, chunk[9], 11) FFF(bbb, ccc, ddd, eee, aaa, chunk[11], 11)
    ddd += cc + output_[1]; output_[1] = output_[2] + dd + eee; output_[2] = output_[3] + ee + aaa;
    output_[3] = output_[4] + aa + bbb; output_[4] = output_[0] + bb + ccc; output_[0] = ddd;
    for (int i = 0; i < 20; i++)
        output[i] = ((unsigned char*)output_)[i];
}
