void __thiscall vostok::particle::particle_action_orbit::load_binary(
        vostok::particle::particle_action_orbit *this,
        vostok::mutable_buffer *buffer)
{
  vostok::math::curve_line_ranged_xyz_float *v3; // ecx
  vostok::math::curve_line_ranged_xyz_float *v4; // ecx
  vostok::math::curve_line_points<float,0> *v5; // ecx
  vostok::math::curve_line_ranged_xyz_float *v6; // ecx

  vostok::math::curve_line_ranged_xyz_float::load_binary(
    (vostok::math::curve_line_ranged_xyz_float *)this,
    &this->m_radius.m_line_x,
    buffer);
  vostok::math::curve_line_ranged_xyz_float::load_binary(v3, &this->m_spin.m_line_x, buffer);
  vostok::math::curve_line_ranged_xyz_float::load_binary(v4, &this->m_spin_offset.m_line_x, buffer);
  vostok::math::curve_line_ranged_base::load_binary(&this->m_speed.m_line, buffer, v5);
  vostok::math::curve_line_ranged_xyz_float::load_binary(v6, &this->m_rotation.m_line_x, buffer);
}
