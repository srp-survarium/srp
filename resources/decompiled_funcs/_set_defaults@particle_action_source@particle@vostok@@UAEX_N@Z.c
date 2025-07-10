void __thiscall vostok::particle::particle_action_source::set_defaults(
        vostok::particle::particle_action_source *this,
        bool mt_alloc)
{
  vostok::particle::particle_action::set_defaults(this, mt_alloc);
  vostok::particle::particle_domain_complex::set_defaults(&this->m_domain);
}
