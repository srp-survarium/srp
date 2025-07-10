void __cdecl vostok::vfs::upgrade_branch(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::lock_type_enum from_lock,
        vostok::vfs::lock_type_enum to_lock)
{
  vostok::vfs::base_node<1> *v3; // eax
  vostok::vfs::lock_type_enum v4; // [esp-8h] [ebp-14h]
  vostok::vfs::lock_type_enum v5; // [esp-4h] [ebp-10h]
  vostok::vfs::base_folder_node<1> *folder_node; // [esp+4h] [ebp-8h]
  vostok::vfs::base_folder_node<1> *parent; // [esp+8h] [ebp-4h]

  folder_node = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node);
  parent = node->m_parent.pointer;
  if ( parent )
  {
    vostok::vfs::unlock_node(node, from_lock);
    v5 = vostok::vfs::soften_lock(to_lock);
    v4 = vostok::vfs::soften_lock(from_lock);
    v3 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(parent);
    vostok::vfs::upgrade_branch(v3, v4, v5);
    vostok::vfs::lock_node(node, to_lock, lock_operation_lock);
  }
  else if ( folder_node )
  {
    vostok::vfs::base_folder_node<1>::upgrade_lock(folder_node, from_lock, to_lock);
  }
}
