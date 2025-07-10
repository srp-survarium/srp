vostok::buffer_string *__userpurge vostok::buffer_string::assign_replace@<eax>(
        vostok::buffer_string *this@<ecx>,
        vostok::buffer_string *a2@<eax>,
        const char *source,
        const char *what,
        const char *with)
{
  char *m_begin; // eax
  vostok::buffer_string *v7; // ecx

  m_begin = a2->m_begin;
  a2->m_end = m_begin;
  *m_begin = 0;
  vostok::buffer_string::operator+=(a2, source);
  vostok::buffer_string::replace(v7, a2, "resources/", "resources.sources/");
  return a2;
}
