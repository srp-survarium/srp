void __usercall vostok::render::change_substring(char *what@<eax>, vostok::fs_new::virtual_path_string *src_and_dest)
{
  int v3; // eax
  char *v4; // ecx
  int v5; // esi
  unsigned int v6; // edi
  char *i; // eax
  char *m_end; // ecx
  char *j; // eax
  unsigned __int8 *m_begin; // [esp-8h] [ebp-128h]
  const char *toa; // [esp+8h] [ebp-118h] BYREF
  vostok::fs_new::virtual_path_string result; // [esp+Ch] [ebp-114h] BYREF

  result.m_string.m_begin = result.m_string.m_buffer;
  m_begin = (unsigned __int8 *)src_and_dest->m_string.m_begin;
  toa = (const char *)&buf;
  result.m_string.m_end = result.m_string.m_buffer;
  result.m_string.m_max_end = &result.m_separator;
  result.m_string.m_buffer[0] = 0;
  result.m_separator = 47;
  strstr(m_begin, (unsigned __int8 *)what);
  if ( v3 )
  {
    v4 = src_and_dest->m_string.m_begin;
    v5 = v3 - (unsigned int)src_and_dest->m_string.m_begin;
    if ( v5 != -1 )
    {
      v6 = strlen(what);
      result.m_string.m_end = result.m_string.m_begin;
      *result.m_string.m_begin = 0;
      for ( i = v4; i != &v4[v5]; ++i )
        *result.m_string.m_end++ = *i;
      *result.m_string.m_end = 0;
      vostok::fs_new::path_string_impl::append<char const *>(&result, (char **)&toa);
      m_end = src_and_dest->m_string.m_end;
      for ( j = &src_and_dest->m_string.m_begin[v6 + v5]; j != m_end; ++j )
        *result.m_string.m_end++ = *j;
      *result.m_string.m_end = 0;
      vostok::fs_new::virtual_path_string::operator=(src_and_dest, &result);
    }
  }
}
