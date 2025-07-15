void __thiscall vostok::particle::particle_action_acceleration::load_binary(
        vostok::particle::particle_action_animated_source *this,
        vostok::mutable_buffer *buffer)
{
  vostok::math::curve_line_ranged_xyz_float::load_binary(&this->m_scale, &this->m_scale.m_line_x, buffer);
}
