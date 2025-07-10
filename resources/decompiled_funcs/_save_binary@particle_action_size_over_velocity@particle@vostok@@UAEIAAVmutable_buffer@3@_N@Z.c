unsigned int __thiscall vostok::particle::particle_action_size_over_velocity::save_binary(
        vostok::particle::particle_action_size_over_velocity *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  return vostok::particle::curve_line_ranged_xyz_float::save_binary(&this->m_size_over_velocity, buffer, calc_size);
}
