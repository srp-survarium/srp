vostok::memory::managed_node *__thiscall vostok::memory::managed_node_owner::pin(
        vostok::memory::managed_node_owner *this)
{
  vostok::memory::managed_node *m_node; // eax

  m_node = this->m_node;
  _InterlockedExchangeAdd(&m_node->m_pin_count, 1u);
  return m_node + 1;
}
