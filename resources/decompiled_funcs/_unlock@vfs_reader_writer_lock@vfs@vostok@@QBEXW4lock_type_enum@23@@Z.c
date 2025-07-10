void __thiscall vostok::vfs::vfs_reader_writer_lock::unlock(
        vostok::vfs::vfs_reader_writer_lock *this,
        vostok::vfs::lock_type_enum lock_type)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  vostok::vfs::vfs_reader_writer_lock::counters_type dec; // [esp+Ch] [ebp-4h] BYREF

  dec.0 = 0;
  vostok::vfs::vfs_reader_writer_lock::counters_type::change_unsafe((survarium::game_camera *)&dec, 1, lock_type);
  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  survarium::weapon_user_dead_state::finalize(v5);
  _InterlockedExchangeAdd((volatile signed __int32 *)this, -*(_DWORD *)&dec.0);
}
