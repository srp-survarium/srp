void __thiscall vostok::particle::particle_action_size_over_lifetime::set_defaults(
        vostok::particle::particle_action_size_over_lifetime *this,
        bool mt_alloc)
{
  vostok::particle::particle_action::set_defaults(this, mt_alloc);
  vostok::particle::curve_line_ranged_xyz_float::set_defaults(&this->m_size_over_life);
  this->m_multiply_x = 1;
  this->m_multiply_y = 1;
  this->m_multiply_z = 1;
}
