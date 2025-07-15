void __userpurge vostok::animation::mixing::n_ary_tree::initialize(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        float a2@<xmm4>,
        vostok::animation::mixing::n_ary_tree *thisa)
{
  vostok::animation::mixing::n_ary_tree *v3; // ebx
  unsigned int m_animations_count; // eax
  vostok::animation::mixing::animation_state **m_animation_events; // esi
  vostok::animation::mixing::animation_state **v6; // edi
  int v7; // eax
  int i; // ecx
  vostok::animation::mixing::animation_state *m_animation_states; // esi
  vostok::animation::mixing::animation_state *j; // edi

  v3 = thisa;
  m_animations_count = thisa->m_animations_count;
  m_animation_events = thisa->m_animation_events;
  v6 = &m_animation_events[m_animations_count];
  LOBYTE(thisa) = 0;
  if ( m_animation_events != v6 )
  {
    v7 = (int)(4 * m_animations_count) >> 2;
    for ( i = 0; v7 != 1; ++i )
      v7 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::animation::mixing::animation_state * *,vostok::animation::mixing::animation_state *,int,event_iterator_predicate>(
      (event_iterator_predicate)v6,
      m_animation_events,
      v6,
      0,
      2 * i,
      (vostok::animation::mixing::animation_state **)thisa);
    stlp_std::priv::__final_insertion_sort<vostok::animation::mixing::animation_state * *,event_iterator_predicate>(
      m_animation_events,
      (event_iterator_predicate)m_animation_events,
      v6,
      0);
  }
  m_animation_states = v3->m_animation_states;
  for ( j = &m_animation_states[v3->m_animations_count]; m_animation_states != j; ++m_animation_states )
  {
    if ( (*(_DWORD *)&m_animation_states->event_iterator.m_value.event_type & 0x80) != 0 )
      vostok::animation::mixing::n_ary_tree::set_object_transform(
        (vostok::animation::mixing::n_ary_tree *)m_animation_states->event_iterator.m_animation_node,
        a2);
  }
}
