unsigned int *__usercall stlp_std::priv::__unguarded_partition<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>@<eax>(
        unsigned int *__first@<eax>,
        unsigned int *__last@<ecx>,
        unsigned int __pivot@<edi>,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  float v4; // xmm0_4
  int v5; // edx
  unsigned int v6; // edx

  while ( 1 )
  {
    v4 = *(float *)((_DWORD)__comp.m_distances + 4 * __pivot);
    while ( v4 > *(float *)((_DWORD)__comp.m_distances + 4 * *__first) )
      ++__first;
    do
      v5 = *--__last;
    while ( *(float *)((_DWORD)__comp.m_distances + 4 * v5) > v4 );
    if ( __first >= __last )
      break;
    v6 = *__first;
    *__first = *__last;
    *__last = v6;
    ++__first;
  }
  return __first;
}
