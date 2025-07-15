char __usercall vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>@<al>(
        const vostok::fs_new::native_path_string *relative_path@<edi>,
        char *a2@<esi>,
        vostok::fs_new::native_path_string *out_result,
        assert_on_fail_bool assert_on_fail)
{
  char *i; // eax
  vostok::fs_new::native_path_string *current_directory; // eax
  char *m_begin; // [esp-4h] [ebp-124h]
  vostok::fixed_string<260> v8; // [esp+8h] [ebp-118h] BYREF
  char v9; // [esp+118h] [ebp-8h]
  bool do_debug_break; // [esp+11Ch] [ebp-4h] BYREF

  for ( i = relative_path->m_string.m_begin; i != relative_path->m_string.m_end; ++i )
  {
    if ( *i == 58 )
    {
      vostok::fixed_string<260>::fixed_string<260>(&v8, &relative_path->m_string);
      v9 = 92;
      if ( out_result != (vostok::fs_new::native_path_string *)&v8 )
        vostok::buffer_string::operator=(&v8, &out_result->m_string);
      return 1;
    }
    if ( *i == 92 )
      break;
  }
  current_directory = (vostok::fs_new::native_path_string *)vostok::fs_new::get_current_directory(a2);
  vostok::fixed_string<260>::operator=(&current_directory->m_string, &out_result->m_string);
  if ( vostok::fs_new::append_relative_path<vostok::fs_new::native_path_string,vostok::fs_new::native_path_string>(
         out_result,
         relative_path) )
  {
    return 1;
  }
  if ( assert_on_fail )
  {
    if ( !`vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>'::`17'::debug_macro_helper_ignore_always )
    {
      m_begin = relative_path->m_string.m_begin;
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_true,
        0,
        "assertion_failed",
        "fatal error",
        "c:\\survarium.deploy\\sources\\vostok/fs/path_string_utils_inline.h",
        "vostok::fs_new::convert_to_absolute_path",
        (const char *)0x60,
        "cannot convert to absolute path: %s",
        m_begin);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
  }
  return 0;
}
