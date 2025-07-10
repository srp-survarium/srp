char __usercall vostok::fs_new::append_relative_path<vostok::fs_new::native_path_string,vostok::fs_new::native_path_string>@<al>(
        vostok::fs_new::native_path_string *in_out_path@<eax>,
        vostok::fs_new::native_path_string *in_relative_path)
{
  unsigned int v3; // kr00_4
  vostok::fs_new::native_path_string *v4; // edi
  vostok::fs_new::native_path_string *v5; // eax
  unsigned int v6; // eax
  char *m_begin; // eax
  vostok::fs_new::native_path_string *v9; // eax
  char up_token[4]; // [esp+Ch] [ebp-4h] BYREF

  strcpy(up_token, "..\\");
  v3 = strlen(up_token);
  in_relative_path = (vostok::fs_new::native_path_string *)in_relative_path->m_string.m_begin;
  v4 = in_relative_path;
  strstr((unsigned __int8 *)in_relative_path, (unsigned __int8 *)up_token);
  if ( v5 == v4 )
  {
    do
    {
      v4 = (vostok::fs_new::native_path_string *)((char *)v4 + v3);
      v6 = vostok::fs_new::path_string_impl::rfind(in_out_path, 92);
      if ( v6 == -1 )
      {
        m_begin = in_out_path->m_string.m_begin;
        if ( in_out_path->m_string.m_end == in_out_path->m_string.m_begin )
        {
          in_relative_path = v4;
          return 0;
        }
      }
      else
      {
        m_begin = &in_out_path->m_string.m_begin[v6];
      }
      in_out_path->m_string.m_end = m_begin;
      *m_begin = 0;
      strstr((unsigned __int8 *)v4, (unsigned __int8 *)up_token);
    }
    while ( v9 == v4 );
    in_relative_path = v4;
  }
  if ( LOBYTE(v4->m_string.m_begin) )
  {
    if ( in_out_path->m_string.m_end != in_out_path->m_string.m_begin )
    {
      *in_out_path->m_string.m_end++ = 92;
      *in_out_path->m_string.m_end = 0;
    }
    vostok::fs_new::path_string_impl::append_with_conversion<char const *>(
      in_out_path,
      (const char **)&in_relative_path);
  }
  return 1;
}
