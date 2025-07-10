int __thiscall vostok::animation::mixing::animation_comparer_predicate::operator()(
        vostok::animation::mixing::animation_comparer_predicate *this,
        const vostok::animation::mixing::n_ary_tree_animation_node *left,
        const vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  unsigned int m_weight_synchronization_group_id; // eax
  unsigned int v5; // ecx
  unsigned int m_time_synchronization_group_id; // eax
  unsigned int v8; // ecx
  const void *m_animated_object; // eax
  const void *v10; // ecx
  unsigned int m_bones_mask; // eax
  unsigned int v12; // ecx
  vostok::animation::mixing::playback_enum m_playback_type; // eax
  vostok::animation::mixing::playback_enum v14; // ecx
  const vostok::animation::mixing::n_ary_tree_animation_node *m_weight_driving_animation; // ecx
  const vostok::animation::mixing::n_ary_tree_animation_node *v16; // eax
  __int32 v17; // eax
  unsigned __int8 m_unique_animation_id; // al
  unsigned __int8 v19; // cl
  bool m_can_generate_events; // al
  int v21; // eax

  m_weight_synchronization_group_id = left->m_weight_synchronization_group_id;
  v5 = right->m_weight_synchronization_group_id;
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
  m_animated_object = left->m_animated_object;
  v10 = right->m_animated_object;
  if ( v10 > m_animated_object )
    return 1;
  if ( v10 < m_animated_object )
    return 2;
  m_bones_mask = left->m_bones_mask;
  v12 = right->m_bones_mask;
  if ( v12 > m_bones_mask )
    return 1;
  if ( v12 < m_bones_mask )
    return 2;
  m_playback_type = left->m_playback_type;
  v14 = right->m_playback_type;
  if ( v14 > m_playback_type )
    return 1;
  if ( v14 < m_playback_type )
    return 2;
  if ( this->m_use_synchronized_animations )
  {
    if ( left->m_weight_driving_animation )
    {
      m_weight_driving_animation = left->m_weight_driving_animation;
    }
    else
    {
      if ( !right->m_weight_driving_animation )
        goto LABEL_22;
      m_weight_driving_animation = left;
    }
    v16 = right->m_weight_driving_animation;
    if ( !v16 )
      v16 = right;
    v17 = vostok::animation::mixing::animation_comparer_predicate::operator()(this, m_weight_driving_animation, v16) - 1;
    if ( !v17 )
      return 1;
    if ( v17 == 1 )
      return 2;
  }
LABEL_22:
  m_unique_animation_id = left->m_unique_animation_id;
  v19 = right->m_unique_animation_id;
  if ( v19 > m_unique_animation_id )
    return 1;
  if ( v19 < m_unique_animation_id )
    return 2;
  m_can_generate_events = left->m_can_generate_events;
  if ( m_can_generate_events )
  {
    if ( right->m_can_generate_events )
      goto LABEL_29;
  }
  else if ( right->m_can_generate_events )
  {
    return 1;
  }
  if ( m_can_generate_events )
    return 2;
LABEL_29:
  v21 = vostok::animation::mixing::compare_animation_intervals(right, left) - 1;
  if ( !v21 )
    return 1;
  if ( v21 == 1 )
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
