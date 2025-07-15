vostok::fixed_string<512> *__usercall vostok::resources::memory_usage_type::log_string@<eax>(
        vostok::resources::memory_usage_type *this@<ecx>,
        vostok::buffer_string *a2@<eax>)
{
  char *v3; // eax
  const char *v5; // eax
  char *m_end; // ecx

  v3 = (char *)&a2[1];
  a2->m_begin = v3;
  a2->m_end = v3;
  a2->m_max_end = v3 + 512;
  *v3 = 0;
  *v3 = 0;
  vostok::buffer_string::appendf(a2, (vostok::buffer_string *)&stru_95B520, (const char *)this->size);
  if ( this->type )
    vostok::buffer_string::operator+=(a2, this->type->m_name);
  else
    vostok::buffer_string::operator+=(a2, (const char *)&stru_95B520.m_end);
  v5 = " bytes";
  do
  {
    m_end = a2->m_end;
    if ( m_end >= a2->m_max_end )
      break;
    *m_end = *v5;
    ++a2->m_end;
    ++v5;
  }
  while ( *v5 );
  *a2->m_end = 0;
  return (vostok::fixed_string<512> *)a2;
}
