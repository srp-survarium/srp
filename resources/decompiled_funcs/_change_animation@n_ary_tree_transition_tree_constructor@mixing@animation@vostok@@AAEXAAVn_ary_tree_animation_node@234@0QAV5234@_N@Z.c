void __userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::change_animation(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *a2@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *from,
        vostok::animation::mixing::n_ary_tree_base_node *const *to,
        vostok::animation::mixing::n_ary_tree_animation_node *const weight_driving_animation,
        vostok::animation::mixing::n_ary_tree_base_node **is_new_driving_animation)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // ebx
  unsigned int m_operands_count; // eax
  unsigned int v9; // edx
  vostok::animation::mixing::n_ary_tree_base_node **p_m_operands_count; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v12; // eax
  unsigned int v13; // edx
  vostok::mutable_buffer *v14; // eax
  int v15; // ecx
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v16; // ecx
  vostok::animation::mixing::n_ary_tree_base_node **v17; // ecx
  vostok::animation::mixing::n_ary_tree_base_node **v18; // ebx
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v19; // ecx
  unsigned int v20; // ebx
  unsigned int v21; // edi
  vostok::mutable_buffer *v22; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v23; // ecx
  vostok::mutable_buffer *v24; // eax
  vostok::animation::mixing::n_ary_tree_animation_node **v25; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *m_result; // ecx
  BOOL v27; // eax
  vostok::animation::mixing::n_ary_tree_base_node **i; // ebp
  vostok::animation::mixing::n_ary_tree_base_node *v29; // ecx
  int v30; // ecx
  vostok::mutable_buffer *v31; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v32; // eax
  const vostok::math::float4x4 *v33; // xmm0_4
  vostok::animation::mixing::n_ary_tree_base_node **v34; // edi
  unsigned int v35; // ebp
  vostok::mutable_buffer *v36; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v37; // ebx
  vostok::mutable_buffer *v38; // eax
  BOOL v39; // eax
  vostok::animation::mixing::n_ary_tree_base_node **j; // ebp
  vostok::animation::mixing::n_ary_tree_base_node *v41; // ecx
  vostok::animation::mixing::n_ary_tree_base_node **v42; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v43; // edi
  vostok::mutable_buffer *v44; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v45; // edi
  const vostok::animation::base_interpolator *v46; // eax
  int v47; // ecx
  vostok::mutable_buffer *v48; // eax
  const vostok::animation::base_interpolator *m_weight_interpolator; // eax
  const vostok::math::float4x4 *v50; // xmm0_4
  const vostok::animation::base_interpolator *v51; // eax
  vostok::animation::mixing::n_ary_tree_base_node **v52; // xmm0_4
  vostok::mutable_buffer *v53; // eax
  vostok::animation::mixing::n_ary_tree_base_node *const *v54; // eax
  const vostok::animation::base_interpolator *v55; // eax
  unsigned int m_current_time_in_ms; // ebp
  const vostok::animation::base_interpolator *v57; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v58; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v59; // eax
  unsigned int v60; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node *v61; // eax
  vostok::animation::mixing::n_ary_tree_base_node *const *v62; // edx
  char *v63; // ecx
  vostok::mutable_buffer *m_buffer; // eax
  char *m_data; // edi
  int v66; // ebp
  unsigned int v67; // [esp+0h] [ebp-50h]
  vostok::animation::mixing::n_ary_tree_animation_node *v68; // [esp+4h] [ebp-4Ch]
  BOOL v69; // [esp+Ch] [ebp-44h]
  vostok::animation::mixing::n_ary_tree_base_node **new_operands; // [esp+20h] [ebp-30h]
  vostok::animation::mixing::n_ary_tree_base_node *weight_from; // [esp+24h] [ebp-2Ch] BYREF
  unsigned int right_multiplicands_count; // [esp+28h] [ebp-28h]
  unsigned int v73; // [esp+2Ch] [ebp-24h] BYREF
  vostok::animation::mixing::n_ary_tree_base_node **to_end; // [esp+30h] [ebp-20h]
  vostok::animation::mixing::n_ary_tree_animation_node *new_animation; // [esp+34h] [ebp-1Ch]
  vostok::animation::mixing::n_ary_tree_base_node **multiplicands; // [esp+38h] [ebp-18h]
  unsigned int left_multiplicands_count; // [esp+3Ch] [ebp-14h]
  vostok::animation::mixing::n_ary_tree_animation_node *result; // [esp+40h] [ebp-10h] BYREF
  unsigned int animation_interval_id[3]; // [esp+44h] [ebp-Ch] BYREF

  v6 = (vostok::animation::mixing::n_ary_tree_animation_node *)to;
  if ( (!from->m_is_transitting_to_zero || *((_BYTE *)to + 81))
    && (!(_BYTE)is_new_driving_animation || !from->m_animation_state->are_there_any_weight_transitions) )
  {
    vostok::animation::mixing::computed_operands_count(
      from,
      (stlp_std::pair<unsigned int,unsigned int> *)animation_interval_id,
      to);
    v60 = animation_interval_id[0];
    LOBYTE(to) = v6->m_is_transitting_to_zero;
    is_new_driving_animation = (vostok::animation::mixing::n_ary_tree_base_node **)animation_interval_id[1];
    v61 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
            v6,
            (unsigned int *)&to,
            a2,
            (const vostok::animation::mixing::animation_state *)from,
            weight_driving_animation,
            animation_interval_id[0],
            (unsigned int *)&is_new_driving_animation,
            animation_interval_id,
            (float *)&weight_driving_animation,
            (bool)to,
            COERCE_FLOAT(1));
    v62 = to;
    result = v61;
    v63 = (char *)is_new_driving_animation + v60;
    m_buffer = a2->m_buffer;
    m_data = m_buffer->m_data;
    v66 = 4 * ((_DWORD)is_new_driving_animation + v60);
    m_buffer->m_data += v66;
    m_buffer->m_size -= v66;
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_operands(
      (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)&m_data[4 * (_DWORD)v62
                                                                                 + 4 * (v63 - (char *)v62)],
      a2,
      from,
      (vostok::animation::mixing::n_ary_tree_base_node **)v6,
      (vostok::animation::mixing::n_ary_tree_base_node **)&m_data[4 * (_DWORD)v62],
      (vostok::animation::mixing::n_ary_tree_base_node **)&m_data[4 * (_DWORD)v62 + 4 * (v63 - (char *)v62)],
      v62 != 0);
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
      (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)result,
      (int)a2,
      result,
      from->m_animation_state,
      animation_interval_id[0],
      *(float *)&weight_driving_animation,
      0);
    return;
  }
  m_operands_count = from->m_operands_count;
  v9 = *((_DWORD *)to + 1);
  p_m_operands_count = (vostok::animation::mixing::n_ary_tree_base_node **)&from[1];
  right_multiplicands_count = (unsigned int)&from[1] + 4 * m_operands_count;
  v11 = (vostok::animation::mixing::n_ary_tree_animation_node *)(to + 22);
  is_new_driving_animation = (vostok::animation::mixing::n_ary_tree_base_node **)(to + 22);
  to_end = (vostok::animation::mixing::n_ary_tree_base_node **)&to[v9 + 22];
  if ( m_operands_count )
  {
    if ( (*p_m_operands_count)->is_time_scale(*p_m_operands_count) )
    {
LABEL_10:
      weight_from = (vostok::animation::mixing::n_ary_tree_base_node *)1;
      goto LABEL_12;
    }
    v11 = (vostok::animation::mixing::n_ary_tree_animation_node *)is_new_driving_animation;
  }
  if ( v6->m_operands_count
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v11->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(v11->__vftable) )
  {
    goto LABEL_10;
  }
  weight_from = 0;
LABEL_12:
  LOBYTE(left_multiplicands_count) = v6->m_is_transitting_to_zero;
  v12 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
          v6,
          &v73,
          a2,
          (const vostok::animation::mixing::animation_state *)from,
          weight_driving_animation,
          1u,
          (unsigned int *)&weight_from,
          animation_interval_id,
          (float *)&result,
          left_multiplicands_count,
          COERCE_FLOAT(1));
  v13 = v73;
  new_animation = v12;
  v14 = a2->m_buffer;
  new_operands = (vostok::animation::mixing::n_ary_tree_base_node **)&v14->m_data[4 * v73];
  v15 = 4 * (_DWORD)weight_from + 4;
  v14->m_data += v15;
  v14->m_size -= v15;
  if ( !v13 )
  {
    if ( from->m_operands_count && (*p_m_operands_count)->is_time_scale(*p_m_operands_count) )
    {
      if ( v6->m_operands_count && (*is_new_driving_animation)->is_time_scale(*is_new_driving_animation) )
      {
        *new_operands = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition(
                          v6,
                          *is_new_driving_animation,
                          a2,
                          (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)from,
                          *p_m_operands_count);
        v17 = new_operands + 1;
        p_m_operands_count = (vostok::animation::mixing::n_ary_tree_base_node **)&from[1].m_operands_count;
        ++is_new_driving_animation;
      }
      else
      {
        *new_operands = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition(
                          v16,
                          (vostok::animation::mixing::n_ary_tree_visitor *)a2,
                          from,
                          *p_m_operands_count,
                          *(float *)&v69);
        v17 = new_operands + 1;
        p_m_operands_count = (vostok::animation::mixing::n_ary_tree_base_node **)&from[1].m_operands_count;
      }
    }
    else
    {
      if ( !v6->m_operands_count )
        goto LABEL_23;
      v18 = is_new_driving_animation;
      if ( !(*is_new_driving_animation)->is_time_scale(*is_new_driving_animation) )
        goto LABEL_23;
      *new_operands = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition(
                        v19,
                        *(const float *)&a2,
                        from->m_animation_state->animation_interval_time,
                        *v18);
      v17 = new_operands + 1;
      is_new_driving_animation = v18 + 1;
    }
    new_operands = v17;
  }
LABEL_23:
  v20 = right_multiplicands_count;
  v21 = (int)(right_multiplicands_count - (_DWORD)p_m_operands_count) >> 2;
  left_multiplicands_count = v21;
  if ( v21 && (*p_m_operands_count)->is_time_scale(*p_m_operands_count) )
    left_multiplicands_count = --v21;
  if ( v21 )
  {
    if ( v21 == 1 )
    {
      v30 = *(_DWORD *)(v20 - 4);
      a2->m_cloner.m_result = 0;
      a2->m_cloner.m_animation_interpolator = 0;
      (*(void (__thiscall **)(int, vostok::animation::mixing::n_ary_tree_cloner *))(*(_DWORD *)v30 + 8))(
        v30,
        &a2->m_cloner);
      m_result = (vostok::animation::mixing::n_ary_tree_animation_node *)a2->m_cloner.m_result;
      a2->m_cloner.m_animation_interpolator = 0;
      weight_from = m_result;
    }
    else
    {
      v22 = a2->m_buffer;
      v23 = (vostok::animation::mixing::n_ary_tree_base_node *)v22->m_data;
      v22->m_data += 8;
      v22->m_size -= 8;
      weight_from = v23;
      if ( v23 )
      {
        v23[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v21;
        v23->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_multiplication_node::`vftable';
      }
      v24 = a2->m_buffer;
      v25 = (vostok::animation::mixing::n_ary_tree_animation_node **)v24->m_data;
      m_result = (vostok::animation::mixing::n_ary_tree_animation_node *)(4 * v21);
      v24->m_data += 4 * v21;
      v24->m_size -= 4 * v21;
      v27 = v73 && (*p_m_operands_count)->is_time_scale(*p_m_operands_count);
      for ( i = &p_m_operands_count[v27];
            i != (vostok::animation::mixing::n_ary_tree_base_node **)right_multiplicands_count;
            ++v25 )
      {
        v29 = *i;
        a2->m_cloner.m_result = 0;
        a2->m_cloner.m_animation_interpolator = 0;
        v29->accept(v29, &a2->m_cloner);
        m_result = (vostok::animation::mixing::n_ary_tree_animation_node *)a2->m_cloner.m_result;
        a2->m_cloner.m_animation_interpolator = 0;
        *v25 = m_result;
        ++i;
      }
    }
  }
  else
  {
    v31 = a2->m_buffer;
    m_result = (vostok::animation::mixing::n_ary_tree_animation_node *)v31->m_data;
    v31->m_data += 12;
    v31->m_size -= 12;
    weight_from = m_result;
    if ( m_result )
    {
      m_result = (vostok::animation::mixing::n_ary_tree_animation_node *)new_animation->m_weight_interpolator;
      v32 = weight_from;
      v33 = clear_value;
      weight_from->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v32[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)m_result;
      v32[2].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v33;
    }
  }
  v34 = to_end;
  v35 = to_end - is_new_driving_animation;
  right_multiplicands_count = v35;
  if ( v35 && (*is_new_driving_animation)->is_time_scale(*is_new_driving_animation) )
    right_multiplicands_count = --v35;
  if ( v35 )
  {
    if ( v35 == 1 )
    {
      v47 = (int)*(v34 - 1);
      a2->m_cloner.m_result = 0;
      a2->m_cloner.m_animation_interpolator = 0;
      (*(void (__thiscall **)(int, vostok::animation::mixing::n_ary_tree_cloner *))(*(_DWORD *)v47 + 8))(
        v47,
        &a2->m_cloner);
      v37 = a2->m_cloner.m_result;
      a2->m_cloner.m_animation_interpolator = 0;
    }
    else
    {
      v36 = a2->m_buffer;
      v37 = (vostok::animation::mixing::n_ary_tree_base_node *)v36->m_data;
      v36->m_data += 8;
      v36->m_size -= 8;
      if ( v37 )
      {
        v37[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v35;
        v37->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_multiplication_node::`vftable';
      }
      v38 = a2->m_buffer;
      multiplicands = (vostok::animation::mixing::n_ary_tree_base_node **)v38->m_data;
      v38->m_data += 4 * v35;
      v38->m_size -= 4 * v35;
      v39 = v73 && (*is_new_driving_animation)->is_time_scale(*is_new_driving_animation);
      m_result = (vostok::animation::mixing::n_ary_tree_animation_node *)is_new_driving_animation;
      for ( j = &is_new_driving_animation[v39]; j != to_end; multiplicands = v42 + 1 )
      {
        v41 = *j;
        a2->m_cloner.m_result = 0;
        a2->m_cloner.m_animation_interpolator = 0;
        v41->accept(v41, &a2->m_cloner);
        v42 = multiplicands;
        m_result = (vostok::animation::mixing::n_ary_tree_animation_node *)a2->m_cloner.m_result;
        a2->m_cloner.m_animation_interpolator = 0;
        *v42 = m_result;
        ++j;
      }
      v35 = right_multiplicands_count;
    }
  }
  else
  {
    v48 = a2->m_buffer;
    v37 = (vostok::animation::mixing::n_ary_tree_base_node *)v48->m_data;
    v48->m_data += 12;
    v48->m_size -= 12;
    if ( v37 )
    {
      m_result = new_animation;
      m_weight_interpolator = new_animation->m_weight_interpolator;
      v50 = clear_value;
      v37->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v37[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)m_weight_interpolator;
      v37[2].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v50;
    }
  }
  if ( left_multiplicands_count >= 2
    || v35 >= 2
    || (v43 = weight_from, weight_from->is_transition(weight_from))
    || *(float *)&v43[2].__vftable != *(float *)&v37[2].__vftable )
  {
    v53 = a2->m_buffer;
    v45 = (vostok::animation::mixing::n_ary_tree_base_node *)v53->m_data;
    v53->m_data += 20;
    v53->m_size -= 20;
    v54 = (vostok::animation::mixing::n_ary_tree_base_node *const *)weight_driving_animation;
    if ( !weight_driving_animation )
      v54 = to;
    v55 = (const vostok::animation::base_interpolator *)*((_DWORD *)v54 + 8);
    if ( v45 )
    {
      m_current_time_in_ms = a2->m_current_time_in_ms;
      v57 = vostok::animation::mixing::n_ary_tree_cloner::clone(
              (vostok::animation::mixing::n_ary_tree_cloner *)m_result,
              (int)&a2->m_cloner,
              v55,
              v69);
      v58 = weight_from;
      v45->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
      v45[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v58;
      v45[2].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v37;
      v45[3].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v57;
      v45[4].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)m_current_time_in_ms;
    }
  }
  else
  {
    v44 = a2->m_buffer;
    v45 = (vostok::animation::mixing::n_ary_tree_base_node *)v44->m_data;
    v44->m_data += 12;
    v44->m_size -= 12;
    if ( weight_driving_animation )
    {
      v46 = weight_driving_animation->m_weight_interpolator;
    }
    else
    {
      m_result = (vostok::animation::mixing::n_ary_tree_animation_node *)to;
      v46 = (const vostok::animation::base_interpolator *)*((_DWORD *)to + 8);
    }
    if ( v45 )
    {
      is_new_driving_animation = (vostok::animation::mixing::n_ary_tree_base_node **)v37[2].__vftable;
      v51 = vostok::animation::mixing::n_ary_tree_cloner::clone(
              (vostok::animation::mixing::n_ary_tree_cloner *)m_result,
              (int)&a2->m_cloner,
              v46,
              v69);
      v52 = is_new_driving_animation;
      v45->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v45[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v51;
      v45[2].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v52;
    }
  }
  v68 = result;
  v67 = animation_interval_id[0];
  v59 = new_animation;
  *new_operands = v45;
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
    (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)from,
    (int)a2,
    v59,
    from->m_animation_state,
    v67,
    *(float *)&v68,
    0);
}
