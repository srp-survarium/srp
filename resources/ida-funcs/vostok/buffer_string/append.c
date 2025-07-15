vostok::buffer_string *__userpurge vostok::buffer_string::append@<eax>(
        vostok::buffer_string *this@<esi>,
        const char *end_src@<eax>,
        char *begin_src)
{
  int v3; // edi

  v3 = end_src - begin_src;
  memcpy((unsigned __int8 *)this->m_end, (unsigned __int8 *)begin_src, end_src - begin_src);
  this->m_end += v3;
  *this->m_end = 0;
  return this;
}


vostok::buffer_string *__userpurge vostok::buffer_string::append@<eax>(
        vostok::buffer_string *this@<ecx>,
        int a2@<esi>,
        char *c_string)
{
  unsigned int v3; // edi

  v3 = strlen(c_string);
  memcpy(*(unsigned __int8 **)(a2 + 4), (unsigned __int8 *)c_string, v3);
  *(_DWORD *)(a2 + 4) += v3;
  **(_BYTE **)(a2 + 4) = 0;
  return (vostok::buffer_string *)a2;
}
