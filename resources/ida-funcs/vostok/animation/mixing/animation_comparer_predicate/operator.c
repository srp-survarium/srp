int __thiscall vostok::animation::mixing::animation_comparer_predicate::operator()(
        vostok::animation::mixing::animation_comparer_predicate *this,
        vostok::animation::mixing::n_ary_tree_animation_node *left,
        vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  unsigned int m_weight_synchronization_group_id; // eax
  unsigned int v5; // ecx
  unsigned int m_time_synchronization_group_id; // eax
  unsigned int v8; // ecx
  bool m_is_time_driving_animation; // al
  vostok::animation::mixing::playback_enum m_playback_type; // eax
  vostok::animation::mixing::playback_enum v11; // ecx
  int v12; // ecx
  unsigned __int8 v13; // al
  unsigned __int8 v14; // bl
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v15; // ecx
  unsigned __int8 v16; // al
  unsigned int m_bones_mask; // eax
  unsigned int v18; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_weight_driving_animation; // eax
  bool v20; // zf
  vostok::animation::mixing::n_ary_tree_animation_node *v21; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v22; // eax
  int v23; // eax
  unsigned __int8 m_unique_animation_id; // al
  unsigned __int8 v25; // cl
  bool m_can_generate_events; // al
  const void *m_animated_object; // eax
  const void *v28; // ecx
  int v29; // eax
  vostok::animation::mixing::animation_comparer_predicate *v30; // [esp+Ch] [ebp-4h]

  m_weight_synchronization_group_id = left->m_weight_synchronization_group_id;
  v5 = right->m_weight_synchronization_group_id;
  v30 = this;
  if ( v5 > m_weight_synchronization_group_id )
    return 1;
  if ( v5 < m_weight_synchronization_group_id )
    return 2;
  m_time_synchronization_group_id = left->m_time_synchronization_group_id;
  v8 = right->m_time_synchronization_group_id;
  if ( v8 > m_time_synchronization_group_id )
    return 1;
  if ( v8 < m_time_synchronization_group_id )
    return 2;
  if ( this->m_use_synchronized_animations )
  {
    m_is_time_driving_animation = left->m_is_time_driving_animation;
    if ( m_is_time_driving_animation )
    {
      if ( !right->m_is_time_driving_animation )
        return 1;
    }
    else if ( !right->m_is_time_driving_animation )
    {
      goto LABEL_12;
    }
    if ( !m_is_time_driving_animation )
      return 2;
  }
LABEL_12:
  m_playback_type = left->m_playback_type;
  v11 = right->m_playback_type;
  if ( v11 > m_playback_type )
    return 1;
  if ( v11 < m_playback_type )
    return 2;
  v12 = -(this->m_animated_object_resolver->vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v12) != 0 )
  {
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)v12,
      &this->m_animated_object_resolver->vtable,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)left->m_animated_object);
    v14 = v13;
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      v15,
      &v30->m_animated_object_resolver->vtable,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)right->m_animated_object);
    if ( v16 > v14 )
      return 1;
    if ( v16 < v14 )
      return 2;
    this = v30;
  }
  else
  {
    m_animated_object = left->m_animated_object;
    v28 = right->m_animated_object;
    if ( v28 > m_animated_object )
      return 1;
    if ( v28 < m_animated_object )
      return 2;
  }
  m_bones_mask = left->m_bones_mask;
  v18 = right->m_bones_mask;
  if ( v18 > m_bones_mask )
    return 1;
  if ( v18 < m_bones_mask )
    return 2;
  if ( this->m_use_synchronized_animations )
  {
    m_weight_driving_animation = left->m_weight_driving_animation;
    v20 = m_weight_driving_animation == 0;
    if ( !m_weight_driving_animation )
    {
      if ( !right->m_weight_driving_animation )
        goto LABEL_30;
      v20 = 1;
    }
    v21 = left->m_weight_driving_animation;
    v22 = right->m_weight_driving_animation;
    if ( v20 )
      v21 = left;
    if ( !v22 )
      v22 = right;
    v23 = vostok::animation::mixing::animation_comparer_predicate::operator()(this, v21, v22) - 1;
    if ( !v23 )
      return 1;
    if ( v23 == 1 )
      return 2;
  }
LABEL_30:
  m_unique_animation_id = left->m_unique_animation_id;
  v25 = right->m_unique_animation_id;
  if ( v25 > m_unique_animation_id )
    return 1;
  if ( v25 < m_unique_animation_id )
    return 2;
  m_can_generate_events = left->m_can_generate_events;
  if ( m_can_generate_events )
  {
    if ( right->m_can_generate_events )
      goto LABEL_40;
  }
  else if ( right->m_can_generate_events )
  {
    return 1;
  }
  if ( m_can_generate_events )
    return 2;
LABEL_40:
  v29 = vostok::animation::mixing::compare_animation_intervals(left, right) - 1;
  if ( !v29 )
    return 1;
  if ( v29 == 1 )
    return 2;
  if ( this->m_use_overriding_animations )
  {
    if ( left->m_override_existing_animation )
    {
      if ( !right->m_override_existing_animation )
        return 2;
    }
    else if ( right->m_override_existing_animation )
    {
      return 1;
    }
  }
  return 0;
}
