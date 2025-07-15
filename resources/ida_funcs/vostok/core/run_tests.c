void __thiscall vostok::core::run_tests(vostok::command_line::key *ecx0)
{
  const char *v1; // edi
  vostok::core_test_suite *v2; // esi
  char *m_begin; // eax
  vostok::fs_new::path_string_impl *p_m_resources_path; // esi

  vostok::testing::initialize(ecx0);
  vostok::debug::notify_xbox_debugger();
  v1 = s_engine_0->get_resources_path(s_engine_0);
  v2 = vostok::testing::suite_base<vostok::core_test_suite>::singleton();
  m_begin = v2->m_resources_path.m_string.m_begin;
  p_m_resources_path = &v2->m_resources_path;
  if ( m_begin != v1 )
  {
    p_m_resources_path->m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&p_m_resources_path->m_string, v1);
  }
  vostok::fs_new::path_string_impl::convert(
    p_m_resources_path,
    p_m_resources_path->m_string.m_begin,
    p_m_resources_path->m_string.m_end);
  vostok::testing::suite_base<vostok::core_test_suite>::run_tests();
}
