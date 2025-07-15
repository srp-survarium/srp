void __thiscall vostok::particle::particle_action_color_over_lifetime::load_binary(
        vostok::particle::particle_action_color_over_lifetime *this,
        vostok::mutable_buffer *buffer)
{
  unsigned int v2; // eax

  this->m_color_over_life.m_points.pointer = (vostok::particle::color_matrix_point_type *)buffer->m_data;
  v2 = 24 * this->m_color_over_life.m_num_rows * this->m_color_over_life.m_num_columns;
  buffer->m_data += v2;
  buffer->m_size -= v2;
}
