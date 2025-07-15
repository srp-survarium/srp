unsigned int __userpurge vostok::math::curve_line_points<float,0>::save_binary@<eax>(
        vostok::math::curve_line_points<float,0> *this@<eax>,
        vostok::mutable_buffer *buffer@<esi>,
        bool calc_size)
{
  unsigned int v3; // edi

  v3 = 24 * this->num_points;
  if ( !calc_size )
  {
    memcpy((unsigned __int8 *)buffer->m_data, (unsigned __int8 *)this->points.pointer, v3);
    buffer->m_data += v3;
    buffer->m_size -= v3;
  }
  return v3;
}


unsigned int __userpurge vostok::math::curve_line_points<vostok::math::float4_pod,1>::save_binary@<eax>(
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *this@<eax>,
        vostok::mutable_buffer *buffer@<esi>,
        bool calc_size)
{
  unsigned int v3; // edi

  v3 = 72 * this->num_points;
  if ( !calc_size )
  {
    memcpy((unsigned __int8 *)buffer->m_data, (unsigned __int8 *)this->points.pointer, v3);
    buffer->m_data += v3;
    buffer->m_size -= v3;
  }
  return v3;
}
