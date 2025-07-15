char __thiscall vostok::vfs::vfs_reader_writer_lock::lock(
        vostok::vfs::vfs_reader_writer_lock *this,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum operation)
{
  int v4; // eax
  bool v5; // [esp+0h] [ebp-1Ch]
  bool v6; // [esp+4h] [ebp-18h]
  vostok::vfs::vfs_reader_writer_lock::counters_type new_counters; // [esp+10h] [ebp-Ch] BYREF
  vostok::vfs::vfs_reader_writer_lock::counters_type previous_counters; // [esp+14h] [ebp-8h]
  bool check; // [esp+1Bh] [ebp-1h]

  while ( 1 )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    previous_counters.0 = ($E3F6406041541B22B272F6C75322E84C)this->m_counters;
    check = 0;
    switch ( lock_type )
    {
      case 1:
        v6 = ((*(_DWORD *)&previous_counters.0 >> 30) & 1) == 0 && (previous_counters.whole & 0x3F000000) == 0;
        check = v6;
        break;
      case 3:
        check = ((*(_DWORD *)&previous_counters.0 >> 30) & 1) == 0;
        break;
      case 2:
        check = *(_DWORD *)&previous_counters.0 == 0;
        break;
      case 4:
        v5 = ((*(_DWORD *)&previous_counters.0 >> 30) & 1) == 0
          && ((*(_DWORD *)&previous_counters.0 >> 14) & 0x3FF) == 0;
        check = v5;
        break;
    }
    if ( !check )
    {
      if ( operation == lock_operation_try_lock )
        return 0;
      goto LABEL_20;
    }
    new_counters.0 = previous_counters.0;
    vostok::vfs::vfs_reader_writer_lock::counters_type::change_unsafe(
      (survarium::game_camera *)&new_counters,
      1,
      lock_type);
    v4 = vostok::threading::interlocked_compare_exchange(
           new_counters.whole,
           (volatile int *)this,
           previous_counters.whole);
    if ( v4 == *(_DWORD *)&previous_counters.0 )
      return 1;
    if ( operation == lock_operation_try_lock )
      return 0;
LABEL_20:
    vostok::threading::yield(0);
  }
}
