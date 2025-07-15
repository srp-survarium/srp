void __thiscall vostok::particle::particle_action_initial_color::free_memory(
        vostok::particle::particle_action_initial_color *this,
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *allocator)
{
  vostok::math::curve_line_points<vostok::math::float4_pod,1>::free_memory(allocator, (int)&this->m_init_color);
}
