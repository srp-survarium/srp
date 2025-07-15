__int16 __thiscall vostok::physics::bt_dynamic_rigid_body::get_collision_group(
        vostok::physics::bt_dynamic_rigid_body *this)
{
  return this->m_bt_body->m_broadphaseHandle->m_collisionFilterGroup;
}
