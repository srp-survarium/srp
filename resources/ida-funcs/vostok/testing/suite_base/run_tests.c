bool __cdecl vostok::testing::suite_base<vostok::engine_test_suite>::run_tests()
{
  vostok::engine_test_suite *v0; // esi
  vostok::intrusive_list<vostok::testing::test_base,vostok::testing::test_base *,4,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy> *v1; // ecx
  vostok::testing::test_base *v2; // eax
  vostok::command_line::key *v3; // ecx
  const char *v5; // [esp-4h] [ebp-14h]

  if ( !vostok::testing::suite_base<vostok::engine_test_suite>::s_suite )
    vostok::bind_pointer_to_buffer_mt_safe<vostok::engine_test_suite,vostok::bind_pointer_to_buffer_mt_safe_placement_new_predicate>((char (*)[48])vostok::testing::suite_base<vostok::engine_test_suite>::memory_helper::s_buffer);
  v0 = vostok::testing::suite_base<vostok::engine_test_suite>::s_suite;
  v5 = type_info::name(&vostok::engine_test_suite `RTTI Type Descriptor', &__type_info_root_node);
  v2 = vostok::intrusive_list<vostok::testing::test_base,vostok::testing::test_base *,4,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
         v1,
         (int)v0);
  return vostok::testing::detail::run_tests_impl(v2, v3, v5);
}
