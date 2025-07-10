void __usercall stlp_std::priv::__fill<vostok::fixed_string<32> *,vostok::fixed_string<32>,int>(
        vostok::fixed_string<32> *__first@<ecx>,
        vostok::fixed_string<32> *__last@<eax>,
        const vostok::fixed_string<32> *__val)
{
  vostok::fixed_string<32> *v3; // esi
  int i; // ebx
  char *m_begin; // eax
  unsigned int v6; // edi

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    if ( v3 != __val )
    {
      m_begin = v3->m_begin;
      v3->m_end = v3->m_begin;
      *m_begin = 0;
      v6 = __val->m_end - __val->m_begin;
      memcpy((unsigned __int8 *)v3->m_end, (unsigned __int8 *)__val->m_begin, v6);
      v3->m_end += v6;
      *v3->m_end = 0;
    }
    --i;
  }
}
