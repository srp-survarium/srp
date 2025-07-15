unsigned int __thiscall vostok::particle::particle_action_acceleration::save_binary(
        vostok::particle::particle_action_acceleration *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  return vostok::particle::curve_line_ranged_xyz_float::save_binary(&this->m_acceleration, buffer, calc_size);
}
