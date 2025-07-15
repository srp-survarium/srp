char __usercall vostok::fs_new::append_relative_path<vostok::fs_new::native_path_string,vostok::fs_new::native_path_string>@<al>(
        vostok::fs_new::native_path_string *in_out_path@<esi>,
        const vostok::fs_new::native_path_string *in_relative_path)
{
  unsigned int v2; // kr00_4
  unsigned __int8 *m_begin; // edi
  char *v4; // ecx
  char *v5; // eax
  int v6; // eax
  char *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 str2[4]; // [esp+Ch] [ebp-4h] BYREF

  strcpy((char *)str2, "..\\");
  v2 = strlen((const char *)str2);
  m_begin = (unsigned __int8 *)in_relative_path->m_string.m_begin;
  in_relative_path = (const vostok::fs_new::native_path_string *)in_relative_path->m_string.m_begin;
  while ( 1 )
  {
    strstr(m_begin, str2);
    if ( v8 != m_begin )
      break;
    m_begin += v2;
    v4 = in_out_path->m_string.m_begin;
    v5 = in_out_path->m_string.m_end - 1;
    in_relative_path = (const vostok::fs_new::native_path_string *)m_begin;
    if ( v5 < v4 )
      goto LABEL_22;
    while ( 1 )
    {
      if ( *v5 == 92 )
      {
        v6 = v5 - v4;
        goto LABEL_9;
      }
      if ( v5 == v4 )
        break;
      --v5;
    }
    v6 = -1;
LABEL_9:
    if ( v6 == -1 )
    {
LABEL_22:
      if ( in_out_path->m_string.m_end == v4 )
        return 0;
      in_out_path->m_string.m_end = v4;
      *v4 = 0;
    }
    else
    {
      v7 = &v4[v6];
      in_out_path->m_string.m_end = v7;
      *v7 = 0;
    }
  }
  if ( *m_begin )
  {
    if ( in_out_path->m_string.m_end != in_out_path->m_string.m_begin )
    {
      *in_out_path->m_string.m_end++ = 92;
      *in_out_path->m_string.m_end = 0;
    }
    vostok::fs_new::path_string_impl::append_with_conversion<char const *>(in_out_path, (char **)&in_relative_path);
  }
  return 1;
}


char __usercall vostok::fs_new::append_relative_path<vostok::fs_new::virtual_path_string,char const *>@<al>(
        vostok::fs_new::virtual_path_string *in_out_path@<esi>,
        const char ****in_relative_path)
{
  unsigned int v2; // kr00_4
  const char ***v3; // edi
  char *m_begin; // ecx
  char *v5; // eax
  int v6; // eax
  char *v7; // eax
  const char ***v8; // eax
  unsigned __int8 str2[4]; // [esp+Ch] [ebp-4h] BYREF

  strcpy((char *)str2, "../");
  v2 = strlen((const char *)str2);
  v3 = *in_relative_path;
  in_relative_path = (const char ****)*in_relative_path;
  while ( 1 )
  {
    strstr((unsigned __int8 *)v3, str2);
    if ( v8 != v3 )
      break;
    v3 = (const char ***)((char *)v3 + v2);
    m_begin = in_out_path->m_string.m_begin;
    v5 = in_out_path->m_string.m_end - 1;
    in_relative_path = (const char ****)v3;
    if ( v5 < m_begin )
      goto LABEL_22;
    while ( 1 )
    {
      if ( *v5 == 47 )
      {
        v6 = v5 - m_begin;
        goto LABEL_9;
      }
      if ( v5 == m_begin )
        break;
      --v5;
    }
    v6 = -1;
LABEL_9:
    if ( v6 == -1 )
    {
LABEL_22:
      if ( in_out_path->m_string.m_end == m_begin )
        return 0;
      in_out_path->m_string.m_end = m_begin;
      *m_begin = 0;
    }
    else
    {
      v7 = &m_begin[v6];
      in_out_path->m_string.m_end = v7;
      *v7 = 0;
    }
  }
  if ( *(_BYTE *)v3 )
  {
    if ( in_out_path->m_string.m_end != in_out_path->m_string.m_begin )
    {
      *in_out_path->m_string.m_end++ = 47;
      *in_out_path->m_string.m_end = 0;
    }
    vostok::fs_new::path_string_impl::append_with_conversion<char const *>(in_out_path, (char **)&in_relative_path);
  }
  return 1;
}
