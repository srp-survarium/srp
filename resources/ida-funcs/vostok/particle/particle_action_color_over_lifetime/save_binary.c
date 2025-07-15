unsigned int __thiscall vostok::particle::particle_action_color_over_lifetime::save_binary(
        vostok::particle::particle_action_color_over_lifetime *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  unsigned int v3; // edi

  v3 = 24 * this->m_color_over_life.m_num_rows * this->m_color_over_life.m_num_columns;
  if ( !calc_size )
  {
    memcpy((unsigned __int8 *)buffer->m_data, (unsigned __int8 *)this->m_color_over_life.m_points.pointer, v3);
    buffer->m_data += v3;
    buffer->m_size -= v3;
  }
  return v3;
}
