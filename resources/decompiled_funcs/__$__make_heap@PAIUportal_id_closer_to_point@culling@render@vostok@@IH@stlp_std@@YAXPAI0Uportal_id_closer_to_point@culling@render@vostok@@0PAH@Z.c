void __usercall stlp_std::__make_heap<unsigned int *,vostok::render::culling::portal_id_closer_to_point,unsigned int,int>(
        unsigned int *__first@<edi>,
        unsigned int *__last,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  int v3; // ebx
  int v4; // esi
  unsigned int v5; // ecx

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    v4 = (v3 - 2) / 2;
    stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
      __first,
      v4,
      __last - __first,
      __first[v4],
      __comp);
    while ( v4 )
    {
      v5 = __first[--v4];
      stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        __first,
        v4,
        v3,
        v5,
        __comp);
    }
  }
}
