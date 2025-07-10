vostok::animation::mixing::n_ary_tree_animation_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        int a2@<esi>,
        vostok::animation::mixing::n_ary_tree_animation_node *new_animation,
        const vostok::animation::mixing::animation_state *previous_animation_state,
        unsigned int animation_interval_id,
        float animation_interval_time,
        bool is_new_animation)
{
  unsigned int v8; // edx
  vostok::animation::mixing::n_ary_tree_animation_node *v9; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v10; // ebx
  bool v11; // cl
  int v12; // eax
  float animation_time_threshold; // xmm0_4
  float m_weight; // xmm1_4
  vostok::animation::mixing::n_ary_tree_weight_calculator weight_calculator; // [esp+10h] [ebp-20h] BYREF
  __int16 initial_event_types; // [esp+34h] [ebp+4h]

  **(_DWORD **)(a2 + 116) = *(_DWORD *)(a2 + 100);
  *(_DWORD *)(a2 + 116) += 4;
  initial_event_types = 0;
  if ( is_new_animation )
  {
    initial_event_types = 129;
  }
  else if ( previous_animation_state && !previous_animation_state->are_there_any_weight_transitions )
  {
    initial_event_types = 128;
  }
  v8 = *(_DWORD *)(a2 + 132);
  weight_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_weight_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_calculator::`vftable';
  memset((void *)&weight_calculator.m_animation, 0, 12);
  weight_calculator.m_current_time_in_ms = v8;
  memset(&weight_calculator.m_weight, 0, 9);
  vostok::animation::mixing::n_ary_tree_weight_calculator::visit(&weight_calculator, new_animation);
  v9 = new_animation + 1;
  v10 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)new_animation
                                                               + 4 * new_animation->m_operands_count
                                                               + 88);
  new_animation->m_animation_state = *(vostok::animation::mixing::animation_state **)(a2 + 100);
  if ( &new_animation[1] != v10 )
  {
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v9->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 3))(v9->__vftable);
      v9 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v9 + 4);
    }
    while ( v9 != v10 );
  }
  v11 = previous_animation_state
     && (!previous_animation_state->event_iterator.m_animation_node->m_is_transitting_to_zero
      || new_animation->m_is_transitting_to_zero
      || !previous_animation_state->is_freezed);
  v12 = *(_DWORD *)(a2 + 100);
  if ( v12 )
  {
    if ( v11 )
      animation_time_threshold = previous_animation_state->animation_time_threshold;
    else
      animation_time_threshold = 0.0;
    m_weight = weight_calculator.m_weight;
    *(_DWORD *)v12 = animation_interval_id;
    *(float *)(v12 + 4) = animation_interval_time;
    *(float *)(v12 + 8) = animation_time_threshold;
    *(float *)(v12 + 12) = m_weight;
    *(_WORD *)(v12 + 16) = initial_event_types;
    *(_DWORD *)(v12 + 20) = v11 ? previous_animation_state : 0;
  }
  *(_DWORD *)(a2 + 100) += 180;
  return new_animation;
}
