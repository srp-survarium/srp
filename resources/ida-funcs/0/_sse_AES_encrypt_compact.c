int __usercall _sse_AES_encrypt_compact@<eax>(int a1@<ebp>, __m64 *a2@<edi>, __m64 a3@<mm0>, __m64 a4@<mm4>)
{
  __m64 v4; // mm0
  __m64 v5; // mm4
  unsigned int v6; // eax
  unsigned int v7; // ebx
  int v8; // ecx
  __m64 v9; // mm2
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  __m64 v13; // mm0
  int v14; // ecx
  unsigned int v15; // eax
  int v16; // ecx
  int v17; // ebx
  __m64 v18; // mm1
  int v19; // ecx
  __m64 v20; // mm0
  int v21; // ecx
  int result; // eax
  __m64 v23; // mm4
  __m64 v24; // mm1
  __m64 v25; // mm5
  __m64 v26; // mm2
  __m64 v27; // mm6
  __m64 v28; // mm0
  __m64 v29; // mm4
  __m64 v30; // mm1
  __m64 v31; // mm5
  __m64 v32; // mm0
  __m64 v33; // mm4
  __m64 v34; // mm2
  __m64 v35; // mm6
  __m64 *v41; // [esp+18h] [ebp+18h]

  v4 = _m_pxor(a3, (__m64)a2->m64_u64);
  v5 = _m_pxor(a4, a2[1]);
  v41 = &a2[2 * a2[30].m64_i32[0] - 2];
  while ( 1 )
  {
    v6 = _mm_cvtsi64_si32(_m_pshufw(v4, 8));
    v7 = _mm_cvtsi64_si32(_m_pshufw(v5, 13));
    v8 = *(unsigned __int8 *)(a1 + (unsigned __int8)v6 - 128);
    v9 = _m_pshufw(v4, 13);
    v10 = *(unsigned __int8 *)(a1 + BYTE1(v6) - 128) << 8;
    v6 >>= 16;
    v11 = (*(unsigned __int8 *)(a1 + (unsigned __int8)v7 - 128) << 16) | v8;
    v12 = (*(unsigned __int8 *)(a1 + BYTE1(v7) - 128) << 24) | v10;
    v7 >>= 16;
    v13 = _mm_cvtsi32_si64(
            (*(unsigned __int8 *)(a1 + BYTE1(v7) - 128) << 24)
          | (*(unsigned __int8 *)(a1 + BYTE1(v6) - 128) << 8)
          | (unsigned int)v11);
    v14 = *(unsigned __int8 *)(a1 + (unsigned __int8)v6 - 128);
    v15 = _mm_cvtsi64_si32(v9);
    v16 = (*(unsigned __int8 *)(a1 + (unsigned __int8)v7 - 128) << 16) | v14;
    v17 = _mm_cvtsi64_si32(_m_pshufw(v5, 8));
    v18 = _mm_cvtsi32_si64(
            (*(unsigned __int8 *)(a1 + BYTE1(v17) - 128) << 8)
          | (*(unsigned __int8 *)(a1 + BYTE1(v15) - 128) << 24)
          | (unsigned int)v16);
    v19 = (*(unsigned __int8 *)(a1 + (unsigned __int8)v15 - 128) << 16)
        | *(unsigned __int8 *)(a1 + (unsigned __int8)v17 - 128);
    v15 >>= 16;
    v20 = _m_punpckldq(v13, v18);
    v21 = (*(unsigned __int8 *)(a1 + BYTE1(v15) - 128) << 24) | v19;
    result = *(unsigned __int8 *)(a1 + (unsigned __int8)v15 - 128) << 16;
    v23 = _m_punpckldq(
            _mm_cvtsi32_si64((*(unsigned __int8 *)(a1 + HIBYTE(v17) - 128) << 8) | (unsigned int)v21),
            _mm_cvtsi32_si64(*(unsigned __int8 *)(a1 + BYTE2(v17) - 128) | result | (unsigned int)v12));
    a2 += 2;
    if ( a2 > v41 )
      break;
    v24 = v20;
    v25 = v23;
    v26 = _m_pshufw(v20, 177);
    v27 = _m_pshufw(v23, 177);
    v28 = _m_pxor(_m_paddb(v20, v20), _m_pand(_m_pcmpgtb(0, v20), (__m64)0x1B1B1B1B1B1B1B1BLL));
    v29 = _m_pxor(_m_paddb(v23, v23), _m_pand(_m_pcmpgtb(0, v23), (__m64)0x1B1B1B1B1B1B1B1BLL));
    v30 = _m_pxor(v24, v28);
    v31 = _m_pxor(v25, v29);
    v32 = _m_pxor(v28, v26);
    v33 = _m_pxor(v29, v27);
    v34 = _m_pshufw(v26, 177);
    v35 = _m_pshufw(v27, 177);
    v4 = _m_pxor(
           _m_pxor(
             _m_pxor(_m_pxor(_m_pxor(v32, _m_pslldi(v34, 8u)), _m_psrldi(v34, 0x18u)), _m_psrldi(v30, 8u)),
             _m_pslldi(v30, 0x18u)),
           (__m64)a2->m64_u64);
    v5 = _m_pxor(
           _m_pxor(
             _m_pxor(_m_pxor(_m_pxor(v33, _m_pslldi(v35, 8u)), _m_psrldi(v35, 0x18u)), _m_psrldi(v31, 8u)),
             _m_pslldi(v31, 0x18u)),
           a2[1]);
  }
  return result;
}
