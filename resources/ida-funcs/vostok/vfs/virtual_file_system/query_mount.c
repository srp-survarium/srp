void __thiscall vostok::vfs::virtual_file_system::query_mount(
        vostok::vfs::virtual_file_system *this,
        vostok::vfs::query_mount_arguments *args)
{
  bool clear_root_write_lock; // [esp+7h] [ebp-1h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  clear_root_write_lock = args->root_write_lock == 0;
  vostok::vfs::virtual_file_system::query_mount_impl(this, args);
  if ( clear_root_write_lock )
    args->root_write_lock = 0;
}
