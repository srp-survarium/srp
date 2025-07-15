unsigned int __userpurge vostok::animation::mixing::n_ary_tree_animation_event_iterator::get_time_in_ms@<eax>(
        vostok::animation::mixing::n_ary_tree_animation_event_iterator *this@<eax>,
        unsigned __int16 *event_type@<edi>,
        unsigned int start_time_in_ms,
        float time_from_interval_start,
        float *event_time)
{
  vostok::animation::mixing::n_ary_tree_animation_node *m_animation; // eax
  unsigned __int16 m_event_type; // dx
  unsigned int result; // eax
  vostok::animation::mixing::n_ary_tree_time_in_ms_calculator time_in_ms_calculator; // [esp+10h] [ebp-1Ch] BYREF

  m_animation = this->m_animation;
  if ( m_animation->m_time_driving_animation )
    m_animation = m_animation->m_time_driving_animation;
  vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::n_ary_tree_time_in_ms_calculator(
    &time_in_ms_calculator,
    m_animation,
    *event_type,
    start_time_in_ms,
    time_from_interval_start,
    *event_time);
  m_event_type = time_in_ms_calculator.m_event_type;
  result = time_in_ms_calculator.m_time_in_ms;
  *event_time = time_in_ms_calculator.m_event_time;
  *event_type = m_event_type;
  return result;
}
