void __usercall stlp_std::_Copy_Construct<stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *>>(
        stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *__p@<esi>,
        const stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *__val)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // edi

  if ( __p )
  {
    m_begin = (unsigned __int8 *)__val->first.m_begin;
    v3 = __val->first.m_end - __val->first.m_begin;
    __p->first.m_max_end = (char *)&__p->second;
    v4 = v3;
    __p->first.m_begin = __p->first.m_buffer;
    __p->first.m_end = __p->first.m_buffer;
    memcpy((unsigned __int8 *)__p->first.m_buffer, m_begin, v3);
    __p->first.m_end += v4;
    *__p->first.m_end = 0;
    __p->second = __val->second;
  }
}
