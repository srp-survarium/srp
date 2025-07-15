void __cdecl vostok::vfs::upgrade_node(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::lock_type_enum from_lock,
        vostok::vfs::lock_type_enum to_lock)
{
  vostok::vfs::base_folder_node<1> *v3; // [esp+0h] [ebp-8h]

  if ( node )
  {
    if ( (node->m_flags & 0x300) != 0 )
      v3 = 0;
    else
      v3 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node);
    if ( v3 )
      vostok::vfs::base_folder_node<1>::upgrade_lock(v3, from_lock, to_lock);
  }
}
