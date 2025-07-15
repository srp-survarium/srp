void __userpurge vostok::animation::mixing::n_ary_tree::process_events(
        unsigned __int16 event_types@<ax>,
        vostok::animation::mixing::n_ary_tree *this,
        vostok::animation::mixing::n_ary_tree_animation_node **target_time_in_ms)
{
  vostok::animation::mixing::n_ary_tree_animation_node *m_weight_root; // esi
  vostok::animation::mixing::animation_state *m_animation_state; // eax
  vostok::animation::mixing::n_ary_tree *event_time_in_ms; // ecx
  bool v9; // zf
  void *v10; // esp
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // eax
  vostok::animation::mixing::n_ary_tree_animation_node **v12; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *i; // eax
  vostok::animation::mixing::n_ary_tree_animation_node **v14; // eax
  int v15; // edx
  int v16; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v17; // [esp+0h] [ebp-10h] BYREF
  _BYTE v18[12]; // [esp+4h] [ebp-Ch] BYREF
  char v19; // [esp+1Bh] [ebp+Bh]

  m_weight_root = this->m_weight_root;
  v19 = 0;
  if ( m_weight_root )
  {
    do
    {
      m_animation_state = m_weight_root->m_animation_state;
      event_time_in_ms = (vostok::animation::mixing::n_ary_tree *)m_animation_state->event_iterator.m_value.event_time_in_ms;
      if ( event_time_in_ms == (vostok::animation::mixing::n_ary_tree *)target_time_in_ms
        && (m_animation_state->event_iterator.m_value.event_type & event_types) != 0 )
      {
        if ( vostok::animation::mixing::n_ary_tree::process_event(event_time_in_ms, m_weight_root, event_types)
          || (v9 = v19 == 0, v19 = 0, !v9) )
        {
          v19 = 1;
        }
      }
      m_weight_root = m_weight_root->m_next_weight_animation;
    }
    while ( m_weight_root );
    if ( v19 )
    {
      v10 = alloca(4 * this->m_animations_count);
      v11 = this->m_weight_root;
      v12 = &v17;
      while ( v11 )
      {
        *v12 = v11;
        v11 = v11->m_next_weight_animation;
        ++v12;
      }
      LOBYTE(target_time_in_ms) = 0;
      stlp_std::sort<vostok::animation::mixing::n_ary_tree_animation_node * *,vostok::animation::mixing::time_animations_predicate>(
        &v17,
        v12,
        target_time_in_ms);
      for ( i = this->m_weight_root; i; i = i->m_next_weight_animation )
        i->m_next_time_animation = 0;
      this->m_time_root = v17;
      v14 = (vostok::animation::mixing::n_ary_tree_animation_node **)v18;
      if ( v18 != (_BYTE *)v12 )
      {
        do
        {
          v15 = (int)*(v14 - 1);
          v16 = (int)*v14++;
          *(_DWORD *)(v15 + 44) = v16;
        }
        while ( v14 != v12 );
      }
    }
  }
}
