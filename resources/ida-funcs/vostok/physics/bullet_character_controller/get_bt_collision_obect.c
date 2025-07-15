btCollisionObject *__thiscall vostok::physics::bullet_character_controller::get_bt_collision_obect(
        vostok::physics::bullet_character_controller *this)
{
  return (btCollisionObject *)&this->m_crouch_shape_dim.elements[1];
}
