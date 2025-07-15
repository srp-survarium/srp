int vostok::core::_dynamic_initializer_for__s_preinitializer__()
{
  vostok::debug::initialize(&s_preinitializer.m_engine);
  return atexit(vostok::core::_dynamic_atexit_destructor_for__s_preinitializer__);
}
