int __usercall _book_maptype1_quantvals@<eax>(
        const static_codebook *b@<eax>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        __int128 a5@<xmm0>)
{
  int dim; // esi
  __m128d v6; // xmm2
  double v7; // xmm1_8
  __m128d v8; // xmm3
  int result; // eax
  int v10; // ecx
  int v11; // edi
  long double v12; // [esp-Ch] [ebp-20h]
  long double v13; // [esp-4h] [ebp-18h]
  int v14; // [esp+Ch] [ebp-8h]
  int entries; // [esp+10h] [ebp-4h]

  LODWORD(v13) = a2;
  HIDWORD(v12) = a4;
  dim = b->dim;
  LODWORD(v12) = a3;
  entries = b->entries;
  *(double *)&a5 = (float)entries;
  __libm_sse2_pow(v12, v13);
  *(_QWORD *)&v6.m128d_f64[0] = *(_QWORD *)&DOUBLE_N0_0 & a5;
  v7 = *(double *)&a5
     + COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&v6.m128d_f64[0])
     - COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&v6.m128d_f64[0]);
  v8.m128d_f64[1] = *((long double *)&a5 + 1);
  v8.m128d_f64[0] = v7 - *(double *)&a5;
  for ( result = (int)(v7 - COERCE_DOUBLE(*(_OWORD *)&_mm_cmpgt_sd(v8, v6) & *(_QWORD *)&DOUBLE_1_0)); ; ++result )
  {
    while ( 1 )
    {
      v10 = 1;
      v14 = 1;
      if ( dim > 0 )
      {
        v11 = dim;
        do
        {
          v10 *= result;
          --v11;
          v14 *= result + 1;
        }
        while ( v11 );
      }
      if ( v10 <= entries )
        break;
      --result;
    }
    if ( v14 > entries )
      break;
  }
  return result;
}
