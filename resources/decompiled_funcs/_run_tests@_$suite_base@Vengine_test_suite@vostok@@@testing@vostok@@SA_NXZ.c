bool __cdecl vostok::testing::suite_base<vostok::engine_test_suite>::run_tests()
{
  vostok::engine_test_suite *v0; // ebp
  vostok::testing::test_base **p_m_first; // esi
  vostok::testing::test_base *v2; // ebx
  const char *v3; // eax
  volatile int *v5; // [esp+0h] [ebp-14h]
  vostok::bind_pointer_to_buffer_mt_safe_placement_new_predicate v6; // [esp+4h] [ebp-10h]
  vostok::engine_test_suite **pointer; // [esp+10h] [ebp-4h]

  v0 = vostok::testing::suite_base<vostok::engine_test_suite>::s_suite;
  if ( !vostok::testing::suite_base<vostok::engine_test_suite>::s_suite )
  {
    LOBYTE(pointer) = 0;
    vostok::bind_pointer_to_buffer_mt_safe<vostok::engine_test_suite,vostok::bind_pointer_to_buffer_mt_safe_placement_new_predicate>(
      pointer,
      (char (*)[48])vostok::testing::suite_base<vostok::engine_test_suite>::memory_helper::s_buffer,
      v5,
      v6);
    v0 = vostok::testing::suite_base<vostok::engine_test_suite>::s_suite;
  }
  p_m_first = &v0->m_tests.m_first;
  if ( v0->m_tests.m_first )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&v0->m_tests.vostok::threading::mutex_tasks_unaware);
    v2 = *p_m_first;
    *p_m_first = 0;
    v0->m_tests.m_last = 0;
    v0->m_tests.m_size = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&v0->m_tests.vostok::threading::mutex_tasks_unaware);
  }
  else
  {
    v2 = 0;
  }
  v3 = type_info::name(&vostok::engine_test_suite `RTTI Type Descriptor', &__type_info_root_node);
  return vostok::testing::detail::run_tests_impl(v2, v3);
}
