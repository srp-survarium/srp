void __thiscall vostok::fs_new::physical_path_info::initialize_full_path_if_needed(
        vostok::fs_new::physical_path_info *this)
{
  char s[2]; // [esp+14Eh] [ebp-11Ah] BYREF
  vostok::fs_new::native_path_string name; // [esp+150h] [ebp-118h] BYREF

  if ( this->data.path_type != path_type_contains_full_path )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    vostok::fs_new::native_path_string::native_path_string(&name, &this->data.path);
    vostok::fs_new::physical_path_info::get_full_path(
      (vostok::fs_new::physical_path_info *)this->parent,
      &this->data.path);
    strcpy(s, "\\");
    vostok::fs_new::path_string_impl::operator+=<char>(&this->data.path, s);
    vostok::fs_new::path_string_impl::append<vostok::fixed_string<260>>(&this->data.path, &name.m_string);
    this->data.path_type = path_type_contains_full_path;
  }
}
