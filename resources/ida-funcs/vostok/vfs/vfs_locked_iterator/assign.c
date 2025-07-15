void __thiscall vostok::vfs::vfs_locked_iterator::assign(
        vostok::vfs::vfs_locked_iterator *this,
        vostok::vfs::base_node<1> *node,
        vostok::vfs::vfs_hashset *hashset,
        vostok::vfs::vfs_iterator::type_enum type,
        unsigned int mount_operation_id)
{
  int v5; // eax
  vostok::vfs::vfs_iterator v7; // [esp+4h] [ebp-10h] BYREF

  if ( this->m_node != node )
  {
    vostok::vfs::vfs_locked_iterator::unlock_and_decref_if_needed(this);
    vostok::vfs::vfs_iterator::vfs_iterator(&v7, node, 0, hashset, type);
    this->m_hashset = *(vostok::vfs::vfs_hashset **)v5;
    this->m_node = *(vostok::vfs::base_node<1> **)(v5 + 4);
    this->m_link_target = *(vostok::vfs::base_node<1> **)(v5 + 8);
    this->m_type = *(_DWORD *)(v5 + 12);
    this->mount_operation_id = mount_operation_id;
  }
}
