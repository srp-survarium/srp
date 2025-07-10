char *__thiscall vostok::buffer_string::operator[](vostok::buffer_string *this, unsigned int i)
{
  survarium::game_camera *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  return &this->m_begin[i];
}
