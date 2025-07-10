unsigned int __thiscall vostok::particle::particle_action_orbit::save_binary(
        vostok::particle::particle_action_orbit *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  unsigned int v3; // esi
  unsigned int v4; // esi

  v3 = vostok::particle::curve_line_ranged_xyz_float::save_binary(&this->m_offset_amount, buffer, calc_size);
  v4 = vostok::particle::curve_line_ranged_xyz_float::save_binary(&this->m_rotation_amount, buffer, calc_size) + v3;
  return v4
       + vostok::particle::curve_line_ranged_xyz_float::save_binary(&this->m_rotation_rate_amount, buffer, calc_size);
}
