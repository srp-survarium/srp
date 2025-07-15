void __userpurge vostok::animation::mixing::n_ary_tree_deserializer::n_ary_tree_deserializer(
        vostok::animation::mixing::n_ary_tree_deserializer *this@<ecx>,
        float a2@<xmm4>,
        vostok::animation::mixing::n_ary_tree_deserializer *data_buffer,
        vostok::network_core::buffer_reader *tree_buffer,
        vostok::mutable_buffer *a4)
{
  char *m_data; // eax
  vostok::mutable_buffer *m_buffer; // eax
  vostok::mutable_buffer *v8; // eax
  vostok::mutable_buffer *v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  int v13; // edx
  unsigned int v14; // edx
  vostok::mutable_buffer *v15; // ecx
  vostok::mutable_buffer *v16; // eax
  int v17; // edi
  vostok::mutable_buffer *v18; // eax
  unsigned int v19; // eax
  vostok::animation::mixing::animation_state *v20; // ecx
  vostok::mutable_buffer *v21; // eax
  vostok::animation::mixing::animated_object_holder *v22; // ecx
  vostok::animation::mixing::n_ary_tree_event_iterator *v23; // ecx
  void *v24; // esp
  vostok::animation::mixing::n_ary_tree_animation_node **v25; // eax
  vostok::animation::mixing::n_ary_tree_animation_node **v26; // esi
  vostok::animation::mixing::animation_state *m_animation_states; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *m_weight_root; // eax
  bool m_null_weight_found; // al
  vostok::animation::mixing::n_ary_tree_event_iterator *v30; // ecx
  bool v31; // zf
  float v32; // xmm0_4
  _DWORD *p_x; // edi
  _DWORD *v34; // esi
  vostok::math::float3 *p_translation; // edx
  _DWORD *v36; // edi
  _DWORD *v37; // esi
  void *v38; // esp
  vostok::animation::mixing::n_ary_tree_animation_node *v39; // eax
  vostok::animation::mixing::n_ary_tree_animation_node **v40; // esi
  vostok::animation::mixing::n_ary_tree_animation_node **v41; // eax
  int v42; // edx
  int v43; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_root; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v45; // ecx
  unsigned int m_time_synchronization_group_id; // edx
  vostok::animation::mixing::n_ary_tree_intrusive_base *v47; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v48; // [esp+0h] [ebp-B4h] BYREF
  _BYTE v49[12]; // [esp+4h] [ebp-B0h] BYREF
  vostok::animation::mixing::animation_event result; // [esp+10h] [ebp-A4h] BYREF
  unsigned int animation_interval_id; // [esp+20h] [ebp-94h]
  float animation_interval_time; // [esp+24h] [ebp-90h]
  unsigned int event_time_in_ms; // [esp+28h] [ebp-8Ch]
  int v54; // [esp+2Ch] [ebp-88h]
  float v55; // [esp+30h] [ebp-84h]
  float v56; // [esp+34h] [ebp-80h]
  float v57; // [esp+38h] [ebp-7Ch]
  float v58; // [esp+3Ch] [ebp-78h]
  float v59; // [esp+40h] [ebp-74h]
  float v60; // [esp+44h] [ebp-70h]
  float v61; // [esp+48h] [ebp-6Ch]
  float v62; // [esp+4Ch] [ebp-68h]
  float v63; // [esp+50h] [ebp-64h]
  float v64; // [esp+54h] [ebp-60h]
  float v65; // [esp+58h] [ebp-5Ch]
  vostok::animation::mixing::n_ary_tree_weight_calculator v66; // [esp+5Ch] [ebp-58h] BYREF
  _DWORD v67[3]; // [esp+80h] [ebp-34h] BYREF
  float v68; // [esp+8Ch] [ebp-28h]
  float v69; // [esp+90h] [ebp-24h]
  float v70; // [esp+94h] [ebp-20h]
  _DWORD v71[3]; // [esp+98h] [ebp-1Ch] BYREF
  char *v72; // [esp+A4h] [ebp-10h]
  vostok::animation::mixing::n_ary_tree *v73; // [esp+A8h] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_animation_node **v74; // [esp+ACh] [ebp-8h]
  vostok::animation::mixing::n_ary_tree_deserializer *v75; // [esp+BCh] [ebp+8h]
  vostok::animation::mixing::n_ary_tree_deserializer *v76; // [esp+BCh] [ebp+8h]
  vostok::animation::mixing::n_ary_tree_deserializer *v77; // [esp+BCh] [ebp+8h]
  vostok::animation::mixing::n_ary_tree_animation_node *v78; // [esp+BCh] [ebp+8h]
  unsigned int v79; // [esp+C0h] [ebp+Ch]
  vostok::animation::mixing::animation_state *v80; // [esp+C4h] [ebp+10h]

  data_buffer->m_result.m_object = 0;
  data_buffer->m_times_in_ms.m_begin = (unsigned int *)data_buffer->m_times_in_ms.m_buffer;
  data_buffer->m_times_in_ms.m_end = (unsigned int *)data_buffer->m_times_in_ms.m_buffer;
  data_buffer->m_times_in_ms.m_max_end = (unsigned int *)&data_buffer->m_floats;
  data_buffer->m_floats.m_begin = (float *)data_buffer->m_floats.m_buffer;
  data_buffer->m_floats.m_end = (float *)data_buffer->m_floats.m_buffer;
  data_buffer->m_floats.m_max_end = (float *)&data_buffer->m_buffer;
  data_buffer->m_buffer = a4;
  vostok::animation::mixing::n_ary_tree_deserializer::decode_data(
    (vostok::animation::mixing::n_ary_tree_deserializer *)&data_buffer->m_buffer,
    data_buffer,
    tree_buffer);
  m_data = data_buffer->m_buffer->m_data;
  *(_DWORD *)m_data = -1315241803;
  v72 = m_data;
  m_buffer = data_buffer->m_buffer;
  m_buffer->m_size -= 4;
  m_buffer->m_data += 4;
  *(_DWORD *)data_buffer->m_buffer->m_data = 0;
  v8 = data_buffer->m_buffer;
  v8->m_data += 4;
  v8->m_size -= 4;
  v9 = data_buffer->m_buffer;
  v73 = (vostok::animation::mixing::n_ary_tree *)v9->m_data;
  v10 = vostok::math::align_up<unsigned long>(4u);
  v9->m_data += v10;
  v9->m_size -= v10;
  v11 = *--data_buffer->m_times_in_ms.m_end;
  data_buffer->m_actual_time_in_ms = v11;
  v79 = vostok::animation::mixing::n_ary_tree_deserializer::r(data_buffer, 6u);
  v12 = vostok::animation::mixing::n_ary_tree_deserializer::r(data_buffer, 4u);
  v13 = (unsigned __int16)((unsigned __int8)((((((v12 & 0x55) + ((v12 >> 1) & 0x55)) & 0x33)
                                             + ((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555)) >> 2) & 0x33))
                                            & 0xF)
                                           + ((((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555)) & 0x33333333)
                                              + ((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4)
                                            & 0xF))
                         + (unsigned __int8)((unsigned __int16)((((((v12 & 0x5555) + ((v12 >> 1) & 0x5555)) & 0x3333)
                                                                + ((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555)) >> 2)
                                                                 & 0x3333))
                                                               & 0xF0F)
                                                              + ((((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555))
                                                                  & 0x33333333)
                                                                 + ((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555)) >> 2)
                                                                  & 0x33333333)) >> 4)
                                                               & 0xF0F)) >> 8));
  v14 = (((((((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555)) & 0x33333333)
            + ((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555)) >> 2) & 0x33333333))
           & 0xF0F0F0F)
          + ((((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555)) & 0x33333333)
             + ((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4)
           & 0xF0F0F0F))
         & 0xFF00FF)
        + ((((((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555)) & 0x33333333)
             + ((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555)) >> 2) & 0x33333333))
            & 0xF0F0F0F)
           + ((((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555)) & 0x33333333)
              + ((((v12 & 0x55555555) + ((v12 >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4)
            & 0xF0F0F0F)) >> 8)
         & 0xFF00FF)) >> 16)
      + v13;
  v15 = data_buffer->m_buffer;
  data_buffer->m_interpolators_count = v14;
  v14 *= 4;
  data_buffer->m_interpolators = (const vostok::animation::base_interpolator **)v15->m_data;
  v15->m_data += v14;
  v15->m_size -= v14;
  vostok::animation::mixing::n_ary_tree_deserializer::process_interpolators(data_buffer, v12);
  v16 = data_buffer->m_buffer;
  v17 = v79;
  data_buffer->m_animation_states = (vostok::animation::mixing::animation_state *)v16->m_data;
  v16->m_data += 176 * v79;
  v16->m_size -= 176 * v79;
  vostok::animation::mixing::n_ary_tree_deserializer::process_animation_states(data_buffer, v79);
  v18 = data_buffer->m_buffer;
  data_buffer->m_animation_events = (vostok::animation::mixing::animation_state **)v18->m_data;
  v18->m_data += 4 * v79;
  v18->m_size -= 4 * v79;
  v19 = 0;
  if ( v79 )
  {
    v75 = 0;
    do
    {
      v20 = (vostok::animation::mixing::animation_state *)((char *)v75 + (unsigned int)data_buffer->m_animation_states);
      v75 = (vostok::animation::mixing::n_ary_tree_deserializer *)((char *)v75 + 176);
      data_buffer->m_animation_events[v19++] = v20;
    }
    while ( v19 < v79 );
  }
  v21 = data_buffer->m_buffer;
  v22 = (vostok::animation::mixing::animated_object_holder *)v21->m_data;
  data_buffer->m_animated_objects = (vostok::animation::mixing::animated_object_holder *)v21->m_data;
  v21->m_data += 272;
  v21->m_size -= 272;
  vostok::animation::mixing::n_ary_tree_deserializer::process_animated_objects(
    (vostok::animation::mixing::n_ary_tree_deserializer *)v22,
    (int)data_buffer);
  v24 = alloca(72 * v79);
  v25 = &v48;
  v26 = (vostok::animation::mixing::n_ary_tree_animation_node **)&v49[72 * v79 - 4];
  v74 = &v48;
  v76 = (vostok::animation::mixing::n_ary_tree_deserializer *)&v48;
  if ( &v48 != v26 )
  {
    do
    {
      vostok::animation::mixing::n_ary_tree_deserializer::process_animation_node(
        data_buffer,
        (vostok::animation::mixing::n_ary_tree_deserializer::n_ary_tree_animation_node_helper *)v76);
      v76 = (vostok::animation::mixing::n_ary_tree_deserializer *)((char *)v76 + 72);
    }
    while ( v76 != (vostok::animation::mixing::n_ary_tree_deserializer *)v26 );
    v17 = v79;
    v25 = v74;
  }
  data_buffer->m_weight_root = 0;
  data_buffer->m_previous_animation = 0;
  v77 = (vostok::animation::mixing::n_ary_tree_deserializer *)v25;
  if ( v25 != v26 )
  {
    do
    {
      vostok::animation::mixing::n_ary_tree_deserializer::resolve_animation_node(
        (vostok::animation::mixing::n_ary_tree_deserializer::n_ary_tree_animation_node_helper *)v77,
        data_buffer);
      v77 = (vostok::animation::mixing::n_ary_tree_deserializer *)((char *)v77 + 72);
    }
    while ( v77 != (vostok::animation::mixing::n_ary_tree_deserializer *)v26 );
  }
  m_animation_states = data_buffer->m_animation_states;
  m_weight_root = data_buffer->m_weight_root;
  v78 = m_weight_root;
  v80 = m_animation_states;
  v74 = (vostok::animation::mixing::n_ary_tree_animation_node **)&m_animation_states[v17];
  if ( m_animation_states != &m_animation_states[v17] )
  {
    v59 = 0.0;
    v60 = 0.0;
    v61 = 0.0;
    v62 = s_bm_current_air_resistance;
    v68 = s_bm_current_air_resistance;
    v69 = s_bm_current_air_resistance;
    v70 = s_bm_current_air_resistance;
    v55 = 0.0;
    v56 = 0.0;
    v57 = 0.0;
    v58 = s_bm_current_air_resistance;
    v63 = s_bm_current_air_resistance;
    v64 = s_bm_current_air_resistance;
    v65 = s_bm_current_air_resistance;
    while ( 1 )
    {
      m_weight_root->m_animation_state = m_animation_states;
      if ( m_animation_states->is_freezed )
        m_weight_root->m_time_driving_animation = 0;
      m_animation_states->are_there_any_weight_transitions = vostok::animation::mixing::n_ary_tree_event_iterator::are_there_any_weight_transitions(
                                                               v23,
                                                               (int)&m_animation_states->event_iterator);
      v66.m_current_time_in_ms = data_buffer->m_actual_time_in_ms;
      v66.__vftable = (vostok::animation::mixing::n_ary_tree_weight_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_calculator::`vftable';
      memset((void *)&v66.m_animation, 0, 12);
      memset(&v66.m_weight, 0, 13);
      vostok::animation::mixing::n_ary_tree_weight_calculator::visit(&v66, v78);
      m_null_weight_found = v66.m_null_weight_found;
      m_animation_states->weight = v66.m_weight;
      v78->m_is_transitting_to_zero = m_null_weight_found;
      animation_interval_id = m_animation_states->event_iterator.m_animation_event_iterator.m_value.animation_interval_id;
      animation_interval_time = m_animation_states->event_iterator.m_animation_event_iterator.m_value.animation_interval_time;
      event_time_in_ms = m_animation_states->event_iterator.m_animation_event_iterator.m_value.event_time_in_ms;
      v54 = *(_DWORD *)&m_animation_states->event_iterator.m_animation_event_iterator.m_value.event_type;
      v80->event_iterator.m_animation_event_iterator.m_animation = (unsigned __int16)v54 != 0 ? v78 : 0;
      v80->event_iterator.m_weight_event_iterator.m_animation = vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator*(
                                                                  (vostok::animation::mixing::n_ary_tree_weight_event_iterator *)&result,
                                                                  &result)->event_type != 0
                                                              ? v78
                                                              : 0;
      vostok::animation::mixing::n_ary_tree_event_iterator::select_state(
        v30,
        &v80->event_iterator.m_animation_event_iterator.m_value.animation_interval_id);
      v31 = !v80->is_freezed;
      v80->event_iterator.m_animation_node = v78;
      v32 = v31
          ? float_max_31
          : v78->m_animation_intervals[v80->animation_interval_id].m_start_time + v80->animation_interval_time;
      v80->animation_time = v32;
      v31 = !v80->are_there_any_weight_transitions;
      v80->bone_matrices_computer.accumulated_object_movement.rotation.x = v59;
      v80->bone_matrices_computer.accumulated_object_movement.rotation.y = v60;
      v80->bone_matrices_computer.accumulated_object_movement.rotation.z = v61;
      v80->bone_matrices_computer.accumulated_object_movement.rotation.w = v62;
      v80->bone_matrices_computer.accumulated_object_movement.scale.x = v68;
      v80->bone_matrices_computer.accumulated_object_movement.scale.y = v69;
      v80->bone_matrices_computer.accumulated_object_movement.scale.z = v70;
      v80->bone_matrices_computer.previous_object_movement.rotation.x = v55;
      v80->bone_matrices_computer.previous_object_movement.rotation.y = v56;
      v80->bone_matrices_computer.previous_object_movement.rotation.z = v57;
      v80->bone_matrices_computer.previous_object_movement.rotation.w = v58;
      v80->bone_matrices_computer.previous_object_movement.scale.x = v63;
      v80->bone_matrices_computer.previous_object_movement.scale.y = v64;
      v80->bone_matrices_computer.previous_object_movement.scale.z = v65;
      if ( v31 )
      {
        memset(v67, 0, sizeof(v67));
        p_x = (_DWORD *)&v80->bone_matrices_computer.previous_object_movement.translation.x;
        v34 = v67;
        p_translation = &v80->bone_matrices_computer.accumulated_object_movement.translation;
      }
      else
      {
        memset(v71, 0, sizeof(v71));
        p_x = (_DWORD *)&v80->bone_matrices_computer.accumulated_object_movement.translation.x;
        v34 = v71;
        p_translation = &v80->bone_matrices_computer.previous_object_movement.translation;
      }
      *p_x = *v34;
      v37 = v34 + 1;
      v36 = p_x + 1;
      *v36 = *v37;
      v36[1] = v37[1];
      vostok::animation::mixing::n_ary_tree_deserializer::process_translation(data_buffer, p_translation);
      ++v80;
      v78 = v78->m_next_weight_animation;
      if ( v80 == (vostok::animation::mixing::animation_state *)v74 )
        break;
      m_animation_states = v80;
      m_weight_root = v78;
    }
  }
  v38 = alloca(4 * v79);
  v39 = data_buffer->m_weight_root;
  v40 = &v48;
  while ( v39 )
  {
    *v40 = v39;
    v39 = v39->m_next_weight_animation;
    ++v40;
  }
  LOBYTE(v80) = 0;
  stlp_std::sort<vostok::animation::mixing::n_ary_tree_animation_node * *,vostok::animation::mixing::time_animations_predicate>(
    &v48,
    v40,
    (vostok::animation::mixing::n_ary_tree_animation_node **)v80);
  data_buffer->m_time_root = v48;
  v41 = (vostok::animation::mixing::n_ary_tree_animation_node **)v49;
  if ( v49 != (_BYTE *)v40 )
  {
    do
    {
      v42 = (int)*(v41 - 1);
      v43 = (int)*v41++;
      *(_DWORD *)(v42 + 44) = v43;
    }
    while ( v41 != v40 );
  }
  m_time_root = data_buffer->m_time_root;
  v45 = 0;
  while ( m_time_root )
  {
    if ( !v45 )
      goto LABEL_33;
    m_time_synchronization_group_id = m_time_root->m_time_synchronization_group_id;
    if ( v45->m_time_synchronization_group_id != m_time_synchronization_group_id )
      goto LABEL_33;
    if ( m_time_synchronization_group_id != -1 && !m_time_root->m_animation_state->is_freezed )
      m_time_root->m_time_driving_animation = v45;
    if ( v45->m_time_synchronization_group_id != m_time_synchronization_group_id )
LABEL_33:
      v45 = m_time_root;
    m_time_root = m_time_root->m_next_time_animation;
  }
  if ( v73 )
    vostok::animation::mixing::n_ary_tree::n_ary_tree(
      data_buffer->m_animation_states,
      v79,
      a2,
      v73,
      data_buffer->m_weight_root,
      data_buffer->m_time_root,
      data_buffer->m_interpolators,
      data_buffer->m_animation_events,
      data_buffer->m_animated_objects,
      2u,
      data_buffer->m_interpolators_count,
      data_buffer->m_actual_time_in_ms);
  else
    v47 = 0;
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &data_buffer->m_result,
    v47);
  *((_DWORD *)v72 + 1) = data_buffer->m_buffer->m_data - v72;
}
