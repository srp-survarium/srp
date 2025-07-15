unsigned int __thiscall vostok::particle::particle_action_billboard::save_binary(
        vostok::particle::particle_action_billboard *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  unsigned int v4; // ebx

  v4 = vostok::math::curve_line_ranged_base::save_binary(&this->m_subimage_index.m_line, buffer, calc_size);
  return v4 + vostok::math::curve_line_ranged_base::save_binary(&this->m_movie_start_frame.m_line, buffer, calc_size);
}
