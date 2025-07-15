char *__usercall vostok::fs_new::file_name_from_path<vostok::fs_new::native_path_string>@<eax>(
        const vostok::fs_new::native_path_string *path@<eax>)
{
  char *m_end; // ecx
  char *result; // eax
  const char *v3; // ecx
  int v4; // ecx

  m_end = path->m_string.m_end;
  result = path->m_string.m_begin;
  v3 = m_end - 1;
  if ( v3 >= result )
  {
    while ( 1 )
    {
      if ( *v3 == 92 )
      {
        v4 = v3 - result;
        goto LABEL_8;
      }
      if ( v3 == result )
        break;
      --v3;
    }
    v4 = -1;
LABEL_8:
    if ( v4 != -1 )
      result += v4 + 1;
  }
  return result;
}


char *__usercall vostok::fs_new::file_name_from_path<vostok::fs_new::virtual_path_string>@<eax>(
        const vostok::fs_new::virtual_path_string *path@<eax>)
{
  char *m_end; // ecx
  char *result; // eax
  const char *v3; // ecx
  int v4; // ecx

  m_end = path->m_string.m_end;
  result = path->m_string.m_begin;
  v3 = m_end - 1;
  if ( v3 >= result )
  {
    while ( 1 )
    {
      if ( *v3 == 47 )
      {
        v4 = v3 - result;
        goto LABEL_8;
      }
      if ( v3 == result )
        break;
      --v3;
    }
    v4 = -1;
LABEL_8:
    if ( v4 != -1 )
      result += v4 + 1;
  }
  return result;
}
