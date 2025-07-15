unsigned int __thiscall vostok::particle::particle_action_initial_color::save_binary(
        vostok::particle::particle_action_initial_color *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  return vostok::math::curve_line_points<vostok::math::float4_pod,1>::save_binary(
           &this->m_init_color,
           buffer,
           calc_size);
}
