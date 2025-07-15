void __thiscall vostok::particle::particle_action_initial_rotation_rate::load_binary(
        vostok::particle::particle_action_initial_rotation_rate *this,
        vostok::mutable_buffer *buffer)
{
  vostok::particle::curve_line_ranged_xyz_float::load_binary(&this->m_init_rate, buffer);
}
