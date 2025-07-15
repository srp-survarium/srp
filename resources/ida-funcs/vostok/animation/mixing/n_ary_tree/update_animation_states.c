void __userpurge vostok::animation::mixing::n_ary_tree::update_animation_states(
        vostok::animation::mixing::n_ary_tree *this@<eax>,
        unsigned int target_time_in_ms@<edi>,
        float a3@<xmm4>,
        vostok::animation::mixing::n_ary_tree *start_time_in_ms)
{
  vostok::animation::mixing::n_ary_tree_animation_node *i; // esi
  unsigned int v5; // [esp+0h] [ebp-8h]

  for ( i = this->m_time_root; i; i = i->m_next_time_animation )
  {
    if ( !i->m_time_driving_animation )
      vostok::animation::mixing::n_ary_tree::update_time_synchronization_group(
        i,
        a3,
        start_time_in_ms,
        target_time_in_ms,
        v5);
  }
}
