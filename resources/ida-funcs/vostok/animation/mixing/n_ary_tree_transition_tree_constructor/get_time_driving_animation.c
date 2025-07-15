vostok::animation::mixing::n_ary_tree_animation_node *__fastcall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::get_time_driving_animation(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        unsigned int time_synchronization_group_id)
{
  vostok::animation::mixing::n_ary_tree_animation_node **m_time_driving_animations_begin; // eax
  vostok::animation::mixing::n_ary_tree_animation_node **m_time_driving_animations_end; // ecx

  m_time_driving_animations_begin = this->m_time_driving_animations_begin;
  m_time_driving_animations_end = this->m_time_driving_animations_end;
  if ( m_time_driving_animations_begin == m_time_driving_animations_end )
    return 0;
  while ( (*m_time_driving_animations_begin)->m_time_synchronization_group_id != time_synchronization_group_id )
  {
    if ( ++m_time_driving_animations_begin == m_time_driving_animations_end )
      return 0;
  }
  return *m_time_driving_animations_begin;
}
