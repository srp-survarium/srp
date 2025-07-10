void __thiscall vostok::particle::particle_action_initial_color::load_binary(
        vostok::particle::particle_action_initial_color *this,
        vostok::mutable_buffer *buffer)
{
  vostok::particle::curve_line_points<vostok::math::float4_pod,1>::load_binary(&this->m_init_color, buffer);
}
