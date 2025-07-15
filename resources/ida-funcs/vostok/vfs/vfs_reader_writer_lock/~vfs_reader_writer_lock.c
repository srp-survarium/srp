void __thiscall vostok::vfs::vfs_reader_writer_lock::~vfs_reader_writer_lock(vostok::vfs::vfs_reader_writer_lock *this)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
}
