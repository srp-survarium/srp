void __thiscall vostok::particle::particle_action_light::load_binary(
        vostok::particle::particle_action_light *this,
        vostok::mutable_buffer *buffer)
{
  vostok::math::curve_line_points<float,0> *v3; // ecx
  vostok::math::curve_line_points<float,0> *v4; // ecx
  vostok::math::curve_line_points<float,0> *v5; // ecx
  vostok::math::curve_line_points<float,0> *v6; // ecx
  unsigned int v7; // ecx

  vostok::math::curve_line_ranged_base::load_binary(
    &this->m_radius.m_line,
    buffer,
    (vostok::math::curve_line_points<float,0> *)this);
  vostok::math::curve_line_ranged_base::load_binary(&this->m_attenuation.m_line, buffer, v3);
  vostok::math::curve_line_ranged_base::load_binary(&this->m_intensity.m_line, buffer, v4);
  vostok::math::curve_line_ranged_base::load_binary(&this->m_diffuse_factor.m_line, buffer, v5);
  vostok::math::curve_line_ranged_base::load_binary(&this->m_specular_factor.m_line, buffer, v6);
  this->m_color.points.pointer = (vostok::math::curve_point<vostok::math::float4_pod> *)buffer->m_data;
  v7 = 72 * this->m_color.num_points;
  buffer->m_data += v7;
  buffer->m_size -= v7;
  vostok::math::curve_line_points<vostok::math::float4_pod,1>::recalculate_ranges(
    (vostok::math::curve_line_points<vostok::math::float4_pod,1> *)v7,
    (int)&this->m_color);
}
