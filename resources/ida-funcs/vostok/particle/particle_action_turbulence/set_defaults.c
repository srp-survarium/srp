void __thiscall vostok::particle::particle_action_turbulence::set_defaults(
        vostok::particle::particle_action_turbulence *this,
        bool mt_alloc)
{
  this->m_next.pointer = 0;
  this->m_visibility = 1;
  vostok::particle::particle_domain_complex::set_defaults(
    (vostok::particle::particle_domain_complex *)this,
    (int)&this->m_domain);
  this->m_octaves = 0;
  this->m_magnitude = 0.0;
  this->m_min_magnitude = 0.0;
  this->m_attenuation = 0.0;
  this->m_frequency = 0.0;
  this->m_ratio_x = 0.0;
  this->m_ratio_y = 0.0;
  this->m_ratio_z = 0.0;
}
