void __userpurge vostok::animation::mixing::n_ary_tree_weight_event_iterator::n_ary_tree_weight_event_iterator(
        vostok::animation::mixing::n_ary_tree_weight_event_iterator *this@<esi>,
        vostok::animation::mixing::n_ary_tree_animation_node *animation@<eax>,
        unsigned int start_time_in_ms,
        unsigned int initial_event_types)
{
  unsigned int m_weight_transition_end_time_in_ms; // eax
  vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator weight_transition_end_time_calculator; // [esp+0h] [ebp-14h] BYREF

  weight_transition_end_time_calculator.m_event_type = 0;
  this->m_animation = animation;
  weight_transition_end_time_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::`vftable';
  weight_transition_end_time_calculator.m_weight_transition_end_time_in_ms = -1;
  vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::visit(
    &weight_transition_end_time_calculator,
    animation);
  m_weight_transition_end_time_in_ms = weight_transition_end_time_calculator.m_weight_transition_end_time_in_ms;
  this->m_time_in_ms = weight_transition_end_time_calculator.m_weight_transition_end_time_in_ms;
  if ( m_weight_transition_end_time_in_ms == -1 )
  {
    this->m_animation = 0;
    this->m_event_type = 0;
  }
  else if ( initial_event_types )
  {
    this->m_time_in_ms = start_time_in_ms;
    this->m_event_type = 128;
  }
  else
  {
    this->m_event_type = weight_transition_end_time_calculator.m_event_type;
  }
}
