vostok::animation::mixing::n_ary_tree_weight_event_iterator *__usercall vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator++@<eax>(
        vostok::animation::mixing::n_ary_tree_weight_event_iterator *this@<ecx>,
        int a2@<esi>)
{
  unsigned int m_weight_transition_end_time_in_ms; // eax
  unsigned __int16 m_event_type; // dx
  vostok::animation::mixing::n_ary_tree_animation_node *v5; // [esp-4h] [ebp-18h]
  vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator weight_transition_end_time_calculator; // [esp+0h] [ebp-14h] BYREF

  v5 = *(vostok::animation::mixing::n_ary_tree_animation_node **)a2;
  weight_transition_end_time_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::`vftable';
  weight_transition_end_time_calculator.m_weight_transition_end_time_in_ms = -1;
  weight_transition_end_time_calculator.m_event_type = 0;
  vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::visit(
    &weight_transition_end_time_calculator,
    v5);
  m_weight_transition_end_time_in_ms = weight_transition_end_time_calculator.m_weight_transition_end_time_in_ms;
  m_event_type = weight_transition_end_time_calculator.m_event_type;
  *(_DWORD *)(a2 + 4) = weight_transition_end_time_calculator.m_weight_transition_end_time_in_ms;
  *(_WORD *)(a2 + 8) = m_event_type;
  if ( m_weight_transition_end_time_in_ms == -1 )
  {
    *(_DWORD *)a2 = 0;
    *(_WORD *)(a2 + 8) = 0;
  }
  return (vostok::animation::mixing::n_ary_tree_weight_event_iterator *)a2;
}
