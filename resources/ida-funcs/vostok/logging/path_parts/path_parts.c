void __thiscall vostok::logging::path_parts::path_parts(vostok::logging::path_parts *this, const char *initiator)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)this);
  this->m_current_element = 0;
  this->m_index = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *initiator != 58 )
    vostok::logging::path_parts::add_part(this, initiator);
  vostok::logging::path_parts::add_part(this, 0);
}
