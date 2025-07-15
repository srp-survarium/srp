vostok::resources::cook_base **vostok::resources::_dynamic_atexit_destructor_for__s_cooks_registry__()
{
  vostok::resources::cook_base **result; // eax

  result = s_cooks_registry.m_begin;
  s_cooks_registry.m_end = s_cooks_registry.m_begin;
  return result;
}
