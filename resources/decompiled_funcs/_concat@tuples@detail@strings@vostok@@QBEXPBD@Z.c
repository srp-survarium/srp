void __userpurge vostok::strings::detail::tuples::concat(char *result@<eax>, vostok::strings::detail::tuples *this)
{
  unsigned int v3; // ebp
  unsigned __int8 *v4; // esi
  unsigned int *p_second; // edi

  memcpy((unsigned __int8 *)result, (unsigned __int8 *)this->m_strings[0].first, this->m_strings[0].second);
  v3 = 1;
  v4 = (unsigned __int8 *)&result[this->m_strings[0].second];
  if ( this->m_count > 1 )
  {
    p_second = &this->m_strings[1].second;
    do
    {
      memcpy(v4, (unsigned __int8 *)*(p_second - 1), *p_second);
      v4 += *p_second;
      ++v3;
      p_second += 2;
    }
    while ( v3 < this->m_count );
  }
  *v4 = 0;
}
