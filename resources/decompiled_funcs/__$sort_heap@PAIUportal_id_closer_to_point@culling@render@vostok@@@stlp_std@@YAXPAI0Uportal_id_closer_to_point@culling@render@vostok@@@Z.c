void __usercall stlp_std::sort_heap<unsigned int *,vostok::render::culling::portal_id_closer_to_point>(
        char *__first@<esi>,
        char *__last@<eax>,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // edi

  v3 = __last - __first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(_DWORD *)&__first[v3 - 4];
      *(_DWORD *)&__first[v3 - 4] = *(_DWORD *)__first;
      v5 = v3 - 4;
      stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        (unsigned int *)__first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}
