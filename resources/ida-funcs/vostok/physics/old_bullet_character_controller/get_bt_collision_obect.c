btCollisionObject *__thiscall vostok::physics::old_bullet_character_controller::get_bt_collision_obect(
        vostok::physics::old_bullet_character_controller *this)
{
  return (btCollisionObject *)((char *)&this->m_crouch_shape_dim + 12);
}
