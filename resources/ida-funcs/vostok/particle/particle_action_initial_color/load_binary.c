void __thiscall vostok::particle::particle_action_initial_color::load_binary(
        vostok::particle::particle_action_initial_color *this,
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *buffer)
{
  unsigned int v2; // edx

  this->m_init_color.points.pointer = (vostok::math::curve_point<vostok::math::float4_pod> *)LODWORD(buffer->curve_time_min);
  v2 = 72 * this->m_init_color.num_points;
  LODWORD(buffer->curve_time_min) += v2;
  LODWORD(buffer->curve_time_max) -= v2;
  vostok::math::curve_line_points<vostok::math::float4_pod,1>::recalculate_ranges(buffer, (int)&this->m_init_color);
}
