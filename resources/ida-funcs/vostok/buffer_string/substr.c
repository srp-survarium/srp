void __fastcall vostok::buffer_string::substr(
        vostok::buffer_string *out_dest,
        char *count,
        vostok::buffer_string *this,
        unsigned int pos)
{
  char *m_begin; // eax
  char *v5; // edi
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // esi

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
  v9 = &v5[pos + (_DWORD)count];
  if ( &v5[pos] == v9 )
  {
    *out_dest->m_end = 0;
  }
  else
  {
    do
      *out_dest->m_end++ = *v8++;
    while ( v8 != v9 );
    *out_dest->m_end = 0;
  }
}
