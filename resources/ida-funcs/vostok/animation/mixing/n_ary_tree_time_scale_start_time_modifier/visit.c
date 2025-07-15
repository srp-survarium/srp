void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  float m_animation_interval_time; // xmm0_4

  m_animation_interval_time = this->m_animation_interval_time;
  node->m_time_scale_start_time_in_ms = this->m_new_start_time_in_ms;
  node->m_animation_time_before_scale_starts = m_animation_interval_time;
}
