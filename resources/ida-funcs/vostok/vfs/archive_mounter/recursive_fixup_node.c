void __thiscall vostok::vfs::archive_mounter::recursive_fixup_node(
        vostok::vfs::archive_mounter *this,
        vostok::vfs::base_node<1> *node,
        char *buffer_origin)
{
  vostok::vfs::base_folder_node<1> *v4; // eax
  vostok::vfs::base_node<1> *pointer; // eax
  vostok::vfs::base_node<1> *i; // esi
  vostok::vfs::fixup_node direction; // [esp+Ch] [ebp-Ch] BYREF

  if ( this->m_reverse_byte_order )
    vostok::vfs::base_node<1>::reverse_bytes_for_final_class((vostok::vfs::base_node<1> *)this, (char *)node);
  vostok::vfs::fixup_node::fixup_node(&direction, node, this->m_mount_root_base, buffer_origin);
  if ( (node->m_flags & 0x300) != 0 )
    v4 = 0;
  else
    v4 = vostok::vfs::cast_folder<1>(node);
  if ( v4 )
    pointer = v4->m_first_child.pointer;
  else
    pointer = 0;
  for ( i = pointer; i; i = i->m_next.pointer )
    vostok::vfs::archive_mounter::recursive_fixup_node(this, i, buffer_origin);
}
