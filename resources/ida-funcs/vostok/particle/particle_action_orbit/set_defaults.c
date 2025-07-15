void __thiscall vostok::particle::particle_action_orbit::set_defaults(
        vostok::particle::particle_action_orbit *this,
        bool mt_alloc)
{
  vostok::particle::particle_action::set_defaults(this, mt_alloc);
  vostok::particle::curve_line_ranged_xyz_float::set_defaults(&this->m_offset_amount);
  vostok::particle::curve_line_ranged_xyz_float::set_defaults(&this->m_rotation_amount);
  vostok::particle::curve_line_ranged_xyz_float::set_defaults(&this->m_rotation_rate_amount);
}
