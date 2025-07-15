void __thiscall vostok::vfs::archive_mounter::recursive_fixup_node(
        vostok::vfs::archive_mounter *this,
        vostok::vfs::base_node<1> *node,
        char *buffer_origin)
{
  vostok::vfs::base_node<1> *pointer; // [esp+0h] [ebp-44h]
  vostok::vfs::base_folder_node<1> *v4; // [esp+4h] [ebp-40h]
  vostok::vfs::fixup_node v6; // [esp+30h] [ebp-14h] BYREF
  vostok::vfs::base_node<1> *it_child; // [esp+3Ch] [ebp-8h]
  vostok::vfs::base_folder_node<1> *node_as_folder; // [esp+40h] [ebp-4h]

  if ( this->m_reverse_byte_order )
    vostok::vfs::base_node<1>::reverse_bytes_for_final_class(node, reverse_direction_to_native);
  vostok::vfs::fixup_node::fixup_node(&v6, node, buffer_origin, this->m_mount_root_base);
  if ( (node->m_flags & 0x300) != 0 )
    v4 = 0;
  else
    v4 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node);
  node_as_folder = v4;
  if ( v4 )
    pointer = node_as_folder->m_first_child.pointer;
  else
    pointer = 0;
  for ( it_child = pointer; it_child; it_child = it_child->m_next.pointer )
    vostok::vfs::archive_mounter::recursive_fixup_node(this, it_child, buffer_origin);
}
