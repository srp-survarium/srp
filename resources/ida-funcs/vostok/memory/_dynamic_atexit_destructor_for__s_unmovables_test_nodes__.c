vostok::memory::unmovable_test_node *vostok::memory::_dynamic_atexit_destructor_for__s_unmovables_test_nodes__()
{
  vostok::memory::unmovable_test_node *result; // eax

  result = vostok::memory::s_unmovables_test_nodes.m_begin;
  vostok::memory::s_unmovables_test_nodes.m_end = vostok::memory::s_unmovables_test_nodes.m_begin;
  return result;
}
