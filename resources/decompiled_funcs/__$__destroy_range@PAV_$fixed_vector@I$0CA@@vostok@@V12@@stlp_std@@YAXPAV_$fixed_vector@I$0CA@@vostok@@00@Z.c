void __cdecl stlp_std::__destroy_range<vostok::fixed_vector<unsigned int,32> *,vostok::fixed_vector<unsigned int,32>>(
        vostok::fixed_vector<unsigned int,32> *__first,
        vostok::fixed_vector<unsigned int,32> *__last)
{
  unsigned int *i; // [esp+4h] [ebp-8h]

  while ( __first != __last )
  {
    for ( i = __first->m_begin; i != __first->m_end; ++i )
      ;
    __first->m_end = __first->m_begin;
    ++__first;
  }
}
