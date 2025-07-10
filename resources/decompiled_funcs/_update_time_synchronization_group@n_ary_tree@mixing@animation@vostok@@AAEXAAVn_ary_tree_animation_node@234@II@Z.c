void __userpurge vostok::animation::mixing::n_ary_tree::update_time_synchronization_group(
        vostok::animation::mixing::n_ary_tree_animation_node *animation_node@<eax>,
        float a2@<xmm4>,
        vostok::animation::mixing::n_ary_tree *this,
        unsigned int start_time_in_ms,
        const unsigned int target_time_in_ms)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v5; // esi
  bool are_there_any_weight_transitions; // bl
  unsigned int m_time_synchronization_group_id; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *m_next_time_animation; // eax
  unsigned int v9; // [esp+0h] [ebp-14h]
  unsigned int v10; // [esp+0h] [ebp-14h]

  v5 = animation_node;
  are_there_any_weight_transitions = animation_node->m_animation_state->are_there_any_weight_transitions;
  m_time_synchronization_group_id = animation_node->m_time_synchronization_group_id;
  if ( are_there_any_weight_transitions )
  {
LABEL_18:
    vostok::animation::mixing::n_ary_tree::update_synchronization_group_using_integration(
      v5,
      a2,
      this,
      start_time_in_ms,
      v9);
  }
  else
  {
    if ( m_time_synchronization_group_id != -1 )
    {
      m_next_time_animation = animation_node->m_next_time_animation;
      if ( m_next_time_animation )
      {
        while ( m_next_time_animation->m_time_synchronization_group_id == m_time_synchronization_group_id )
        {
          if ( m_next_time_animation->m_animation_state->are_there_any_weight_transitions )
          {
            are_there_any_weight_transitions = 1;
            goto LABEL_18;
          }
          m_next_time_animation = m_next_time_animation->m_next_time_animation;
          if ( !m_next_time_animation )
            break;
        }
      }
    }
    vostok::animation::mixing::n_ary_tree::update_animation_state(
      v5,
      start_time_in_ms,
      0,
      start_time_in_ms,
      m_time_synchronization_group_id,
      *(float *)&v5,
      this,
      v9);
  }
  if ( m_time_synchronization_group_id != -1 )
  {
    if ( !are_there_any_weight_transitions )
      v5 = v5->m_next_time_animation;
    for ( ; v5; v5 = v5->m_next_time_animation )
    {
      if ( v5->m_time_synchronization_group_id != m_time_synchronization_group_id )
        break;
      if ( !v5->m_animation_state->are_there_any_weight_transitions )
        vostok::animation::mixing::n_ary_tree::update_animation_state(
          v5,
          start_time_in_ms,
          are_there_any_weight_transitions,
          start_time_in_ms,
          m_time_synchronization_group_id,
          *(float *)&v5,
          this,
          v10);
    }
  }
}
