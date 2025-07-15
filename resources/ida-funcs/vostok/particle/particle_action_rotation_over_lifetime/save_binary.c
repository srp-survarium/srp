unsigned int __thiscall vostok::particle::particle_action_rotation_over_lifetime::save_binary(
        vostok::particle::particle_action_rotation_over_lifetime *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  return vostok::particle::curve_line_ranged_xyz_float::save_binary(&this->m_rotation_over_life, buffer, calc_size);
}
