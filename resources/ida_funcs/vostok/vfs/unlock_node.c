void __cdecl vostok::vfs::unlock_node(vostok::vfs::base_node<1> *node, vostok::vfs::lock_type_enum lock_type)
{
  vostok::vfs::base_folder_node<1> *v2; // [esp+0h] [ebp-8h]

  if ( (node->m_flags & 0x300) != 0 )
    v2 = 0;
  else
    v2 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node);
  if ( v2 )
    vostok::vfs::base_folder_node<1>::unlock(v2, lock_type);
}
