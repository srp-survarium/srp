char __thiscall vostok::vfs::vfs_reader_writer_lock::upgrade(
        vostok::vfs::vfs_reader_writer_lock *this,
        vostok::vfs::lock_type_enum from_lock,
        vostok::vfs::lock_type_enum to_lock,
        vostok::vfs::lock_operation_enum operation)
{
  survarium::game_camera *v4; // ecx
  int v6; // eax
  bool v7; // [esp+0h] [ebp-28h]
  bool v8; // [esp+4h] [ebp-24h]
  bool v9; // [esp+8h] [ebp-20h]
  vostok::vfs::vfs_reader_writer_lock::counters_type new_counters; // [esp+18h] [ebp-10h] BYREF
  vostok::vfs::vfs_reader_writer_lock::counters_type previous_counters; // [esp+1Ch] [ebp-Ch]
  bool check; // [esp+23h] [ebp-5h]
  vostok::vfs::vfs_reader_writer_lock::counters_type allowed; // [esp+24h] [ebp-4h] BYREF

  allowed.0 = 0;
  vostok::vfs::vfs_reader_writer_lock::counters_type::change_unsafe((survarium::game_camera *)&allowed, 1, from_lock);
  if ( from_lock == lock_type_read
    || from_lock == (lock_type_write|lock_type_read)
    || from_lock == lock_type_write
    || from_lock == 4 )
  {
    survarium::weapon_user_dead_state::finalize(v4);
  }
  while ( 1 )
  {
    survarium::weapon_user_dead_state::finalize(v4);
    previous_counters.0 = ($E3F6406041541B22B272F6C75322E84C)this->m_counters;
    check = 0;
    switch ( to_lock )
    {
      case 1:
        v9 = ((*(_DWORD *)&previous_counters.0 >> 30) & 1u) <= ((*(_DWORD *)&allowed.0 >> 30) & 1u)
          && (HIBYTE(previous_counters.whole) & 0x3Fu) <= (HIBYTE(allowed.whole) & 0x3Fu);
        check = v9;
        break;
      case 3:
        check = ((*(_DWORD *)&allowed.0 >> 30) & 1u) >= ((*(_DWORD *)&previous_counters.0 >> 30) & 1u);
        break;
      case 2:
        v8 = ((*(_DWORD *)&previous_counters.0 >> 30) & 1u) <= ((*(_DWORD *)&allowed.0 >> 30) & 1u)
          && (HIBYTE(previous_counters.whole) & 0x3Fu) <= (HIBYTE(allowed.whole) & 0x3Fu)
          && ((*(_DWORD *)&previous_counters.0 >> 14) & 0x3FFu) <= ((*(_DWORD *)&allowed.0 >> 14) & 0x3FFu)
          && (*(_WORD *)&previous_counters.0 & 0x3FFFu) <= (*(_WORD *)&allowed.0 & 0x3FFFu);
        check = v8;
        break;
      case 4:
        v7 = ((*(_DWORD *)&previous_counters.0 >> 30) & 1u) <= ((*(_DWORD *)&allowed.0 >> 30) & 1u)
          && ((*(_DWORD *)&previous_counters.0 >> 14) & 0x3FFu) <= ((*(_DWORD *)&allowed.0 >> 14) & 0x3FFu);
        check = v7;
        break;
    }
    if ( !check )
    {
      if ( operation == lock_operation_try_lock )
        return 0;
      goto LABEL_32;
    }
    new_counters.0 = previous_counters.0;
    vostok::vfs::vfs_reader_writer_lock::counters_type::change_unsafe(
      (survarium::game_camera *)&new_counters,
      -1,
      from_lock);
    vostok::vfs::vfs_reader_writer_lock::counters_type::change_unsafe(
      (survarium::game_camera *)&new_counters,
      1,
      to_lock);
    v6 = vostok::threading::interlocked_compare_exchange(
           new_counters.whole,
           (volatile int *)this,
           previous_counters.whole);
    if ( v6 == *(_DWORD *)&previous_counters.0 )
      return 1;
    if ( operation == lock_operation_try_lock )
      return 0;
LABEL_32:
    vostok::threading::yield(0);
  }
}
