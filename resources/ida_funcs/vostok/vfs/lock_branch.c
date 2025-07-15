char __cdecl vostok::vfs::lock_branch(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum operation)
{
  vostok::vfs::base_node<1> *v3; // eax
  vostok::vfs::base_node<1> *v5; // eax
  vostok::vfs::lock_type_enum soft_lock; // [esp+4h] [ebp-8h]
  vostok::vfs::base_folder_node<1> *parent; // [esp+8h] [ebp-4h]

  parent = node->m_parent.pointer;
  soft_lock = vostok::vfs::soften_lock(lock_type);
  if ( parent )
  {
    v3 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(parent);
    if ( !vostok::vfs::lock_branch(v3, soft_lock, operation) )
      return 0;
  }
  if ( vostok::vfs::lock_node(node, lock_type, operation) )
    return 1;
  if ( parent )
  {
    v5 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(parent);
    vostok::vfs::unlock_branch(v5, soft_lock);
  }
  return 0;
}
