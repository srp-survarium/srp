void __usercall floor0_map_lazy_init(vorbis_block *vb@<eax>, vorbis_look_floor0 *look@<esi>, int *infoX)
{
  int W; // ecx
  int v4; // ebx
  __int64 v5; // rax
  int v6; // edi
  double v7; // xmm0_8
  __m128d v8; // xmm2
  int v9; // eax
  int v10; // edx
  long double v11; // [esp+0h] [ebp-40h]
  long double v12; // [esp+0h] [ebp-40h]
  long double v13; // [esp+0h] [ebp-40h]
  long double v14; // [esp+0h] [ebp-40h]
  float v15; // [esp+10h] [ebp-30h]
  int v16; // [esp+10h] [ebp-30h]
  double ln; // [esp+18h] [ebp-28h]
  float v18; // [esp+18h] [ebp-28h]
  float v19; // [esp+28h] [ebp-18h]
  int v20; // [esp+34h] [ebp-Ch]

  W = vb->W;
  v20 = W;
  if ( !look->linearmap[W] )
  {
    v4 = W;
    v5 = *((int *)vb->vd->vi->codec_setup + W);
    v15 = (float)infoX[1] * 0.5;
    ln = (double)look->ln;
    v6 = ((int)v5 - HIDWORD(v5)) >> 1;
    __libm_sse2_atan(v11);
    __libm_sse2_atan(v12);
    v19 = ln
        / ((float)((float)(v15 * v15) * 0.0000000185) * 2.240000009536743
         + (float)(v15 * 0.00073999999) * 13.10000038146973
         + (float)(v15 * 0.000099999997));
    v16 = 0;
    for ( look->linearmap[v4] = (int *)ogg_malloc_impl(4 * v6 + 4); v16 < v6; look->linearmap[v4][v10] = v9 )
    {
      v18 = (float)((float)((float)infoX[1] * 0.5) / (float)v6) * (float)v16;
      __libm_sse2_atan(v13);
      __libm_sse2_atan(v14);
      v7 = ((float)((float)(v18 * v18) * 0.0000000185) * 2.240000009536743
          + (float)(v18 * 0.00073999999) * 13.10000038146973
          + (float)(v18 * 0.000099999997))
         * v19;
      *(_QWORD *)&v8.m128d_f64[0] = *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v7;
      v9 = (int)(v7
               + COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v7)
               - COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v7)
               - COERCE_DOUBLE(
                   *(_OWORD *)&_mm_cmpgt_sd(
                                 (__m128d)COERCE_UNSIGNED_INT64(
                                            v7
                                          + COERCE_DOUBLE(
                                              *(_QWORD *)&DOUBLE_4_503599627370496e15
                                            | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v7)
                                          - COERCE_DOUBLE(
                                              *(_QWORD *)&DOUBLE_4_503599627370496e15
                                            | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v7)
                                          - v7),
                                 v8)
                 & *(_QWORD *)&DOUBLE_1_0));
      if ( v9 >= look->ln )
        v9 = look->ln - 1;
      v10 = v16++;
    }
    look->linearmap[v4][v16] = -1;
    look->n[v20] = v6;
  }
}
