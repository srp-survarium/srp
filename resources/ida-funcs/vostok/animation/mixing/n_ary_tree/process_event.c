char __thiscall vostok::animation::mixing::n_ary_tree::process_event(
        vostok::animation::mixing::n_ary_tree *this,
        vostok::animation::mixing::n_ary_tree_animation_node *current_animation_node,
        __int16 event_types)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // esi
  vostok::animation::mixing::animation_state *m_animation_state; // ebx
  int v6; // eax
  float v7; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_driving_animation; // eax
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v9; // edi
  float v10; // xmm0_4
  const vostok::animation::mixing::animation_interval *v11; // edi
  vostok::resources::pinned_ptr_mutable<unsigned char> *v12; // ecx
  int v13; // eax
  _DWORD *v14; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v15; // ecx
  bool v16; // zf
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *p_m_first_view_animation; // edi
  vostok::resources::pinned_ptr_mutable<unsigned char> *v18; // ecx
  int v19; // eax
  _DWORD *v20; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v21; // ecx
  int v22; // eax
  int v23; // edi
  vostok::resources::pinned_ptr_mutable<unsigned char> *v24; // ecx
  int v25; // eax
  _DWORD *v26; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v27; // ecx
  float v28; // xmm0_4
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v29; // edi
  vostok::resources::pinned_ptr_mutable<unsigned char> *v30; // ecx
  int v31; // eax
  _DWORD *v32; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v33; // ecx
  double animation_interval_time; // st7
  unsigned int animation_interval_id; // eax
  int v36; // edi
  vostok::resources::pinned_ptr_mutable<unsigned char> *v37; // ecx
  int v38; // eax
  _DWORD *v39; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v40; // ecx
  float v41; // xmm0_4
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v42; // edx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v43; // ecx
  const vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *v44; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v45; // ecx
  float x; // xmm0_4
  vostok::math::quaternion *v47; // ecx
  const vostok::math::quaternion *v48; // eax
  const vostok::math::quaternion *v49; // esi
  vostok::math::quaternion *v50; // eax
  vostok::math::quaternion *v51; // eax
  float v52; // xmm0_4
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v53; // edx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v54; // ecx
  const vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *v55; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v56; // ecx
  float v57; // xmm0_4
  vostok::math::quaternion *v58; // ecx
  float v59; // xmm0_4
  float *v60; // eax
  float y; // xmm0_4
  vostok::animation::mixing::n_ary_tree_event_iterator *v62; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v63; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v64; // edx
  vostok::math::float3 v66; // [esp-Ch] [ebp-DCh] BYREF
  unsigned int v67; // [esp+0h] [ebp-D0h]
  struct vostok::animation::mixing::n_ary_tree_animation_node *v68; // [esp+4h] [ebp-CCh]
  _BYTE v69[4]; // [esp+Ch] [ebp-C4h] BYREF
  vostok::animation::mixing::n_ary_tree_weight_calculator v70; // [esp+10h] [ebp-C0h] BYREF
  vostok::math::quaternion v71; // [esp+34h] [ebp-9Ch] BYREF
  _DWORD v72[14]; // [esp+44h] [ebp-8Ch] BYREF
  float v73; // [esp+7Ch] [ebp-54h]
  float v74; // [esp+80h] [ebp-50h]
  float v75; // [esp+84h] [ebp-4Ch] BYREF
  _DWORD v76[3]; // [esp+88h] [ebp-48h] BYREF
  vostok::animation::frame f; // [esp+94h] [ebp-3Ch] BYREF
  vostok::math::quaternion v78; // [esp+B8h] [ebp-18h] BYREF
  int v79; // [esp+C8h] [ebp-8h]
  char v80; // [esp+CFh] [ebp-1h]
  float v81; // [esp+DCh] [ebp+Ch]
  float v82; // [esp+DCh] [ebp+Ch]
  float v83; // [esp+DCh] [ebp+Ch]
  float v84; // [esp+DCh] [ebp+Ch]
  bool are_there_any_weight_transitions; // [esp+DFh] [ebp+Fh]

  v4 = current_animation_node;
  m_animation_state = current_animation_node->m_animation_state;
  v6 = (unsigned __int16)(event_types & m_animation_state->event_iterator.m_value.event_type);
  v80 = 0;
  v79 = v6;
  if ( (v6 & 1) != 0 )
  {
    v81 = *(float *)&m_animation_state->event_iterator.m_value.event_time_in_ms;
    vostok::animation::mixing::n_ary_tree_time_scale_calculator::n_ary_tree_time_scale_calculator(
      0,
      (int)v69,
      LODWORD(m_animation_state->animation_interval_time),
      LODWORD(v81),
      v81,
      v67,
      v68);
    m_time_driving_animation = current_animation_node->m_time_driving_animation;
    if ( !m_time_driving_animation )
      m_time_driving_animation = current_animation_node;
    if ( m_time_driving_animation->m_operands_count )
      v9 = m_time_driving_animation[1].__vftable;
    else
      v9 = 0;
    if ( !v9 )
      goto LABEL_12;
    if ( (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v9->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
          + 3))(v9) )
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, _BYTE *))v9->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v9,
        v69);
    if ( (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v9->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
          + 3))(v9) )
      v10 = *(float *)&v70.m_weight_transition_ended_time_in_ms;
    else
LABEL_12:
      v10 = s_bm_current_air_resistance;
    if ( v10 == 0.0 )
    {
      vostok::animation::mixing::n_ary_tree_time_scale_calculator::n_ary_tree_time_scale_calculator(
        0,
        (int)&v72[4],
        LODWORD(m_animation_state->animation_interval_time),
        LODWORD(v81) + 1,
        COERCE_FLOAT(LODWORD(v81) + 1),
        v67,
        v68);
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, _DWORD *))v9->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v9,
        &v72[4]);
      v10 = *(float *)&v72[11];
    }
    if ( v10 >= 0.0 )
    {
      v11 = &current_animation_node->m_animation_intervals[m_animation_state->animation_interval_id];
      v66.z = v7;
      v74 = v11->m_start_time + m_animation_state->animation_interval_time;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v66.elements[2],
        &v11->m_first_view_animation);
      vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
        v12,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&v78.vector.elements[1],
        LODWORD(v66.elements[2]));
      v14 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v13 + 4) + 20) + *(_DWORD *)(v13 + 4));
      v15 = (vostok::resources::pinned_ptr_const<unsigned char> *)(v14[1] + 16 * *v14);
      v82 = *(float *)((char *)&v14[5 * *v14 - 1] + v14[1]);
      v73 = *(float *)((char *)v14 + (_DWORD)v15);
      vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
        v15,
        (int)&v78.y);
      v4 = current_animation_node;
      if ( v74 == (float)((float)(v82 - v73) * 0.033333335) )
        m_animation_state->animation_time = 0.0;
    }
    are_there_any_weight_transitions = m_animation_state->are_there_any_weight_transitions;
    m_animation_state->are_there_any_weight_transitions = 0;
    vostok::animation::mixing::n_ary_tree::set_object_transform(v4);
    m_animation_state->are_there_any_weight_transitions = are_there_any_weight_transitions;
  }
  if ( (v79 & 8) != 0 )
  {
    if ( v4->m_playback_type == play_once_and_freeze_at_end )
    {
      v22 = 20 * v4->m_animation_intervals_count;
      LODWORD(v66.z) = v4->m_animation_intervals;
      v23 = v22 + LODWORD(v66.z) - 20;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v66.elements[2],
        (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)v23);
      vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
        v24,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&v78.vector.elements[1],
        LODWORD(v66.elements[2]));
      v26 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v25 + 4) + 20) + *(_DWORD *)(v25 + 4));
      v27 = (vostok::resources::pinned_ptr_const<unsigned char> *)(v26[1] + 20 * *v26);
      v83 = (float)(*(float *)((char *)v26 + (_DWORD)v27 - 4) - *(float *)((char *)&v26[4 * *v26] + v26[1]))
          * 0.033333335;
      vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
        v27,
        (int)&v78.y);
      m_animation_state->animation_time_threshold = v83;
      v28 = v83 - *(float *)(v23 + 12);
      m_animation_state->animation_interval_time = v28;
      m_animation_state->animation_time = v28 + *(float *)(v23 + 12);
      m_animation_state->is_freezed = 1;
      current_animation_node->m_time_driving_animation = 0;
      v80 = 1;
      v4 = current_animation_node;
    }
    else
    {
      v16 = (v79 & 4) == 0;
      m_animation_state->animation_time = 0.0;
      if ( v16 )
      {
        p_m_first_view_animation = &v4->m_animation_intervals[m_animation_state->animation_interval_id].m_first_view_animation;
        LODWORD(v66.z) = this;
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
          (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v66.elements[2],
          p_m_first_view_animation);
        vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
          v18,
          (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&v78.vector.elements[1],
          LODWORD(v66.elements[2]));
        v20 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v19 + 4) + 20) + *(_DWORD *)(v19 + 4));
        v21 = (vostok::resources::pinned_ptr_const<unsigned char> *)(v20[1] + 20 * *v20);
        m_animation_state->animation_time_threshold = (float)(*(float *)((char *)v20 + (_DWORD)v21 - 4)
                                                            - *(float *)((char *)&v20[4 * *v20] + v20[1]))
                                                    * 0.033333335;
        vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
          v21,
          (int)&v78.y);
        v4 = current_animation_node;
      }
    }
  }
  if ( (v79 & 0x10) == 0 )
  {
LABEL_29:
    if ( (v79 & 4) == 0 )
      goto LABEL_38;
    goto LABEL_30;
  }
  if ( v4->m_playback_type == play_once_and_freeze_at_end )
  {
    m_animation_state->animation_time = v4->m_animation_intervals->m_start_time;
    m_animation_state->animation_time_threshold = 0.0;
    m_animation_state->animation_interval_time = 0.0;
    m_animation_state->is_freezed = 1;
    v4->m_time_driving_animation = 0;
    v80 = 1;
    goto LABEL_29;
  }
  v29 = &v4->m_animation_intervals[m_animation_state->animation_interval_id].m_first_view_animation;
  LODWORD(v66.z) = this;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v66.elements[2],
    v29);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v30,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&v78.vector.elements[1],
    LODWORD(v66.elements[2]));
  v32 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v31 + 4) + 20) + *(_DWORD *)(v31 + 4));
  v33 = (vostok::resources::pinned_ptr_const<unsigned char> *)(v32[1] + 20 * *v32);
  m_animation_state->animation_time = (float)(*(float *)((char *)v32 + (_DWORD)v33 - 4)
                                            - *(float *)((char *)&v32[4 * *v32] + v32[1]))
                                    * 0.033333335;
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v33,
    (int)&v78.y);
  v4 = current_animation_node;
  if ( (v79 & 4) == 0 )
  {
    m_animation_state->animation_time_threshold = 0.0;
    goto LABEL_29;
  }
LABEL_30:
  if ( !m_animation_state->is_freezed )
  {
    animation_interval_time = m_animation_state->event_iterator.m_value.animation_interval_time;
    m_animation_state->previous_animation_interval_id = m_animation_state->animation_interval_id;
    m_animation_state->animation_interval_time = animation_interval_time;
    animation_interval_id = m_animation_state->event_iterator.m_value.animation_interval_id;
    m_animation_state->animation_interval_id = animation_interval_id;
    LODWORD(v66.z) = v4->m_animation_intervals;
    v36 = 20 * animation_interval_id + LODWORD(v66.z);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v66.elements[2],
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)v36);
    vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
      v37,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&v78.vector.elements[1],
      LODWORD(v66.elements[2]));
    v39 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v38 + 4) + 20) + *(_DWORD *)(v38 + 4));
    v40 = (vostok::resources::pinned_ptr_const<unsigned char> *)(16 * *v39);
    v84 = (float)(*(float *)((char *)&v39[5 * *v39 - 1] + v39[1]) - *(float *)((char *)v39 + (_DWORD)v40 + v39[1]))
        * 0.033333335;
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
      v40,
      (int)&v78.y);
    v41 = *(float *)(v36 + 12);
    if ( (float)(*(float *)(v36 + 16) + v41) <= v84 || (float)(v41 + m_animation_state->animation_interval_time) <= v84 )
      m_animation_state->animation_time_threshold = 0.0;
    else
      m_animation_state->animation_time_threshold = v84;
    vostok::animation::mixing::n_ary_tree::update_animation_time(m_animation_state);
    v4 = current_animation_node;
  }
  if ( !v4->m_time_driving_animation )
  {
    vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::n_ary_tree_time_scale_start_time_modifier(
      (vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier *)m_animation_state->event_iterator.m_value.event_time_in_ms,
      (int)v4,
      v76,
      LODWORD(m_animation_state->animation_interval_time));
    v4 = current_animation_node;
  }
LABEL_38:
  if ( (v79 & 0x40) != 0 && !v4->m_time_driving_animation )
  {
    vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::n_ary_tree_time_scale_start_time_modifier(
      (vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier *)m_animation_state->event_iterator.m_value.event_time_in_ms,
      (int)v4,
      v76,
      LODWORD(m_animation_state->animation_interval_time));
    v4 = current_animation_node;
  }
  if ( (v79 & 0x80u) != 0 )
  {
    v42 = &v4->m_animation_intervals[v4->m_animation_state->animation_interval_id].m_first_view_animation;
    memset(&v72[5], 0, 0x24u);
    v66.z = 0.0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v66.elements[2],
      v42);
    vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
      v43,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v76,
      LODWORD(v66.elements[2]));
    vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>(
      (vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *)&v78.vector.elements[1],
      v44);
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
      v45,
      (int)v76);
    vostok::animation::evaluate_frame(
      (const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *)(LODWORD(v78.z) + *(_DWORD *)(LODWORD(v78.z) + 20)),
      channel_scale_x,
      m_animation_state->animation_time * 30.0,
      &f,
      (vostok::animation::current_frame_position *)&v72[5]);
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
      (vostok::resources::pinned_ptr_const<unsigned char> *)LODWORD(v66.z),
      (int)&v78.y);
    v78.y = f.translation.x - m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.x;
    v78.z = f.translation.y - m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.y;
    v78.w = f.translation.z - m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.z;
    x = f.rotation.x;
    *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.x = *(_QWORD *)&v78.vector.elements[1];
    m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.z = v78.w;
    *(_QWORD *)&v66.x = __PAIR64__(LODWORD(f.rotation.y), LODWORD(x));
    v66.z = f.rotation.z;
    vostok::math::quaternion::quaternion(v47, &v75, v66);
    v49 = v48;
    v50 = vostok::math::conjugate(&m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation, &v78);
    v51 = vostok::math::operator*(v49, v50, &v71);
    v52 = f.scale.x;
    m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation = *v51;
    v78.y = v52 / m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.x;
    v78.z = f.scale.y / m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.y;
    v78.w = f.scale.z / m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.z;
    *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.x = *(_QWORD *)&v78.vector.elements[1];
    m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.z = v78.w;
    v4 = current_animation_node;
    m_animation_state->are_there_any_weight_transitions = 1;
  }
  if ( (v79 & 0x100) != 0 )
  {
    v53 = &v4->m_animation_intervals[v4->m_animation_state->animation_interval_id].m_first_view_animation;
    memset(&v72[5], 0, 0x24u);
    v66.z = 0.0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v66.elements[2],
      v53);
    vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
      v54,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v76,
      LODWORD(v66.elements[2]));
    vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>(
      (vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *)&v78.vector.elements[1],
      v55);
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
      v56,
      (int)v76);
    vostok::animation::evaluate_frame(
      (const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *)(LODWORD(v78.z) + *(_DWORD *)(LODWORD(v78.z) + 20)),
      channel_scale_x,
      m_animation_state->animation_time * 30.0,
      &f,
      (vostok::animation::current_frame_position *)&v72[5]);
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
      (vostok::resources::pinned_ptr_const<unsigned char> *)LODWORD(v66.z),
      (int)&v78.y);
    *(_QWORD *)&v78.vector.elements[1] = *(_QWORD *)&f.translation.x;
    v78.w = f.translation.z;
    v57 = f.rotation.x;
    *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.x = *(_QWORD *)&f.translation.x;
    m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.z = v78.w;
    *(_QWORD *)&v66.x = __PAIR64__(LODWORD(f.rotation.y), LODWORD(v57));
    v66.z = f.rotation.z;
    vostok::math::quaternion::quaternion(v58, &v71.x, v66);
    v59 = f.scale.x;
    LODWORD(v66.z) = m_animation_state->event_iterator.m_value.event_time_in_ms;
    m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.x = *v60;
    m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.y = v60[1];
    m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.z = v60[2];
    v78.y = v59;
    y = f.scale.y;
    m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.w = v60[3];
    *(_QWORD *)&v78.vector.elements[2] = __PAIR64__(LODWORD(f.scale.z), LODWORD(y));
    m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.x = v78.y;
    *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.elements[1] = *(_QWORD *)&v78.vector.elements[2];
    vostok::animation::mixing::n_ary_tree_weight_calculator::n_ary_tree_weight_calculator(
      &v70,
      current_animation_node,
      LODWORD(v66.z));
    vostok::animation::mixing::n_ary_tree_weight_calculator::visit(&v70, current_animation_node);
    qmemcpy(v72, &m_animation_state->event_iterator, sizeof(v72));
    vostok::animation::mixing::n_ary_tree_event_iterator::operator++(0, (int)v72);
    m_animation_state->are_there_any_weight_transitions = vostok::animation::mixing::n_ary_tree_event_iterator::are_there_any_weight_transitions(
                                                            v62,
                                                            (int)v72);
    v63 = current_animation_node->m_time_driving_animation;
    v64 = v63;
    if ( !v63 )
    {
      v64 = current_animation_node;
      v63 = current_animation_node;
    }
    vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::n_ary_tree_time_scale_start_time_modifier(
      (vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier *)m_animation_state->event_iterator.m_value.event_time_in_ms,
      (int)v63,
      v76,
      LODWORD(v64->m_animation_state->animation_interval_time));
  }
  return v80;
}
