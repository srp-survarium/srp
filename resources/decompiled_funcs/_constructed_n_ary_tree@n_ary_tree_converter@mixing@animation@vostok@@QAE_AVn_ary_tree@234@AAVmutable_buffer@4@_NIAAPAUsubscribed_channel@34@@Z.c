vostok::mutable_buffer *__thiscall vostok::animation::mixing::n_ary_tree_converter::constructed_n_ary_tree(
        vostok::animation::mixing::n_ary_tree_converter *this,
        vostok::animation::mixing::n_ary_tree_animation_node *result,
        vostok::mutable_buffer *buffer,
        vostok::mutable_buffer *is_final_tree,
        char *current_time_in_ms,
        vostok::animation::subscribed_channel **channels_head)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // esi
  unsigned int *v7; // edi
  _DWORD *p_x; // eax
  int v9; // eax
  const vostok::animation::base_interpolator **m_pthis; // ebx
  const vostok::animation::base_interpolator **v11; // eax
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v12; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  const vostok::animation::base_interpolator **m_animation_intervals; // edx
  vostok::animation::mixing::animated_object_holder *m_weight_driving_animation; // ecx
  const vostok::animation::base_interpolator **m_pFunction; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_next_time_animation; // edx
  vostok::animation::mixing::n_ary_tree_animation_node *v21; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *m_operands_count; // eax
  unsigned int m_time_synchronization_group_id; // eax
  const vostok::animation::mixing::animation_interval *v24; // edx
  unsigned int v25; // eax
  void (__thiscall ***v26)(_DWORD, _DWORD); // ecx
  bool v27; // zf
  unsigned int v28; // eax
  unsigned int v29; // eax
  unsigned int v30; // ecx
  interpolator_predicate v31; // edx
  void (__thiscall ***v32)(_DWORD, _DWORD); // ecx
  void (__thiscall ***v33)(_DWORD, _DWORD); // ecx
  vostok::animation::mixing::animation_interval *m_weight_interpolator; // esi
  const vostok::animation::mixing::animation_interval *v35; // edx
  const vostok::animation::mixing::animation_interval *v36; // eax
  vostok::animation::mixing::animation_interval *v37; // eax
  vostok::animation::mixing::animated_object_holder *v38; // esi
  unsigned int user_data; // eax
  unsigned int v40; // ecx
  int v41; // edx
  unsigned int m_time_driving_animation; // ecx
  char v43; // al
  unsigned int v44; // edi
  char v45; // dl
  unsigned __int8 v46; // al
  unsigned int v47; // eax
  char m_weight_driving_animation_high; // al
  unsigned int v49; // edx
  unsigned int v50; // edi
  unsigned int v51; // ecx
  vostok::animation::mixing::playback_enum m_playback_type; // ecx
  vostok::animation::mixing::n_ary_tree_base_node **m_data; // edi
  unsigned int v54; // eax
  unsigned int v55; // eax
  unsigned int v56; // ecx
  float v57; // xmm0_4
  const vostok::animation::base_interpolator **v58; // eax
  char *v59; // ecx
  int v60; // xmm0_4
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v61; // xmm1_4
  _DWORD *j; // esi
  vostok::animation::mixing::n_ary_tree_base_node **v63; // esi
  int v64; // eax
  int k; // ecx
  vostok::animation::mixing::animation_state **v66; // eax
  const vostok::animation::base_interpolator **v67; // esi
  unsigned int v68; // eax
  unsigned int v69; // ecx
  vostok::render::skeleton_model_instance *(__thiscall *v70)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  unsigned int m_animation_intervals_count; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v72; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v73; // ecx
  void *v74; // esp
  vostok::animation::mixing::binary_tree_animation_node *v75; // eax
  vostok::animation::mixing::binary_tree_animation_node *m_object; // edi
  const vostok::animation::base_interpolator **v77; // ebx
  vostok::animation::mixing::binary_tree_animation_node *v78; // eax
  vostok::animation::mixing::binary_tree_animation_node *v79; // ecx
  vostok::render::skeleton_model_instance *(__thiscall *v80)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // eax
  vostok::animation::mixing::n_ary_tree *m_n_ary_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v82; // edi
  vostok::animation::mixing::binary_tree_animation_node *v83; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v84; // edx
  vostok::animation::mixing::n_ary_tree_animation_node *v85; // eax
  vostok::animation::mixing::animation_state *m_animation_state; // ebx
  unsigned int animation_interval_id; // edi
  vostok::animation::mixing::animation_interval *v88; // ecx
  double v89; // st7
  unsigned int v90; // eax
  double v91; // st7
  vostok::animation::mixing::binary_tree_animation_node *v92; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v93; // eax
  vostok::animation::mixing::binary_tree_animation_node *v94; // ecx
  char **v95; // ecx
  int v96; // eax
  int m; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node **v98; // edi
  const vostok::animation::base_interpolator **v99; // eax
  int v100; // edx
  int v101; // edi
  char *v102; // eax
  unsigned int v103; // ecx
  char *m_next_weight_animation; // edx
  unsigned int m_animated_object; // ebx
  char *v106; // edi
  unsigned int v107; // esi
  char *v108; // eax
  unsigned int v110; // [esp+8h] [ebp-D4h]
  vostok::animation::mixing::n_ary_tree_animation_node *v111; // [esp+Ch] [ebp-D0h]
  vostok::animation::mixing::playback_enum v112; // [esp+10h] [ebp-CCh]
  unsigned int v113; // [esp+18h] [ebp-C4h]
  float animation_interval_time; // [esp+24h] [ebp-B8h]
  float start_time; // [esp+30h] [ebp-ACh]
  float length; // [esp+34h] [ebp-A8h]
  _BYTE v117[16]; // [esp+38h] [ebp-A4h] BYREF
  vostok::animation::mixing::n_ary_tree_weight_calculator weight_calculator; // [esp+48h] [ebp-94h] BYREF
  vostok::animation::mixing::n_ary_tree_node_constructor node_constructor; // [esp+68h] [ebp-74h] BYREF
  bool v120[4]; // [esp+7Ch] [ebp-60h]
  unsigned __int8 unique_animation_id[4]; // [esp+80h] [ebp-5Ch]
  bool override_existing_animation[4]; // [esp+84h] [ebp-58h]
  bool v123[4]; // [esp+88h] [ebp-54h]
  bool is_positive_event_direction[4]; // [esp+8Ch] [ebp-50h]
  bool v125[4]; // [esp+90h] [ebp-4Ch]
  bool can_generate_user_defined_events[4]; // [esp+94h] [ebp-48h]
  vostok::animation::mixing::n_ary_tree_animation_node *previous; // [esp+98h] [ebp-44h]
  unsigned int v128; // [esp+9Ch] [ebp-40h]
  vostok::animation::mixing::animation_state **event; // [esp+A0h] [ebp-3Ch]
  node_predicate __comp[4]; // [esp+A4h] [ebp-38h]
  vostok::animation::mixing::n_ary_tree_animation_node *weight_driving_animation; // [esp+A8h] [ebp-34h]
  const vostok::animation::mixing::animation_interval *intervals_end; // [esp+ACh] [ebp-30h] BYREF
  void (__thiscall ***v133)(_DWORD, _DWORD); // [esp+B0h] [ebp-2Ch]
  vostok::animation::mixing::animated_object_holder *animated_objects_end; // [esp+B4h] [ebp-28h]
  vostok::animation::mixing::n_ary_tree_base_node **multiplicands_begin; // [esp+B8h] [ebp-24h]
  vostok::animation::mixing::n_ary_tree_animation_node *weight_root; // [esp+BCh] [ebp-20h]
  vostok::animation::mixing::n_ary_tree_animation_node *time_driving_animation; // [esp+C0h] [ebp-1Ch]
  const vostok::animation::base_interpolator **e; // [esp+C4h] [ebp-18h]
  unsigned int operands_count; // [esp+C8h] [ebp-14h]
  const vostok::animation::mixing::animation_interval *cloned_intervals_begin; // [esp+CCh] [ebp-10h]
  bool v141; // [esp+D3h] [ebp-9h]
  int v142; // [esp+D4h] [ebp-8h]
  char *animation; // [esp+E4h] [ebp+8h]
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> i; // [esp+ECh] [ebp+10h]
  vostok::animation::subscribed_channel **channels_heada; // [esp+F4h] [ebp+18h]

  v6 = result;
  v7 = (unsigned int *)is_final_tree;
  result->m_animation_state = (vostok::animation::mixing::animation_state *)is_final_tree->m_data;
  is_final_tree->m_data += 4;
  is_final_tree->m_size -= 4;
  p_x = (_DWORD *)&result->m_animation_state->bone_matrices_computer.previous_object_movement.rotation.x;
  v142 = 0;
  if ( p_x )
    *p_x = 0;
  v9 = 4 * (int)result->m_next_time_animation;
  result->m_time_calculator.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))is_final_tree->m_data;
  is_final_tree->m_data += v9;
  is_final_tree->m_size -= v9;
  m_pthis = (const vostok::animation::base_interpolator **)result->m_time_calculator.m_Closure.m_pthis;
  v11 = &m_pthis[(int)result->m_next_time_animation];
  weight_root = (vostok::animation::mixing::n_ary_tree_animation_node *)result->m_time_calculator.m_Closure.m_pFunction;
  for ( e = v11; m_pthis != e; weight_root = (vostok::animation::mixing::n_ary_tree_animation_node *)&v13->m_operands_count )
  {
    v12 = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)(*m_pthis)->clone(*m_pthis, is_final_tree);
    v13 = weight_root;
    weight_root->__vftable = v12;
    ++m_pthis;
  }
  v14 = 180 * (int)result->m_animated_object;
  result->m_animation_intervals = (const vostok::animation::mixing::animation_interval *const)is_final_tree->m_data;
  is_final_tree->m_data += v14;
  is_final_tree->m_size -= v14;
  v15 = 4 * (int)result->m_animated_object;
  result->m_time_driving_animation = (vostok::animation::mixing::n_ary_tree_animation_node *)is_final_tree->m_data;
  is_final_tree->m_data += v15;
  is_final_tree->m_size -= v15;
  v16 = 136 * (int)result->m_next_weight_animation;
  result->m_weight_driving_animation = (vostok::animation::mixing::n_ary_tree_animation_node *const)is_final_tree->m_data;
  is_final_tree->m_data += v16;
  is_final_tree->m_size -= v16;
  m_animation_intervals = (const vostok::animation::base_interpolator **)result->m_animation_intervals;
  m_weight_driving_animation = (vostok::animation::mixing::animated_object_holder *)result->m_weight_driving_animation;
  event = (vostok::animation::mixing::animation_state **)result->m_time_driving_animation;
  m_pFunction = (const vostok::animation::base_interpolator **)result->m_time_calculator.m_Closure.m_pFunction;
  e = m_animation_intervals;
  m_next_time_animation = result->m_next_time_animation;
  node_constructor.m_interpolators_begin = m_pFunction;
  v21 = 0;
  node_constructor.m_interpolators_end = &m_pFunction[(_DWORD)m_next_time_animation];
  m_operands_count = (vostok::animation::mixing::n_ary_tree_animation_node *)result->m_operands_count;
  weight_root = 0;
  previous = 0;
  animated_objects_end = m_weight_driving_animation;
  node_constructor.__vftable = (vostok::animation::mixing::n_ary_tree_node_constructor_vtbl *)&vostok::animation::mixing::n_ary_tree_node_constructor::`vftable';
  node_constructor.m_buffer = is_final_tree;
  node_constructor.m_result = 0;
  if ( m_operands_count )
  {
    ++m_operands_count->m_animation_intervals;
    v21 = m_operands_count;
  }
  while ( v21 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v27 = v21->m_animation_intervals-- == (const vostok::animation::mixing::animation_interval *const)1;
      if ( v27 )
        ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_animation_node *, _DWORD))v21->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node)(
          v21,
          0);
      break;
    }
    if ( !LOBYTE(v21[1].m_animation_state) )
    {
      m_time_synchronization_group_id = v21->m_time_synchronization_group_id;
      v24 = 0;
      cloned_intervals_begin = 0;
      if ( m_time_synchronization_group_id )
      {
        ++*(_DWORD *)(m_time_synchronization_group_id + 16);
        v142 |= 1u;
        v24 = (const vostok::animation::mixing::animation_interval *)m_time_synchronization_group_id;
        v25 = v21->m_time_synchronization_group_id;
        v26 = 0;
        cloned_intervals_begin = v24;
        v133 = 0;
        if ( v25 )
        {
          ++*(_DWORD *)(v25 + 16);
          v26 = (void (__thiscall ***)(_DWORD, _DWORD))v25;
          v133 = (void (__thiscall ***)(_DWORD, _DWORD))v25;
        }
        weight_driving_animation = (vostok::animation::mixing::n_ary_tree_animation_node *)v26[14];
      }
      else
      {
        v26 = v133;
        weight_driving_animation = 0;
      }
      if ( (v142 & 1) != 0 )
      {
        v142 &= ~1u;
        if ( v26 )
        {
          v27 = v26[4] == (void (__thiscall **)(_DWORD, _DWORD))1;
          v26[4] = (void (__thiscall **)(_DWORD, _DWORD))((char *)v26[4] - 1);
          if ( v27 )
          {
            (**v133)(v133, 0);
            v24 = cloned_intervals_begin;
          }
        }
      }
      if ( v24 )
      {
        v27 = LODWORD(v24[1].m_start_time)-- == 1;
        if ( v27 )
          ((void (__thiscall *)(const vostok::animation::mixing::animation_interval *, _DWORD))cloned_intervals_begin->m_animation.m_object->__vftable)(
            cloned_intervals_begin,
            0);
      }
      v28 = v21->m_time_synchronization_group_id;
      operands_count = 0;
      if ( v28 )
      {
        v142 |= 2u;
        ++*(_DWORD *)(v28 + 16);
        operands_count = v28;
        v29 = v21->m_time_synchronization_group_id;
        v30 = 0;
        v128 = 0;
        if ( v29 )
        {
          ++*(_DWORD *)(v29 + 16);
          v30 = v29;
          v128 = v29;
        }
        v31.m_interpolator = *(const vostok::animation::base_interpolator **)(v30 + 36);
      }
      else
      {
        v31.m_interpolator = (const vostok::animation::base_interpolator *)v21->m_animated_object;
      }
      *(float *)&multiplicands_begin = COERCE_FLOAT(
                                         stlp_std::priv::__find_if<vostok::animation::base_interpolator const * *,interpolator_predicate>(
                                           (const vostok::animation::base_interpolator **)v6->m_time_calculator.m_Closure.m_pFunction,
                                           (const vostok::animation::base_interpolator **)v6->m_time_calculator.m_Closure.m_pFunction
                                         + (int)v6->m_next_time_animation,
                                           v31));
      if ( (v142 & 2) != 0 )
      {
        v32 = (void (__thiscall ***)(_DWORD, _DWORD))v128;
        v142 &= ~2u;
        if ( v128 )
        {
          v27 = (*(_DWORD *)(v128 + 16))-- == 1;
          if ( v27 )
            (**v32)(v32, 0);
        }
      }
      v33 = (void (__thiscall ***)(_DWORD, _DWORD))operands_count;
      if ( operands_count )
      {
        v27 = (*(_DWORD *)(operands_count + 16))-- == 1;
        if ( v27 )
          (**v33)(v33, 0);
      }
      m_weight_interpolator = (vostok::animation::mixing::animation_interval *)v21->m_weight_interpolator;
      v35 = (const vostok::animation::mixing::animation_interval *)*v7;
      v36 = &m_weight_interpolator[v21->m_additivity_priority];
      intervals_end = v36;
      for ( cloned_intervals_begin = v35; m_weight_interpolator != v36; ++m_weight_interpolator )
      {
        operands_count = *v7;
        if ( operands_count )
        {
          length = vostok::animation::mixing::animation_interval::length(m_weight_interpolator);
          start_time = vostok::animation::mixing::animation_interval::start_time(m_weight_interpolator);
          v37 = vostok::animation::mixing::animation_interval::animation(m_weight_interpolator);
          vostok::animation::mixing::animation_interval::animation_interval(
            (vostok::animation::mixing::animation_interval *)operands_count,
            &v37->m_animation,
            start_time,
            length);
          v36 = intervals_end;
        }
        *v7 += 12;
        v7[1] -= 12;
      }
      v38 = animated_objects_end;
      intervals_end = (const vostok::animation::mixing::animation_interval *)v21->m_next_time_animation;
      if ( stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
             (vostok::animation::mixing::animated_object_holder *)result->m_weight_driving_animation,
             animated_objects_end,
             (const void *const *)&intervals_end) == v38 )
      {
        animated_objects_end = v38 + 1;
        if ( v38 )
        {
          v38->animated_object = v21->m_next_time_animation;
          v38->need_new_transform = 0;
        }
      }
      user_data = v21->user_data;
      v142 |= 4u;
      v40 = 0;
      if ( user_data )
      {
        ++*(_DWORD *)(user_data + 16);
        v40 = user_data;
        goto LABEL_43;
      }
      if ( *(float *)&v21[1].__vftable == *(float *)&clear_value )
LABEL_43:
        v41 = 0;
      else
        v41 = 1;
      operands_count = v41 + v21->m_start_cycle_interval_id;
      if ( (v142 & 4) != 0 )
      {
        v142 &= ~4u;
        if ( v40 )
        {
          v27 = (*(_DWORD *)(v40 + 16))-- == 1;
          if ( v27 )
            (**(void (__thiscall ***)(unsigned int, _DWORD))v40)(v40, 0);
        }
      }
      if ( weight_driving_animation )
      {
        if ( is_final_tree->m_data )
        {
          m_time_driving_animation = (unsigned int)v21[1].m_time_driving_animation;
          v43 = BYTE2(v21[1].m_weight_driving_animation);
          v44 = (unsigned int)v21[1].m_animation_intervals;
          can_generate_user_defined_events[0] = HIBYTE(v21[1].m_weight_driving_animation);
          v45 = BYTE1(v21[1].m_weight_driving_animation);
          is_positive_event_direction[0] = v43;
          v46 = (unsigned __int8)v21[1].m_weight_driving_animation;
          override_existing_animation[0] = v45;
          v113 = (unsigned int)v21[1].m_time_calculator.m_Closure.m_pthis;
          v112 = v21[1].m_operands_count;
          v111 = v21->m_next_time_animation;
          v110 = *(_DWORD *)&v21->m_can_generate_events;
          unique_animation_id[0] = v46;
          vostok::animation::mixing::n_ary_tree_animation_node::n_ary_tree_animation_node(
            weight_driving_animation,
            &cloned_intervals_begin[v21->m_additivity_priority],
            (vostok::animation::mixing::n_ary_tree_animation_node *)is_final_tree->m_data,
            cloned_intervals_begin,
            v46,
            v110,
            v111,
            v112,
            (const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *)&v21->m_time_driving_animation,
            v113,
            v45,
            is_positive_event_direction[0],
            can_generate_user_defined_events[0],
            v44,
            m_time_driving_animation,
            operands_count,
            0);
          goto LABEL_56;
        }
LABEL_55:
        v47 = 0;
LABEL_56:
        cloned_intervals_begin = (const vostok::animation::mixing::animation_interval *)v47;
      }
      else
      {
        if ( !is_final_tree->m_data )
          goto LABEL_55;
        m_weight_driving_animation_high = HIBYTE(v21[1].m_weight_driving_animation);
        v49 = (unsigned int)v21[1].m_time_driving_animation;
        v50 = (unsigned int)v21[1].m_animation_intervals;
        v120[0] = BYTE2(v21[1].m_weight_driving_animation);
        LOBYTE(time_driving_animation) = v21[1].m_weight_driving_animation;
        v123[0] = m_weight_driving_animation_high;
        v51 = (unsigned int)v21[1].m_time_calculator.m_Closure.m_pFunction;
        v125[0] = BYTE1(v21[1].m_weight_driving_animation);
        vostok::animation::mixing::n_ary_tree_animation_node::n_ary_tree_animation_node(
          (vostok::animation::mixing::n_ary_tree_animation_node *)is_final_tree->m_data,
          cloned_intervals_begin,
          &cloned_intervals_begin[v21->m_additivity_priority],
          (unsigned __int8)time_driving_animation,
          *(_DWORD *)&v21->m_can_generate_events,
          (const vostok::animation::base_interpolator *)*multiplicands_begin,
          v21->m_next_time_animation,
          (vostok::animation::mixing::playback_enum)v21[1].m_operands_count,
          (const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *)&v21->m_time_driving_animation,
          (unsigned int)v21[1].m_time_calculator.m_Closure.m_pthis,
          v51,
          v125[0],
          v120[0],
          m_weight_driving_animation_high,
          v50,
          v49,
          operands_count,
          0);
        cloned_intervals_begin = (const vostok::animation::mixing::animation_interval *)v47;
      }
      m_playback_type = v21->m_playback_type;
      v21->m_weight_synchronization_group_id = v47;
      *(_DWORD *)(v47 + 48) = m_playback_type;
      is_final_tree->m_data += 88;
      is_final_tree->m_size -= 88;
      if ( weight_root )
      {
        previous->m_next_weight_animation = (vostok::animation::mixing::n_ary_tree_animation_node *)v47;
      }
      else
      {
        weight_root = (vostok::animation::mixing::n_ary_tree_animation_node *)v47;
        *(_DWORD *)(v47 + 40) = 0;
      }
      m_data = (vostok::animation::mixing::n_ary_tree_base_node **)is_final_tree->m_data;
      v142 |= 8u;
      previous = (vostok::animation::mixing::n_ary_tree_animation_node *)cloned_intervals_begin;
      v54 = operands_count;
      is_final_tree->m_size -= 4 * operands_count;
      is_final_tree->m_data = (char *)&m_data[v54];
      v55 = v21->user_data;
      v56 = 0;
      if ( v55 )
      {
        ++*(_DWORD *)(v55 + 16);
        v56 = v55;
        goto LABEL_63;
      }
      v57 = *(float *)&v21[1].__vftable;
      v141 = 1;
      if ( v57 == *(float *)&clear_value )
LABEL_63:
        v141 = 0;
      if ( (v142 & 8) != 0 )
      {
        v142 &= ~8u;
        if ( v56 )
        {
          v27 = (*(_DWORD *)(v56 + 16))-- == 1;
          if ( v27 )
            (**(void (__thiscall ***)(unsigned int, _DWORD))v56)(v56, 0);
        }
      }
      if ( v141 )
      {
        v58 = stlp_std::priv::__find_if<vostok::animation::base_interpolator const * *,interpolator_predicate>(
                (const vostok::animation::base_interpolator **)result->m_time_calculator.m_Closure.m_pFunction,
                (const vostok::animation::base_interpolator **)result->m_time_calculator.m_Closure.m_pFunction
              + (int)result->m_next_time_animation,
                (interpolator_predicate)v21->m_next_weight_animation);
        v59 = is_final_tree->m_data;
        if ( is_final_tree->m_data )
        {
          v60 = *(_DWORD *)&v21->m_unique_animation_id;
          v61 = v21[1].__vftable;
          *((_DWORD *)v59 + 1) = *v58;
          *(_DWORD *)v59 = &vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
          *((_DWORD *)v59 + 2) = v61;
          *((_DWORD *)v59 + 3) = v60;
          *((_DWORD *)v59 + 4) = current_time_in_ms;
        }
        else
        {
          v59 = 0;
        }
        is_final_tree->m_data += 20;
        is_final_tree->m_size -= 20;
        *m_data++ = (vostok::animation::mixing::n_ary_tree_base_node *)v59;
      }
      if ( v21->m_start_cycle_interval_id )
      {
        multiplicands_begin = m_data;
        fill_weights((vostok::animation::mixing::binary_tree_animation_node *)v21);
        for ( j = (_DWORD *)v21->m_operands_count; j; j = (_DWORD *)j[1] )
        {
          if ( !j[2] )
          {
            (*(void (__thiscall **)(_DWORD *, vostok::animation::mixing::n_ary_tree_node_constructor *))(*j + 4))(
              j,
              &node_constructor);
            *m_data++ = node_constructor.m_result;
          }
        }
        v63 = multiplicands_begin;
        __comp[0] = 0;
        if ( multiplicands_begin != m_data )
        {
          v64 = m_data - multiplicands_begin;
          for ( k = 0; v64 != 1; ++k )
            v64 >>= 1;
          stlp_std::priv::__introsort_loop<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,int,node_predicate>(
            multiplicands_begin,
            m_data,
            0,
            2 * k,
            *(vostok::animation::mixing::n_ary_tree_base_node ***)__comp);
          stlp_std::priv::__final_insertion_sort<vostok::animation::mixing::n_ary_tree_base_node * *,node_predicate>(
            v63,
            m_data,
            __comp[0]);
        }
      }
      v66 = event;
      v67 = e;
      *event = (vostok::animation::mixing::animation_state *)e;
      event = v66 + 1;
      weight_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_weight_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_calculator::`vftable';
      memset((void *)&weight_calculator.m_animation, 0, 12);
      weight_calculator.m_current_time_in_ms = (unsigned int)current_time_in_ms;
      memset(&weight_calculator.m_weight, 0, 9);
      vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        &weight_calculator,
        (vostok::animation::mixing::n_ary_tree_animation_node *)cloned_intervals_begin);
      v68 = v21->user_data;
      v69 = 0;
      if ( v68 )
      {
        ++*(_DWORD *)(v68 + 16);
        v69 = v68;
        v70 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
      }
      else
      {
        v70 = 0;
      }
      v141 = v70 != 0;
      if ( v69 )
      {
        v27 = (*(_DWORD *)(v69 + 16))-- == 1;
        if ( v27 )
          (**(void (__thiscall ***)(unsigned int, _DWORD))v69)(v69, 0);
      }
      if ( v141 )
      {
        v67[26] = (const vostok::animation::base_interpolator *)LODWORD(weight_calculator.m_weight);
      }
      else if ( v67 )
      {
        vostok::animation::mixing::animation_state::animation_state(
          (vostok::animation::mixing::animation_state *)channels_head,
          (vostok::animation::mixing::n_ary_tree_animation_node *)cloned_intervals_begin,
          (unsigned int)current_time_in_ms,
          1u,
          v21->m_bones_mask,
          v21->m_bones_mask,
          *(float *)&v21->m_unique_animation_id,
          0.0,
          weight_calculator.m_weight,
          channels_head,
          0);
      }
      v7 = (unsigned int *)is_final_tree;
      LODWORD(cloned_intervals_begin[2].m_start_time) = v67;
      e = v67 + 45;
      v6 = result;
    }
    m_animation_intervals_count = v21->m_animation_intervals_count;
    v72 = 0;
    if ( m_animation_intervals_count )
    {
      v72 = (vostok::animation::mixing::n_ary_tree_animation_node *)v21->m_animation_intervals_count;
      ++*(_DWORD *)(m_animation_intervals_count + 16);
    }
    v73 = v21;
    v21 = v72;
    v27 = v73->m_animation_intervals-- == (const vostok::animation::mixing::animation_interval *const)1;
    if ( v27 )
      ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_animation_node *, _DWORD))v73->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node)(
        v73,
        0);
  }
  v74 = alloca(4 * (int)v6->m_animated_object);
  v75 = (vostok::animation::mixing::binary_tree_animation_node *)v6->m_operands_count;
  m_object = 0;
  v77 = (const vostok::animation::base_interpolator **)v117;
  operands_count = (unsigned int)v117;
  i.m_object = 0;
  if ( v75 )
  {
    ++v75->m_reference_count;
    m_object = v75;
    i.m_object = v75;
  }
  while ( m_object )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v27 = m_object->m_reference_count-- == 1;
      if ( v27 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
          m_object,
          0);
      break;
    }
    *v77 = (const vostok::animation::base_interpolator *)m_object->m_n_ary_animation;
    v78 = m_object->m_time_driving_animation;
    ++v77;
    v79 = 0;
    e = v77;
    if ( v78 )
    {
      ++v78->m_reference_count;
      v79 = v78;
      v80 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
    }
    else
    {
      v80 = 0;
    }
    HIBYTE(result) = v80 != 0;
    if ( v79 )
    {
      v27 = v79->m_reference_count-- == 1;
      if ( v27 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v79->~vostok::animation::mixing::binary_tree_base_node)(
          v79,
          0);
    }
    if ( HIBYTE(result) )
    {
      m_n_ary_animation = (vostok::animation::mixing::n_ary_tree *)m_object->m_n_ary_animation;
      v82 = m_object->m_time_driving_animation;
      v83 = 0;
      result = (vostok::animation::mixing::n_ary_tree_animation_node *)m_n_ary_animation;
      if ( v82 )
      {
        ++v82->m_reference_count;
        v83 = v82;
      }
      v84 = v83->m_n_ary_animation;
      v27 = v83->m_reference_count-- == 1;
      time_driving_animation = v84;
      if ( v27 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v83->~vostok::animation::mixing::binary_tree_base_node)(
          v83,
          0);
      v85 = time_driving_animation;
      result->m_time_driving_animation = time_driving_animation;
      m_animation_state = v85->m_animation_state;
      animation_interval_id = m_animation_state->animation_interval_id;
      v88 = &result->m_animation_intervals[animation_interval_id];
      time_driving_animation = (vostok::animation::mixing::n_ary_tree_animation_node *)v85->m_animation_intervals;
      *(float *)&multiplicands_begin = vostok::animation::mixing::animation_interval::length(v88);
      v89 = vostok::animation::mixing::animation_interval::length(
              (vostok::animation::mixing::animation_interval *)time_driving_animation
            + m_animation_state->animation_interval_id);
      v90 = (unsigned int)result->m_animation_state;
      v91 = *(float *)&multiplicands_begin / v89 * m_animation_state->animation_interval_time;
      if ( v90 )
      {
        animation_interval_time = v91;
        vostok::animation::mixing::animation_state::animation_state(
          (vostok::animation::mixing::animation_state *)result,
          result,
          (unsigned int)current_time_in_ms,
          1u,
          animation_interval_id,
          animation_interval_id,
          animation_interval_time,
          0.0,
          *(float *)(v90 + 104),
          channels_head,
          0);
      }
      v77 = e;
      m_object = i.m_object;
    }
    v92 = m_object->m_next_weight_animation.m_object;
    v93 = 0;
    if ( v92 )
    {
      v93 = m_object->m_next_weight_animation.m_object;
      ++v92->m_reference_count;
    }
    v94 = m_object;
    m_object = v93;
    i.m_object = v93;
    if ( v94 )
    {
      v27 = v94->m_reference_count-- == 1;
      if ( v27 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v94->~vostok::animation::mixing::binary_tree_base_node)(
          v94,
          0);
    }
  }
  v95 = (char **)operands_count;
  LOBYTE(result) = 0;
  if ( (const vostok::animation::base_interpolator **)operands_count != v77 )
  {
    v96 = (int)((int)v77 - operands_count) >> 2;
    for ( m = 0; v96 != 1; ++m )
      v96 >>= 1;
    v98 = (vostok::animation::mixing::n_ary_tree_animation_node **)operands_count;
    stlp_std::priv::__introsort_loop<vostok::animation::mixing::n_ary_tree_animation_node * *,vostok::animation::mixing::n_ary_tree_animation_node *,int,vostok::animation::mixing::time_animations_predicate>(
      (vostok::animation::mixing::time_animations_predicate)v6,
      (vostok::animation::mixing::n_ary_tree_animation_node **)operands_count,
      (vostok::animation::mixing::n_ary_tree_animation_node **)v77,
      0,
      2 * m,
      (vostok::animation::mixing::n_ary_tree_animation_node **)result);
    stlp_std::priv::__final_insertion_sort<vostok::animation::mixing::n_ary_tree_animation_node * *,vostok::animation::mixing::time_animations_predicate>(
      v98,
      (vostok::animation::mixing::n_ary_tree_animation_node **)v77,
      0);
    v95 = (char **)v98;
  }
  v99 = (const vostok::animation::base_interpolator **)(v95 + 1);
  animation = *v95;
  if ( v95 + 1 != (char **)v77 )
  {
    do
    {
      v100 = (int)*(v99 - 1);
      v101 = (int)*v99++;
      *(_DWORD *)(v100 + 44) = v101;
    }
    while ( v99 != v77 );
  }
  v102 = (char *)v6->m_animation_state;
  v103 = (unsigned int)v6->m_next_time_animation;
  m_next_weight_animation = (char *)v6->m_next_weight_animation;
  m_animated_object = (unsigned int)v6->m_animated_object;
  time_driving_animation = v6->m_weight_driving_animation;
  channels_heada = (vostok::animation::subscribed_channel **)v6->m_time_driving_animation;
  v106 = (char *)v6->m_animation_intervals;
  v107 = (unsigned int)v6->m_time_calculator.m_Closure.m_pFunction;
  buffer->m_data = 0;
  if ( v102 )
  {
    ++*(_DWORD *)v102;
    buffer->m_data = v102;
  }
  buffer->m_size = (unsigned int)weight_root;
  buffer[1].m_data = animation;
  buffer[2].m_data = v106;
  buffer[2].m_size = (unsigned int)channels_heada;
  v108 = (char *)time_driving_animation;
  buffer[4].m_size = v103;
  buffer[1].m_size = v107;
  buffer[3].m_data = v108;
  buffer[3].m_size = m_animated_object;
  buffer[4].m_data = m_next_weight_animation;
  buffer[5].m_data = current_time_in_ms;
  LOBYTE(buffer[5].m_size) = 0;
  vostok::animation::mixing::n_ary_tree::initialize((vostok::animation::mixing::n_ary_tree *)current_time_in_ms);
  return buffer;
}
