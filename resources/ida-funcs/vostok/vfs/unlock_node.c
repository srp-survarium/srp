void __usercall vostok::vfs::unlock_node(vostok::vfs::base_node<1> *node@<eax>, vostok::vfs::lock_type_enum lock_type)
{
  vostok::vfs::base_folder_node<1> *v2; // esi
  vostok::vfs::vfs_reader_writer_lock::counters_type v3; // [esp+4h] [ebp-4h] BYREF

  if ( (node->m_flags & 0x300) != 0 )
    v2 = 0;
  else
    v2 = vostok::vfs::cast_folder<1>(node);
  if ( v2 )
  {
    v3.0 = 0;
    vostok::vfs::vfs_reader_writer_lock::counters_type::change_unsafe(&v3, lock_type, 1);
    _InterlockedExchangeAdd((volatile signed __int32 *)&v2->m_readers_writers_counters, -*(_DWORD *)&v3.0);
  }
}
