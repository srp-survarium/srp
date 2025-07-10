void __usercall vostok::core::generate_log_file_name(vostok::fs_new::virtual_path_string *out_result@<esi>)
{
  vostok::fs_new::path_string_impl *v1; // eax
  char *m_buffer; // ecx
  char *v3; // eax
  char *v4; // ecx
  bool v5; // zf
  char *s; // [esp+0h] [ebp-22Ch] BYREF
  vostok::fs_new::path_string_impl v7; // [esp+4h] [ebp-228h] BYREF
  vostok::fs_new::native_path_string user_name; // [esp+118h] [ebp-114h] BYREF

  v1 = (vostok::fs_new::path_string_impl *)s_engine_0->get_user_data_directory(s_engine_0);
  m_buffer = v7.m_string.m_buffer;
  v7.m_string.m_max_end = &v7.m_separator;
  v7.m_string.m_begin = v7.m_string.m_buffer;
  v7.m_string.m_end = v7.m_string.m_buffer;
  v7.m_string.m_buffer[0] = 0;
  v7.m_separator = 92;
  if ( v7.m_string.m_buffer != (char *)v1 )
  {
    v7.m_string.m_end = v7.m_string.m_buffer;
    v7.m_string.m_buffer[0] = 0;
    if ( v1 )
    {
      for ( ; LOBYTE(v1->m_string.m_begin); ++v7.m_string.m_end )
      {
        if ( m_buffer >= v7.m_string.m_max_end )
          break;
        *m_buffer = (char)v1->m_string.m_begin;
        m_buffer = v7.m_string.m_end + 1;
        v1 = (vostok::fs_new::path_string_impl *)((char *)v1 + 1);
      }
      *m_buffer = 0;
      m_buffer = v7.m_string.m_end;
    }
  }
  vostok::fs_new::path_string_impl::convert(&v7, v7.m_string.m_begin, m_buffer);
  vostok::fs_new::virtual_path_string::operator=(out_result, (vostok::fs_new::virtual_path_string *)&v7);
  s = (char *)vostok::core::application_name();
  vostok::fs_new::path_string_impl::append_path<char const *>(out_result, &s);
  if ( !s_initialized_6 )
  {
    s = (char *)512;
    GetUserNameA(s_user, (LPDWORD)&s);
    s_initialized_6 = 1;
  }
  v3 = user_name.m_string.m_buffer;
  user_name.m_string.m_begin = user_name.m_string.m_buffer;
  user_name.m_string.m_end = user_name.m_string.m_buffer;
  user_name.m_string.m_max_end = &user_name.m_separator;
  user_name.m_string.m_buffer[0] = 0;
  v4 = s_user;
  if ( s_user[0] )
  {
    do
    {
      if ( v3 >= user_name.m_string.m_max_end )
        break;
      *v3 = *v4;
      v3 = user_name.m_string.m_end + 1;
      v5 = *++v4 == 0;
      ++user_name.m_string.m_end;
    }
    while ( !v5 );
  }
  *v3 = 0;
  user_name.m_separator = 92;
  if ( user_name.m_string.m_end != user_name.m_string.m_begin )
    vostok::fs_new::path_string_impl::appendf(out_result, "_%s", user_name.m_string.m_begin);
  vostok::fs_new::path_string_impl::appendf(out_result, ".%s", "log");
}
