void __thiscall vostok::particle::particle_action_kill_volume::set_defaults(
        vostok::particle::particle_action_kill_volume *this,
        bool mt_alloc)
{
  this->m_next.pointer = 0;
  this->m_visibility = 1;
  vostok::particle::particle_domain_complex::set_defaults(
    (vostok::particle::particle_domain_complex *)this,
    (int)&this->m_domain);
  this->m_kill_inside = 1;
}
