char __thiscall vostok::fs_new::path_string_impl::operator[](vostok::fs_new::path_string_impl *this, unsigned int i)
{
  survarium::game_camera *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  return this->m_string.m_begin[i];
}
