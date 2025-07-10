void __userpurge vostok::animation::mixing::n_ary_tree::update_event_iterators(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        int a2@<esi>,
        vostok::animation::mixing::n_ary_tree_event_iterator *target_time_in_ms)
{
  int v3; // eax
  vostok::animation::mixing::n_ary_tree_event_iterator *v4; // ecx
  int v5; // edi
  unsigned int m_weight_transition_end_time_in_ms; // eax
  vostok::animation::mixing::animation_state **v7; // edi
  unsigned __int8 *v8; // eax
  vostok::animation::mixing::animation_state *v9; // ebp
  int *v10; // edx
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // [esp-4h] [ebp-24h]
  vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator v12; // [esp+10h] [ebp-10h] BYREF

  v3 = **(_DWORD **)(a2 + 20);
  v4 = target_time_in_ms;
  if ( *(vostok::animation::mixing::n_ary_tree_event_iterator **)(v3 + 164) == target_time_in_ms )
  {
    do
    {
      v5 = v3 + 120;
      if ( (*(_BYTE *)(v3 + 176) & 1) != 0 )
        vostok::animation::mixing::n_ary_tree_animation_event_iterator::advance(&v4->m_animation_event_iterator, v5, 0);
      if ( (*(_BYTE *)(v5 + 56) & 2) != 0 )
      {
        v11 = *(vostok::animation::mixing::n_ary_tree_animation_node **)(v5 + 24);
        v12.__vftable = (vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::`vftable';
        v12.m_weight_transition_end_time_in_ms = -1;
        v12.m_event_type = 0;
        vostok::animation::mixing::n_ary_tree_weight_transition_end_time_calculator::visit(&v12, v11);
        m_weight_transition_end_time_in_ms = v12.m_weight_transition_end_time_in_ms;
        LOWORD(v4) = v12.m_event_type;
        *(_DWORD *)(v5 + 28) = v12.m_weight_transition_end_time_in_ms;
        *(_WORD *)(v5 + 32) = (_WORD)v4;
        if ( m_weight_transition_end_time_in_ms == -1 )
        {
          *(_DWORD *)(v5 + 24) = 0;
          *(_WORD *)(v5 + 32) = 0;
        }
      }
      vostok::animation::mixing::n_ary_tree_event_iterator::select_state(v4, v5);
      v7 = stlp_std::priv::__lower_bound<vostok::animation::mixing::animation_state * *,vostok::animation::mixing::animation_state *,event_iterator_predicate,event_iterator_predicate,int>(
             (vostok::animation::mixing::animation_state **)(*(_DWORD *)(a2 + 20) + 4),
             (vostok::animation::mixing::animation_state **)(*(_DWORD *)(a2 + 20) + 4 * *(_DWORD *)(a2 + 28)),
             *(vostok::animation::mixing::animation_state *const **)(a2 + 20));
      v8 = *(unsigned __int8 **)(a2 + 20);
      v9 = *(vostok::animation::mixing::animation_state **)v8;
      if ( v7 != (vostok::animation::mixing::animation_state **)(v8 + 4) )
        memmove(v8, v8 + 4, (char *)v7 - (char *)(v8 + 4));
      v4 = target_time_in_ms;
      *(v7 - 1) = v9;
      v10 = *(int **)(a2 + 20);
      v3 = *v10;
    }
    while ( *(vostok::animation::mixing::n_ary_tree_event_iterator **)(*v10 + 164) == target_time_in_ms );
  }
}
