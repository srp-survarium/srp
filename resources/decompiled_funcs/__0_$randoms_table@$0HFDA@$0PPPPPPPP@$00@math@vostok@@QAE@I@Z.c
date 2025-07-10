void __thiscall vostok::math::randoms_table<30000,4294967295,1>::randoms_table<30000,4294967295,1>(
        vostok::math::randoms_table<30000,4294967295,1> *this)
{
  int v1; // esi
  int v2; // edi
  unsigned int *m_end; // eax

  this->m_randoms.m_begin = (unsigned int *)this->m_randoms.m_buffer;
  this->m_randoms.m_end = (unsigned int *)this->m_randoms.m_buffer;
  v1 = 0;
  v2 = 30000;
  do
  {
    v1 = 134775813 * v1 + 1;
    m_end = this->m_randoms.m_end;
    if ( m_end )
      *m_end = (0xFFFFFFFF * (unsigned __int64)(unsigned int)v1) >> 32;
    ++this->m_randoms.m_end;
    --v2;
  }
  while ( v2 );
  this->m_index = 0;
}
