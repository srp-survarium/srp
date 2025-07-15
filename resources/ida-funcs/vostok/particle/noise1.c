__m128 __usercall vostok::particle::noise1@<xmm0>(unsigned int seed@<ecx>, __int128 a2@<xmm1>, int sx)
{
  *(float *)&a2 = (float)((float)(*(float *)&a2 - (float)sx)
                        * g[(int)((1873 * seed + 2311 * sx) ^ ((int)(1873 * seed + 2311 * sx) >> 8)) % 256])
                * 2.1199999;
  return (__m128)a2;
}
