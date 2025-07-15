char __userpurge vostok::vfs::vfs_reader_writer_lock::lock@<al>(
        vostok::vfs::vfs_reader_writer_lock *this@<ecx>,
        vostok::vfs::vfs_reader_writer_lock::counters_type *a2@<edi>,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum operation)
{
  vostok::vfs::vfs_reader_writer_lock::counters_type v4; // ecx
  bool v5; // al
  signed __int32 v6; // eax
  vostok::vfs::vfs_reader_writer_lock::counters_type v8; // [esp+8h] [ebp-8h] BYREF
  vostok::vfs::vfs_reader_writer_lock::counters_type v9; // [esp+Ch] [ebp-4h]

  while ( 1 )
  {
    v4.0 = a2->0;
    v9.0 = a2->0;
    if ( lock_type != lock_type_read )
      break;
    if ( (*(_DWORD *)&v4.0 & 0x40000000) == 0 && (*(_DWORD *)&v4.0 & 0x3F000000) == 0 )
      goto LABEL_13;
LABEL_14:
    if ( operation == lock_operation_try_lock )
      return 0;
    vostok::threading::yield(0, (vostok::tasks *)v4.whole);
  }
  switch ( lock_type )
  {
    case 3:
      v5 = (*(_DWORD *)&v4.0 & 0x40000000) == 0;
      break;
    case 2:
      v5 = *(_DWORD *)&v9.0 == 0;
      break;
    case 4:
      if ( (*(_DWORD *)&v4.0 & 0x40FFC000) == 0 )
        goto LABEL_13;
      v5 = 0;
      break;
    default:
      goto LABEL_14;
  }
  if ( !v5 )
    goto LABEL_14;
LABEL_13:
  v8.0 = v4.0;
  vostok::vfs::vfs_reader_writer_lock::counters_type::change_unsafe(&v8, lock_type, 1);
  v6 = _InterlockedCompareExchange((volatile signed __int32 *)a2, v8.whole, v9.whole);
  v4.0 = v9.0;
  if ( v6 != *(_DWORD *)&v9.0 )
    goto LABEL_14;
  return 1;
}
