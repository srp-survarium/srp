void __thiscall vostok::particle::particle_action_orbit::load_binary(
        vostok::particle::particle_action_orbit *this,
        vostok::mutable_buffer *buffer)
{
  vostok::particle::curve_line_ranged_xyz_float::load_binary(&this->m_offset_amount, buffer);
  vostok::particle::curve_line_ranged_xyz_float::load_binary(&this->m_rotation_amount, buffer);
  vostok::particle::curve_line_ranged_xyz_float::load_binary(&this->m_rotation_rate_amount, buffer);
}
