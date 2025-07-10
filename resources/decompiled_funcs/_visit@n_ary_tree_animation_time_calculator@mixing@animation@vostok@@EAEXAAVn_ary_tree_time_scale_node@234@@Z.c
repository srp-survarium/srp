void __thiscall vostok::animation::mixing::n_ary_tree_animation_time_calculator::visit(
        vostok::animation::mixing::n_ary_tree_animation_time_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  float v3; // xmm0_4
  float m_animation_interval_length; // xmm1_4
  float nodea; // [esp+18h] [ebp+4h]

  nodea = vostok::animation::mixing::n_ary_tree_animation_time_calculator::computed_animation_time(
            this,
            this->m_target_time_in_ms,
            node->m_animation_time_before_scale_starts,
            node->m_time_scale_start_time_in_ms,
            this->m_start_time_in_ms,
            node->m_time_scale);
  v3 = nodea;
  this->m_animation_time = nodea;
  if ( nodea <= 0.0 )
    v3 = 0.0;
  m_animation_interval_length = this->m_animation_interval_length;
  if ( m_animation_interval_length <= v3 )
    this->m_animation_time = m_animation_interval_length;
  else
    this->m_animation_time = v3;
}
