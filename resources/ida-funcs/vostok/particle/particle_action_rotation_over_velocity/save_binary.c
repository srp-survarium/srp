unsigned int __thiscall vostok::particle::particle_action_rotation_over_velocity::save_binary(
        vostok::particle::particle_action_animated_source *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  return vostok::math::curve_line_ranged_xyz_float::save_binary(
           &this->m_scale,
           &this->m_scale.m_line_x,
           buffer,
           calc_size);
}
