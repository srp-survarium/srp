void __thiscall vostok::particle::particle_action_gravity::set_defaults(
        vostok::particle::particle_action_gravity *this,
        bool mt_alloc)
{
  vostok::particle::particle_action::set_defaults(this, mt_alloc);
  this->m_force = *(float *)&FLOAT_0_0;
}
