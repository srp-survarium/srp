void __usercall vostok::testing::set_testing(bool is_testing@<al>)
{
  _InterlockedExchange(&s_environment.is_testing, is_testing);
}
