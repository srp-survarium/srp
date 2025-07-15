unsigned int __userpurge vostok::math::curve_line_ranged_base::save_binary@<eax>(
        vostok::math::curve_line_ranged_base *this@<edi>,
        vostok::mutable_buffer *buffer@<eax>,
        bool calc_size)
{
  unsigned int v4; // ebx

  v4 = vostok::math::curve_line_points<float,0>::save_binary(&this->m_lower, buffer, calc_size);
  return v4 + vostok::math::curve_line_points<float,0>::save_binary(&this->m_upper, buffer, calc_size);
}
