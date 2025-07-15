int __thiscall vostok::testing::_dynamic_initializer_for__s_environment__(vostok::testing::environment *this)
{
  vostok::testing::environment::environment(this);
  return atexit(vostok::testing::_dynamic_atexit_destructor_for__s_environment__);
}
