void __usercall stlp_std::sort<unsigned int *,vostok::render::culling::portal_id_closer_to_point>(
        unsigned int *__first@<edi>,
        vostok::render::culling::portal_id_closer_to_point a2@<ebp>,
        unsigned int *__last,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  int v4; // eax
  int i; // ecx
  vostok::render::culling::portal_id_closer_to_point v6; // [esp-14h] [ebp-18h]

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,vostok::render::culling::portal_id_closer_to_point>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    if ( __last - __first <= 16 )
    {
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        __first,
        __last,
        (unsigned int *)__comp.m_distances,
        a2);
    }
    else
    {
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        __first,
        __first + 16,
        (unsigned int *)__comp.m_distances,
        a2);
      stlp_std::priv::__unguarded_insertion_sort_aux<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        __first + 16,
        __last,
        (unsigned int *)__comp.m_distances,
        v6);
    }
  }
}
