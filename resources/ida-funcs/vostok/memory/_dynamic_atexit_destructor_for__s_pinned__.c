vostok::memory::tester_pinned_resource *vostok::memory::_dynamic_atexit_destructor_for__s_pinned__()
{
  vostok::memory::tester_pinned_resource *result; // eax

  result = vostok::memory::s_pinned.m_begin;
  vostok::memory::s_pinned.m_end = vostok::memory::s_pinned.m_begin;
  return result;
}
