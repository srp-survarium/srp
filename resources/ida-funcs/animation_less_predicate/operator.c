bool __userpurge animation_less_predicate::operator()@<al>(
        const vostok::animation::mixing::binary_tree_animation_node *left@<esi>,
        const vostok::animation::mixing::binary_tree_animation_node *right@<edi>,
        animation_less_predicate *this)
{
  unsigned int m_weight_synchronization_group_id; // eax
  unsigned int v4; // ecx
  vostok::animation::mixing::binary_tree_animation_node *m_weight_driving_animation; // eax
  char v7; // bl
  animation_less_predicate *v8; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v9; // eax
  bool v10; // zf
  vostok::animation::mixing::binary_tree_animation_node *v11; // eax
  char v12; // bl
  animation_less_predicate *v13; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v14; // eax
  unsigned int m_time_synchronization_group_id; // eax
  unsigned int v16; // ecx
  vostok::animation::mixing::binary_tree_animation_node *m_time_driving_animation; // eax
  char v18; // bl
  animation_less_predicate *v19; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v20; // eax
  vostok::animation::mixing::binary_tree_animation_node *v21; // eax
  char v22; // bl
  animation_less_predicate *v23; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v24; // eax
  vostok::animation::mixing::playback_enum m_playback_type; // eax
  vostok::animation::mixing::playback_enum v26; // ecx
  int v27; // ecx
  unsigned __int8 v28; // al
  unsigned __int8 v29; // bl
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v30; // ecx
  unsigned __int8 v31; // al
  bool v32; // cf
  unsigned int m_bones_mask; // eax
  unsigned int v34; // ecx
  unsigned __int8 m_unique_animation_id; // al
  unsigned __int8 v36; // cl
  bool m_can_generate_user_defined_events; // al
  bool v38; // cl
  unsigned int m_animation_intervals_count; // eax
  unsigned int v40; // ecx
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // ecx
  unsigned int *p_m_animation_id; // ebx
  unsigned int m_animation_id; // eax
  unsigned int m_start_animation_interval_id; // eax
  unsigned int v45; // ecx
  const void *m_animated_object; // eax
  const void *v47; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v48; // [esp+4h] [ebp-8h]
  vostok::animation::mixing::binary_tree_animation_node *v49; // [esp+4h] [ebp-8h]
  vostok::animation::mixing::binary_tree_animation_node *v50; // [esp+4h] [ebp-8h]
  vostok::animation::mixing::binary_tree_animation_node *v51; // [esp+4h] [ebp-8h]
  char v52; // [esp+Bh] [ebp-1h]
  char v53; // [esp+Bh] [ebp-1h]
  char v54; // [esp+Bh] [ebp-1h]
  char v55; // [esp+Bh] [ebp-1h]
  const vostok::animation::mixing::animation_interval *v56; // [esp+14h] [ebp+8h]

  m_weight_synchronization_group_id = left->m_weight_synchronization_group_id;
  v4 = right->m_weight_synchronization_group_id;
  if ( v4 > m_weight_synchronization_group_id )
    return 1;
  if ( v4 < m_weight_synchronization_group_id )
    return 0;
  m_weight_driving_animation = left->m_weight_driving_animation;
  v48 = 0;
  v7 = 1;
  if ( m_weight_driving_animation )
  {
    ++m_weight_driving_animation->m_reference_count;
    v8 = this;
    v48 = m_weight_driving_animation;
LABEL_9:
    v52 = 0;
    goto LABEL_10;
  }
  v9 = right->m_weight_driving_animation;
  v8 = 0;
  v7 = 3;
  if ( !v9 )
    goto LABEL_9;
  ++v9->m_reference_count;
  v8 = (animation_less_predicate *)v9;
  v52 = 1;
  if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    goto LABEL_9;
LABEL_10:
  if ( (v7 & 2) != 0 )
  {
    v7 &= ~2u;
    if ( v8 )
    {
      v10 = v8[4].m_animated_object_resolver-- == (const boost::function<unsigned char __cdecl(void const *)> *)1;
      if ( v10 )
        ((void (__thiscall *)(animation_less_predicate *, _DWORD))v8->m_animated_object_resolver->vtable)(v8, 0);
    }
  }
  if ( (v7 & 1) != 0 )
  {
    v7 &= ~1u;
    if ( v48 )
    {
      v10 = v48->m_reference_count-- == 1;
      if ( v10 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v48->~vostok::animation::mixing::binary_tree_base_node)(
          v48,
          0);
    }
  }
  if ( v52 )
    return 1;
  v11 = right->m_weight_driving_animation;
  v49 = 0;
  v12 = v7 | 4;
  if ( v11 )
  {
    ++v11->m_reference_count;
    v13 = this;
    v49 = v11;
LABEL_23:
    v53 = 0;
    goto LABEL_24;
  }
  v14 = left->m_weight_driving_animation;
  v12 |= 8u;
  v13 = 0;
  if ( !v14 )
    goto LABEL_23;
  ++v14->m_reference_count;
  v13 = (animation_less_predicate *)v14;
  v53 = 1;
  if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    goto LABEL_23;
LABEL_24:
  if ( (v12 & 8) != 0 )
  {
    v12 &= ~8u;
    if ( v13 )
    {
      v10 = v13[4].m_animated_object_resolver-- == (const boost::function<unsigned char __cdecl(void const *)> *)1;
      if ( v10 )
        ((void (__thiscall *)(animation_less_predicate *, _DWORD))v13->m_animated_object_resolver->vtable)(v13, 0);
    }
  }
  if ( (v12 & 4) != 0 )
  {
    v12 &= ~4u;
    if ( v49 )
    {
      v10 = v49->m_reference_count-- == 1;
      if ( v10 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v49->~vostok::animation::mixing::binary_tree_base_node)(
          v49,
          0);
    }
  }
  if ( v53 )
    return 0;
  m_time_synchronization_group_id = left->m_time_synchronization_group_id;
  v16 = right->m_time_synchronization_group_id;
  if ( v16 > m_time_synchronization_group_id )
    return 1;
  if ( v16 < m_time_synchronization_group_id )
    return 0;
  m_time_driving_animation = left->m_time_driving_animation;
  v50 = 0;
  v18 = v12 | 0x10;
  if ( m_time_driving_animation )
  {
    ++m_time_driving_animation->m_reference_count;
    v19 = this;
    v50 = m_time_driving_animation;
LABEL_39:
    v54 = 0;
    goto LABEL_40;
  }
  v20 = right->m_time_driving_animation;
  v18 |= 0x20u;
  v19 = 0;
  if ( !v20 )
    goto LABEL_39;
  ++v20->m_reference_count;
  v19 = (animation_less_predicate *)v20;
  v54 = 1;
  if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    goto LABEL_39;
LABEL_40:
  if ( (v18 & 0x20) != 0 )
  {
    v18 &= ~0x20u;
    if ( v19 )
    {
      v10 = v19[4].m_animated_object_resolver-- == (const boost::function<unsigned char __cdecl(void const *)> *)1;
      if ( v10 )
        ((void (__thiscall *)(animation_less_predicate *, _DWORD))v19->m_animated_object_resolver->vtable)(v19, 0);
    }
  }
  if ( (v18 & 0x10) != 0 )
  {
    v18 &= ~0x10u;
    if ( v50 )
    {
      v10 = v50->m_reference_count-- == 1;
      if ( v10 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v50->~vostok::animation::mixing::binary_tree_base_node)(
          v50,
          0);
    }
  }
  if ( v54 )
    return 1;
  v21 = right->m_time_driving_animation;
  v51 = 0;
  v22 = v18 | 0x40;
  if ( v21 )
  {
    ++v21->m_reference_count;
    v23 = this;
    v51 = v21;
LABEL_53:
    v55 = 0;
    goto LABEL_54;
  }
  v24 = left->m_time_driving_animation;
  v22 |= 0x80u;
  v23 = 0;
  if ( !v24 )
    goto LABEL_53;
  ++v24->m_reference_count;
  v23 = (animation_less_predicate *)v24;
  v55 = 1;
  if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    goto LABEL_53;
LABEL_54:
  if ( v22 < 0 )
  {
    v22 &= ~0x80u;
    if ( v23 )
    {
      v10 = v23[4].m_animated_object_resolver-- == (const boost::function<unsigned char __cdecl(void const *)> *)1;
      if ( v10 )
        ((void (__thiscall *)(animation_less_predicate *, _DWORD))v23->m_animated_object_resolver->vtable)(v23, 0);
    }
  }
  if ( (v22 & 0x40) != 0 && v51 )
  {
    v10 = v51->m_reference_count-- == 1;
    if ( v10 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v51->~vostok::animation::mixing::binary_tree_base_node)(
        v51,
        0);
  }
  if ( v55 )
    return 0;
  m_playback_type = left->m_playback_type;
  v26 = right->m_playback_type;
  if ( v26 > m_playback_type )
    return 1;
  if ( v26 < m_playback_type )
    return 0;
  v27 = -(this->m_animated_object_resolver->vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v27) != 0 )
  {
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)v27,
      &this->m_animated_object_resolver->vtable,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)left->m_animated_object);
    v29 = v28;
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      v30,
      &this->m_animated_object_resolver->vtable,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)right->m_animated_object);
    v32 = v31 < v29;
    if ( v31 > v29 )
      return 1;
  }
  else
  {
    m_animated_object = left->m_animated_object;
    v47 = right->m_animated_object;
    v32 = v47 < m_animated_object;
    if ( v47 > m_animated_object )
      return 1;
  }
  if ( v32 )
    return 0;
  m_bones_mask = left->m_bones_mask;
  v34 = right->m_bones_mask;
  if ( v34 > m_bones_mask )
    return 1;
  if ( v34 < m_bones_mask )
    return 0;
  m_unique_animation_id = left->m_unique_animation_id;
  v36 = right->m_unique_animation_id;
  if ( v36 > m_unique_animation_id )
    return 1;
  if ( v36 < m_unique_animation_id )
    return 0;
  m_can_generate_user_defined_events = left->m_can_generate_user_defined_events;
  v38 = right->m_can_generate_user_defined_events;
  if ( (unsigned __int8)v38 > (unsigned __int8)m_can_generate_user_defined_events )
    return 1;
  if ( (unsigned __int8)v38 < (unsigned __int8)m_can_generate_user_defined_events )
    return 0;
  m_animation_intervals_count = left->m_animation_intervals_count;
  v40 = right->m_animation_intervals_count;
  if ( v40 > m_animation_intervals_count )
    return 1;
  if ( v40 < m_animation_intervals_count )
    return 0;
  m_animation_intervals = left->m_animation_intervals;
  v56 = &m_animation_intervals[m_animation_intervals_count];
  if ( m_animation_intervals != v56 )
  {
    p_m_animation_id = &right->m_animation_intervals->m_animation_id;
    do
    {
      m_animation_id = m_animation_intervals->m_animation_id;
      if ( *p_m_animation_id > m_animation_id )
        return 1;
      if ( *p_m_animation_id < m_animation_id )
        return 0;
      ++m_animation_intervals;
      p_m_animation_id += 5;
    }
    while ( m_animation_intervals != v56 );
  }
  m_start_animation_interval_id = left->m_start_animation_interval_id;
  v45 = right->m_start_animation_interval_id;
  if ( m_start_animation_interval_id < v45 )
    return 1;
  if ( m_start_animation_interval_id > v45 )
    return 0;
  return right->m_start_animation_interval_time > left->m_start_animation_interval_time;
}
