void __thiscall survarium::grenade_core::remove_physics(survarium::grenade_core *this)
{
  vostok::physics::world **p_m_physics_world; // esi
  vostok::physics::world *m_physics_world; // eax

  p_m_physics_world = &this->m_physics_world;
  m_physics_world = this->m_physics_world;
  if ( m_physics_world )
  {
    m_physics_world->remove(m_physics_world, this->m_rigid_body);
    *p_m_physics_world = 0;
  }
}
