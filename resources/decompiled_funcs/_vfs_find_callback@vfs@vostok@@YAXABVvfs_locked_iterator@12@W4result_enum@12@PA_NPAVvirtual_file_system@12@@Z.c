void __cdecl vostok::vfs::vfs_find_callback(
        const vostok::vfs::vfs_locked_iterator *it,
        vostok::vfs::result_enum result,
        bool *found,
        vostok::vfs::virtual_file_system *vfs)
{
  survarium::game_camera *v4; // ecx
  _BYTE *v5; // eax
  survarium::game_camera *v6; // [esp+0h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize(v4);
  if ( *v5 )
  {
    v6 = (survarium::game_camera *)(it->m_node && result == result_error);
    survarium::weapon_user_dead_state::finalize(v6);
  }
  vostok::vfs::log_vfs_root(vfs, 0);
  *found = 1;
}
