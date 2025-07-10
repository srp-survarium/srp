void __thiscall vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  float m_time_scale; // xmm0_4
  float m_target_animation_time; // xmm1_4
  unsigned int m_start_time_in_ms; // ebx
  unsigned int m_time_scale_start_time_in_ms; // edi

  m_time_scale = node->m_time_scale;
  if ( m_time_scale == 0.0 )
  {
    this->m_time_in_ms = -1;
  }
  else
  {
    m_target_animation_time = this->m_target_animation_time;
    m_start_time_in_ms = this->m_start_time_in_ms;
    m_time_scale_start_time_in_ms = node->m_time_scale_start_time_in_ms;
    if ( m_time_scale_start_time_in_ms <= m_start_time_in_ms )
      this->m_time_in_ms = m_start_time_in_ms
                         + vostok::math::floor(
                             (float)((float)(m_target_animation_time - this->m_start_animation_time) / m_time_scale)
                           * 1000.0);
    else
      this->m_time_in_ms = m_time_scale_start_time_in_ms
                         + vostok::math::floor(
                             (float)((float)(m_target_animation_time - node->m_animation_time_before_scale_starts)
                                   / m_time_scale)
                           * 1000.0);
  }
}
