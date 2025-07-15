void __userpurge vostok::vfs::vfs_locked_iterator::assign(
        vostok::vfs::base_node<1> *node@<eax>,
        vostok::vfs::vfs_locked_iterator *a2@<ecx>,
        vostok::vfs::vfs_locked_iterator *this,
        vostok::vfs::vfs_hashset *hashset,
        vostok::vfs::vfs_iterator::type_enum type,
        unsigned int mount_operation_id)
{
  vostok::vfs::vfs_hashset **v7; // eax
  _DWORD v8[4]; // [esp+10h] [ebp-10h] BYREF

  if ( this->m_node != node )
  {
    vostok::vfs::vfs_locked_iterator::unlock_and_decref_if_needed(a2, (int)this);
    v8[2] = 0;
    v8[0] = hashset;
    v8[3] = type;
    v8[1] = node;
    v7 = (vostok::vfs::vfs_hashset **)v8;
    if ( node )
      vostok::vfs::vfs_iterator::vfs_iterator((vostok::vfs::vfs_iterator *)node, (int)v8);
    this->m_hashset = *v7;
    this->m_node = (vostok::vfs::base_node<1> *)v7[1];
    this->m_link_target = (vostok::vfs::base_node<1> *)v7[2];
    this->m_type = (vostok::vfs::vfs_iterator::type_enum)v7[3];
    this->mount_operation_id = mount_operation_id;
  }
}
