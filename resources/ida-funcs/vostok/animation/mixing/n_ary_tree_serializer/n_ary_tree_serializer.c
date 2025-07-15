void __thiscall vostok::animation::mixing::n_ary_tree_serializer::n_ary_tree_serializer(
        vostok::animation::mixing::n_ary_tree_serializer *this,
        vostok::animation::mixing::n_ary_tree_serializer *writer,
        vostok::animation::mixing::n_ary_tree *tree,
        const vostok::animation::mixing::n_ary_tree *a4)
{
  unsigned __int8 *v5; // edx
  unsigned __int8 *v6; // ecx
  vostok::buffer_vector<unsigned int> *v7; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v8; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v9; // ecx
  const vostok::animation::base_interpolator **m_interpolators; // edi
  unsigned int m_interpolators_count; // eax
  vostok::animation::mixing::n_ary_tree_serializer *v12; // ecx
  vostok::animation::mixing::animation_state *m_animation_states; // eax
  vostok::animation::mixing::animation_state *v14; // edi
  vostok::animation::mixing::animation_state *v15; // eax
  vostok::animation::mixing::animation_state *v16; // edi
  vostok::animation::mixing::n_ary_tree_serializer *v17; // ecx
  vostok::animation::mixing::animated_object_holder *m_animated_objects; // eax
  vostok::animation::mixing::n_ary_tree_serializer *v19; // ecx
  const vostok::animation::mixing::n_ary_tree *v20; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *m_weight_root; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v22; // eax
  const vostok::animation::base_interpolator **v23; // edi
  float *p_x; // ecx
  unsigned int v25; // eax
  bool v26; // zf
  const vostok::math::float3 *v27; // esi
  unsigned __int8 *v28; // esi
  vostok::animation::mixing::n_ary_tree_serializer *v29; // ecx
  vostok::animation::mixing::n_ary_tree_serializer *v30; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *j; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *k; // ecx
  unsigned __int8 *v33; // eax
  int i; // [esp+Ch] [ebp-64h]
  vostok::animation::mixing::animation_state *v35; // [esp+Ch] [ebp-64h]
  vostok::animation::mixing::animated_object_holder *v36; // [esp+Ch] [ebp-64h]
  vostok::animation::mixing::n_ary_tree_animation_node *m_next_weight_animation; // [esp+Ch] [ebp-64h]
  float *v38; // [esp+Ch] [ebp-64h]
  const vostok::animation::base_interpolator **m_tree_actual_time_in_ms; // [esp+10h] [ebp-60h] BYREF
  float *v40; // [esp+14h] [ebp-5Ch]
  void **v41; // [esp+18h] [ebp-58h] BYREF
  unsigned int v42; // [esp+1Ch] [ebp-54h]
  float v43; // [esp+20h] [ebp-50h]
  float v44; // [esp+24h] [ebp-4Ch]
  float v45; // [esp+28h] [ebp-48h]
  float v46; // [esp+2Ch] [ebp-44h]
  float v47; // [esp+30h] [ebp-40h]
  float v48; // [esp+34h] [ebp-3Ch]
  int v49; // [esp+38h] [ebp-38h]
  int v50; // [esp+3Ch] [ebp-34h]
  int v51; // [esp+40h] [ebp-30h]
  int v52; // [esp+44h] [ebp-2Ch]
  int v53; // [esp+48h] [ebp-28h]
  int v54; // [esp+4Ch] [ebp-24h]
  int v55; // [esp+50h] [ebp-20h]
  int v56; // [esp+54h] [ebp-1Ch]
  int v57; // [esp+58h] [ebp-18h]
  float v58; // [esp+5Ch] [ebp-14h]
  int v59; // [esp+60h] [ebp-10h]
  int v60; // [esp+64h] [ebp-Ch]
  int v61; // [esp+68h] [ebp-8h]
  float v62; // [esp+6Ch] [ebp-4h]

  writer->vostok::animation::mixing::n_ary_tree_visitor::__vftable = (vostok::animation::mixing::n_ary_tree_serializer_vtbl *)&vostok::animation::mixing::n_ary_tree_serializer::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
  writer->vostok::animation::interpolator_visitor::__vftable = (vostok::animation::interpolator_visitor_vtbl *)&vostok::animation::mixing::n_ary_tree_serializer::`vftable'{for `vostok::animation::interpolator_visitor'};
  writer->m_times_in_ms_stream.m_begin = (unsigned int *)writer->m_times_in_ms_stream.m_buffer;
  writer->m_times_in_ms_stream.m_end = (unsigned int *)writer->m_times_in_ms_stream.m_buffer;
  writer->m_times_in_ms_stream.m_max_end = (unsigned int *)&writer->m_floats_stream;
  writer->m_floats_stream.m_begin = (float *)writer->m_floats_stream.m_buffer;
  writer->m_floats_stream.m_end = (float *)writer->m_floats_stream.m_buffer;
  writer->m_floats_stream.m_max_end = (float *)&writer->m_tree;
  writer->m_tree = a4;
  v5 = (unsigned __int8 *)(*((_DWORD *)tree->m_animation_events + 1) + *((_DWORD *)tree->m_animation_events + 3));
  writer->m_bits_stream = v5;
  v6 = (unsigned __int8 *)(*((_DWORD *)tree->m_animation_events + 1) + *((_DWORD *)tree->m_animation_events + 2));
  writer->m_write_operation_id = 0;
  writer->m_bits_stream_end = v6;
  writer->m_current_bit = 7;
  *v5 = 0;
  vostok::animation::mixing::n_ary_tree_serializer::append(
    (vostok::animation::mixing::n_ary_tree_serializer *)v6,
    (int)writer,
    0,
    0x10u);
  m_tree_actual_time_in_ms = (const vostok::animation::base_interpolator **)a4->m_tree_actual_time_in_ms;
  vostok::buffer_vector<unsigned int>::push_back(
    v7,
    (int)&writer->m_times_in_ms_stream,
    (const unsigned int *)&m_tree_actual_time_in_ms);
  vostok::animation::mixing::n_ary_tree_serializer::append(v8, (int)writer, a4->m_animations_count, 6u);
  m_interpolators = a4->m_interpolators;
  m_interpolators_count = a4->m_interpolators_count;
  v42 = 0;
  v41 = &vostok::animation::mixing::n_ary_tree_serializer::interpolators_mask::`vftable';
  for ( m_tree_actual_time_in_ms = &m_interpolators[m_interpolators_count];
        m_interpolators != m_tree_actual_time_in_ms;
        ++m_interpolators )
  {
    (*m_interpolators)->accept(*m_interpolators, (vostok::animation::interpolator_visitor *)&v41);
  }
  vostok::animation::mixing::n_ary_tree_serializer::append(v9, (int)writer, v42, 4u);
  m_animation_states = a4->m_animation_states;
  v14 = &m_animation_states[a4->m_animations_count];
  for ( i = (int)m_animation_states; (vostok::animation::mixing::animation_state *)i != v14; i += 176 )
    vostok::animation::mixing::n_ary_tree_serializer::visit(v12, writer, i);
  v15 = a4->m_animation_states;
  v16 = &v15[a4->m_animations_count];
  v35 = v15;
  if ( v15 != v16 )
  {
    while ( 1 )
    {
      vostok::animation::mixing::n_ary_tree_serializer::visit(v12, writer, (int)&v15->event_iterator);
      vostok::animation::mixing::n_ary_tree_serializer::visit(
        v17,
        (int)writer,
        &v35->event_iterator.m_weight_event_iterator);
      if ( ++v35 == v16 )
        break;
      v15 = v35;
    }
  }
  m_animated_objects = a4->m_animated_objects;
  v36 = m_animated_objects;
  m_tree_actual_time_in_ms = (const vostok::animation::base_interpolator **)&m_animated_objects[1];
  while ( 1 )
  {
    vostok::animation::mixing::n_ary_tree_serializer::visit(writer, m_animated_objects);
    if ( ++v36 == (vostok::animation::mixing::animated_object_holder *)m_tree_actual_time_in_ms )
      break;
    m_animated_objects = v36;
  }
  v20 = a4;
  m_weight_root = a4->m_weight_root;
  while ( m_weight_root )
  {
    vostok::animation::mixing::n_ary_tree_serializer::visit(writer, m_weight_root, v19, v20);
    m_weight_root = m_weight_root->m_next_weight_animation;
    v20 = a4;
  }
  v22 = v20->m_weight_root;
  m_next_weight_animation = v22;
  if ( v22 )
  {
    while ( 1 )
    {
      v23 = (const vostok::animation::base_interpolator **)&v22[1];
      m_tree_actual_time_in_ms = (const vostok::animation::base_interpolator **)(&v22[1].__vftable
                                                                               + v22->m_operands_count);
      if ( &v22[1] != (vostok::animation::mixing::n_ary_tree_animation_node *)m_tree_actual_time_in_ms )
      {
        do
        {
          (*v23)->clone(*v23, (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)writer);
          ++v23;
        }
        while ( v23 != m_tree_actual_time_in_ms );
        v22 = m_next_weight_animation;
      }
      m_next_weight_animation = v22->m_next_weight_animation;
      if ( !m_next_weight_animation )
        break;
      v22 = v22->m_next_weight_animation;
    }
  }
  p_x = &v20->m_animation_states->bone_matrices_computer.previous_object_movement.rotation.x;
  v38 = p_x;
  v40 = &p_x[44 * v20->m_animations_count];
  if ( p_x != v40 )
  {
    v25 = (unsigned int)(p_x + 17);
    v55 = 0;
    v56 = 0;
    v57 = 0;
    v58 = s_bm_current_air_resistance;
    v43 = s_bm_current_air_resistance;
    v44 = s_bm_current_air_resistance;
    v45 = s_bm_current_air_resistance;
    v59 = 0;
    v60 = 0;
    v61 = 0;
    v62 = s_bm_current_air_resistance;
    v46 = s_bm_current_air_resistance;
    v47 = s_bm_current_air_resistance;
    v48 = s_bm_current_air_resistance;
    for ( m_tree_actual_time_in_ms = (const vostok::animation::base_interpolator **)(p_x + 17);
          ;
          v25 = (unsigned int)m_tree_actual_time_in_ms )
    {
      v26 = *(_BYTE *)(v25 + 48) == 0;
      *(_DWORD *)(v25 - 28) = v55;
      *(_DWORD *)(v25 - 28 + 4) = v56;
      *(_DWORD *)(v25 - 28 + 8) = v57;
      *(float *)(v25 - 28 + 12) = v58;
      *(float *)v25 = v43;
      *(float *)(v25 + 4) = v44;
      *(float *)(v25 + 8) = v45;
      *(_DWORD *)p_x = v59;
      *((_DWORD *)p_x + 1) = v60;
      *((_DWORD *)p_x + 2) = v61;
      p_x[3] = v62;
      *(float *)(v25 - 40) = v46;
      *(float *)(v25 - 40 + 4) = v47;
      *(float *)(v25 - 40 + 8) = v48;
      if ( v26 )
      {
        v52 = 0;
        v53 = 0;
        v54 = 0;
        *(_DWORD *)(v25 - 52) = 0;
        *(_DWORD *)(v25 - 52 + 4) = v53;
        *(_DWORD *)(v25 - 52 + 8) = v54;
        v27 = (const vostok::math::float3 *)(v25 - 12);
      }
      else
      {
        v49 = 0;
        v50 = 0;
        v51 = 0;
        *(_DWORD *)(v25 - 12) = 0;
        *(_DWORD *)(v25 - 12 + 4) = v50;
        *(_DWORD *)(v25 - 12 + 8) = v51;
        v27 = (const vostok::math::float3 *)(v25 - 52);
      }
      vostok::animation::mixing::n_ary_tree_serializer::visit_translation(v27, writer);
      v38 += 44;
      m_tree_actual_time_in_ms += 44;
      if ( v38 == v40 )
        break;
      p_x = v38;
    }
  }
  v28 = (unsigned __int8 *)(*((_DWORD *)tree->m_animation_events + 1) + *((_DWORD *)tree->m_animation_events + 3));
  vostok::animation::mixing::n_ary_tree_serializer::save_bits(writer, v28);
  vostok::animation::mixing::n_ary_tree_serializer::save_times_in_ms(v29, (int)writer);
  vostok::animation::mixing::n_ary_tree_serializer::save_floats(v30, (int)writer);
  for ( j = a4->m_weight_root; j; j = j->m_next_weight_animation )
    ;
  for ( k = a4->m_time_root; k; k = k->m_next_time_animation )
    ;
  v33 = (unsigned __int8 *)(writer->m_bits_stream - v28);
  if ( writer->m_current_bit != 7 )
    ++v33;
  vostok::network_core::mutable_buffer::resize(
    (vostok::network_core::mutable_buffer *)tree->m_animation_events,
    (unsigned int)&v33[*((_DWORD *)tree->m_animation_events + 3)]);
}
