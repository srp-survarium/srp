void __thiscall vostok::buffer_string::rtrim(vostok::buffer_string *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  *--this->m_end = 0;
}
