void __usercall vostok::math::curve_line_ranged_base::load_binary(
        vostok::math::curve_line_ranged_base *this@<edi>,
        vostok::mutable_buffer *buffer@<esi>,
        vostok::math::curve_line_points<float,0> *a3@<ecx>)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx

  this->m_upper.points.pointer = (vostok::math::curve_point<float> *)buffer->m_data;
  v3 = 24 * this->m_upper.num_points;
  buffer->m_data += v3;
  buffer->m_size -= v3;
  vostok::math::curve_line_points<float,0>::recalculate_ranges(a3, (int)this);
  this->m_lower.points.pointer = (vostok::math::curve_point<float> *)buffer->m_data;
  v4 = 24 * this->m_lower.num_points;
  buffer->m_data += v4;
  buffer->m_size -= v4;
  vostok::math::curve_line_points<float,0>::recalculate_ranges(
    (vostok::math::curve_line_points<float,0> *)v4,
    (int)&this->m_lower);
}
