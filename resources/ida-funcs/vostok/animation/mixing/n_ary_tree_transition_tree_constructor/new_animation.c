vostok::animation::mixing::n_ary_tree_animation_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation@<eax>(
        vostok::animation::mixing::n_ary_tree_animation_node *to@<ecx>,
        unsigned int *target_operands_offset@<eax>,
        const vostok::animation::base_interpolator *this,
        vostok::animation::mixing::n_ary_tree_animation_node *from,
        vostok::animation::mixing::n_ary_tree_animation_node *weight_driving_animation,
        unsigned int weight_operands_count,
        fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *time_scale_operands_count,
        const vostok::animation::mixing::animation_interval *source_operands_offset,
        unsigned int *animation_interval_id,
        float *animation_interval_time,
        bool is_transitting_to_zero,
        vostok::animation::mixing::n_ary_tree_animation_node *can_be_time_driving_animation)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v12; // esi
  bool m_override_existing_animation; // al
  vostok::animation::mixing::n_ary_tree_animation_node *v15; // ecx
  unsigned int v16; // edx
  unsigned int *v17; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v18; // eax
  double v19; // st7
  float *v20; // eax
  bool v21; // zf
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v22; // eax
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // edi
  char *interpolated_value; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v25; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_data; // eax
  vostok::mutable_buffer *v27; // eax
  vostok::mutable_buffer *v28; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v29; // edi
  unsigned int m_bones_mask; // eax
  vostok::animation::mixing::n_ary_tree_node_cloner *m_additivity_priority; // ecx
  unsigned int m_animation_intervals_count; // edi
  const vostok::animation::base_interpolator *v33; // eax
  vostok::mutable_buffer *v34; // eax
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v35; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_driving_animation; // eax
  vostok::animation::mixing::animation_state *m_animation_state; // ecx
  unsigned int v38; // eax
  bool v39; // cl
  vostok::animation::mixing::n_ary_tree_animation_node *v40; // eax
  vostok::animation::mixing::animated_object_holder *v41; // esi
  vostok::animation::mixing::animated_object_holder *v42; // eax
  unsigned __int8 m_animated_object_id; // al
  const vostok::animation::mixing::n_ary_tree *v44; // ecx
  vostok::animation::mixing::animated_object_holder *m_animated_objects; // eax
  vostok::animation::mixing::animated_object_holder *v46; // esi
  vostok::animation::mixing::animated_object_holder *v47; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *result; // eax
  const void *v49; // [esp-30h] [ebp-A8h]
  vostok::animation::mixing::playback_enum m_playback_type; // [esp-28h] [ebp-A0h]
  unsigned int m_time_synchronization_group_id; // [esp-20h] [ebp-98h]
  unsigned int m_weight_synchronization_group_id; // [esp-1Ch] [ebp-94h]
  unsigned int v53; // [esp-8h] [ebp-80h]
  unsigned int v54; // [esp-4h] [ebp-7Ch]
  fastdelegate::detail::GenericClass *v55; // [esp+0h] [ebp-78h]
  bool v56; // [esp+4h] [ebp-74h]
  boost::function1<vostok::math::float4x4,void const *> *v57; // [esp+4h] [ebp-74h]
  vostok::math::float4x4 v58; // [esp+18h] [ebp-60h] BYREF
  int v59; // [esp+58h] [ebp-20h]
  unsigned int m_start_cycle_interval_id; // [esp+5Ch] [ebp-1Ch]
  int v61; // [esp+60h] [ebp-18h]
  int v62; // [esp+64h] [ebp-14h]
  BOOL v63; // [esp+68h] [ebp-10h]
  BOOL v64; // [esp+6Ch] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v65; // [esp+70h] [ebp-8h]
  BOOL v66; // [esp+74h] [ebp-4h]
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *v67; // [esp+84h] [ebp+Ch]
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *m_animated_object; // [esp+84h] [ebp+Ch]
  bool m_can_generate_events; // [esp+88h] [ebp+10h]

  v12 = to;
  m_override_existing_animation = to->m_override_existing_animation;
  if ( m_override_existing_animation || (v15 = from, from->m_animation_state->is_freezed) )
    v15 = v12;
  v16 = v15->m_animation_state->animation_interval_id;
  v17 = animation_interval_id;
  *animation_interval_id = v16;
  if ( m_override_existing_animation || (v18 = from, from->m_animation_state->is_freezed) )
    v18 = v12;
  v19 = v18->m_animation_state->animation_interval_time;
  v20 = animation_interval_time;
  source_operands_offset->m_first_view_animation.m_object = 0;
  *v20 = v19;
  *target_operands_offset = 0;
  v65 = 0;
  if ( (_BYTE)can_be_time_driving_animation && v12->m_is_time_driving_animation )
  {
    v21 = v12->m_time_synchronization_group_id == -1;
    LOBYTE(v66) = 1;
    if ( v21 )
      goto LABEL_18;
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale(v12, this, v17, v20);
    v65 = v22;
    if ( v22 )
    {
      time_scale_operands_count->m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)1;
      *target_operands_offset = 1;
    }
  }
  else
  {
    LOBYTE(v66) = 0;
  }
  if ( v12->m_time_synchronization_group_id != -1
    && (!v66 || v65)
    && from->m_operands_count
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))from[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(from[1].__vftable) )
  {
    source_operands_offset->m_first_view_animation.m_object = (vostok::resources::managed_resource *)1;
  }
LABEL_18:
  m_animation_intervals = v12->m_animation_intervals;
  interpolated_value = (char *)this[17].interpolated_value;
  v25 = (vostok::animation::mixing::n_ary_tree_animation_node *)&m_animation_intervals[v12->m_animation_intervals_count];
  can_be_time_driving_animation = v25;
  source_operands_offset = (const vostok::animation::mixing::animation_interval *)interpolated_value;
  while ( 1 )
  {
    v28 = (vostok::mutable_buffer *)this[17].__vftable;
    if ( m_animation_intervals == (const vostok::animation::mixing::animation_interval *)v25 )
      break;
    m_data = (vostok::animation::mixing::n_ary_tree_animation_node *)v28->m_data;
    if ( m_data )
    {
      vostok::animation::mixing::animation_interval::animation_interval(
        (vostok::animation::mixing::animation_interval *)m_data,
        &m_animation_intervals->m_first_view_animation,
        m_animation_intervals->m_animation_id,
        m_animation_intervals->m_start_time,
        m_animation_intervals->m_length);
      v25 = can_be_time_driving_animation;
    }
    v27 = (vostok::mutable_buffer *)this[17].__vftable;
    v27->m_data += 20;
    v27->m_size -= 20;
    ++m_animation_intervals;
  }
  v29 = (vostok::animation::mixing::n_ary_tree_animation_node *)v28->m_data;
  can_be_time_driving_animation = (vostok::animation::mixing::n_ary_tree_animation_node *)v28->m_data;
  if ( weight_driving_animation )
  {
    if ( !v29 )
      goto LABEL_30;
    vostok::animation::mixing::n_ary_tree_animation_node::n_ary_tree_animation_node(
      weight_driving_animation,
      source_operands_offset,
      &v12->m_time_calculator,
      v29,
      &source_operands_offset[v12->m_animation_intervals_count],
      v12->m_unique_animation_id,
      v12->m_start_cycle_interval_id,
      v12->m_animated_object,
      v12->m_animated_object_id,
      (vostok::animation::mixing::playback_enum)v12->m_playback_type,
      v12->m_time_calculator_id,
      v12->m_time_synchronization_group_id,
      v12->m_override_existing_animation,
      v12->m_is_positive_event_direction,
      v12->m_can_generate_events,
      v66,
      v12->m_additivity_priority,
      v12->m_bones_mask,
      (unsigned int)&time_scale_operands_count->m_Closure.m_pthis[weight_operands_count],
      is_transitting_to_zero);
  }
  else
  {
    if ( !v29 )
      goto LABEL_30;
    v56 = is_transitting_to_zero;
    m_can_generate_events = v12->m_can_generate_events;
    m_bones_mask = v12->m_bones_mask;
    LOBYTE(v64) = v12->m_is_positive_event_direction;
    m_additivity_priority = (vostok::animation::mixing::n_ary_tree_node_cloner *)v12->m_additivity_priority;
    LOBYTE(v63) = v12->m_override_existing_animation;
    LOBYTE(v62) = v12->m_time_calculator_id;
    LOBYTE(v61) = v12->m_animated_object_id;
    m_start_cycle_interval_id = v12->m_start_cycle_interval_id;
    LOBYTE(v59) = v12->m_unique_animation_id;
    m_animation_intervals_count = v12->m_animation_intervals_count;
    v55 = &time_scale_operands_count->m_Closure.m_pthis[weight_operands_count];
    v54 = m_bones_mask;
    v53 = (unsigned int)m_additivity_priority;
    time_scale_operands_count = &v12->m_time_calculator;
    m_weight_synchronization_group_id = v12->m_weight_synchronization_group_id;
    m_time_synchronization_group_id = v12->m_time_synchronization_group_id;
    m_playback_type = v12->m_playback_type;
    v33 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
            m_additivity_priority,
            (int)&this[8],
            v12->m_weight_interpolator,
            (bool)v12->m_animated_object);
    vostok::animation::mixing::n_ary_tree_animation_node::n_ary_tree_animation_node(
      can_be_time_driving_animation,
      time_scale_operands_count,
      source_operands_offset,
      &source_operands_offset[m_animation_intervals_count],
      v59,
      m_start_cycle_interval_id,
      v33,
      v49,
      v61,
      m_playback_type,
      v62,
      m_time_synchronization_group_id,
      m_weight_synchronization_group_id,
      v63,
      v64,
      m_can_generate_events,
      v66,
      v53,
      v54,
      (unsigned int)v55,
      v56);
  }
  v29 = can_be_time_driving_animation;
LABEL_30:
  v34 = (vostok::mutable_buffer *)this[17].__vftable;
  v34->m_data += 88;
  v34->m_size -= 88;
  v29->user_data = v12->user_data;
  if ( this[22].__vftable )
    this[32].~vostok::animation::base_interpolator = (void (__thiscall *)(vostok::animation::base_interpolator *))v29;
  else
    this[22].__vftable = (vostok::animation::base_interpolator_vtbl *)v29;
  if ( !v66 || v12->m_time_synchronization_group_id == -1 )
  {
    m_time_driving_animation = v12->m_time_driving_animation;
    if ( m_time_driving_animation )
    {
      m_animation_state = m_time_driving_animation->m_animation_state;
      v38 = m_animation_state->animation_interval_id;
      *animation_interval_id = v38;
      *animation_interval_time = (float)(v12->m_animation_intervals[v38].m_length
                                       / v12->m_time_driving_animation->m_animation_intervals[v38].m_length)
                               * m_animation_state->animation_interval_time;
    }
    else
    {
      v39 = v12->m_override_existing_animation;
      if ( v39 || (v40 = from, from->m_animation_state->is_freezed) )
        v40 = v12;
      *animation_interval_id = v40->m_animation_state->animation_interval_id;
      if ( !v39 && !from->m_animation_state->is_freezed )
        v12 = from;
      *animation_interval_time = v12->m_animation_state->animation_interval_time;
    }
  }
  else
  {
    this[25].interpolated_value = (float (__thiscall *)(vostok::animation::base_interpolator *, float))v29;
    v35 = v65;
    this[25].__vftable = (vostok::animation::base_interpolator_vtbl *)((char *)this[25].__vftable + 4);
    if ( v35 )
      v29[1].__vftable = v35;
  }
  v41 = (vostok::animation::mixing::animated_object_holder *)this[30].__vftable;
  v42 = (vostok::animation::mixing::animated_object_holder *)this[29].__vftable;
  time_scale_operands_count = (fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *)v29->m_animated_object;
  v67 = time_scale_operands_count;
  if ( stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
         v42,
         (const void **)&time_scale_operands_count,
         v41) == v41 )
  {
    if ( v41 )
    {
      m_animated_object_id = can_be_time_driving_animation->m_animated_object_id;
      v41->animated_object = v67;
      v41->animated_object_id = m_animated_object_id;
      v41->need_new_transform = 0;
    }
    v44 = (const vostok::animation::mixing::n_ary_tree *)this[18].__vftable;
    m_animated_objects = v44->m_animated_objects;
    v46 = &m_animated_objects[v44->m_animated_objects_count];
    m_animated_object = (fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *)can_be_time_driving_animation->m_animated_object;
    time_scale_operands_count = m_animated_object;
    v47 = stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
            m_animated_objects,
            (const void **)&time_scale_operands_count,
            v46);
    if ( v47 == v46 )
      v47 = (vostok::animation::mixing::animated_object_holder *)boost::function1<vostok::math::float4x4,void const *>::operator()(
                                                                   v57,
                                                                   this,
                                                                   &v58,
                                                                   m_animated_object);
    qmemcpy(this[30].__vftable, v47, 0x40u);
    this[30].__vftable = (vostok::animation::base_interpolator_vtbl *)((char *)this[30].__vftable + 136);
  }
  result = can_be_time_driving_animation;
  this[32].__vftable = (vostok::animation::base_interpolator_vtbl *)can_be_time_driving_animation;
  return result;
}
