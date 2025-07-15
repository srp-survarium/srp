unsigned __int16 __thiscall vostok::physics::bullet_character_controller::get_collision_group(
        vostok::physics::bullet_character_controller *this)
{
  return *((_WORD *)&this->m_jump_down_tester.m_world + 2);
}
