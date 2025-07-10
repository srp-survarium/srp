bool __thiscall animation_less_predicate::operator()(
        animation_less_predicate *this,
        const vostok::animation::mixing::binary_tree_animation_node *left,
        const vostok::animation::mixing::binary_tree_animation_node *right)
{
  unsigned int m_weight_synchronization_group_id; // eax
  unsigned int v4; // ecx
  vostok::animation::mixing::binary_tree_animation_node *m_weight_driving_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v7; // esi
  char v8; // bl
  const vostok::animation::mixing::binary_tree_animation_node *v9; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v10; // eax
  bool v11; // zf
  vostok::animation::mixing::binary_tree_animation_node *v12; // eax
  char v13; // bl
  vostok::animation::mixing::binary_tree_animation_node *v14; // esi
  const vostok::animation::mixing::binary_tree_animation_node *v15; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v16; // eax
  unsigned int m_time_synchronization_group_id; // eax
  unsigned int v18; // ecx
  vostok::animation::mixing::base_lexeme *m_time_driving_animation; // eax
  char v20; // bl
  vostok::animation::mixing::binary_tree_animation_node *v21; // eax
  vostok::animation::mixing::binary_tree_animation_node *v22; // eax
  char v23; // bl
  vostok::animation::mixing::base_lexeme *v24; // eax
  const void *m_animated_object; // eax
  const void *v26; // ecx
  unsigned int m_bones_mask; // eax
  unsigned int v28; // ecx
  vostok::animation::mixing::playback_enum m_playback_type; // eax
  vostok::animation::mixing::playback_enum v30; // ecx
  unsigned __int8 m_unique_animation_id; // al
  unsigned __int8 v32; // cl
  bool m_can_generate_user_defined_events; // al
  bool v34; // cl
  unsigned int m_animation_intervals_count; // eax
  unsigned int v36; // ecx
  vostok::animation::mixing::animation_interval *m_animation_intervals; // esi
  vostok::animation::mixing::animation_interval *v38; // edi
  vostok::animation::mixing::animation_interval *i; // ebp
  vostok::animation::mixing::animation_interval *v40; // ebx
  vostok::animation::mixing::animation_interval *v41; // ebx
  unsigned int m_start_animation_interval_id; // eax
  unsigned int v43; // ecx
  char v44; // [esp+11h] [ebp-9h]
  char v45; // [esp+11h] [ebp-9h]
  char v46; // [esp+11h] [ebp-9h]
  char v47; // [esp+11h] [ebp-9h]
  vostok::animation::mixing::expression v48; // [esp+12h] [ebp-8h] BYREF

  v48.m_lexeme = 0;
  m_weight_synchronization_group_id = left->m_weight_synchronization_group_id;
  v4 = right->m_weight_synchronization_group_id;
  if ( v4 > m_weight_synchronization_group_id )
    return 1;
  if ( v4 < m_weight_synchronization_group_id )
    return 0;
  m_weight_driving_animation = left->m_weight_driving_animation;
  v7 = 0;
  v8 = 1;
  if ( m_weight_driving_animation )
  {
    ++m_weight_driving_animation->m_reference_count;
    v9 = left;
    v7 = m_weight_driving_animation;
LABEL_9:
    v44 = 0;
    goto LABEL_10;
  }
  v10 = right->m_weight_driving_animation;
  v9 = 0;
  v8 = 3;
  if ( !v10 )
    goto LABEL_9;
  ++v10->m_reference_count;
  v9 = v10;
  v44 = 1;
  if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    goto LABEL_9;
LABEL_10:
  if ( (v8 & 2) != 0 )
  {
    v8 &= ~2u;
    if ( v9 )
    {
      v11 = v9->m_reference_count-- == 1;
      if ( v11 )
        ((void (__thiscall *)(const vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v9->~vostok::animation::mixing::binary_tree_base_node)(
          v9,
          0);
    }
  }
  if ( (v8 & 1) != 0 )
  {
    v8 &= ~1u;
    if ( v7 )
    {
      v11 = v7->m_reference_count-- == 1;
      if ( v11 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v7->~vostok::animation::mixing::binary_tree_base_node)(
          v7,
          0);
    }
  }
  if ( v44 )
    return 1;
  v12 = right->m_weight_driving_animation;
  v13 = v8 | 4;
  v14 = 0;
  if ( v12 )
  {
    ++v12->m_reference_count;
    v15 = left;
    v14 = v12;
  }
  else
  {
    v16 = left->m_weight_driving_animation;
    v13 |= 8u;
    v15 = 0;
    if ( v16 )
    {
      ++v16->m_reference_count;
      v15 = v16;
      v45 = 1;
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        goto LABEL_24;
    }
  }
  v45 = 0;
LABEL_24:
  if ( (v13 & 8) != 0 )
  {
    v13 &= ~8u;
    if ( v15 )
    {
      v11 = v15->m_reference_count-- == 1;
      if ( v11 )
        ((void (__thiscall *)(const vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v15->~vostok::animation::mixing::binary_tree_base_node)(
          v15,
          0);
    }
  }
  if ( (v13 & 4) != 0 )
  {
    v13 &= ~4u;
    if ( v14 )
    {
      v11 = v14->m_reference_count-- == 1;
      if ( v11 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v14->~vostok::animation::mixing::binary_tree_base_node)(
          v14,
          0);
    }
  }
  if ( v45 )
    return 0;
  m_time_synchronization_group_id = left->m_time_synchronization_group_id;
  v18 = right->m_time_synchronization_group_id;
  if ( v18 > m_time_synchronization_group_id )
    return 1;
  if ( v18 < m_time_synchronization_group_id )
    return 0;
  m_time_driving_animation = (vostok::animation::mixing::base_lexeme *)left->m_time_driving_animation;
  v20 = v13 | 0x10;
  v48.m_lexeme = 0;
  if ( m_time_driving_animation )
  {
    ++m_time_driving_animation[2].m_buffer;
    v48.m_lexeme = m_time_driving_animation;
LABEL_39:
    v46 = 0;
    goto LABEL_40;
  }
  v21 = right->m_time_driving_animation;
  v20 |= 0x20u;
  v48.m_node.m_object = 0;
  if ( !v21 )
    goto LABEL_39;
  ++v21->m_reference_count;
  v48.m_node.m_object = v21;
  v46 = 1;
  if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    goto LABEL_39;
LABEL_40:
  if ( (v20 & 0x20) != 0 )
  {
    v20 &= ~0x20u;
    vostok::animation::mixing::expression::~expression(&v48);
  }
  if ( (v20 & 0x10) != 0 )
  {
    v20 &= ~0x10u;
    vostok::animation::mixing::expression::~expression((vostok::animation::mixing::expression *)&v48.m_lexeme);
  }
  if ( v46 )
    return 1;
  v22 = right->m_time_driving_animation;
  v23 = v20 | 0x40;
  v48.m_node.m_object = 0;
  if ( v22 )
  {
    ++v22->m_reference_count;
    v48.m_node.m_object = v22;
LABEL_49:
    v47 = 0;
    goto LABEL_50;
  }
  v24 = (vostok::animation::mixing::base_lexeme *)left->m_time_driving_animation;
  v23 |= 0x80u;
  v48.m_lexeme = 0;
  if ( !v24 )
    goto LABEL_49;
  ++v24[2].m_buffer;
  v48.m_lexeme = v24;
  v47 = 1;
  if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    goto LABEL_49;
LABEL_50:
  if ( v23 < 0 )
  {
    v23 &= ~0x80u;
    vostok::animation::mixing::expression::~expression((vostok::animation::mixing::expression *)&v48.m_lexeme);
  }
  if ( (v23 & 0x40) != 0 )
    vostok::animation::mixing::expression::~expression(&v48);
  if ( v47 )
    return 0;
  m_animated_object = left->m_animated_object;
  v26 = right->m_animated_object;
  if ( v26 > m_animated_object )
    return 1;
  if ( v26 < m_animated_object )
    return 0;
  m_bones_mask = left->m_bones_mask;
  v28 = right->m_bones_mask;
  if ( v28 > m_bones_mask )
    return 1;
  if ( v28 < m_bones_mask )
    return 0;
  m_playback_type = left->m_playback_type;
  v30 = right->m_playback_type;
  if ( v30 > m_playback_type )
    return 1;
  if ( v30 < m_playback_type )
    return 0;
  m_unique_animation_id = left->m_unique_animation_id;
  v32 = right->m_unique_animation_id;
  if ( v32 > m_unique_animation_id )
    return 1;
  if ( v32 < m_unique_animation_id )
    return 0;
  m_can_generate_user_defined_events = left->m_can_generate_user_defined_events;
  v34 = right->m_can_generate_user_defined_events;
  if ( (unsigned __int8)v34 > (unsigned __int8)m_can_generate_user_defined_events )
    return 1;
  if ( (unsigned __int8)v34 < (unsigned __int8)m_can_generate_user_defined_events )
    return 0;
  m_animation_intervals_count = left->m_animation_intervals_count;
  v36 = right->m_animation_intervals_count;
  if ( v36 > m_animation_intervals_count )
    return 1;
  if ( v36 < m_animation_intervals_count )
    return 0;
  m_animation_intervals = left->m_animation_intervals;
  v38 = right->m_animation_intervals;
  for ( i = &m_animation_intervals[m_animation_intervals_count]; m_animation_intervals != i; ++v38 )
  {
    v40 = vostok::animation::mixing::animation_interval::animation(v38);
    if ( vostok::animation::mixing::animation_interval::animation(m_animation_intervals)->m_animation.m_object < v40->m_animation.m_object )
      return 1;
    v41 = vostok::animation::mixing::animation_interval::animation(v38);
    if ( v41->m_animation.m_object < vostok::animation::mixing::animation_interval::animation(m_animation_intervals)->m_animation.m_object )
      return 0;
    ++m_animation_intervals;
  }
  m_start_animation_interval_id = left->m_start_animation_interval_id;
  v43 = right->m_start_animation_interval_id;
  if ( m_start_animation_interval_id < v43 )
    return 1;
  if ( m_start_animation_interval_id > v43 )
    return 0;
  return right->m_start_animation_interval_time > left->m_start_animation_interval_time;
}
