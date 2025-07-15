vostok::core_test_suite *vostok::testing::suite_base<vostok::core_test_suite>::singleton()
{
  if ( !vostok::testing::suite_base<vostok::core_test_suite>::s_suite )
    vostok::bind_pointer_to_buffer_mt_safe<vostok::core_test_suite,vostok::bind_pointer_to_buffer_mt_safe_placement_new_predicate>((char (*)[328])vostok::testing::suite_base<vostok::core_test_suite>::memory_helper::s_buffer);
  return vostok::testing::suite_base<vostok::core_test_suite>::s_suite;
}
