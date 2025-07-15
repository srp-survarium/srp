void __userpurge vostok::animation::mixing::n_ary_tree::update_animation_states(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        int a2@<eax>,
        vostok::animation::mixing::n_ary_tree *start_time_in_ms,
        char *target_time_in_ms)
{
  vostok::animation::mixing::n_ary_tree_animation_node *i; // esi
  unsigned int v6; // [esp+0h] [ebp-4h]

  for ( i = *(vostok::animation::mixing::n_ary_tree_animation_node **)(a2 + 8); i; i = i->m_next_time_animation )
  {
    if ( !i->m_time_driving_animation )
      vostok::animation::mixing::n_ary_tree::update_time_synchronization_group(
        i,
        start_time_in_ms,
        target_time_in_ms,
        v6);
  }
}
