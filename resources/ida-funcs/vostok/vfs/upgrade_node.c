void __usercall vostok::vfs::upgrade_node(
        vostok::vfs::base_node<1> *node@<eax>,
        vostok::vfs::lock_type_enum from_lock,
        vostok::vfs::lock_operation_enum to_lock)
{
  int v3; // ecx
  vostok::vfs::base_folder_node<1> *v4; // eax

  if ( node )
  {
    v3 = 768;
    if ( (node->m_flags & 0x300) != 0 )
      v4 = 0;
    else
      v4 = vostok::vfs::cast_folder<1>(node);
    if ( v4 )
      vostok::vfs::vfs_reader_writer_lock::upgrade(
        (vostok::vfs::vfs_reader_writer_lock *)v3,
        &v4->m_readers_writers_counters.m_counters,
        from_lock,
        (vostok::vfs::lock_type_enum)to_lock);
  }
}
