void __userpurge vostok::animation::mixing::n_ary_tree::process_events(
        vostok::animation::mixing::n_ary_tree *this@<eax>,
        unsigned int event_types@<edi>,
        float a3@<xmm4>,
        unsigned int target_time_in_ms)
{
  vostok::animation::mixing::n_ary_tree_animation_node *i; // esi
  vostok::animation::mixing::animation_state *m_animation_state; // eax
  vostok::animation::mixing::n_ary_tree *event_type; // ecx

  for ( i = this->m_weight_root; i; i = i->m_next_weight_animation )
  {
    m_animation_state = i->m_animation_state;
    if ( m_animation_state->event_iterator.m_value.event_time_in_ms == target_time_in_ms )
    {
      event_type = (vostok::animation::mixing::n_ary_tree *)m_animation_state->event_iterator.m_value.event_type;
      if ( ((unsigned int)event_type & event_types) != 0 )
        vostok::animation::mixing::n_ary_tree::process_event(event_type, a3, i, event_types);
    }
  }
}
