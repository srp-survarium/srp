vostok::core_test_suite *__cdecl vostok::testing::suite_base<vostok::core_test_suite>::singleton()
{
  vostok::core_test_suite *result; // eax

  result = vostok::testing::suite_base<vostok::core_test_suite>::s_suite;
  if ( !vostok::testing::suite_base<vostok::core_test_suite>::s_suite )
  {
    if ( _InterlockedExchange(
           (volatile __int32 *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag,
           1) )
    {
      result = vostok::testing::suite_base<vostok::core_test_suite>::s_suite;
      while ( !vostok::testing::suite_base<vostok::core_test_suite>::s_suite )
        ;
    }
    else
    {
      vostok::core_test_suite::core_test_suite(&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag);
      _InterlockedExchange(
        (volatile __int32 *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite,
        (__int32)vostok::testing::suite_base<vostok::core_test_suite>::memory_helper::s_buffer);
      return vostok::testing::suite_base<vostok::core_test_suite>::s_suite;
    }
  }
  return result;
}
