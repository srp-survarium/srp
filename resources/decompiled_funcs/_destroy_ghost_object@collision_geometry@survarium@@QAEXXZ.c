void __thiscall survarium::collision_geometry::destroy_ghost_object(survarium::collision_geometry *this)
{
  vostok::physics::destroy_ghost_object(this->m_ghost_object);
}
