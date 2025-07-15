int vostok::resources::_dynamic_initializer_for__g_resources_manager__()
{
  int result; // eax

  result = 0;
  vostok::resources::g_resources_manager.m_initialized = 0;
  vostok::resources::g_resources_manager.m_construction_started = 0;
  return result;
}
