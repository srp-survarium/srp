void __thiscall vostok::fs_new::set_extension_for_path<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::virtual_path_string *in_out_result)
{
  char *m_begin; // esi
  char *v2; // eax
  unsigned int v3; // eax
  char *m_end; // edi
  char *v5; // edx
  unsigned int v6; // edx
  unsigned int v7; // eax
  char *v8; // eax
  bool do_debug_break; // [esp+Bh] [ebp-5h] BYREF
  const char *extensiona; // [esp+Ch] [ebp-4h] BYREF

  m_begin = in_out_result->m_string.m_begin;
  v2 = in_out_result->m_string.m_end - 1;
  extensiona = "dds";
  if ( v2 >= m_begin )
  {
    if ( *v2 == 46 )
    {
LABEL_5:
      v3 = v2 - m_begin;
      goto LABEL_7;
    }
    while ( v2 != m_begin )
    {
      if ( *--v2 == 46 )
        goto LABEL_5;
    }
  }
  v3 = -1;
LABEL_7:
  m_end = in_out_result->m_string.m_end;
  v5 = m_end - 1;
  if ( m_end - 1 < m_begin )
  {
LABEL_12:
    v6 = -1;
    goto LABEL_13;
  }
  if ( *v5 != 47 )
  {
    while ( v5 != m_begin )
    {
      if ( *--v5 == 47 )
        goto LABEL_11;
    }
    goto LABEL_12;
  }
LABEL_11:
  v6 = v5 - m_begin;
LABEL_13:
  if ( v3 != -1 && (v6 == -1 || v3 >= v6) )
  {
    v8 = &m_begin[v3 + 1];
    in_out_result->m_string.m_end = v8;
    *v8 = 0;
    vostok::fs_new::path_string_impl::append<char const *>(in_out_result, (char **)&extensiona);
  }
  else if ( `vostok::fs_new::set_extension_for_path<vostok::fs_new::virtual_path_string>'::`8'::debug_macro_helper_ignore_always
         || m_end != m_begin )
  {
    vostok::fs_new::path_string_impl::appendf(in_out_result, ".%s", "dds");
  }
  else
  {
    v7 = `vostok::fs_new::set_extension_for_path<vostok::fs_new::virtual_path_string>'::`11'::occurances_left;
    if ( `vostok::fs_new::set_extension_for_path<vostok::fs_new::virtual_path_string>'::`11'::occurances_left == -1 )
      v7 = 10;
    `vostok::fs_new::set_extension_for_path<vostok::fs_new::virtual_path_string>'::`11'::occurances_left = v7 - 1;
    if ( v7 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_false,
        &`vostok::fs_new::set_extension_for_path<vostok::fs_new::virtual_path_string>'::`8'::debug_macro_helper_ignore_always,
        assert_untyped,
        "assertion_failed",
        "in_out_result->length()",
        "C:\\survarium\\sources\\vostok/fs/path_string_utils_inline.h",
        "vostok::fs_new::set_extension_for_path",
        0xF9u);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
  }
}
