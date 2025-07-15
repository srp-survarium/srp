const vostok::fs_new::virtual_path_string *__usercall vostok::fs_new::virtual_path_string::operator=<char const *>@<eax>(
        vostok::fs_new::virtual_path_string *this@<esi>,
        const char **s@<eax>)
{
  const char *v2; // ecx
  char *m_begin; // eax

  v2 = *s;
  m_begin = this->m_string.m_begin;
  if ( this->m_string.m_begin != v2 )
  {
    this->m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&this->m_string, v2);
  }
  return this;
}


const vostok::fs_new::virtual_path_string *__usercall vostok::fs_new::virtual_path_string::operator+=<char const [5]>@<eax>(
        vostok::fs_new::virtual_path_string *this@<ecx>,
        int a2@<esi>)
{
  unsigned int v2; // edi

  v2 = strlen(".dds");
  memcpy(*(unsigned __int8 **)(a2 + 4), ".dds", v2);
  *(_DWORD *)(a2 + 4) += v2;
  **(_BYTE **)(a2 + 4) = 0;
  return (const vostok::fs_new::virtual_path_string *)a2;
}


const vostok::fs_new::virtual_path_string *__thiscall vostok::fs_new::virtual_path_string::operator=(
        vostok::fs_new::virtual_path_string *this,
        vostok::fs_new::virtual_path_string *s)
{
  if ( this != s )
    vostok::buffer_string::operator=((vostok::fixed_string<32> *)s, (vostok::fixed_string<32> *)this);
  vostok::fs_new::path_string_impl::verify_self(this);
  return this;
}
