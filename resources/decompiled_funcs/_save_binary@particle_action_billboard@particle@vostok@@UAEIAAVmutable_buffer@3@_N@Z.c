unsigned int __thiscall vostok::particle::particle_action_billboard::save_binary(
        vostok::particle::particle_action_billboard *this,
        vostok::mutable_buffer *buffer,
        bool calc_size)
{
  unsigned int v3; // esi
  vostok::particle::curve_line_ranged_base *p_m_line; // [esp+8h] [ebp-14h]

  p_m_line = &this->m_subimage_index.m_line;
  v3 = vostok::particle::curve_line_points<float,0>::save_binary(
         &this->m_subimage_index.m_line.m_lower,
         buffer,
         calc_size);
  return v3 + vostok::particle::curve_line_points<float,0>::save_binary(&p_m_line->m_upper, buffer, calc_size);
}
