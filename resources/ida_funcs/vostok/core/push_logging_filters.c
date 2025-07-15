char vostok::core::push_logging_filters()
{
  vostok::logging::verbosity v0; // esi
  vostok::command_line::key *v1; // ecx
  char *m_buffer; // eax
  const char *v3; // ecx
  bool v4; // zf
  char result; // al
  int v6; // edi
  vostok::fs_new::native_path_string v7; // [esp-114h] [ebp-558h] BYREF
  vostok::fs_new::path_string_impl v8; // [esp+8h] [ebp-43Ch] BYREF
  vostok::fs_new::native_path_string cfg_file_path; // [esp+11Ch] [ebp-328h] BYREF
  vostok::fixed_string<512> verbosity_string; // [esp+234h] [ebp-210h] BYREF
  char v11; // [esp+440h] [ebp-4h] BYREF

  verbosity_string.m_begin = verbosity_string.m_buffer;
  verbosity_string.m_end = verbosity_string.m_buffer;
  v0 = warning;
  verbosity_string.m_max_end = &v11;
  verbosity_string.m_buffer[0] = 0;
  if ( vostok::command_line::key::is_set_as_string(&s_log_verbosity, &verbosity_string) )
  {
    v0 = vostok::logging::string_to_verbosity(verbosity_string.m_begin);
  }
  else if ( vostok::testing::run_tests_command_line(v1) )
  {
    vostok::debug::is_debugger_present();
  }
  vostok::logging::push_filter(vostok::core::g_log_filter_tree, (vostok::fixed_string<16> *)&buf, v0, 0xFFFFFFFF);
  cfg_file_path.m_string.m_end = cfg_file_path.m_string.m_buffer;
  cfg_file_path.m_string.m_begin = cfg_file_path.m_string.m_buffer;
  v8.m_string.m_max_end = &v8.m_separator;
  m_buffer = v8.m_string.m_buffer;
  cfg_file_path.m_string.m_max_end = &cfg_file_path.m_separator;
  cfg_file_path.m_string.m_buffer[0] = 0;
  cfg_file_path.m_separator = 92;
  v8.m_string.m_begin = v8.m_string.m_buffer;
  v8.m_separator = 92;
  v8.m_string.m_end = v8.m_string.m_buffer;
  v8.m_string.m_buffer[0] = 0;
  v3 = "../../user_data/user.cfg";
  do
  {
    if ( m_buffer >= v8.m_string.m_max_end )
      break;
    *m_buffer = *v3;
    m_buffer = v8.m_string.m_end + 1;
    v4 = *++v3 == 0;
    ++v8.m_string.m_end;
  }
  while ( !v4 );
  *m_buffer = 0;
  vostok::fs_new::path_string_impl::convert(&v8, v8.m_string.m_begin, v8.m_string.m_end);
  result = vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>(
             (vostok::fixed_string<32> *)&cfg_file_path,
             (vostok::fs_new::native_path_string *)&v8,
             assert_on_fail_false);
  if ( result )
  {
    v7.m_string.m_max_end = &v7.m_separator;
    v6 = cfg_file_path.m_string.m_end - cfg_file_path.m_string.m_begin;
    v7.m_string.m_begin = v7.m_string.m_buffer;
    memcpy(
      (unsigned __int8 *)v7.m_string.m_buffer,
      (unsigned __int8 *)cfg_file_path.m_string.m_begin,
      cfg_file_path.m_string.m_end - cfg_file_path.m_string.m_begin);
    v7.m_string.m_end = &v7.m_string.m_buffer[v6];
    *v7.m_string.m_end = 0;
    v7.m_separator = 92;
    return vostok::console_commands::execute_console_commands(v7);
  }
  return result;
}
