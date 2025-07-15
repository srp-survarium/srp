void __usercall vostok::fs_new::convert_to_relative_path<vostok::fs_new::virtual_path_string,vostok::fs_new::virtual_path_string>(
        const vostok::fs_new::virtual_path_string *root_to_relate@<eax>,
        vostok::fs_new::virtual_path_string *out_relative_path,
        const vostok::fs_new::virtual_path_string *absolute_path)
{
  char *m_begin; // ecx
  int v4; // edx
  int v5; // ebx
  char *v6; // ecx
  int v7; // edx
  vostok::fs_new::path_string_impl *v8; // edi
  const vostok::fs_new::virtual_path_string *v9; // esi
  char *v10; // ecx
  char v11; // al
  int v12; // edx
  vostok::fs_new::path_string_impl *v13; // ecx
  int v14; // eax
  vostok::fs_new::virtual_path_string out_common_path; // [esp+8h] [ebp-A8h] BYREF
  char *v16; // [esp+11Ch] [ebp+6Ch] BYREF

  m_begin = root_to_relate->m_string.m_begin;
  if ( root_to_relate->m_string.m_end == root_to_relate->m_string.m_begin )
  {
    v5 = 0;
  }
  else
  {
    v4 = 0;
    while ( *m_begin )
    {
      if ( *m_begin == 47 )
        ++v4;
      ++m_begin;
    }
    v5 = v4 + 1;
  }
  v6 = absolute_path->m_string.m_begin;
  if ( absolute_path->m_string.m_end == absolute_path->m_string.m_begin )
  {
    v8 = 0;
  }
  else
  {
    v7 = 0;
    while ( *v6 )
    {
      if ( *v6 == 47 )
        ++v7;
      ++v6;
    }
    v8 = (vostok::fs_new::path_string_impl *)(v7 + 1);
  }
  out_common_path.m_string.m_begin = out_common_path.m_string.m_buffer;
  out_common_path.m_string.m_end = out_common_path.m_string.m_buffer;
  v9 = absolute_path;
  out_common_path.m_string.m_max_end = &out_common_path.m_separator;
  out_common_path.m_string.m_buffer[0] = 0;
  out_common_path.m_separator = 47;
  vostok::fs_new::common_prefix_path<vostok::fs_new::virtual_path_string>(
    &out_common_path,
    absolute_path,
    root_to_relate);
  if ( out_common_path.m_string.m_end == out_common_path.m_string.m_begin )
  {
    v13 = 0;
  }
  else
  {
    v10 = out_common_path.m_string.m_begin;
    v11 = *out_common_path.m_string.m_begin;
    v12 = 0;
    while ( v11 )
    {
      if ( v11 == 47 )
        ++v12;
      v11 = *++v10;
    }
    v13 = (vostok::fs_new::path_string_impl *)(v12 + 1);
  }
  if ( v8 == v13 )
  {
    vostok::fs_new::path_string_impl::operator=<char const [1]>(v13, out_relative_path);
  }
  else
  {
    absolute_path = (const vostok::fs_new::virtual_path_string *)byte_2F2E2E;
    vostok::buffer_string::append_repeat(v5 - (_DWORD)v13, &out_relative_path->m_string, (char *)&absolute_path);
    if ( out_common_path.m_string.m_end == out_common_path.m_string.m_begin )
      v14 = 0;
    else
      v14 = out_common_path.m_string.m_end - out_common_path.m_string.m_begin + 1;
    v16 = &v9->m_string.m_begin[v14];
    vostok::fs_new::path_string_impl::append_with_conversion<char const *>(out_relative_path, &v16);
  }
}
