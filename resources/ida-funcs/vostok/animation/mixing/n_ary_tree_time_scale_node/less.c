bool __userpurge vostok::animation::mixing::n_ary_tree_time_scale_node::less@<al>(
        vostok::animation::mixing::n_ary_tree_time_scale_node *this@<edi>,
        const vostok::animation::mixing::n_ary_tree_time_scale_node *other@<esi>,
        const bool compare_dynamic_members)
{
  float m_time_scale; // xmm0_4
  float v4; // xmm1_4
  float m_animation_time_before_scale_starts; // xmm0_4
  float v7; // xmm1_4

  m_time_scale = this->m_time_scale;
  v4 = other->m_time_scale;
  if ( v4 > m_time_scale )
    return 1;
  if ( m_time_scale > v4 )
    return 0;
  if ( vostok::animation::compare(other->m_interpolator) == (const vostok::animation::base_interpolator *)1 )
    return 1;
  if ( vostok::animation::compare(this->m_interpolator) == (const vostok::animation::base_interpolator *)1
    || !compare_dynamic_members )
  {
    return 0;
  }
  m_animation_time_before_scale_starts = this->m_animation_time_before_scale_starts;
  v7 = other->m_animation_time_before_scale_starts;
  if ( v7 > m_animation_time_before_scale_starts )
    return 1;
  if ( m_animation_time_before_scale_starts > v7 )
    return 0;
  return this->m_time_scale_start_time_in_ms < other->m_time_scale_start_time_in_ms;
}
