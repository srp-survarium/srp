int vostok::resources::_dynamic_initializer_for__s_hdd_device__()
{
  int result; // eax

  result = 0;
  vostok::resources::s_hdd_device.m_initialized = 0;
  vostok::resources::s_hdd_device.m_construction_started = 0;
  return result;
}
