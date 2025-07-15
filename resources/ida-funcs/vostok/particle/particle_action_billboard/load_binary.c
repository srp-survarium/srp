void __thiscall vostok::particle::particle_action_billboard::load_binary(
        vostok::particle::particle_action_billboard *this,
        vostok::mutable_buffer *buffer)
{
  vostok::math::curve_line_points<float,0> *v3; // ecx

  vostok::math::curve_line_ranged_base::load_binary(
    &this->m_subimage_index.m_line,
    buffer,
    (vostok::math::curve_line_points<float,0> *)this);
  vostok::math::curve_line_ranged_base::load_binary(&this->m_movie_start_frame.m_line, buffer, v3);
}
