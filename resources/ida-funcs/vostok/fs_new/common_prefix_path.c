void __usercall vostok::fs_new::common_prefix_path<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::virtual_path_string *out_common_path@<eax>,
        const vostok::fs_new::virtual_path_string *first_path,
        const vostok::fs_new::virtual_path_string *second_path)
{
  char *m_begin; // ecx
  int v5; // edx
  char *v6; // edi
  char v7; // al
  char *v8; // eax
  char *m_end; // edi
  char *v10; // ecx
  int v11; // eax
  char v12; // dl
  char v13; // al
  char *v14; // eax
  int v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax

  m_begin = first_path->m_string.m_begin;
  v5 = 0;
  if ( *first_path->m_string.m_begin )
  {
    v6 = first_path->m_string.m_begin;
    do
    {
      v7 = v6[second_path->m_string.m_begin - m_begin];
      if ( !v7 )
        break;
      if ( *v6 != v7 )
        break;
      ++v5;
      ++v6;
    }
    while ( *v6 );
  }
  v8 = out_common_path->m_string.m_begin;
  out_common_path->m_string.m_end = out_common_path->m_string.m_begin;
  *v8 = 0;
  vostok::buffer_string::append(&out_common_path->m_string, &m_begin[v5], m_begin);
  m_end = out_common_path->m_string.m_end;
  v10 = out_common_path->m_string.m_begin;
  v11 = m_end - out_common_path->m_string.m_begin;
  v12 = first_path->m_string.m_begin[v11];
  if ( v12 && v12 != 47 || (v13 = second_path->m_string.m_begin[v11]) != 0 && v13 != 47 )
  {
    v14 = m_end - 1;
    if ( m_end - 1 < v10 )
      goto LABEL_18;
    while ( 1 )
    {
      if ( *v14 == 47 )
      {
        v15 = v14 - v10;
        goto LABEL_17;
      }
      if ( v14 == v10 )
        break;
      --v14;
    }
    v15 = -1;
LABEL_17:
    if ( v15 == -1 )
    {
LABEL_18:
      vostok::fs_new::path_string_impl::operator=<char const [1]>(
        (vostok::fs_new::path_string_impl *)v10,
        out_common_path);
    }
    else
    {
      v16 = &v10[v15];
      out_common_path->m_string.m_end = v16;
      *v16 = 0;
    }
  }
  v17 = out_common_path->m_string.m_end;
  if ( v17 != out_common_path->m_string.m_begin )
  {
    v18 = v17 - 1;
    if ( *v18 == 47 )
    {
      out_common_path->m_string.m_end = v18;
      *v18 = 0;
    }
  }
}
