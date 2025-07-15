void __usercall vostok::fs_new::set_extension_for_path<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::virtual_path_string *in_out_result@<eax>)
{
  char *m_end; // ecx
  char *m_begin; // eax
  char *v4; // ecx
  unsigned int v5; // ecx
  char *v6; // edi
  char *v7; // edx
  unsigned int v8; // edx
  unsigned int v9; // eax
  char *v10; // ecx
  bool v11; // [esp+Fh] [ebp-1h] BYREF

  m_end = in_out_result->m_string.m_end;
  m_begin = in_out_result->m_string.m_begin;
  v4 = m_end - 1;
  if ( v4 >= m_begin )
  {
    while ( *v4 != 46 )
    {
      if ( v4 == m_begin )
        goto LABEL_2;
      --v4;
    }
    v5 = v4 - m_begin;
  }
  else
  {
LABEL_2:
    v5 = -1;
  }
  v6 = in_out_result->m_string.m_end;
  v7 = v6 - 1;
  if ( v6 - 1 >= m_begin )
  {
    while ( *v7 != 47 )
    {
      if ( v7 == m_begin )
        goto LABEL_4;
      --v7;
    }
    v8 = v7 - m_begin;
  }
  else
  {
LABEL_4:
    v8 = -1;
  }
  if ( v5 != -1 && (v8 == -1 || v5 >= v8) )
  {
    v10 = &m_begin[v5 + 1];
    in_out_result->m_string.m_end = v10;
    *v10 = 0;
    vostok::buffer_string::append((vostok::buffer_string *)v10, (int)in_out_result, "dds");
  }
  else if ( `vostok::fs_new::set_extension_for_path<vostok::fs_new::virtual_path_string>'::`8'::debug_macro_helper_ignore_always
         || v6 != m_begin )
  {
    vostok::buffer_string::appendf(in_out_result, (vostok::buffer_string *)v5, (vostok::buffer_string *)".%s", "dds");
  }
  else
  {
    v9 = `vostok::fs_new::set_extension_for_path<vostok::fs_new::virtual_path_string>'::`11'::occurances_left;
    if ( `vostok::fs_new::set_extension_for_path<vostok::fs_new::virtual_path_string>'::`11'::occurances_left == -1 )
      v9 = 10;
    `vostok::fs_new::set_extension_for_path<vostok::fs_new::virtual_path_string>'::`11'::occurances_left = v9 - 1;
    if ( v9 )
    {
      v11 = 0;
      vostok::debug::on_error(
        &v11,
        process_error_false,
        (bool *)"in_out_result->length()",
        "c:\\survarium.deploy\\sources\\vostok/fs/path_string_utils_inline.h",
        "vostok::fs_new::set_extension_for_path",
        (const char *)0xF9);
      if ( vostok::debug::is_debugger_present() || v11 )
        __debugbreak();
    }
  }
}
