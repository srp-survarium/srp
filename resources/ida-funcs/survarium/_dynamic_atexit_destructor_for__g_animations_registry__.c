survarium::animations_registry::animations_tuple *survarium::_dynamic_atexit_destructor_for__g_animations_registry__()
{
  survarium::animations_registry::animations_tuple *result; // eax

  vostok::buffer_vector<survarium::animations_registry::animations_tuple>::destroy(
    survarium::g_animations_registry.m_indices.m_begin,
    &survarium::g_animations_registry.m_indices.m_end);
  survarium::g_animations_registry.m_indices.m_end = survarium::g_animations_registry.m_indices.m_begin;
  vostok::buffer_vector<survarium::animations_registry::animations_tuple>::destroy(
    survarium::g_animations_registry.m_animations.m_begin,
    &survarium::g_animations_registry.m_animations.m_end);
  result = survarium::g_animations_registry.m_animations.m_begin;
  survarium::g_animations_registry.m_animations.m_end = survarium::g_animations_registry.m_animations.m_begin;
  return result;
}
