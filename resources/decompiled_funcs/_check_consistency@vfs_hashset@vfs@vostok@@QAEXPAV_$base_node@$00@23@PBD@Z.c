void __thiscall vostok::vfs::vfs_hashset::check_consistency(
        vostok::vfs::vfs_hashset *this,
        vostok::vfs::base_node<1> *node,
        const char *path)
{
  _BYTE *v3; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v3 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)node);
}
