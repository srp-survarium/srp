int __cdecl bn_mul_add_words(unsigned int *a1, unsigned int *a2, int a3, unsigned int a4)
{
  unsigned int *v4; // eax
  unsigned int *v5; // edx
  int v6; // ecx
  __m64 v7; // mm0
  __m64 v8; // mm1
  __m64 v9; // mm1
  __m64 v10; // mm3
  __m64 v11; // mm5
  __m64 v12; // mm7
  __m64 v13; // mm2
  __m64 v14; // mm4
  __m64 v15; // mm1
  __m64 v16; // mm6
  __m64 v17; // mm3
  __m64 v18; // mm1
  __m64 v19; // mm2
  __m64 v20; // mm1
  __m64 v21; // mm4
  __m64 v22; // mm1
  __m64 v23; // mm6
  __m64 v24; // mm1
  __m64 v25; // mm3
  __m64 v26; // mm1
  __m64 v27; // mm1
  __m64 v28; // mm2
  __m64 v29; // mm1
  int result; // eax
  unsigned int v31; // esi
  unsigned int *v32; // edi
  unsigned int *v33; // ebx
  unsigned int v34; // ecx
  unsigned __int64 v35; // rax
  unsigned __int64 v36; // rax
  unsigned __int64 v37; // rax
  unsigned __int64 v38; // rax
  unsigned __int64 v39; // rax
  unsigned __int64 v40; // rax
  unsigned __int64 v41; // rax
  unsigned __int64 v42; // rax
  unsigned __int64 v43; // rax
  unsigned __int64 v44; // rax
  unsigned __int64 v45; // rax
  unsigned __int64 v46; // rax
  unsigned __int64 v47; // rax
  unsigned __int64 v48; // rax
  unsigned __int64 v49; // rax

  if ( _bittest((const signed __int32 *)&OPENSSL_ia32cap_P, 0x1Au) )
  {
    v4 = a1;
    v5 = a2;
    v6 = a3;
    v7 = _mm_cvtsi32_si64(a4);
    v8.m64_u64 = 0;
    while ( (v6 & 0xFFFFFFF8) != 0 )
    {
      v9 = _mm_add_si64(_mm_add_si64(v8, _mm_cvtsi32_si64(*v4)), _mm_mul_su64(_mm_cvtsi32_si64(*v5), v7));
      v10 = _mm_add_si64(_mm_cvtsi32_si64(v4[1]), _mm_mul_su64(_mm_cvtsi32_si64(v5[1]), v7));
      v11 = _mm_add_si64(_mm_cvtsi32_si64(v4[2]), _mm_mul_su64(_mm_cvtsi32_si64(v5[2]), v7));
      v12 = _mm_add_si64(_mm_mul_su64(_mm_cvtsi32_si64(v5[3]), v7), _mm_cvtsi32_si64(v4[3]));
      *v4 = _mm_cvtsi64_si32(v9);
      v13 = _mm_mul_su64(_mm_cvtsi32_si64(v5[4]), v7);
      v14 = _mm_mul_su64(_mm_cvtsi32_si64(v5[5]), v7);
      v15 = _mm_add_si64(_m_psrlqi(v9, 0x20u), v10);
      v16 = _mm_mul_su64(_mm_cvtsi32_si64(v5[6]), v7);
      v4[1] = _mm_cvtsi64_si32(v15);
      v17 = _mm_cvtsi32_si64(v5[7]);
      v5 += 8;
      v18 = _mm_add_si64(_m_psrlqi(v15, 0x20u), v11);
      v19 = _mm_add_si64(v13, _mm_cvtsi32_si64(v4[4]));
      v4[2] = _mm_cvtsi64_si32(v18);
      v20 = _mm_add_si64(_m_psrlqi(v18, 0x20u), v12);
      v21 = _mm_add_si64(v14, _mm_cvtsi32_si64(v4[5]));
      v4[3] = _mm_cvtsi64_si32(v20);
      v22 = _mm_add_si64(_m_psrlqi(v20, 0x20u), v19);
      v23 = _mm_add_si64(v16, _mm_cvtsi32_si64(v4[6]));
      v4[4] = _mm_cvtsi64_si32(v22);
      v24 = _mm_add_si64(_m_psrlqi(v22, 0x20u), v21);
      v25 = _mm_add_si64(_mm_mul_su64(v17, v7), _mm_cvtsi32_si64(v4[7]));
      v4[5] = _mm_cvtsi64_si32(v24);
      v26 = _mm_add_si64(_m_psrlqi(v24, 0x20u), v23);
      v4[6] = _mm_cvtsi64_si32(v26);
      v27 = _mm_add_si64(_m_psrlqi(v26, 0x20u), v25);
      v4[7] = _mm_cvtsi64_si32(v27);
      v4 += 8;
      v8 = _m_psrlqi(v27, 0x20u);
      v6 -= 8;
      if ( !v6 )
        goto $L003maw_sse2_exit;
    }
    do
    {
      v28 = _mm_mul_su64(_mm_cvtsi32_si64(*v5++), v7);
      v29 = _mm_add_si64(_mm_add_si64(v8, _mm_cvtsi32_si64(*v4)), v28);
      *v4 = _mm_cvtsi64_si32(v29);
      --v6;
      v8 = _m_psrlqi(v29, 0x20u);
      ++v4;
    }
    while ( v6 );
$L003maw_sse2_exit:
    result = _mm_cvtsi64_si32(v8);
    _m_empty();
  }
  else
  {
    v31 = 0;
    v32 = a1;
    v33 = a2;
    v34 = a3 & 0xFFFFFFF8;
    if ( (a3 & 0xFFFFFFF8) != 0 )
    {
      do
      {
        v35 = *v32 + v31 + a4 * (unsigned __int64)*v33;
        *v32 = v35;
        v36 = v32[1] + HIDWORD(v35) + a4 * (unsigned __int64)v33[1];
        v32[1] = v36;
        v37 = v32[2] + HIDWORD(v36) + a4 * (unsigned __int64)v33[2];
        v32[2] = v37;
        v38 = v32[3] + HIDWORD(v37) + a4 * (unsigned __int64)v33[3];
        v32[3] = v38;
        v39 = v32[4] + HIDWORD(v38) + a4 * (unsigned __int64)v33[4];
        v32[4] = v39;
        v40 = v32[5] + HIDWORD(v39) + a4 * (unsigned __int64)v33[5];
        v32[5] = v40;
        v41 = v32[6] + HIDWORD(v40) + a4 * (unsigned __int64)v33[6];
        v32[6] = v41;
        v42 = v32[7] + HIDWORD(v41) + a4 * (unsigned __int64)v33[7];
        v32[7] = v42;
        v31 = HIDWORD(v42);
        v34 -= 8;
        v33 += 8;
        v32 += 8;
      }
      while ( v34 );
    }
    if ( (a3 & 7) != 0 )
    {
      v43 = *v32 + v31 + a4 * (unsigned __int64)*v33;
      *v32 = v43;
      v31 = HIDWORD(v43);
      if ( (a3 & 7) != 1 )
      {
        v44 = v32[1] + HIDWORD(v43) + a4 * (unsigned __int64)v33[1];
        v32[1] = v44;
        v31 = HIDWORD(v44);
        if ( (a3 & 7) != 2 )
        {
          v45 = v32[2] + HIDWORD(v44) + a4 * (unsigned __int64)v33[2];
          v32[2] = v45;
          v31 = HIDWORD(v45);
          if ( (a3 & 7) != 3 )
          {
            v46 = v32[3] + HIDWORD(v45) + a4 * (unsigned __int64)v33[3];
            v32[3] = v46;
            v31 = HIDWORD(v46);
            if ( (a3 & 7) != 4 )
            {
              v47 = v32[4] + HIDWORD(v46) + a4 * (unsigned __int64)v33[4];
              v32[4] = v47;
              v31 = HIDWORD(v47);
              if ( (a3 & 7) != 5 )
              {
                v48 = v32[5] + HIDWORD(v47) + a4 * (unsigned __int64)v33[5];
                v32[5] = v48;
                v31 = HIDWORD(v48);
                if ( (a3 & 7) != 6 )
                {
                  v49 = v32[6] + HIDWORD(v48) + a4 * (unsigned __int64)v33[6];
                  v32[6] = v49;
                  return HIDWORD(v49);
                }
              }
            }
          }
        }
      }
    }
    return v31;
  }
  return result;
}
