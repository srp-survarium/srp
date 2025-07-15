void __userpurge vostok::buffer_string::substr(
        unsigned int pos@<edi>,
        char *count@<eax>,
        vostok::buffer_string *out_dest@<ecx>,
        vostok::buffer_string *this)
{
  char *m_begin; // edx
  char *v5; // edx
  char *v6; // esi
  char *v7; // esi
  char *v8; // edx
  char *i; // esi
  char v10; // bl

  m_begin = out_dest->m_begin;
  out_dest->m_end = out_dest->m_begin;
  *m_begin = 0;
  v5 = this->m_begin;
  if ( count == (char *)-1 )
  {
    count = (char *)(this->m_end - v5 - pos);
  }
  else
  {
    v6 = (char *)(this->m_end - v5);
    if ( (unsigned int)v6 <= pos )
      v7 = 0;
    else
      v7 = &v6[-pos];
    if ( count > v7 )
      count = v7;
    if ( count > (char *)(out_dest->m_max_end - out_dest->m_begin) )
      count = (char *)(out_dest->m_max_end - out_dest->m_begin);
  }
  v8 = &v5[pos];
  for ( i = &count[(_DWORD)v8]; v8 != i; ++out_dest->m_end )
  {
    v10 = *v8++;
    *out_dest->m_end = v10;
  }
  *out_dest->m_end = 0;
}
