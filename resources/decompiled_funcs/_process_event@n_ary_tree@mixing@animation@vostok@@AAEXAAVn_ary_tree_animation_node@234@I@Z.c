// local variable allocation has failed, the output may be wrong!
void __userpurge vostok::animation::mixing::n_ary_tree::process_event(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        float a2@<xmm4>,
        vostok::animation::mixing::n_ary_tree_animation_node *current_animation_node,
        __int16 event_types)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // ebx
  vostok::animation::mixing::animation_state *m_animation_state; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node *event_time_in_ms; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_driving_animation; // eax
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v8; // esi
  char v9; // al
  const vostok::math::float4x4 *m_time_in_ms; // xmm0_4
  unsigned int animation_interval_time_low; // xmm0_4
  void (__thiscall *v12)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::current_frame_position *); // edx
  vostok::animation::mixing::animation_interval *v13; // esi
  vostok::animation::mixing::animation_interval *v14; // eax
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v15; // ecx
  _DWORD *v16; // eax
  int v17; // ecx
  char v18; // al
  vostok::animation::mixing::animation_interval *v19; // eax
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  vostok::animation::mixing::animation_interval *v24; // eax
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v25; // ecx
  _DWORD *v26; // eax
  float v27; // xmm0_4
  vostok::animation::mixing::animation_interval *v28; // ecx
  double started; // st7
  double v30; // st7
  vostok::animation::mixing::animation_interval *m_animation_intervals; // ecx
  vostok::animation::mixing::animation_interval *v32; // eax
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v33; // ecx
  int v34; // ecx
  unsigned int animation_interval_id; // edx
  unsigned int v36; // eax
  vostok::animation::mixing::animation_interval *v37; // eax
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v38; // ecx
  _DWORD *v39; // eax
  vostok::animation::mixing::animation_interval *v40; // esi
  double v41; // st7
  double v42; // st6
  float v43; // xmm0_4
  unsigned int v44; // edx
  float animation_interval_time; // xmm0_4
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v46; // esi
  unsigned int v47; // eax
  float v48; // xmm0_4
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v49; // esi
  vostok::animation::mixing::animation_interval *v50; // ecx
  vostok::animation::mixing::animation_interval *v51; // eax
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v52; // ecx
  float v53; // edx
  unsigned int m_recursion_level; // xmm0_4
  vostok::math::quaternion *v55; // ecx
  int v56; // eax
  float v57; // xmm4_4
  float v58; // xmm5_4
  float v59; // xmm0_4
  float v60; // xmm7_4
  float v61; // eax
  vostok::animation::mixing::animation_interval *v62; // ecx
  vostok::animation::mixing::animation_interval *v63; // eax
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v64; // ecx
  vostok::math::quaternion *v65; // ecx
  unsigned int v66; // xmm0_4
  _QWORD *v67; // eax
  unsigned int v68; // edx
  vostok::animation::mixing::n_ary_tree_weight_event_iterator *v69; // ecx
  bool v70; // al
  vostok::animation::mixing::n_ary_tree_animation_node *v71; // ecx
  float v72; // xmm0_4
  unsigned int v73; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v74; // ebx
  vostok::math::float3 v75[2]; // [esp+8h] [ebp-D8h] BYREF
  _BYTE animation_length[12]; // [esp+24h] [ebp-BCh] OVERLAPPED BYREF
  __int64 v77; // [esp+30h] [ebp-B0h]
  int v78; // [esp+38h] [ebp-A8h]
  const vostok::animation::mixing::animation_interval *interval; // [esp+3Ch] [ebp-A4h]
  vostok::math::quaternion pinned_animation; // [esp+40h] [ebp-A0h] OVERLAPPED BYREF
  vostok::animation::current_frame_position frame_position; // [esp+50h] [ebp-90h] BYREF
  int v82; // [esp+74h] [ebp-6Ch]
  vostok::animation::mixing::n_ary_tree_weight_calculator weight_calculator; // [esp+78h] [ebp-68h] BYREF
  float v84; // [esp+98h] [ebp-48h]
  float v85; // [esp+9Ch] [ebp-44h]
  vostok::animation::mixing::n_ary_tree_event_iterator event_iterator; // [esp+A0h] [ebp-40h] BYREF

  v4 = current_animation_node;
  m_animation_state = current_animation_node->m_animation_state;
  v78 = (unsigned __int16)(event_types & m_animation_state->event_iterator.m_value.event_type);
  if ( (v78 & 1) == 0 )
    goto LABEL_18;
  event_time_in_ms = (vostok::animation::mixing::n_ary_tree_animation_node *)m_animation_state->event_iterator.m_value.event_time_in_ms;
  m_time_driving_animation = current_animation_node->m_time_driving_animation;
  event_iterator.m_animation_event_iterator.m_channels_head = (vostok::animation::subscribed_channel **)LODWORD(m_animation_state->animation_interval_time);
  *(_DWORD *)animation_length = event_time_in_ms;
  event_iterator.m_animation_event_iterator.m_value.animation_interval_id = (unsigned int)&vostok::animation::mixing::n_ary_tree_time_scale_calculator::`vftable';
  memset(&event_iterator.m_animation_event_iterator.m_value.animation_interval_time, 0, 12);
  event_iterator.m_animation_event_iterator.m_animation = event_time_in_ms;
  event_iterator.m_weight_event_iterator.m_animation = event_time_in_ms;
  memset(&event_iterator.m_weight_event_iterator.m_time_in_ms, 0, 12);
  if ( !m_time_driving_animation )
    m_time_driving_animation = current_animation_node;
  if ( !m_time_driving_animation->m_operands_count )
  {
    v8 = 0;
LABEL_11:
    m_time_in_ms = clear_value;
    goto LABEL_12;
  }
  v8 = m_time_driving_animation[1].__vftable;
  if ( !v8 )
    goto LABEL_11;
  if ( (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v8->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(v8) )
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_event_iterator *))v8->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 2))(
      v8,
      &event_iterator);
  v9 = (*((int (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v8->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(v8);
  event_time_in_ms = *(vostok::animation::mixing::n_ary_tree_animation_node **)animation_length;
  if ( !v9 )
    goto LABEL_11;
  m_time_in_ms = (const vostok::math::float4x4 *)event_iterator.m_weight_event_iterator.m_time_in_ms;
LABEL_12:
  if ( *(float *)&m_time_in_ms == 0.0 )
  {
    animation_interval_time_low = LODWORD(m_animation_state->animation_interval_time);
    frame_position.m_current_domains[4] = (unsigned int)&event_time_in_ms->__vftable + 1;
    frame_position.m_current_domains[6] = (unsigned int)&event_time_in_ms->__vftable + 1;
    v12 = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::current_frame_position *))*((_DWORD *)v8->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node + 2);
    frame_position.m_current_domains[0] = (unsigned int)&vostok::animation::mixing::n_ary_tree_time_scale_calculator::`vftable';
    memset(&frame_position.m_current_domains[1], 0, 12);
    frame_position.m_current_domains[5] = animation_interval_time_low;
    frame_position.m_current_domains[7] = 0;
    frame_position.m_current_domains[8] = 0;
    v82 = 0;
    v12(v8, &frame_position);
    m_time_in_ms = (const vostok::math::float4x4 *)frame_position.m_current_domains[7];
  }
  if ( *(float *)&m_time_in_ms >= 0.0 )
  {
    v13 = &current_animation_node->m_animation_intervals[m_animation_state->animation_interval_id];
    *(float *)&interval = vostok::animation::mixing::animation_interval::start_time(v13)
                        + m_animation_state->animation_interval_time;
    v14 = vostok::animation::mixing::animation_interval::animation(v13);
    *(_DWORD *)animation_length = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length,
      &v14->m_animation);
    v75[0].z = 0.0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v75[0].elements[2],
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length);
    vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
      v15,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&animation_length[4],
      LODWORD(v75[0].elements[2]));
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length);
    v16 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)&animation_length[8] + 20) + *(_DWORD *)&animation_length[8]);
    v17 = v16[1] + 16 * *v16;
    *(_DWORD *)animation_length = *(_DWORD *)((char *)&v16[5 * *v16 - 1] + v16[1]);
    v85 = *(float *)((char *)v16 + v17);
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&animation_length[4]);
    if ( *(float *)&interval == (float)((float)(*(float *)animation_length - v85) * 0.033333335) )
      m_animation_state->animation_time = 0.0;
  }
  m_animation_state->are_there_any_weight_transitions = 0;
  vostok::animation::mixing::n_ary_tree::set_object_transform(
    (vostok::animation::mixing::n_ary_tree *)current_animation_node,
    a2);
LABEL_18:
  v18 = v78;
  if ( (v78 & 8) != 0 )
  {
    if ( current_animation_node->m_playback_type == play_once_and_freeze_at_end )
    {
      interval = &current_animation_node->m_animation_intervals[current_animation_node->m_animation_intervals_count - 1];
      v24 = vostok::animation::mixing::animation_interval::animation(interval);
      *(_DWORD *)animation_length = 0;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length,
        &v24->m_animation);
      v75[0].z = 0.0;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v75[0].elements[2],
        (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length);
      vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
        v25,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&animation_length[4],
        LODWORD(v75[0].elements[2]));
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length);
      v26 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)&animation_length[8] + 20) + *(_DWORD *)&animation_length[8]);
      *(float *)animation_length = (float)(*(float *)((char *)&v26[5 * *v26 - 1] + v26[1])
                                         - *(float *)((char *)&v26[4 * *v26] + v26[1]))
                                 * 0.033333335;
      vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&animation_length[4]);
      v27 = *(float *)animation_length;
      v28 = interval;
      m_animation_state->animation_time = *(float *)animation_length;
      m_animation_state->animation_time_threshold = v27;
      started = vostok::animation::mixing::animation_interval::start_time(v28);
      v30 = *(float *)animation_length - started;
      m_animation_state->is_freezed = 1;
      m_animation_state->animation_interval_time = v30;
    }
    else
    {
      m_animation_state->animation_time = 0.0;
      if ( (v18 & 4) == 0 )
      {
        v19 = vostok::animation::mixing::animation_interval::animation(&current_animation_node->m_animation_intervals[m_animation_state->animation_interval_id]);
        v75[0].z = 0.0;
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
          (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v75[0].elements[2],
          &v19->m_animation);
        vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>(
          v20,
          LODWORD(v75[0].elements[2]));
        v22 = *(_DWORD *)(v21 + 4);
        v23 = *(_DWORD *)(v22 + 20);
        m_animation_state->animation_time_threshold = (float)(*(float *)(*(_DWORD *)(v23 + v22 + 4)
                                                                       + 20 * *(_DWORD *)(v23 + v22)
                                                                       + v23
                                                                       + v22
                                                                       - 4)
                                                            - *(float *)(16 * *(_DWORD *)(v23 + v22)
                                                                       + *(_DWORD *)(v22 + v23 + 4)
                                                                       + v23
                                                                       + v22))
                                                    * 0.033333335;
        vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pinned_animation);
      }
    }
  }
  if ( (v78 & 0x10) == 0 )
  {
LABEL_29:
    if ( (v78 & 4) == 0 )
      goto LABEL_41;
    goto LABEL_30;
  }
  m_animation_intervals = current_animation_node->m_animation_intervals;
  if ( current_animation_node->m_playback_type == play_once_and_freeze_at_end )
  {
    m_animation_state->animation_time = vostok::animation::mixing::animation_interval::start_time(m_animation_intervals);
    m_animation_state->animation_interval_time = 0.0;
    m_animation_state->is_freezed = 1;
LABEL_28:
    m_animation_state->animation_time_threshold = 0.0;
    goto LABEL_29;
  }
  v32 = vostok::animation::mixing::animation_interval::animation(&m_animation_intervals[m_animation_state->animation_interval_id]);
  *(_DWORD *)animation_length = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length,
    &v32->m_animation);
  v75[0].z = 0.0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v75[0].elements[2],
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v33,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&animation_length[4],
    LODWORD(v75[0].elements[2]));
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length);
  v34 = *(_DWORD *)(*(_DWORD *)&animation_length[8] + 20);
  m_animation_state->animation_time = (float)(*(float *)(*(_DWORD *)(v34 + *(_DWORD *)&animation_length[8] + 4)
                                                       + 20 * *(_DWORD *)(v34 + *(_DWORD *)&animation_length[8])
                                                       + v34
                                                       + *(_DWORD *)&animation_length[8]
                                                       - 4)
                                            - *(float *)(16 * *(_DWORD *)(v34 + *(_DWORD *)&animation_length[8])
                                                       + *(_DWORD *)(*(_DWORD *)&animation_length[8] + v34 + 4)
                                                       + v34
                                                       + *(_DWORD *)&animation_length[8]))
                                    * 0.033333335;
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&animation_length[4]);
  if ( (v78 & 4) == 0 )
    goto LABEL_28;
LABEL_30:
  if ( !m_animation_state->is_freezed )
  {
    animation_interval_id = m_animation_state->animation_interval_id;
    v36 = m_animation_state->event_iterator.m_value.animation_interval_id;
    m_animation_state->animation_interval_time = m_animation_state->event_iterator.m_value.animation_interval_time;
    m_animation_state->animation_interval_id = v36;
    m_animation_state->previous_animation_interval_id = animation_interval_id;
    interval = &current_animation_node->m_animation_intervals[v36];
    v37 = vostok::animation::mixing::animation_interval::animation(interval);
    *(_DWORD *)animation_length = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length,
      &v37->m_animation);
    v75[0].z = 0.0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v75[0].elements[2],
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length);
    vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
      v38,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&animation_length[4],
      LODWORD(v75[0].elements[2]));
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length);
    v39 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)&animation_length[8] + 20) + *(_DWORD *)&animation_length[8]);
    *(float *)animation_length = (*(float *)((char *)&v39[5 * *v39 - 1] + v39[1])
                                - *(float *)((char *)&v39[4 * *v39] + v39[1]))
                               * 0.033333335;
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&animation_length[4]);
    v40 = interval;
    *(float *)&interval = vostok::animation::mixing::animation_interval::start_time(interval);
    v41 = vostok::animation::mixing::animation_interval::length(v40);
    if ( v41 + *(float *)&interval <= *(float *)animation_length
      || (v42 = vostok::animation::mixing::animation_interval::start_time(v40)
              + m_animation_state->animation_interval_time,
          v42 <= *(float *)animation_length) )
    {
      v43 = 0.0;
    }
    else
    {
      v43 = *(float *)animation_length;
    }
    m_animation_state->animation_time_threshold = v43;
    vostok::animation::mixing::n_ary_tree::update_animation_time(m_animation_state);
  }
  if ( !current_animation_node->m_time_driving_animation )
  {
    v44 = m_animation_state->event_iterator.m_value.event_time_in_ms;
    animation_interval_time = m_animation_state->animation_interval_time;
    *(_DWORD *)&animation_length[4] = &vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::`vftable';
    *(_DWORD *)&animation_length[8] = v44;
    *(float *)&v77 = animation_interval_time;
    if ( current_animation_node->m_operands_count )
    {
      v46 = current_animation_node[1].__vftable;
      if ( v46 )
      {
        if ( (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v46->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
              + 3))(current_animation_node[1].__vftable) )
          (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, _BYTE *))v46->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
           + 2))(
            v46,
            &animation_length[4]);
      }
    }
  }
LABEL_41:
  if ( (v78 & 0x40) != 0 && !current_animation_node->m_time_driving_animation )
  {
    v47 = m_animation_state->event_iterator.m_value.event_time_in_ms;
    v48 = m_animation_state->animation_interval_time;
    *(_DWORD *)&animation_length[4] = &vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::`vftable';
    *(_DWORD *)&animation_length[8] = v47;
    *(float *)&v77 = v48;
    if ( current_animation_node->m_operands_count )
    {
      v49 = current_animation_node[1].__vftable;
      if ( v49 )
      {
        if ( (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v49->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
              + 3))(current_animation_node[1].__vftable) )
          (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, _BYTE *))v49->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
           + 2))(
            v49,
            &animation_length[4]);
      }
    }
  }
  if ( (v78 & 0x80u) != 0 )
  {
    v50 = &current_animation_node->m_animation_intervals[current_animation_node->m_animation_state->animation_interval_id];
    memset(&frame_position, 0, sizeof(frame_position));
    v51 = vostok::animation::mixing::animation_interval::animation(v50);
    *(_DWORD *)animation_length = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length,
      &v51->m_animation);
    v75[0].z = 0.0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v75[0].elements[2],
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length);
    vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
      v52,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&animation_length[4],
      LODWORD(v75[0].elements[2]));
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length);
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>(
      (vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *)&pinned_animation,
      (const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *)&animation_length[4]);
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&animation_length[4]);
    vostok::animation::evaluate_frame(
      (const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *)(LODWORD(pinned_animation.y) + *(_DWORD *)(LODWORD(pinned_animation.y) + 20)),
      (vostok::animation::frame *)&weight_calculator,
      a2,
      m_animation_state->animation_time * 30.0,
      &frame_position);
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pinned_animation);
    *(float *)&animation_length[4] = *(float *)&weight_calculator.__vftable
                                   - m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.x;
    *(float *)&animation_length[8] = *(float *)&weight_calculator.m_animation
                                   - m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.y;
    *(float *)&v77 = *(float *)&weight_calculator.m_result
                   - m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.z;
    v53 = *(float *)&v77;
    *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.x = *(_QWORD *)&animation_length[4];
    m_recursion_level = weight_calculator.m_recursion_level;
    m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.z = v53;
    *(_QWORD *)&v75[0].x = __PAIR64__(weight_calculator.m_current_time_in_ms, m_recursion_level);
    v75[0].z = weight_calculator.m_weight;
    vostok::math::quaternion::quaternion(v55, (float *)&animation_length[4], v75[0]);
    v57 = *(float *)(v56 + 12);
    v58 = *(float *)v56;
    pinned_animation = m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation;
    v59 = *(float *)(v56 + 8);
    *(_DWORD *)animation_length = *(_DWORD *)(v56 + 4);
    *((float *)&v77 + 1) = (float)((float)((float)(v57 * pinned_animation.w) - (float)((float)-pinned_animation.x * v58))
                                 - (float)(*(float *)animation_length * (float)-pinned_animation.y))
                         - (float)(v59 * (float)-pinned_animation.z);
    *(float *)&animation_length[4] = (float)((float)((float)(v58 * pinned_animation.w)
                                                   + (float)(v59 * (float)-pinned_animation.y))
                                           + (float)((float)-pinned_animation.x * v57))
                                   - (float)(*(float *)animation_length * (float)-pinned_animation.z);
    v60 = v57 * (float)-pinned_animation.y;
    a2 = v57 * (float)-pinned_animation.z;
    *(float *)&v77 = (float)((float)((float)(v59 * pinned_animation.w)
                                   + (float)((float)-pinned_animation.x * *(float *)animation_length))
                           - (float)(v58 * (float)-pinned_animation.y))
                   + a2;
    *(float *)&animation_length[8] = (float)((float)((float)(*(float *)animation_length * pinned_animation.w)
                                                   - (float)((float)-pinned_animation.x * v59))
                                           + (float)(v58 * (float)-pinned_animation.z))
                                   + v60;
    *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.x = *(_QWORD *)&animation_length[4];
    *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.vector.elements[2] = v77;
    *(float *)&animation_length[4] = *(float *)&weight_calculator.m_weight_transition_ended_time_in_ms
                                   / m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.x;
    *(float *)&animation_length[8] = *(float *)&weight_calculator.m_null_weight_found
                                   / m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.y;
    *(float *)&v77 = v84 / m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.z;
    v61 = *(float *)&v77;
    *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.x = *(_QWORD *)&animation_length[4];
    m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.z = v61;
    m_animation_state->are_there_any_weight_transitions = 1;
  }
  if ( (v78 & 0x100) != 0 )
  {
    v62 = &current_animation_node->m_animation_intervals[current_animation_node->m_animation_state->animation_interval_id];
    memset(&event_iterator, 0, 36);
    v63 = vostok::animation::mixing::animation_interval::animation(v62);
    *(_DWORD *)animation_length = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length,
      &v63->m_animation);
    v75[0].z = 0.0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v75[0].elements[2],
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length);
    vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
      v64,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&pinned_animation,
      LODWORD(v75[0].elements[2]));
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)animation_length);
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>(
      (vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *)&animation_length[4],
      (const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *)&pinned_animation);
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pinned_animation);
    vostok::animation::evaluate_frame(
      (const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *)(*(_DWORD *)&animation_length[8] + *(_DWORD *)(*(_DWORD *)&animation_length[8] + 20)),
      (vostok::animation::frame *)&frame_position,
      a2,
      m_animation_state->animation_time * 30.0,
      (vostok::animation::current_frame_position *)&event_iterator);
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&animation_length[4]);
    *(_DWORD *)&animation_length[4] = frame_position.m_current_domains[0];
    *(_DWORD *)&animation_length[8] = frame_position.m_current_domains[1];
    LODWORD(v77) = frame_position.m_current_domains[2];
    v65 = (vostok::math::quaternion *)frame_position.m_current_domains[2];
    *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.x = *(_QWORD *)&animation_length[4];
    v66 = frame_position.m_current_domains[3];
    LODWORD(m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.z) = v65;
    *(_QWORD *)&v75[0].x = __PAIR64__(frame_position.m_current_domains[4], v66);
    LODWORD(v75[0].z) = frame_position.m_current_domains[5];
    vostok::math::quaternion::quaternion(v65, &pinned_animation.x, v75[0]);
    *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.x = *v67;
    *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.vector.elements[2] = v67[1];
    *(_DWORD *)&animation_length[4] = frame_position.m_current_domains[6];
    *(_DWORD *)&animation_length[8] = frame_position.m_current_domains[7];
    LODWORD(v77) = frame_position.m_current_domains[8];
    v68 = frame_position.m_current_domains[8];
    *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.x = *(_QWORD *)&animation_length[4];
    LODWORD(m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.z) = v68;
    weight_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_weight_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_calculator::`vftable';
    weight_calculator.m_animation = current_animation_node;
    weight_calculator.m_current_time_in_ms = m_animation_state->event_iterator.m_value.event_time_in_ms;
    weight_calculator.m_result = 0;
    weight_calculator.m_recursion_level = 0;
    memset(&weight_calculator.m_weight, 0, 9);
    vostok::animation::mixing::n_ary_tree_weight_calculator::visit(&weight_calculator, current_animation_node);
    qmemcpy(&event_iterator, &m_animation_state->event_iterator, sizeof(event_iterator));
    v69 = 0;
    if ( (event_iterator.m_state & 1) != 0 )
      vostok::animation::mixing::n_ary_tree_animation_event_iterator::advance(0, (int)&event_iterator, 0);
    if ( (event_iterator.m_state & 2) != 0 )
      vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator++(
        v69,
        (int)&event_iterator.m_weight_event_iterator);
    vostok::animation::mixing::n_ary_tree_event_iterator::select_state(
      (vostok::animation::mixing::n_ary_tree_event_iterator *)v69,
      (int)&event_iterator);
    v70 = !event_iterator.m_weight_event_iterator.m_animation
       && event_iterator.m_weight_event_iterator.m_time_in_ms == -1
       && !event_iterator.m_weight_event_iterator.m_event_type;
    m_animation_state->are_there_any_weight_transitions = !v70;
    v71 = current_animation_node->m_time_driving_animation;
    if ( v71 )
      v4 = current_animation_node->m_time_driving_animation;
    else
      v71 = current_animation_node;
    v72 = v71->m_animation_state->animation_interval_time;
    v73 = m_animation_state->event_iterator.m_value.event_time_in_ms;
    *(_DWORD *)&animation_length[4] = &vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::`vftable';
    *(_DWORD *)&animation_length[8] = v73;
    *(float *)&v77 = v72;
    if ( v4->m_operands_count )
    {
      v74 = v4[1].__vftable;
      if ( v74 )
      {
        if ( (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v74->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
              + 3))(v74) )
          (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, _BYTE *))v74->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
           + 2))(
            v74,
            &animation_length[4]);
      }
    }
  }
}
