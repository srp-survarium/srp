void __thiscall vostok::particle::particle_action_rotation_over_velocity::load_binary(
        vostok::particle::particle_action_rotation_over_velocity *this,
        vostok::mutable_buffer *buffer)
{
  vostok::particle::curve_line_ranged_xyz_float::load_binary(&this->m_rotation_over_velocity, buffer);
}
