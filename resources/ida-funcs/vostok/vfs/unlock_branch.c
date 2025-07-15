void __cdecl vostok::vfs::unlock_branch(vostok::vfs::base_node<1> *node, vostok::vfs::lock_type_enum lock_type)
{
  vostok::vfs::base_node<1> *v2; // eax
  vostok::vfs::lock_type_enum v3; // [esp-4h] [ebp-Ch]
  vostok::vfs::base_folder_node<1> *parent; // [esp+4h] [ebp-4h]

  if ( node )
  {
    vostok::vfs::unlock_node(node, lock_type);
    parent = node->m_parent.pointer;
    if ( parent )
    {
      v3 = vostok::vfs::soften_lock(lock_type);
      v2 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(parent);
      vostok::vfs::unlock_branch(v2, v3);
    }
  }
}
