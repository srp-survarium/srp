void __cdecl vostok::command_line::key_is_set(const char *key_raw)
{
  const char *CommandLineA; // eax

  if ( !s_initialized_5 )
  {
    CommandLineA = GetCommandLineA();
    strcpy_s(
      (char *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[2] + 4,
      0x200u,
      CommandLineA);
    s_initialized_5 = 1;
  }
  vostok::command_line::key_is_set_impl(
    key_raw,
    (char *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[2] + 4);
}
