char __usercall vostok::vfs::lock_node@<al>(
        vostok::vfs::base_node<1> *node@<eax>,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum operation)
{
  int v3; // ecx
  vostok::vfs::base_folder_node<1> *v4; // eax
  char result; // al

  v3 = 768;
  if ( (node->m_flags & 0x300) != 0 )
    v4 = 0;
  else
    v4 = vostok::vfs::cast_folder<1>(node);
  if ( !v4 )
    return 1;
  result = vostok::vfs::vfs_reader_writer_lock::lock(
             (vostok::vfs::vfs_reader_writer_lock *)v3,
             (volatile signed __int32 *)&v4->m_readers_writers_counters,
             lock_type,
             operation);
  if ( result )
    return 1;
  return result;
}
