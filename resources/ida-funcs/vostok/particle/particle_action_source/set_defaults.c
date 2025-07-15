void __thiscall vostok::particle::particle_action_source::set_defaults(
        vostok::particle::particle_action_source *this,
        bool mt_alloc)
{
  this->m_next.pointer = 0;
  this->m_visibility = 1;
  vostok::particle::particle_domain_complex::set_defaults(&this->m_domain, (int)&this->m_domain);
}
