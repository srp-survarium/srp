void __userpurge vostok::animation::mixing::n_ary_tree::adjust_animation_events_times(
        const vostok::animation::mixing::n_ary_tree *other@<eax>,
        vostok::animation::mixing::n_ary_tree *this)
{
  vostok::animation::mixing::n_ary_tree *v2; // ecx
  vostok::animation::mixing::animation_state *m_animation_states; // ebx
  vostok::animation::mixing::animation_state *v4; // ebp
  vostok::animation::mixing::animation_state **m_animation_events; // esi
  unsigned int m_animations_count; // eax
  vostok::animation::mixing::animation_state **v7; // edi
  int v8; // eax
  int i; // ecx
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *animation; // [esp+14h] [ebp-Ch]
  vostok::animation::subscribed_channel **channels_head; // [esp+18h] [ebp-8h]
  vostok::animation::mixing::animation_state *e; // [esp+1Ch] [ebp-4h]

  v2 = this;
  m_animation_states = this->m_animation_states;
  v4 = other->m_animation_states;
  e = &m_animation_states[this->m_animations_count];
  if ( m_animation_states != e )
  {
    do
    {
      animation = (vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *)m_animation_states->event_iterator.m_animation_node;
      channels_head = m_animation_states->event_iterator.m_animation_event_iterator.m_channels_head;
      vostok::animation::mixing::bone_matrices_computer_data::operator=(
        &m_animation_states->bone_matrices_computer,
        &v4->bone_matrices_computer,
        animation);
      m_animation_states->animation_interval_id = v4->animation_interval_id;
      m_animation_states->previous_animation_interval_id = v4->previous_animation_interval_id;
      m_animation_states->animation_interval_time = v4->animation_interval_time;
      m_animation_states->weight = v4->weight;
      m_animation_states->animation_time = v4->animation_time;
      m_animation_states->animation_time_threshold = v4->animation_time_threshold;
      m_animation_states->are_there_any_weight_transitions = v4->are_there_any_weight_transitions;
      m_animation_states->is_freezed = v4->is_freezed;
      qmemcpy(&m_animation_states->event_iterator, &v4->event_iterator, sizeof(m_animation_states->event_iterator));
      m_animation_states->event_iterator.m_animation_node = v4->event_iterator.m_animation_node != 0
                                                          ? (vostok::animation::mixing::n_ary_tree_animation_node *)animation
                                                          : 0;
      m_animation_states->event_iterator.m_animation_event_iterator.m_channels_head = channels_head;
      m_animation_states->event_iterator.m_animation_event_iterator.m_animation = v4->event_iterator.m_animation_event_iterator.m_animation != 0
                                                                                ? (vostok::animation::mixing::n_ary_tree_animation_node *)animation
                                                                                : 0;
      m_animation_states->event_iterator.m_weight_event_iterator.m_animation = v4->event_iterator.m_weight_event_iterator.m_animation != 0
                                                                             ? (vostok::animation::mixing::n_ary_tree_animation_node *)animation
                                                                             : 0;
      ++m_animation_states;
      ++v4;
    }
    while ( m_animation_states != e );
    v2 = this;
  }
  m_animation_events = v2->m_animation_events;
  m_animations_count = v2->m_animations_count;
  v7 = &m_animation_events[m_animations_count];
  LOBYTE(this) = 0;
  if ( m_animation_events != v7 )
  {
    v8 = (int)(4 * m_animations_count) >> 2;
    for ( i = 0; v8 != 1; ++i )
      v8 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::animation::mixing::animation_state * *,vostok::animation::mixing::animation_state *,int,event_iterator_predicate>(
      (event_iterator_predicate)v7,
      m_animation_events,
      v7,
      0,
      2 * i,
      (vostok::animation::mixing::animation_state **)this);
    stlp_std::priv::__final_insertion_sort<vostok::animation::mixing::animation_state * *,event_iterator_predicate>(
      m_animation_events,
      (event_iterator_predicate)m_animation_events,
      v7,
      0);
  }
}
