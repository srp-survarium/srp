char __thiscall vostok::core::push_logging_filters(vostok::command_line::key *this)
{
  vostok::logging::verbosity v1; // esi
  vostok::command_line::key *v2; // ecx
  vostok::logging::verbosity v3; // eax
  vostok::logging::filter_tree *v4; // ecx
  const vostok::fs_new::native_path_string *v5; // eax
  char v6; // al
  vostok::fs_new::native_path_string v7; // [esp-114h] [ebp-55Ch] BYREF
  unsigned int v8; // [esp+0h] [ebp-448h]
  vostok::fs_new::native_path_string result; // [esp+Ch] [ebp-43Ch] BYREF
  vostok::fs_new::native_path_string v10; // [esp+120h] [ebp-328h] BYREF
  vostok::buffer_string in_verbosity; // [esp+238h] [ebp-210h] BYREF
  _BYTE v12[512]; // [esp+244h] [ebp-204h] BYREF
  char v13; // [esp+444h] [ebp-4h] BYREF

  in_verbosity.m_begin = v12;
  in_verbosity.m_end = v12;
  in_verbosity.m_max_end = &v13;
  v1 = info;
  v12[0] = 0;
  if ( vostok::command_line::key::is_set_as_string(this, &s_log_verbosity.m_string_value, &in_verbosity) )
  {
    v3 = vostok::logging::string_to_verbosity(in_verbosity.m_begin);
    v4 = *(vostok::logging::filter_tree **)&v7.m_separator;
    v1 = v3;
  }
  else if ( vostok::testing::run_tests_command_line(v2) && !vostok::debug::is_debugger_present() )
  {
    v1 = warning;
  }
  vostok::logging::filter_tree::push_filter(v4, (int)vostok::core::g_log_filter_tree, (char *)uri, v1, v8);
  vostok::fs_new::native_path_string::native_path_string(&v10);
  v5 = vostok::fs_new::native_path_string::convert(&result, "../../user_data/user.cfg");
  v6 = vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>(
         v5,
         (char *)v1,
         &v10,
         assert_on_fail_false);
  if ( v6 )
  {
    vostok::fixed_string<260>::fixed_string<260>(&v7.m_string, &v10.m_string);
    v7.m_separator = 92;
    return vostok::console_commands::execute_console_commands(v7);
  }
  return v6;
}
