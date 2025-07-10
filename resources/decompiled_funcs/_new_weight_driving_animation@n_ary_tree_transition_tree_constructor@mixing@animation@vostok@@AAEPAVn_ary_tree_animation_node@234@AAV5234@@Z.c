vostok::animation::mixing::n_ary_tree_animation_node *__thiscall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_driving_animation(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *animation,
        vostok::animation::mixing::n_ary_tree_animation_node *operands_begin)
{
  const vostok::animation::base_interpolator *m_weight_interpolator; // ebp
  _DWORD *v5; // eax
  BOOL v6; // edi
  float (__thiscall *transition_time)(vostok::animation::base_interpolator *); // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v8; // eax
  const vostok::math::float4x4 *v9; // xmm0_4
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::n_ary_tree_base_node **v11; // ebp
  unsigned int v12; // ecx
  unsigned int m_operands_count; // edx
  vostok::animation::mixing::n_ary_tree_base_node **v14; // ebx
  const vostok::animation::base_interpolator *v15; // ecx
  vostok::animation::mixing::n_ary_tree_base_node **v16; // edi
  vostok::animation::mixing::n_ary_tree_base_node *v17; // ecx
  char v18; // al
  vostok::animation::mixing::n_ary_tree_base_node *v19; // ecx
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *m_result; // ecx
  const vostok::animation::base_interpolator *v21; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v22; // ecx
  int v23; // edi
  int v24; // eax
  int i; // ecx
  const vostok::animation::base_interpolator *v26; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v27; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v28; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v29; // ecx
  vostok::animation::mixing::n_ary_tree_node_comparer v31; // [esp+Ch] [ebp-4Ch]
  vostok::animation::mixing::n_ary_tree_node_comparer v32; // [esp+10h] [ebp-48h]
  vostok::animation::mixing::n_ary_tree_node_comparer v33; // [esp+10h] [ebp-48h]
  vostok::animation::mixing::n_ary_tree_visitor *v34; // [esp+14h] [ebp-44h]
  float v35; // [esp+14h] [ebp-44h]
  float v36; // [esp+14h] [ebp-44h]
  float v37; // [esp+18h] [ebp-40h]
  vostok::animation::mixing::n_ary_tree_base_node **operands_end; // [esp+24h] [ebp-34h] BYREF
  const vostok::animation::base_interpolator *interpolator; // [esp+28h] [ebp-30h]
  unsigned int operands_offset; // [esp+2Ch] [ebp-2Ch] BYREF
  unsigned int weight_operands_count; // [esp+30h] [ebp-28h]
  float animation_interval_time; // [esp+34h] [ebp-24h] BYREF
  unsigned int animation_interval_id; // [esp+38h] [ebp-20h] BYREF
  vostok::animation::mixing::n_ary_tree_animation_node *result; // [esp+3Ch] [ebp-1Ch]
  vostok::animation::mixing::n_ary_tree_node_comparer comparer; // [esp+40h] [ebp-18h] BYREF
  vostok::animation::mixing::n_ary_tree_weight_node temp; // [esp+48h] [ebp-10h] BYREF
  vostok::animation::mixing::n_ary_tree_base_node **operands_begina; // [esp+60h] [ebp+8h]

  m_weight_interpolator = operands_begin->m_weight_interpolator;
  v5 = &operands_begin[1].__vftable;
  interpolator = m_weight_interpolator;
  operands_begina = (vostok::animation::mixing::n_ary_tree_base_node **)&operands_begin[1];
  if ( operands_begin->m_operands_count )
    v6 = (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)*v5 + 12))(*v5) != 0;
  else
    v6 = 0;
  transition_time = m_weight_interpolator->transition_time;
  operands_end = (vostok::animation::mixing::n_ary_tree_base_node **)v6;
  weight_operands_count = operands_begin->m_operands_count
                        + (((double (__thiscall *)(const vostok::animation::base_interpolator *))transition_time)(m_weight_interpolator) != 0.0)
                        - v6;
  v8 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
         operands_begin,
         &operands_offset,
         animation,
         (const vostok::animation::mixing::animation_state *)operands_begin,
         0,
         weight_operands_count,
         (unsigned int *)&operands_end,
         &animation_interval_id,
         &animation_interval_time,
         0,
         COERCE_FLOAT(1));
  v9 = clear_value;
  result = v8;
  m_buffer = animation->m_buffer;
  v11 = (vostok::animation::mixing::n_ary_tree_base_node **)&m_buffer->m_data[4 * operands_offset];
  v12 = 4 * ((_DWORD)operands_end + weight_operands_count);
  m_buffer->m_data += v12;
  m_buffer->m_size -= v12;
  m_operands_count = operands_begin->m_operands_count;
  v14 = operands_begina;
  v15 = interpolator;
  v16 = &operands_begina[v6 ? operands_offset : 0];
  temp.__vftable = (vostok::animation::mixing::n_ary_tree_weight_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
  temp.m_interpolator = interpolator;
  LODWORD(temp.m_weight) = v9;
  comparer.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  comparer.result = equal;
  operands_end = &operands_begina[m_operands_count];
  if ( v16 == operands_end )
  {
LABEL_11:
    if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))v15->transition_time)(v15) == 0.0 )
      goto LABEL_14;
    v21 = vostok::animation::mixing::n_ary_tree_cloner::clone(
            (vostok::animation::mixing::n_ary_tree_cloner *)interpolator,
            (int)&animation->m_cloner,
            interpolator,
            v32.result);
    *v11 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
             v22,
             (bool)v14,
             (int)animation,
             v21,
             v35,
             v37);
    goto LABEL_13;
  }
  while ( 1 )
  {
    v17 = *v16;
    comparer.result = equal;
    v17->accept(v17, &comparer, &temp);
    if ( comparer.result == more )
      break;
    v18 = ((int (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::comparison_result_enum))(*v16)->is_time_scale)(
            *v16,
            v32.result);
    v19 = *v16;
    operands_begina[9] = 0;
    v34 = (vostok::animation::mixing::n_ary_tree_visitor *)(operands_begina + 8);
    if ( v18 )
    {
      operands_begina[16] = (vostok::animation::mixing::n_ary_tree_base_node *)clear_value;
      operands_begina[13] = 0;
      v19->accept(v19, v34);
      operands_begina[16] = (vostok::animation::mixing::n_ary_tree_base_node *)clear_value;
    }
    else
    {
      operands_begina[11] = 0;
      v19->accept(v19, v34);
      operands_begina[11] = 0;
    }
    v14 = operands_begina;
    *v11 = operands_begina[9];
    ++v16;
    ++v11;
    if ( v16 == operands_end )
    {
      v15 = interpolator;
      goto LABEL_11;
    }
  }
  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))interpolator->transition_time)(interpolator) != 0.0 )
  {
    v26 = vostok::animation::mixing::n_ary_tree_cloner::clone(
            (vostok::animation::mixing::n_ary_tree_cloner *)interpolator,
            (int)&animation->m_cloner,
            interpolator,
            v32.result);
    v28 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
            v27,
            (bool)v14,
            (int)animation,
            v26,
            v36,
            v37);
    v14 = operands_begina;
    *v11++ = v28;
  }
  if ( v16 != operands_end )
  {
    do
    {
      v29 = *v16;
      animation->m_cloner.m_result = 0;
      animation->m_cloner.m_animation_interpolator = 0;
      v29->accept(v29, &animation->m_cloner);
      m_result = (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)animation->m_cloner.m_result;
      animation->m_cloner.m_animation_interpolator = 0;
      *v11 = (vostok::animation::mixing::n_ary_tree_base_node *)m_result;
      ++v16;
      ++v11;
    }
    while ( v16 != operands_end );
LABEL_13:
    v14 = operands_begina;
  }
LABEL_14:
  if ( v14 != operands_end )
  {
    v23 = operands_end - v14;
    v31.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v31.result = equal;
    v24 = v23;
    for ( i = 0; v24 != 1; ++i )
      v24 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,int,vostok::animation::mixing::n_ary_tree_node_comparer>(
      v14,
      operands_end,
      0,
      2 * i,
      v31);
    v32.__vftable = 0;
    if ( v23 <= 16 )
    {
      stlp_std::priv::__insertion_sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,vostok::animation::mixing::n_ary_tree_node_comparer>(
        operands_end,
        v14,
        (vostok::animation::mixing::n_ary_tree_base_node **)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable',
        v32);
    }
    else
    {
      stlp_std::priv::__insertion_sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,vostok::animation::mixing::n_ary_tree_node_comparer>(
        v14 + 16,
        v14,
        (vostok::animation::mixing::n_ary_tree_base_node **)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable',
        v32);
      v33.__vftable = 0;
      stlp_std::priv::__unguarded_insertion_sort_aux<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,vostok::animation::mixing::n_ary_tree_node_comparer>(
        v14 + 16,
        operands_end,
        (vostok::animation::mixing::n_ary_tree_base_node **)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable',
        v33);
    }
  }
  return vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
           m_result,
           (int)animation,
           result,
           0,
           animation_interval_id,
           animation_interval_time,
           1);
}
