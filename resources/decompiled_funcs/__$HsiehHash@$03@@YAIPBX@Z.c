unsigned int __usercall HsiehHash<4>@<eax>(unsigned __int16 *pdata@<eax>)
{
  unsigned int v1; // ecx
  int v2; // ecx
  unsigned int v3; // ecx
  unsigned int v4; // esi
  unsigned int v5; // ecx
  unsigned int v6; // ecx
  unsigned int v7; // ecx

  v1 = (((32
        * (((((32 * (*pdata + 16)) ^ pdata[1]) << 11) ^ (*pdata + 16))
         + (((((32 * (*pdata + 16)) ^ pdata[1]) << 11) ^ ((unsigned int)*pdata + 16)) >> 11)
         + pdata[2]))
       ^ pdata[3]) << 11)
     ^ (((((32 * (*pdata + 16)) ^ pdata[1]) << 11) ^ (*pdata + 16))
      + (((((32 * (*pdata + 16)) ^ pdata[1]) << 11) ^ ((unsigned int)*pdata + 16)) >> 11)
      + pdata[2]);
  v2 = v1 + (v1 >> 11) + pdata[4];
  v3 = (((32 * v2) ^ pdata[5]) << 11) ^ v2;
  v4 = v3 + (v3 >> 11);
  v5 = (((((32 * (v4 + pdata[6])) ^ pdata[7]) << 11) ^ (v4 + pdata[6])) >> 11)
     + ((((32 * (v4 + pdata[6])) ^ pdata[7]) << 11) ^ (v4 + pdata[6]));
  v6 = (((8 * v5) ^ v5) >> 5) + ((8 * v5) ^ v5);
  v7 = (((16 * v6) ^ v6) >> 17) + ((16 * v6) ^ v6);
  return ((v7 << 25) ^ v7) + (((v7 << 25) ^ v7) >> 6);
}
