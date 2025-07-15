void __thiscall vostok::particle::particle_action_orbit::set_defaults(
        vostok::particle::particle_action_orbit *this,
        bool mt_alloc)
{
  vostok::math::curve_line_ranged_xyz_float *v3; // ecx
  vostok::math::curve_line_ranged_xyz_float *v4; // ecx
  vostok::math::curve_line_ranged_xyz_float *v5; // ecx

  this->m_next.pointer = 0;
  this->m_visibility = 1;
  vostok::math::curve_line_ranged_xyz_float::set_defaults(
    (vostok::math::curve_line_ranged_xyz_float *)this,
    (int)&this->m_radius);
  vostok::math::curve_line_ranged_xyz_float::set_defaults(v3, (int)&this->m_spin);
  vostok::math::curve_line_ranged_xyz_float::set_defaults(v4, (int)&this->m_spin_offset);
  vostok::math::curve_line_ranged_base::set_defaults(&this->m_speed.m_line);
  this->m_speed.m_evaluate_type = age_evaluate_type;
  vostok::math::curve_line_ranged_xyz_float::set_defaults(v5, (int)&this->m_rotation);
}
