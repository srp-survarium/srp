bool __thiscall vostok::vfs::filter_by_descriptor::operator()(
        vostok::vfs::filter_by_descriptor *this,
        const char *in_descriptor,
        const char *physical_path,
        survarium::game_camera *virtual_path)
{
  _BYTE *v4; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize(virtual_path);
  return !this->descriptor || !*this->descriptor || vostok::strings::equal(in_descriptor, this->descriptor);
}
