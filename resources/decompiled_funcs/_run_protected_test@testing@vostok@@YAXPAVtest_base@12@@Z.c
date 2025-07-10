void __fastcall vostok::testing::run_protected_test(int a1, vostok::testing::test_base *test)
{
  s_environment.awaited_exception = assert_untyped;
  s_environment.exception_index = 0;
  _InterlockedExchangeAdd(&s_environment.current_test_number, 1u);
  vostok::debug::protected_call(vostok::testing::run_protected_test_helper, test);
}
