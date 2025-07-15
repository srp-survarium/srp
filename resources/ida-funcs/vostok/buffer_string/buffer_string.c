void __userpurge vostok::buffer_string::buffer_string(
        char *buffer@<eax>,
        const unsigned int *max_count@<ecx>,
        vostok::buffer_string *this,
        char **begin_src,
        const char **end_src)
{
  this->m_begin = buffer;
  this->m_end = buffer;
  this->m_max_end = &buffer[*max_count];
  vostok::buffer_string::append(this, *end_src, *begin_src);
}


void __userpurge vostok::buffer_string::buffer_string(
        vostok::buffer_string *this@<ecx>,
        vostok::buffer_string *a2@<eax>,
        char *buffer,
        char *max_count,
        const char *src)
{
  a2->m_begin = (char *)this;
  a2->m_end = (char *)this;
  a2->m_max_end = (char *)this + *(_DWORD *)buffer;
  LOBYTE(this->m_begin) = 0;
  vostok::buffer_string::operator+=(a2, max_count);
}
