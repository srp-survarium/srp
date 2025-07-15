void __thiscall vostok::particle::particle_action_billboard::load_binary(
        vostok::particle::particle_action_billboard *this,
        vostok::mutable_buffer *buffer)
{
  vostok::particle::curve_line_ranged_base *p_m_line; // [esp+4h] [ebp-2Ch]

  p_m_line = &this->m_subimage_index.m_line;
  vostok::particle::curve_line_points<float,0>::load_binary(&this->m_subimage_index.m_line.m_upper, buffer);
  vostok::particle::curve_line_points<float,0>::load_binary(&p_m_line->m_lower, buffer);
}
