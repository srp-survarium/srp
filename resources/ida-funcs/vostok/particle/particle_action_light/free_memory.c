void __thiscall vostok::particle::particle_action_light::free_memory(
        vostok::particle::particle_action_light *this,
        vostok::math::curve_line_points<float,0> *allocator)
{
  vostok::math::curve_line_ranged_base *v3; // ecx
  vostok::math::curve_line_ranged_base *v4; // ecx
  vostok::math::curve_line_ranged_base *v5; // ecx
  vostok::math::curve_line_ranged_base *v6; // ecx

  vostok::math::curve_line_ranged_base::free_memory(
    (vostok::math::curve_line_ranged_base *)this,
    (int)&this->m_radius,
    allocator);
  vostok::math::curve_line_ranged_base::free_memory(v3, (int)&this->m_attenuation, allocator);
  vostok::math::curve_line_ranged_base::free_memory(v4, (int)&this->m_intensity, allocator);
  vostok::math::curve_line_ranged_base::free_memory(v5, (int)&this->m_diffuse_factor, allocator);
  vostok::math::curve_line_ranged_base::free_memory(v6, (int)&this->m_specular_factor, allocator);
  vostok::math::curve_line_points<vostok::math::float4_pod,1>::free_memory(
    (vostok::math::curve_line_points<vostok::math::float4_pod,1> *)allocator,
    (int)&this->m_color);
}
