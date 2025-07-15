void __thiscall vostok::particle::particle_action_initial_size::set_defaults(
        vostok::particle::particle_action_initial_size *this,
        bool mt_alloc)
{
  this->m_next.pointer = 0;
  this->m_visibility = 1;
  vostok::math::curve_line_ranged_xyz_float::set_defaults(
    (vostok::math::curve_line_ranged_xyz_float *)this,
    (int)&this->m_init_size);
  this->m_is_square = 0;
}
