char __thiscall vostok::vfs::vfs_reader_writer_lock::upgrade(
        vostok::vfs::vfs_reader_writer_lock *this,
        vostok::vfs::vfs_reader_writer_lock::counters_type *from_lock,
        vostok::vfs::lock_type_enum to_lock,
        vostok::vfs::lock_type_enum operation)
{
  vostok::vfs::vfs_reader_writer_lock::counters_type v4; // ebx
  vostok::vfs::lock_type_enum v5; // ecx
  $E3F6406041541B22B272F6C75322E84C v6; // eax
  vostok::vfs::vfs_reader_writer_lock::counters_type *v7; // eax
  vostok::tasks *v9; // [esp+10h] [ebp-Ch]
  vostok::vfs::vfs_reader_writer_lock::counters_type v10; // [esp+14h] [ebp-8h] BYREF
  vostok::vfs::vfs_reader_writer_lock::counters_type v11; // [esp+18h] [ebp-4h] BYREF

  v11.0 = 0;
  vostok::vfs::vfs_reader_writer_lock::counters_type::change_unsafe(&v11, to_lock, 1);
  while ( 2 )
  {
    v4.0 = v11.0;
    while ( 1 )
    {
      v5 = operation;
      v6 = from_lock->0;
      v9 = (vostok::tasks *)from_lock->0;
      switch ( operation )
      {
        case lock_type_read:
          v5 = *(_DWORD *)&v6 & 0x40000000;
          if ( (*(unsigned int *)&v6 & 0x40000000) > (*(_DWORD *)&v4.0 & 0x40000000u) )
            goto LABEL_21;
          v5 = 1056964608;
LABEL_6:
          if ( (v5 & *(unsigned int *)&v6) <= ((unsigned int)v5 & *(_DWORD *)&v4.0) )
            goto LABEL_7;
          goto LABEL_21;
        case lock_type_write|lock_type_read:
          v5 = *(_DWORD *)&v6 & 0x40000000;
          LOBYTE(v5) = (*(_DWORD *)&v4.0 & 0x40000000u) >= (*(unsigned int *)&v6 & 0x40000000);
          goto LABEL_20;
        case lock_type_write:
          v5 = *(_DWORD *)&v6 & 0x40000000;
          if ( (*(unsigned int *)&v6 & 0x40000000) > (*(_DWORD *)&v4.0 & 0x40000000u) )
            goto LABEL_21;
          v5 = 1056964608;
          if ( (*(unsigned int *)&v6 & 0x3F000000) > (*(_DWORD *)&v4.0 & 0x3F000000u) )
            goto LABEL_21;
          v5 = (vostok::vfs::lock_type_enum)&s_ui_commands_allocator.m_buffer[2018976];
          if ( ((unsigned int)&s_ui_commands_allocator.m_buffer[2018976] & *(_DWORD *)&v6) > ((unsigned int)&s_ui_commands_allocator.m_buffer[2018976]
                                                                                            & *(_DWORD *)&v4.0) )
            goto LABEL_21;
          v5 = 0x3FFF;
          goto LABEL_6;
      }
      if ( operation != 4 )
        goto LABEL_21;
      v5 = *(_DWORD *)&v6 & 0x40000000;
      if ( (*(unsigned int *)&v6 & 0x40000000) <= (*(_DWORD *)&v4.0 & 0x40000000u) )
      {
        v5 = (vostok::vfs::lock_type_enum)&s_ui_commands_allocator.m_buffer[2018976];
        if ( ((unsigned int)&s_ui_commands_allocator.m_buffer[2018976] & *(_DWORD *)&v6) <= ((unsigned int)&s_ui_commands_allocator.m_buffer[2018976]
                                                                                           & *(_DWORD *)&v4.0) )
          break;
      }
      LOBYTE(v5) = 0;
LABEL_20:
      if ( (_BYTE)v5 )
        break;
LABEL_21:
      vostok::threading::yield(0, (vostok::tasks *)v5);
    }
LABEL_7:
    v10.0 = from_lock->0;
    vostok::vfs::vfs_reader_writer_lock::counters_type::change_unsafe(&v10, to_lock, -1);
    vostok::vfs::vfs_reader_writer_lock::counters_type::change_unsafe(v7, operation, 1);
    if ( (vostok::tasks *)_InterlockedCompareExchange(
                            (volatile signed __int32 *)from_lock,
                            v10.whole,
                            (signed __int32)v9) != v9 )
    {
      vostok::threading::yield(0, v9);
      continue;
    }
    return 1;
  }
}
