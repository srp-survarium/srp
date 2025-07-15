void __userpurge vostok::animation::mixing::n_ary_tree::update_time_synchronization_group(
        vostok::animation::mixing::n_ary_tree_animation_node *animation_node@<eax>,
        vostok::animation::mixing::n_ary_tree *this,
        char *start_time_in_ms,
        const unsigned int target_time_in_ms)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v5; // esi
  bool are_there_any_weight_transitions; // bl
  unsigned int m_time_synchronization_group_id; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *i; // eax
  unsigned int v9; // [esp+0h] [ebp-10h]
  unsigned int v10; // [esp+0h] [ebp-10h]

  v5 = animation_node;
  are_there_any_weight_transitions = animation_node->m_animation_state->are_there_any_weight_transitions;
  m_time_synchronization_group_id = animation_node->m_time_synchronization_group_id;
  if ( are_there_any_weight_transitions )
  {
LABEL_13:
    vostok::animation::mixing::n_ary_tree::update_synchronization_group_using_integration(
      (vostok::animation::mixing::n_ary_tree_time_scale_calculator *)v5,
      this,
      start_time_in_ms,
      v9);
  }
  else
  {
    if ( m_time_synchronization_group_id != -1 )
    {
      for ( i = animation_node->m_next_time_animation;
            i && i->m_time_synchronization_group_id == m_time_synchronization_group_id;
            i = i->m_next_time_animation )
      {
        if ( i->m_animation_state->are_there_any_weight_transitions )
        {
          are_there_any_weight_transitions = 1;
          goto LABEL_13;
        }
      }
    }
    vostok::animation::mixing::n_ary_tree::update_animation_state(v5, this, (unsigned int)start_time_in_ms, v9);
  }
  if ( m_time_synchronization_group_id != -1 )
  {
    if ( are_there_any_weight_transitions )
      goto LABEL_18;
    while ( 1 )
    {
      v5 = v5->m_next_time_animation;
LABEL_18:
      if ( !v5 || v5->m_time_synchronization_group_id != m_time_synchronization_group_id )
        break;
      if ( !v5->m_animation_state->are_there_any_weight_transitions )
        vostok::animation::mixing::n_ary_tree::update_animation_state(v5, this, (unsigned int)start_time_in_ms, v10);
    }
  }
}
