BOOL __thiscall vostok::physics::bullet_character_controller::can_jump(
        vostok::physics::bullet_character_controller *this)
{
  vostok::physics::bullet_character_controller *v1; // ecx

  return !this->m_capsule_is_in_crouch
      && vostok::physics::bullet_character_controller::on_ground(this)
      && !vostok::physics::bullet_character_controller::on_steep_slope(v1, (float *)v1);
}
