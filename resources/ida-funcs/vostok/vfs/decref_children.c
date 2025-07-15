void __cdecl vostok::vfs::decref_children(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::find_enum find_flags,
        vostok::vfs::vfs_hashset *hashset,
        unsigned int mount_operation_id,
        bool is_root_node)
{
  bool v5; // al
  vostok::vfs::base_node<1> *pointer; // eax
  vostok::vfs::base_node<1> *v7; // esi
  vostok::vfs::base_node<1> *referenced_link_node; // eax

  v5 = (find_flags & 1) != 0 || is_root_node;
  if ( (node->m_flags & 1) != 0 && v5 )
  {
    pointer = vostok::vfs::cast_folder<1>(node)->m_first_child.pointer;
    if ( pointer )
    {
      do
      {
        v7 = pointer->m_next.pointer;
        vostok::vfs::decref_children(pointer, find_flags, hashset, mount_operation_id, 0);
        pointer = v7;
      }
      while ( v7 );
    }
  }
  if ( !is_root_node )
  {
    if ( (node->m_flags & 0x200) == 0x200 )
    {
      referenced_link_node = vostok::vfs::find_referenced_link_node(node);
      vostok::vfs::decref_children(referenced_link_node, find_flags, hashset, mount_operation_id, 0);
    }
    vostok::vfs::change_subfat_ref_for_overlapped(
      node,
      (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)-1,
      &mount_operation_id);
  }
}
