bool __thiscall vostok::vfs::filter_helper::filter(
        vostok::vfs::filter_helper *this,
        const char *description,
        const char *physical_path,
        survarium::game_camera *virtual_path)
{
  _BYTE *v4; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize(virtual_path);
  return this->current++ == this->index;
}
