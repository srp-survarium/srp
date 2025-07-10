void __usercall stlp_std::priv::__introsort_loop<float *,float,int,stlp_std::less<float>>(
        stlp_std::less<float> a1@<sil>,
        float *__first,
        float *__last,
        float *__formal,
        int __depth_limit,
        float *__comp)
{
  float *v6; // ebx
  float v8; // xmm0_4
  float v9; // xmm2_4
  int v10; // kr00_4
  float v11; // xmm1_4
  float *v12; // eax
  float v13; // xmm0_4
  float *v14; // eax
  float *i; // esi
  float v16; // xmm1_4
  float v17; // xmm1_4

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( 1 )
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<float *,float,stlp_std::less<float>>(__first, v6, v6, __comp, a1);
        return;
      }
      v8 = *__first;
      v9 = *(v6 - 1);
      v10 = v6 - __first;
      v11 = __first[v10 / 2];
      v12 = &__first[v10 / 2];
      --__depth_limit;
      if ( v11 > *__first )
        break;
      if ( v9 > v8 )
        goto LABEL_8;
      if ( v9 > v11 )
        goto LABEL_10;
LABEL_11:
      v13 = *v12;
      v14 = v6;
      for ( i = __first; ; ++i )
      {
        while ( v13 > *i )
          ++i;
        do
          v16 = *--v14;
        while ( v16 > v13 );
        if ( i >= v14 )
          break;
        v17 = *i;
        *i = *v14;
        *v14 = v17;
      }
      stlp_std::priv::__introsort_loop<float *,float,int,stlp_std::less<float>>(
        i,
        v6,
        0,
        __depth_limit,
        (stlp_std::less<float>)__comp);
      v6 = i;
      if ( (int)(((char *)i - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    if ( v9 > v11 )
      goto LABEL_11;
    if ( v9 <= v8 )
    {
LABEL_8:
      v12 = __first;
      goto LABEL_11;
    }
LABEL_10:
    v12 = v6 - 1;
    goto LABEL_11;
  }
}
