void __thiscall vostok::particle::particle_action_acceleration::load_binary(
        vostok::particle::particle_action_acceleration *this,
        vostok::mutable_buffer *buffer)
{
  vostok::particle::curve_line_ranged_xyz_float::load_binary(&this->m_acceleration, buffer);
}
