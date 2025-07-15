int __usercall noise_normalize@<xmm0>(
        vorbis_look_psy *p@<eax>,
        float *q@<esi>,
        char *out@<edi>,
        int limit,
        float *r,
        float *f,
        char *flags,
        float acc,
        int i,
        int n)
{
  void *v10; // esp
  int v11; // eax
  float *v12; // ecx
  double v13; // xmm5_8
  __m128d v14; // xmm6
  double v15; // xmm1_8
  int v16; // edx
  char *v17; // eax
  float *v18; // ecx
  float v19; // xmm1_4
  unsigned int v20; // ebx
  double v21; // xmm5_8
  __m128d v22; // xmm6
  double v23; // xmm1_8
  _DWORD *v24; // ebx
  signed int k; // ecx
  int v26; // eax
  float v27; // xmm0_4
  int v29; // [esp+0h] [ebp-24h] BYREF
  vorbis_info_psy *vi; // [esp+4h] [ebp-20h]
  int v31; // [esp+8h] [ebp-1Ch]
  void *base; // [esp+Ch] [ebp-18h]
  int j; // [esp+10h] [ebp-14h]
  int v34; // [esp+14h] [ebp-10h]
  int v35; // [esp+18h] [ebp-Ch]
  int v36; // [esp+1Ch] [ebp-8h]
  unsigned int num; // [esp+20h] [ebp-4h]
  float v38; // [esp+3Ch] [ebp+18h]

  vi = p->vi;
  v10 = alloca(4 * n);
  base = &v29;
  num = 0;
  if ( vi->normal_p )
    v11 = vi->normal_start - i;
  else
    v11 = n;
  if ( v11 > n )
    v11 = n;
  v38 = 0.0;
  v36 = 0;
  if ( v11 > 0 )
  {
    j = flags - (char *)q;
    v34 = (char *)f - (char *)q;
    v35 = (char *)r - (char *)q;
    v12 = q;
    v36 = v11;
    do
    {
      if ( !flags || !*(_DWORD *)((char *)v12 + j) )
      {
        v13 = sqrt((float)(*v12 / *(float *)((char *)v12 + v34))) + 0.5;
        *(_QWORD *)&v14.m128d_f64[0] = *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v13;
        v15 = v13
            + COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v13)
            - COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v13)
            - COERCE_DOUBLE(
                *(_OWORD *)&_mm_cmpgt_sd(
                              (__m128d)COERCE_UNSIGNED_INT64(
                                         v13
                                       + COERCE_DOUBLE(
                                           *(_QWORD *)&DOUBLE_4_503599627370496e15
                                         | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v13)
                                       - COERCE_DOUBLE(
                                           *(_QWORD *)&DOUBLE_4_503599627370496e15
                                         | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v13)
                                       - v13),
                              v14)
              & *(_QWORD *)&DOUBLE_1_0);
        if ( *(float *)((char *)v12 + v35) < 0.0 )
          v15 = -v15;
        *(_DWORD *)((char *)v12 + out - (char *)q) = (int)v15;
      }
      ++v12;
      --v11;
    }
    while ( v11 );
  }
  if ( v36 < n )
  {
    v35 = (char *)r - out;
    v16 = (char *)f - out;
    v34 = (char *)q - out;
    v17 = &out[4 * v36];
    v31 = flags - (char *)r;
    for ( j = (char *)f - out; ; v16 = j )
    {
      if ( !flags || !*(_DWORD *)&v17[v31 + v35] )
      {
        v18 = (float *)&v17[v34];
        v19 = *(float *)&v17[v34] / *(float *)&v17[v16];
        if ( v19 >= 0.25 || flags && v36 < limit - i )
        {
          v21 = sqrt(v19) + 0.5;
          *(_QWORD *)&v22.m128d_f64[0] = *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v21;
          v23 = v21
              + COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v21)
              - COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v21)
              - COERCE_DOUBLE(
                  *(_OWORD *)&_mm_cmpgt_sd(
                                (__m128d)COERCE_UNSIGNED_INT64(
                                           v21
                                         + COERCE_DOUBLE(
                                             *(_QWORD *)&DOUBLE_4_503599627370496e15
                                           | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v21)
                                         - COERCE_DOUBLE(
                                             *(_QWORD *)&DOUBLE_4_503599627370496e15
                                           | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v21)
                                         - v21),
                                v22)
                & *(_QWORD *)&DOUBLE_1_0);
          if ( *(float *)&v17[v35] < 0.0 )
            v23 = -v23;
          *(_DWORD *)v17 = (int)v23;
          *v18 = (float)((int)v23 * (int)v23) * *(float *)&v17[j];
        }
        else
        {
          v20 = num++;
          v38 = v19 + v38;
          *(&v29 + v20) = (int)v18;
        }
      }
      ++v36;
      v17 += 4;
      if ( v36 >= n )
        break;
    }
    if ( num )
    {
      v24 = base;
      qsort((char *)base, num, 4u, (int (__cdecl *)(const void *, const void *))apsort);
      for ( k = 0; k < (int)num; ++k )
      {
        v26 = (v24[k] - (int)q) >> 2;
        if ( v38 < vi->normal_thresh )
        {
          *(_DWORD *)&out[v26 * 4] = 0;
          q[v26] = 0.0;
        }
        else
        {
          v27 = v38 - s_bm_current_air_resistance;
          *(_DWORD *)&out[v26 * 4] = (int)COERCE_FLOAT(LODWORD(r[v26]) & 0x80000000 | 0x3F800000);
          v38 = v27;
          q[v26] = f[v26];
        }
      }
    }
  }
  return LODWORD(v38);
}
