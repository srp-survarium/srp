void __thiscall vostok::vfs::mount_root_node_base<1>::prepend_erased_node(
        vostok::vfs::mount_root_node_base<1> *this,
        vostok::vfs::base_node<1> *node)
{
  int v2; // [esp+8h] [ebp-20h] BYREF
  int v3; // [esp+Ch] [ebp-1Ch]
  vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *v4; // [esp+10h] [ebp-18h]
  int *v5; // [esp+14h] [ebp-14h]
  unsigned __int64 max_storage; // [esp+18h] [ebp-10h]
  vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *p_m_next; // [esp+20h] [ebp-8h]

  if ( this->first_erased.pointer )
  {
    max_storage = this->first_erased.max_storage;
    p_m_next = &node->m_next;
    node->m_next.max_storage = max_storage;
  }
  else
  {
    v5 = &v2;
    v3 = 0;
    v2 = 0;
    v4 = &node->m_next;
    node->m_next.pointer = 0;
    HIDWORD(node->m_next.max_storage) = v3;
  }
  this->first_erased.pointer = node;
}
