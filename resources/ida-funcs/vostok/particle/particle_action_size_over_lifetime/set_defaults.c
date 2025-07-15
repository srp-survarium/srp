void __thiscall vostok::particle::particle_action_size_over_lifetime::set_defaults(
        vostok::particle::particle_action_size_over_lifetime *this,
        bool mt_alloc)
{
  this->m_next.pointer = 0;
  this->m_visibility = 1;
  vostok::math::curve_line_ranged_xyz_float::set_defaults(
    (vostok::math::curve_line_ranged_xyz_float *)this,
    (int)&this->m_size_over_life);
  this->m_multiply_x = 1;
  this->m_multiply_y = 1;
  this->m_multiply_z = 1;
}
