void __usercall vostok::animation::mixing::n_ary_tree_deserializer::process_animation_states(
        vostok::animation::mixing::n_ary_tree_deserializer *this@<ecx>,
        const unsigned int animations_count@<eax>)
{
  unsigned int v2; // eax
  vostok::animation::mixing::animation_state *m_animation_states; // edi
  vostok::animation::mixing::animation_state *v5; // ebx
  float *m_end; // eax
  float v7; // xmm0_4
  float v8; // xmm0_4
  vostok::animation::mixing::animation_state *v9; // ebx
  unsigned int v10; // [esp+10h] [ebp-8h]
  vostok::animation::mixing::animation_state *i; // [esp+10h] [ebp-8h]
  __int32 v12; // [esp+14h] [ebp-4h] BYREF

  v2 = 176 * animations_count;
  m_animation_states = this->m_animation_states;
  v5 = (vostok::animation::mixing::animation_state *)((char *)m_animation_states + v2);
  v10 = v2;
  if ( m_animation_states != (vostok::animation::mixing::animation_state *)((char *)m_animation_states + v2) )
  {
    do
    {
      if ( m_animation_states != (vostok::animation::mixing::animation_state *)-80 )
        vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
          (vostok::resources::pinned_ptr_mutable<unsigned char> *)this,
          (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&m_animation_states->bone_matrices_computer.pinned_animation,
          0);
      m_animation_states->animation_interval_id = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 1u);
      m_animation_states->previous_animation_interval_id = vostok::animation::mixing::n_ary_tree_deserializer::r(
                                                             this,
                                                             1u);
      m_end = this->m_floats.m_end;
      v7 = *(m_end - 1);
      _InterlockedExchange(&v12, (__int32)m_end);
      --this->m_floats.m_end;
      m_animation_states->animation_interval_time = v7;
      if ( vostok::animation::mixing::n_ary_tree_deserializer::r(this, 1u) )
        v8 = float_max_31;
      else
        v8 = 0.0;
      m_animation_states->animation_time_threshold = v8;
      m_animation_states->is_freezed = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 1u) == 1;
      ++m_animation_states;
    }
    while ( m_animation_states != v5 );
    v2 = v10;
  }
  v9 = this->m_animation_states;
  for ( i = (vostok::animation::mixing::animation_state *)((char *)v9 + v2); v9 != i; ++v9 )
  {
    vostok::animation::mixing::n_ary_tree_deserializer::process_event_iterator(this, this, (__int32)&v9->event_iterator);
    vostok::animation::mixing::n_ary_tree_deserializer::process_event_iterator(
      this,
      &v9->event_iterator.m_weight_event_iterator);
  }
}
