void __cdecl vostok::logging::delete_log_file(vostok::logging::log_file **log_file)
{
  vostok::memory::base_allocator *v1; // eax

  if ( *log_file )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)log_file);
    vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::logging::log_file>(v1, log_file);
  }
}
