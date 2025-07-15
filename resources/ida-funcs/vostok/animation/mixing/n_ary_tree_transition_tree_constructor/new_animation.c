vostok::animation::mixing::n_ary_tree_animation_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation@<eax>(
        vostok::animation::mixing::n_ary_tree_animation_node *to@<ecx>,
        unsigned int *operands_offset@<eax>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        const vostok::animation::mixing::animation_state *from,
        vostok::animation::mixing::n_ary_tree_animation_node *weight_driving_animation,
        unsigned int weight_operands_count,
        unsigned int *time_scale_operands_count,
        unsigned int *animation_interval_id,
        float *animation_interval_time,
        bool is_transitting_to_zero,
        float can_be_time_driving_animation)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v12; // esi
  bool m_override_existing_animation; // al
  vostok::animation::mixing::n_ary_tree_animation_node *v15; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v16; // eax
  bool v17; // zf
  vostok::animation::mixing::animation_interval *m_animation_intervals; // edi
  vostok::animation::mixing::animation_interval *v19; // ebx
  char *m_data; // ecx
  vostok::animation::mixing::animation_interval *v21; // eax
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v23; // ebx
  unsigned int m_animation_intervals_count; // edi
  const vostok::animation::base_interpolator *v25; // eax
  vostok::mutable_buffer *v26; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_driving_animation; // ecx
  const vostok::animation::mixing::animation_interval *v28; // esi
  const vostok::animation::mixing::animation_interval *v29; // edi
  unsigned int v30; // eax
  vostok::animation::mixing::animation_interval *v31; // edi
  double v32; // st7
  bool v33; // cl
  vostok::animation::mixing::n_ary_tree_animation_node *v34; // eax
  vostok::animation::mixing::animated_object_holder *m_new_animated_object; // esi
  vostok::animation::mixing::animated_object_holder *m_animated_objects; // ecx
  const vostok::animation::mixing::n_ary_tree *m_from; // eax
  vostok::animation::mixing::animated_object_holder *v38; // ecx
  vostok::animation::mixing::animated_object_holder *v39; // esi
  vostok::animation::mixing::animated_object_holder *v40; // eax
  const void *v42; // [esp-28h] [ebp-98h]
  vostok::animation::mixing::playback_enum m_playback_type; // [esp-24h] [ebp-94h]
  unsigned int m_time_synchronization_group_id; // [esp-1Ch] [ebp-8Ch]
  unsigned int m_weight_synchronization_group_id; // [esp-18h] [ebp-88h]
  bool v46; // [esp-14h] [ebp-84h]
  bool m_can_generate_events; // [esp-Ch] [ebp-7Ch]
  unsigned int m_additivity_priority; // [esp-8h] [ebp-78h]
  unsigned int m_bones_mask; // [esp-4h] [ebp-74h]
  float start_time; // [esp+0h] [ebp-70h]
  unsigned int start_timea; // [esp+0h] [ebp-70h]
  float length; // [esp+4h] [ebp-6Ch]
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *time_scale_node; // [esp+1Ch] [ebp-54h]
  vostok::animation::mixing::animation_interval *v54; // [esp+20h] [ebp-50h]
  unsigned int start_cycle_animation_interval_id; // [esp+28h] [ebp-48h]
  unsigned __int8 unique_animation_id; // [esp+2Ch] [ebp-44h]
  vostok::math::float4x4 result; // [esp+30h] [ebp-40h] BYREF
  const vostok::animation::mixing::animation_interval *cloned_intervals_begin; // [esp+74h] [ebp+4h]
  const vostok::animation::mixing::animation_state *time_driving_animation_state; // [esp+78h] [ebp+8h]

  v12 = to;
  m_override_existing_animation = to->m_override_existing_animation;
  if ( m_override_existing_animation
    || (v15 = (vostok::animation::mixing::n_ary_tree_animation_node *)from,
        *(_BYTE *)(LODWORD(from->bone_matrices_computer.previous_object_movement.scale.x) + 117)) )
  {
    v15 = v12;
  }
  *animation_interval_id = v15->m_animation_state->animation_interval_id;
  if ( m_override_existing_animation
    || (v16 = (vostok::animation::mixing::n_ary_tree_animation_node *)from,
        *(_BYTE *)(LODWORD(from->bone_matrices_computer.previous_object_movement.scale.x) + 117)) )
  {
    v16 = v12;
  }
  v17 = LOBYTE(can_be_time_driving_animation) == 0;
  *animation_interval_time = v16->m_animation_state->animation_interval_time;
  *operands_offset = 0;
  time_scale_node = 0;
  if ( !v17 && !v12->m_time_driving_animation && v12->m_time_synchronization_group_id != -1 )
  {
    time_scale_node = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale(
                        (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)animation_interval_id,
                        (int)this,
                        v12,
                        *(float *)&animation_interval_id,
                        (vostok::animation::mixing::n_ary_tree_base_node *)animation_interval_time);
    if ( time_scale_node )
    {
      *time_scale_operands_count = 1;
      *operands_offset = 1;
    }
  }
  m_animation_intervals = v12->m_animation_intervals;
  v19 = &m_animation_intervals[v12->m_animation_intervals_count];
  m_data = this->m_buffer->m_data;
  cloned_intervals_begin = (const vostok::animation::mixing::animation_interval *)m_data;
  if ( m_animation_intervals != v19 )
  {
    do
    {
      v54 = (vostok::animation::mixing::animation_interval *)this->m_buffer->m_data;
      if ( v54 )
      {
        length = vostok::animation::mixing::animation_interval::length(m_animation_intervals);
        start_time = vostok::animation::mixing::animation_interval::start_time(m_animation_intervals);
        v21 = vostok::animation::mixing::animation_interval::animation(m_animation_intervals);
        vostok::animation::mixing::animation_interval::animation_interval(v54, &v21->m_animation, start_time, length);
      }
      m_buffer = this->m_buffer;
      m_buffer->m_data += 12;
      m_buffer->m_size -= 12;
      ++m_animation_intervals;
    }
    while ( m_animation_intervals != v19 );
    m_data = (char *)cloned_intervals_begin;
  }
  v23 = (vostok::animation::mixing::n_ary_tree_animation_node *)this->m_buffer->m_data;
  if ( weight_driving_animation )
  {
    if ( v23 )
      vostok::animation::mixing::n_ary_tree_animation_node::n_ary_tree_animation_node(
        weight_driving_animation,
        (const vostok::animation::mixing::animation_interval *)&m_data[12 * v12->m_animation_intervals_count],
        v23,
        (const vostok::animation::mixing::animation_interval *)m_data,
        v12->m_unique_animation_id,
        v12->m_start_cycle_interval_id,
        v12->m_animated_object,
        (vostok::animation::mixing::playback_enum)v12->m_playback_type,
        &v12->m_time_calculator,
        v12->m_time_synchronization_group_id,
        v12->m_override_existing_animation,
        v12->m_is_positive_event_direction,
        v12->m_can_generate_events,
        v12->m_additivity_priority,
        v12->m_bones_mask,
        weight_operands_count + *time_scale_operands_count,
        is_transitting_to_zero);
  }
  else if ( v23 )
  {
    LOBYTE(v54) = v12->m_is_positive_event_direction;
    start_cycle_animation_interval_id = v12->m_start_cycle_interval_id;
    unique_animation_id = v12->m_unique_animation_id;
    m_animation_intervals_count = v12->m_animation_intervals_count;
    start_timea = weight_operands_count + *time_scale_operands_count;
    m_bones_mask = v12->m_bones_mask;
    m_additivity_priority = v12->m_additivity_priority;
    m_can_generate_events = v12->m_can_generate_events;
    v46 = v12->m_override_existing_animation;
    m_weight_synchronization_group_id = v12->m_weight_synchronization_group_id;
    m_time_synchronization_group_id = v12->m_time_synchronization_group_id;
    m_playback_type = v12->m_playback_type;
    v25 = vostok::animation::mixing::n_ary_tree_cloner::clone(
            (vostok::animation::mixing::n_ary_tree_cloner *)v54,
            (int)&this->m_cloner,
            v12->m_weight_interpolator,
            (bool)v12->m_animated_object);
    vostok::animation::mixing::n_ary_tree_animation_node::n_ary_tree_animation_node(
      v23,
      cloned_intervals_begin,
      &cloned_intervals_begin[m_animation_intervals_count],
      unique_animation_id,
      start_cycle_animation_interval_id,
      v25,
      v42,
      m_playback_type,
      &v12->m_time_calculator,
      m_time_synchronization_group_id,
      m_weight_synchronization_group_id,
      v46,
      (bool)v54,
      m_can_generate_events,
      m_additivity_priority,
      m_bones_mask,
      start_timea,
      is_transitting_to_zero);
  }
  v26 = this->m_buffer;
  v26->m_data += 88;
  v26->m_size -= 88;
  v23->user_data = v12->user_data;
  if ( this->m_weight_root )
    this->m_previous_animation->m_next_weight_animation = v23;
  else
    this->m_weight_root = v23;
  if ( !LOBYTE(can_be_time_driving_animation)
    || v12->m_time_driving_animation
    || v12->m_time_synchronization_group_id == -1 )
  {
    m_time_driving_animation = v12->m_time_driving_animation;
    if ( m_time_driving_animation )
    {
      v28 = v12->m_animation_intervals;
      v29 = m_time_driving_animation->m_animation_intervals;
      time_driving_animation_state = m_time_driving_animation->m_animation_state;
      v30 = time_driving_animation_state->animation_interval_id;
      *animation_interval_id = v30;
      v30 *= 12;
      v31 = (const vostok::animation::mixing::animation_interval *)((char *)v29 + v30);
      can_be_time_driving_animation = vostok::animation::mixing::animation_interval::length((const vostok::animation::mixing::animation_interval *)((char *)v28 + v30));
      v32 = vostok::animation::mixing::animation_interval::length(v31);
      *animation_interval_time = can_be_time_driving_animation
                               / v32
                               * time_driving_animation_state->animation_interval_time;
    }
    else
    {
      v33 = v12->m_override_existing_animation;
      if ( v33
        || (v34 = (vostok::animation::mixing::n_ary_tree_animation_node *)from,
            *(_BYTE *)(LODWORD(from->bone_matrices_computer.previous_object_movement.scale.x) + 117)) )
      {
        v34 = v12;
      }
      *animation_interval_id = v34->m_animation_state->animation_interval_id;
      if ( !v33 && !*(_BYTE *)(LODWORD(from->bone_matrices_computer.previous_object_movement.scale.x) + 117) )
        v12 = (vostok::animation::mixing::n_ary_tree_animation_node *)from;
      *animation_interval_time = v12->m_animation_state->animation_interval_time;
    }
  }
  else
  {
    *this->m_time_driving_animations_end++ = v23;
    if ( time_scale_node )
      v23[1].__vftable = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)time_scale_node;
  }
  m_new_animated_object = this->m_new_animated_object;
  m_animated_objects = this->m_animated_objects;
  can_be_time_driving_animation = *(float *)&v23->m_animated_object;
  if ( stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
         m_animated_objects,
         m_new_animated_object,
         (const void *const *)&can_be_time_driving_animation) == m_new_animated_object )
  {
    if ( m_new_animated_object )
    {
      m_new_animated_object->animated_object = v23->m_animated_object;
      m_new_animated_object->need_new_transform = 0;
    }
    m_from = this->m_from;
    v38 = m_from->m_animated_objects;
    v39 = &v38[m_from->m_animated_objects_count];
    can_be_time_driving_animation = *(float *)&v23->m_animated_object;
    v40 = stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
            v38,
            v39,
            (const void *const *)&can_be_time_driving_animation);
    if ( v40 == v39 )
      v40 = (vostok::animation::mixing::animated_object_holder *)boost::function1<vostok::math::float4x4,void const *>::operator()(
                                                                   (boost::function1<vostok::math::float4x4,void const *> *)&result,
                                                                   this,
                                                                   &result,
                                                                   v23->m_animated_object);
    qmemcpy(this->m_new_animated_object++, v40, 0x40u);
  }
  this->m_previous_animation = v23;
  return v23;
}
