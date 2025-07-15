unsigned __int16 __thiscall vostok::physics::old_bullet_character_controller::get_collision_group(
        vostok::physics::old_bullet_character_controller *this)
{
  return *((_WORD *)&this->m_shape.m_upAxis + 7);
}
