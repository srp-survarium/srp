bool __cdecl vostok::testing::suite_base<vostok::core_test_suite>::run_tests()
{
  vostok::core_test_suite *v0; // eax
  vostok::core_test_suite *v1; // esi
  vostok::testing::test_base *m_first; // ebx
  const char *v3; // eax

  v0 = vostok::testing::suite_base<vostok::core_test_suite>::singleton();
  v1 = v0;
  if ( v0->m_tests.m_first )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&v0->m_tests.vostok::threading::mutex_tasks_unaware);
    m_first = v1->m_tests.m_first;
    v1->m_tests.m_first = 0;
    v1->m_tests.m_last = 0;
    v1->m_tests.m_size = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&v1->m_tests.vostok::threading::mutex_tasks_unaware);
  }
  else
  {
    m_first = 0;
  }
  v3 = type_info::name(&vostok::core_test_suite `RTTI Type Descriptor', &__type_info_root_node);
  return vostok::testing::detail::run_tests_impl(m_first, v3);
}
