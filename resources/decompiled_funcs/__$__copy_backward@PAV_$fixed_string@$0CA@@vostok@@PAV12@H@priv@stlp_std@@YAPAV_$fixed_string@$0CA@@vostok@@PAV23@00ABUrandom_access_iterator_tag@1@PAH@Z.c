vostok::fixed_string<32> *__usercall stlp_std::priv::__copy_backward<vostok::fixed_string<32> *,vostok::fixed_string<32> *,int>@<eax>(
        vostok::fixed_string<32> *__result@<eax>,
        vostok::fixed_string<32> *__first,
        vostok::fixed_string<32> *__last)
{
  vostok::fixed_string<32> *v3; // ebx
  int i; // ebp
  char *m_begin; // eax
  unsigned int v7; // edi

  v3 = __last;
  for ( i = __last - __first; i > 0; --i )
  {
    if ( --__result != --v3 )
    {
      m_begin = __result->m_begin;
      __result->m_end = __result->m_begin;
      *m_begin = 0;
      v7 = v3->m_end - v3->m_begin;
      memcpy((unsigned __int8 *)__result->m_end, (unsigned __int8 *)v3->m_begin, v7);
      __result->m_end += v7;
      *__result->m_end = 0;
    }
  }
  return __result;
}
