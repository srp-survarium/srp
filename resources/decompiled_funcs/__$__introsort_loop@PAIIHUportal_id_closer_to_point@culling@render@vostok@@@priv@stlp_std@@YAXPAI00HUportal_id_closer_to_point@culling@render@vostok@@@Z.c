void __usercall stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,vostok::render::culling::portal_id_closer_to_point>(
        vostok::render::culling::portal_id_closer_to_point a1@<edi>,
        unsigned int *__first,
        unsigned int *__last,
        unsigned int *__formal,
        int __depth_limit,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  unsigned int *v6; // ebp
  int v7; // kr00_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  unsigned int *v11; // eax
  unsigned int *v12; // esi

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
          __first,
          v6,
          v6,
          (unsigned int *)__comp.m_distances,
          a1);
        return;
      }
      --__depth_limit;
      v7 = v6 - __first;
      v8 = *(float *)((_DWORD)__comp.m_distances + 4 * *__first);
      v9 = *(float *)((_DWORD)__comp.m_distances + 4 * __first[v7 / 2]);
      v10 = *(float *)((_DWORD)__comp.m_distances + 4 * *(v6 - 1));
      v11 = &__first[v7 / 2];
      if ( v9 <= v8 )
      {
        if ( v10 > v8 )
          goto LABEL_8;
        if ( v10 > v9 )
LABEL_10:
          v11 = v6 - 1;
      }
      else if ( v10 <= v9 )
      {
        if ( v10 > v8 )
          goto LABEL_10;
LABEL_8:
        v11 = __first;
      }
      v12 = stlp_std::priv::__unguarded_partition<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
              __first,
              v6,
              *v11,
              __comp);
      stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,vostok::render::culling::portal_id_closer_to_point>(
        v12,
        v6,
        0,
        __depth_limit,
        __comp);
      v6 = v12;
    }
    while ( (int)(((char *)v12 - (char *)__first) & 0xFFFFFFFC) > 64 );
  }
}
