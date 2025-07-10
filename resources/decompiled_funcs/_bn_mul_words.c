int __cdecl bn_mul_words(_DWORD *a1, unsigned int *a2, int a3, unsigned int a4)
{
  _DWORD *v4; // eax
  unsigned int *v5; // edx
  int v6; // ecx
  __m64 v7; // mm0
  __m64 v8; // mm1
  __m64 v9; // mm2
  __m64 v10; // mm1
  int result; // eax
  unsigned int v12; // esi
  _DWORD *v13; // edi
  unsigned int *v14; // ebx
  unsigned int v15; // ebp
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rax
  unsigned __int64 v24; // rax
  unsigned __int64 v25; // rax
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // rax
  unsigned __int64 v28; // rax
  unsigned __int64 v29; // rax
  unsigned __int64 v30; // rax

  if ( _bittest((const signed __int32 *)&OPENSSL_ia32cap_P, 0x1Au) )
  {
    v4 = a1;
    v5 = a2;
    v6 = a3;
    v7 = _mm_cvtsi32_si64(a4);
    v8.m64_u64 = 0;
    do
    {
      v9 = _mm_mul_su64(_mm_cvtsi32_si64(*v5++), v7);
      v10 = _mm_add_si64(v8, v9);
      *v4 = _mm_cvtsi64_si32(v10);
      --v6;
      v8 = _m_psrlqi(v10, 0x20u);
      ++v4;
    }
    while ( v6 );
    result = _mm_cvtsi64_si32(v8);
    _m_empty();
  }
  else
  {
    v12 = 0;
    v13 = a1;
    v14 = a2;
    v15 = a3 & 0xFFFFFFF8;
    if ( (a3 & 0xFFFFFFF8) != 0 )
    {
      do
      {
        v16 = v12 + a4 * (unsigned __int64)*v14;
        *v13 = v16;
        v17 = HIDWORD(v16) + a4 * (unsigned __int64)v14[1];
        v13[1] = v17;
        v18 = HIDWORD(v17) + a4 * (unsigned __int64)v14[2];
        v13[2] = v18;
        v19 = HIDWORD(v18) + a4 * (unsigned __int64)v14[3];
        v13[3] = v19;
        v20 = HIDWORD(v19) + a4 * (unsigned __int64)v14[4];
        v13[4] = v20;
        v21 = HIDWORD(v20) + a4 * (unsigned __int64)v14[5];
        v13[5] = v21;
        v22 = HIDWORD(v21) + a4 * (unsigned __int64)v14[6];
        v13[6] = v22;
        v23 = HIDWORD(v22) + a4 * (unsigned __int64)v14[7];
        v13[7] = v23;
        v12 = HIDWORD(v23);
        v14 += 8;
        v13 += 8;
        v15 -= 8;
      }
      while ( v15 );
    }
    if ( (a3 & 7) != 0 )
    {
      v24 = v12 + a4 * (unsigned __int64)*v14;
      *v13 = v24;
      v12 = HIDWORD(v24);
      if ( (a3 & 7) != 1 )
      {
        v25 = HIDWORD(v24) + a4 * (unsigned __int64)v14[1];
        v13[1] = v25;
        v12 = HIDWORD(v25);
        if ( (a3 & 7) != 2 )
        {
          v26 = HIDWORD(v25) + a4 * (unsigned __int64)v14[2];
          v13[2] = v26;
          v12 = HIDWORD(v26);
          if ( (a3 & 7) != 3 )
          {
            v27 = HIDWORD(v26) + a4 * (unsigned __int64)v14[3];
            v13[3] = v27;
            v12 = HIDWORD(v27);
            if ( (a3 & 7) != 4 )
            {
              v28 = HIDWORD(v27) + a4 * (unsigned __int64)v14[4];
              v13[4] = v28;
              v12 = HIDWORD(v28);
              if ( (a3 & 7) != 5 )
              {
                v29 = HIDWORD(v28) + a4 * (unsigned __int64)v14[5];
                v13[5] = v29;
                v12 = HIDWORD(v29);
                if ( (a3 & 7) != 6 )
                {
                  v30 = HIDWORD(v29) + a4 * (unsigned __int64)v14[6];
                  v13[6] = v30;
                  return HIDWORD(v30);
                }
              }
            }
          }
        }
      }
    }
    return v12;
  }
  return result;
}
