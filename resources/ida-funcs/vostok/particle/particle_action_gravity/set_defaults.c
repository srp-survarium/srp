void __thiscall vostok::particle::particle_action_gravity::set_defaults(
        vostok::particle::particle_action_gravity *this,
        bool mt_alloc)
{
  this->m_next.pointer = 0;
  this->m_visibility = 1;
  this->m_force = 0.0;
}
