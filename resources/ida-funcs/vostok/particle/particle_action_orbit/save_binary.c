unsigned int __thiscall vostok::particle::particle_action_orbit::save_binary(
        vostok::particle::particle_action_orbit *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  vostok::math::curve_line_ranged_xyz_float *v5; // ecx
  vostok::math::curve_line_ranged_xyz_float *v6; // ecx
  vostok::math::curve_line_ranged_xyz_float *v7; // ecx
  unsigned int calc_sizea; // [esp+18h] [ebp+Ch]
  unsigned int calc_sizeb; // [esp+18h] [ebp+Ch]
  unsigned int calc_sizec; // [esp+18h] [ebp+Ch]
  unsigned int calc_sized; // [esp+18h] [ebp+Ch]

  calc_sizea = vostok::math::curve_line_ranged_xyz_float::save_binary(
                 (vostok::math::curve_line_ranged_xyz_float *)this,
                 &this->m_radius.m_line_x,
                 buffer,
                 calc_size);
  calc_sizeb = vostok::math::curve_line_ranged_xyz_float::save_binary(v5, &this->m_spin.m_line_x, buffer, calc_size)
             + calc_sizea;
  calc_sizec = vostok::math::curve_line_ranged_xyz_float::save_binary(
                 v6,
                 &this->m_spin_offset.m_line_x,
                 buffer,
                 calc_size)
             + calc_sizeb;
  calc_sized = vostok::math::curve_line_ranged_base::save_binary(&this->m_speed.m_line, buffer, calc_size) + calc_sizec;
  return calc_sized
       + vostok::math::curve_line_ranged_xyz_float::save_binary(v7, &this->m_rotation.m_line_x, buffer, calc_size);
}
