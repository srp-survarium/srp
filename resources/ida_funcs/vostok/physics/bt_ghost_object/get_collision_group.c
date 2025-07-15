__int16 __thiscall vostok::physics::bt_ghost_object::get_collision_group(vostok::physics::bt_ghost_object *this)
{
  return this->m_bt_object->m_broadphaseHandle->m_collisionFilterGroup;
}
