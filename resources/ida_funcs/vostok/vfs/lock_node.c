bool __cdecl vostok::vfs::lock_node(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum operation)
{
  vostok::vfs::base_folder_node<1> *v4; // [esp+0h] [ebp-8h]

  if ( (node->m_flags & 0x300) != 0 )
    v4 = 0;
  else
    v4 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node);
  return !v4 || vostok::vfs::base_folder_node<1>::lock(v4, lock_type, operation);
}
