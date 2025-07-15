void __cdecl vostok::vfs::upgrade_branch(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::lock_type_enum from_lock,
        vostok::vfs::lock_operation_enum to_lock)
{
  vostok::vfs::vfs_reader_writer_lock *v3; // ecx
  vostok::vfs::base_folder_node<1> *v4; // eax
  vostok::vfs::lock_type_enum v5; // eax
  vostok::vfs::base_node<1> *v6; // ecx
  vostok::vfs::lock_operation_enum v7; // [esp-4h] [ebp-10h]

  if ( node )
    v4 = vostok::vfs::cast_folder<1>(node);
  else
    v4 = 0;
  if ( node->m_parent.pointer )
  {
    vostok::vfs::unlock_node(node, from_lock);
    v7 = vostok::vfs::soften_lock((vostok::vfs::lock_type_enum)to_lock);
    v5 = vostok::vfs::soften_lock(from_lock);
    vostok::vfs::upgrade_branch(v6, v5, v7);
    vostok::vfs::lock_node(node, (vostok::vfs::lock_type_enum)to_lock, lock_operation_lock);
  }
  else if ( v4 )
  {
    vostok::vfs::vfs_reader_writer_lock::upgrade(
      v3,
      &v4->m_readers_writers_counters.m_counters,
      from_lock,
      (vostok::vfs::lock_type_enum)to_lock);
  }
}
