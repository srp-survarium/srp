vostok::resources::managed_resource **vostok::memory::_dynamic_atexit_destructor_for__s_resources__()
{
  vostok::resources::managed_resource **result; // eax

  result = vostok::memory::s_resources.m_begin;
  vostok::memory::s_resources.m_end = vostok::memory::s_resources.m_begin;
  return result;
}
