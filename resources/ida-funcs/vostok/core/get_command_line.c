const char *__cdecl vostok::core::get_command_line()
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
  return (char *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[2] + 4;
}
