void __cdecl vostok::animation::invert_animation_times(
        vostok::animation::mixing::n_ary_tree_animation_node *animation,
        unsigned int time_in_ms)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v2; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v3; // edi
  vostok::animation::mixing::n_ary_tree_event_iterator *p_event_iterator; // eax
  n_ary_tree_time_inverter time_inverter; // [esp+10h] [ebp-Ch] BYREF

  v2 = animation + 1;
  v3 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)animation + 4 * animation->m_operands_count + 88);
  time_inverter.__vftable = (n_ary_tree_time_inverter_vtbl *)&n_ary_tree_time_inverter::`vftable';
  time_inverter.m_current_time_in_ms = time_in_ms;
  if ( &animation[1] != v3 )
  {
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, n_ary_tree_time_inverter *))v2->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v2->__vftable,
        &time_inverter);
      v2 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v2 + 4);
    }
    while ( v2 != v3 );
  }
  p_event_iterator = &animation->m_animation_state->event_iterator;
  if ( animation->m_animation_state->event_iterator.m_value.event_type )
    animation->m_animation_state->event_iterator.m_value.event_time_in_ms = time_in_ms
                                                                          - animation->m_animation_state->event_iterator.m_value.event_time_in_ms;
  if ( p_event_iterator->m_weight_event_iterator.m_event_type )
    p_event_iterator->m_weight_event_iterator.m_time_in_ms = time_in_ms
                                                           - p_event_iterator->m_weight_event_iterator.m_time_in_ms;
  if ( p_event_iterator->m_animation_event_iterator.m_value.event_type )
    p_event_iterator->m_animation_event_iterator.m_value.event_time_in_ms = time_in_ms
                                                                          - p_event_iterator->m_animation_event_iterator.m_value.event_time_in_ms;
}
