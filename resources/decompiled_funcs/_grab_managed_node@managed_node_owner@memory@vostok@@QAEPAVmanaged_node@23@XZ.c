vostok::memory::managed_node *__thiscall vostok::memory::managed_node_owner::grab_managed_node(
        vostok::memory::managed_node_owner *this)
{
  vostok::memory::managed_node *result; // eax

  result = this->m_node;
  this->m_node = 0;
  return result;
}
