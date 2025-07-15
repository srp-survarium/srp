int __usercall _sse_AES_decrypt_compact@<eax>(int a1@<ebp>, __m64 *a2@<edi>, __m64 a3@<mm0>, __m64 a4@<mm4>)
{
  __m64 v4; // mm0
  __m64 v5; // mm4
  unsigned int v6; // eax
  unsigned int v7; // ebx
  int v8; // edx
  __m64 v9; // mm2
  int v10; // ecx
  int v11; // edx
  __m64 v12; // mm0
  int v13; // esi
  unsigned int v14; // eax
  int v15; // ecx
  int v16; // esi
  unsigned int v17; // ebx
  __m64 v18; // mm1
  int v19; // edx
  int v20; // edx
  __m64 v21; // mm0
  unsigned int v22; // edx
  int result; // eax
  __m64 v24; // mm4
  __m64 v25; // mm2
  __m64 v26; // mm6
  __m64 v27; // mm3
  __m64 v28; // mm7
  __m64 v29; // mm1
  __m64 v30; // mm5
  __m64 v31; // mm0
  __m64 v32; // mm4
  __m64 v33; // mm1
  __m64 v34; // mm5
  __m64 v35; // mm3
  __m64 v36; // mm7
  __m64 v37; // mm0
  __m64 v38; // mm4
  __m64 v39; // mm1
  __m64 v40; // mm5
  __m64 v41; // mm3
  __m64 v42; // mm7
  __m64 *v48; // [esp+18h] [ebp+18h]

  v4 = _m_pxor(a3, (__m64)a2->m64_u64);
  v5 = _m_pxor(a4, a2[1]);
  v48 = &a2[2 * a2[30].m64_i32[0] - 2];
  while ( 1 )
  {
    v6 = _mm_cvtsi64_si32(_m_pshufw(v4, 12));
    v7 = _mm_cvtsi64_si32(_m_pshufw(v5, 9));
    v8 = *(unsigned __int8 *)(a1 + BYTE1(v6) - 128) << 8;
    v9 = _m_pshufw(v4, 6);
    v10 = (*(unsigned __int8 *)(a1 + (unsigned __int8)v7 - 128) << 16)
        | *(unsigned __int8 *)(a1 + (unsigned __int8)v6 - 128);
    v6 >>= 16;
    v11 = (*(unsigned __int8 *)(a1 + BYTE1(v7) - 128) << 24) | v8;
    v7 >>= 16;
    v12 = _mm_cvtsi32_si64(
            (*(unsigned __int8 *)(a1 + BYTE1(v7) - 128) << 8)
          | (*(unsigned __int8 *)(a1 + BYTE1(v6) - 128) << 24)
          | (unsigned int)v10);
    v13 = (unsigned __int8)v6;
    v14 = _mm_cvtsi64_si32(v9);
    v15 = *(unsigned __int8 *)(a1 + v13 - 128) << 16;
    v16 = (unsigned __int8)v7;
    v17 = _mm_cvtsi64_si32(_m_pshufw(v5, 3));
    v18 = _mm_cvtsi32_si64(
            (*(unsigned __int8 *)(a1 + (unsigned __int8)v17 - 128) << 16)
          | *(unsigned __int8 *)(a1 + (unsigned __int8)v14 - 128)
          | (unsigned int)v11);
    v19 = *(unsigned __int8 *)(a1 + BYTE1(v14) - 128) << 8;
    v14 >>= 16;
    v20 = (*(unsigned __int8 *)(a1 + BYTE1(v17) - 128) << 24) | v19;
    v17 >>= 16;
    v21 = _m_punpckldq(v12, v18);
    v22 = (*(unsigned __int8 *)(a1 + (unsigned __int8)v14 - 128) << 16)
        | *(unsigned __int8 *)(a1 + (unsigned __int8)v17 - 128)
        | v20;
    result = *(unsigned __int8 *)(a1 + BYTE1(v14) - 128) << 24;
    v24 = _m_punpckldq(
            _mm_cvtsi32_si64(v22),
            _mm_cvtsi32_si64(
              result
            | (*(unsigned __int8 *)(a1 + BYTE1(v17) - 128) << 8)
            | *(unsigned __int8 *)(a1 + v16 - 128)
            | (unsigned int)v15));
    a2 += 2;
    if ( a2 > v48 )
      break;
    v25 = _m_pslldi(_m_pshufw(v21, 228), 8u);
    v26 = _m_pslldi(_m_pshufw(v24, 228), 8u);
    v27 = _m_psrldi(v21, 8u);
    v28 = _m_psrldi(v24, 8u);
    v29 = _m_pxor(_m_paddb(v21, v21), _m_pand(_m_pcmpgtb(0, v21), (__m64)0x1B1B1B1B1B1B1B1BLL));
    v30 = _m_pxor(_m_paddb(v24, v24), _m_pand(_m_pcmpgtb(0, v24), (__m64)0x1B1B1B1B1B1B1B1BLL));
    v31 = _m_pxor(
            _m_pxor(
              _m_pxor(
                _m_pxor(
                  _m_pxor(_m_pxor(_m_pxor(_m_pshufw(v21, 177), v25), v27), _m_pslldi(v25, 0x10u)),
                  _m_psrldi(v27, 0x10u)),
                v29),
              _m_pslldi(v29, 0x18u)),
            _m_psrldi(v29, 8u));
    v32 = _m_pxor(
            _m_pxor(
              _m_pxor(
                _m_pxor(
                  _m_pxor(_m_pxor(_m_pxor(_m_pshufw(v24, 177), v26), v28), _m_pslldi(v26, 0x10u)),
                  _m_psrldi(v28, 0x10u)),
                v30),
              _m_pslldi(v30, 0x18u)),
            _m_psrldi(v30, 8u));
    v33 = _m_pxor(_m_paddb(v29, v29), _m_pand(_m_pcmpgtb(0, v29), (__m64)0x1B1B1B1B1B1B1B1BLL));
    v34 = _m_pxor(_m_paddb(v30, v30), _m_pand(_m_pcmpgtb(0, v30), (__m64)0x1B1B1B1B1B1B1B1BLL));
    v35 = _m_pxor(_m_paddb(v33, v33), _m_pand(_m_pcmpgtb(0, v33), (__m64)0x1B1B1B1B1B1B1B1BLL));
    v36 = _m_pxor(_m_paddb(v34, v34), _m_pand(_m_pcmpgtb(0, v34), (__m64)0x1B1B1B1B1B1B1B1BLL));
    v37 = _m_pxor(_m_pxor(_m_pxor(_m_pxor(v31, v33), _m_pshufw(v33, 177)), v35), _m_pshufw(v35, 177));
    v38 = _m_pxor(_m_pxor(_m_pxor(_m_pxor(v32, v34), _m_pshufw(v34, 177)), v36), _m_pshufw(v36, 177));
    v39 = _m_pslldi(v35, 8u);
    v40 = _m_pslldi(v36, 8u);
    v41 = _m_psrldi(v35, 8u);
    v42 = _m_psrldi(v36, 8u);
    v4 = _m_pxor(
           _m_pxor(_m_pxor(_m_pxor(_m_pxor(v37, v39), v41), _m_pslldi(v39, 0x10u)), _m_psrldi(v41, 0x10u)),
           (__m64)a2->m64_u64);
    v5 = _m_pxor(_m_pxor(_m_pxor(_m_pxor(_m_pxor(v38, v40), v42), _m_pslldi(v40, 0x10u)), _m_psrldi(v42, 0x10u)), a2[1]);
  }
  return result;
}
