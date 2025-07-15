int vostok::tasks::_dynamic_initializer_for__s_mutex__()
{
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&s_mutex_0, 0x2710u);
  return atexit(vostok::tasks::_dynamic_atexit_destructor_for__s_mutex__);
}
