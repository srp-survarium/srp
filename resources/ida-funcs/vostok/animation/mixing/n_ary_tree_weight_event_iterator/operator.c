vostok::animation::mixing::n_ary_tree_weight_event_iterator *__usercall vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator++@<eax>(
        vostok::animation::mixing::n_ary_tree_weight_event_iterator *this@<ecx>,
        int a2@<esi>)
{
  unsigned int m_weight_transition_end_time_in_ms; // eax
  unsigned __int16 m_event_type; // cx
  vostok::animation::mixing::n_ary_tree_animation_node *v5; // [esp-4h] [ebp-14h]
  vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator v6; // [esp+0h] [ebp-10h] BYREF

  v5 = *(vostok::animation::mixing::n_ary_tree_animation_node **)a2;
  v6.m_weight_transition_end_time_in_ms = -1;
  v6.__vftable = (vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::`vftable';
  v6.m_event_type = 0;
  vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::visit(&v6, v5);
  m_weight_transition_end_time_in_ms = v6.m_weight_transition_end_time_in_ms;
  m_event_type = v6.m_event_type;
  *(_DWORD *)(a2 + 4) = v6.m_weight_transition_end_time_in_ms;
  *(_WORD *)(a2 + 8) = m_event_type;
  if ( m_weight_transition_end_time_in_ms == -1 )
  {
    *(_DWORD *)a2 = 0;
    *(_WORD *)(a2 + 8) = 0;
  }
  return (vostok::animation::mixing::n_ary_tree_weight_event_iterator *)a2;
}
