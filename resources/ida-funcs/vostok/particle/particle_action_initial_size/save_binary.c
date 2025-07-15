unsigned int __thiscall vostok::particle::particle_action_initial_size::save_binary(
        vostok::particle::particle_action_initial_size *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  return vostok::particle::curve_line_ranged_xyz_float::save_binary(&this->m_init_size, buffer, calc_size);
}
