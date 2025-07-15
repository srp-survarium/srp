_WORD *__usercall vostok::math::half::half@<eax>(
        vostok::math::half *this@<ecx>,
        _WORD *result@<eax>,
        unsigned int a3@<xmm0>)
{
  int v3; // esi
  unsigned int v4; // edi
  signed int v5; // edx
  int v6; // edx
  __int16 v7; // di
  int v8; // edx

  v3 = (unsigned __int8)(a3 >> 23) - 112;
  v4 = HIWORD(a3) & 0x8000;
  v5 = a3 & 0x7FFFFF;
  *result = v4;
  if ( v3 <= 0 )
  {
    v6 = (((v5 | 0x800000) >> (1 - v3)) + 4096) >> 13;
LABEL_11:
    *result = v4 | v6;
    return result;
  }
  if ( (unsigned __int8)(a3 >> 23) != 255 )
  {
    v8 = v5 + 4096;
    if ( (v8 & 0x800000) != 0 )
    {
      v8 = 0;
      ++v3;
    }
    if ( v3 >= 31 )
    {
      *result = v4 | 0x7C00;
      return result;
    }
    v6 = (v3 << 10) | (v8 >> 13);
    goto LABEL_11;
  }
  v7 = v4 | 0x7C00;
  *result = v7;
  if ( v5 )
    *result = (v5 >> 13) | v7 | (v5 >> 13 == 0);
  return result;
}
