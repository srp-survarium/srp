vostok::animation::mixing::n_ary_tree_animation_node *__thiscall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *animation,
        vostok::animation::mixing::n_ary_tree_animation_node *const weight_driving_animation,
        vostok::animation::mixing::n_ary_tree_animation_node *new_operands)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // ebx
  const vostok::animation::base_interpolator *m_weight_interpolator; // ebp
  unsigned int m_operands_count; // edi
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // esi
  unsigned int v8; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node *v9; // eax
  unsigned int v10; // edi
  vostok::animation::mixing::playback_enum m_buffer; // eax
  const vostok::math::float4x4 *v12; // xmm0_4
  int v13; // ecx
  const vostok::animation::base_interpolator *v14; // ecx
  vostok::animation::mixing::n_ary_tree_base_node **v15; // ebp
  vostok::animation::mixing::n_ary_tree_base_node **v16; // edi
  vostok::animation::mixing::n_ary_tree_base_node *v17; // ecx
  char v18; // al
  vostok::animation::mixing::n_ary_tree_base_node *v19; // ecx
  const vostok::math::float4x4 *v20; // xmm0_4
  const vostok::animation::base_interpolator *v21; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v22; // ecx
  int v23; // edi
  int v24; // eax
  int i; // ecx
  vostok::animation::mixing::n_ary_tree_base_node **v26; // ebx
  vostok::animation::mixing::n_ary_tree_cloner *v27; // ecx
  const vostok::animation::base_interpolator *v28; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v29; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v30; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // ecx
  vostok::animation::mixing::n_ary_tree_node_comparer v33; // [esp+Ch] [ebp-48h]
  vostok::animation::mixing::n_ary_tree_node_comparer v34; // [esp+10h] [ebp-44h]
  vostok::animation::mixing::n_ary_tree_node_comparer v35; // [esp+10h] [ebp-44h]
  const vostok::animation::base_interpolator **p_m_weight_interpolator; // [esp+14h] [ebp-40h]
  float v37; // [esp+14h] [ebp-40h]
  float v38; // [esp+14h] [ebp-40h]
  float v39; // [esp+18h] [ebp-3Ch]
  const vostok::animation::base_interpolator *interpolator; // [esp+24h] [ebp-30h]
  unsigned int time_scale_operands_count; // [esp+28h] [ebp-2Ch] BYREF
  unsigned int to_operands_count; // [esp+2Ch] [ebp-28h]
  unsigned int operands_offset; // [esp+30h] [ebp-24h] BYREF
  float animation_interval_time; // [esp+34h] [ebp-20h] BYREF
  unsigned int animation_interval_id; // [esp+38h] [ebp-1Ch] BYREF
  vostok::animation::mixing::n_ary_tree_animation_node *result; // [esp+3Ch] [ebp-18h]
  vostok::animation::mixing::n_ary_tree_node_comparer comparer; // [esp+40h] [ebp-14h] BYREF
  vostok::animation::mixing::n_ary_tree_weight_node temp; // [esp+48h] [ebp-Ch] BYREF
  vostok::animation::mixing::n_ary_tree_base_node **new_operandsa; // [esp+60h] [ebp+Ch]

  v4 = weight_driving_animation;
  if ( new_operands )
  {
    m_weight_interpolator = new_operands->m_weight_interpolator;
    interpolator = m_weight_interpolator;
  }
  else
  {
    interpolator = weight_driving_animation->m_weight_interpolator;
    m_weight_interpolator = interpolator;
  }
  m_operands_count = weight_driving_animation->m_operands_count;
  to_operands_count = m_operands_count;
  v7 = weight_driving_animation + 1;
  if ( m_operands_count
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v7->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(v7->__vftable) )
  {
    --m_operands_count;
  }
  v8 = m_operands_count
     + (((double (__thiscall *)(const vostok::animation::base_interpolator *))m_weight_interpolator->transition_time)(m_weight_interpolator) != 0.0);
  time_scale_operands_count = 0;
  v9 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
         weight_driving_animation,
         &operands_offset,
         animation,
         (const vostok::animation::mixing::animation_state *)weight_driving_animation,
         new_operands,
         v8,
         &time_scale_operands_count,
         &animation_interval_id,
         &animation_interval_time,
         0,
         COERCE_FLOAT(1));
  v10 = time_scale_operands_count;
  result = v9;
  if ( !time_scale_operands_count && to_operands_count )
    v10 = (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v7->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
           + 3))(v7->__vftable) != 0;
  m_buffer = (vostok::animation::mixing::playback_enum)animation->m_buffer;
  v12 = clear_value;
  new_operandsa = *(vostok::animation::mixing::n_ary_tree_base_node ***)m_buffer;
  v13 = 4 * (v10 + v8);
  *(_DWORD *)m_buffer += v13;
  *(_DWORD *)(m_buffer + 4) -= v13;
  v14 = interpolator;
  v15 = (vostok::animation::mixing::n_ary_tree_base_node **)(&v7->__vftable + weight_driving_animation->m_operands_count);
  v16 = (vostok::animation::mixing::n_ary_tree_base_node **)(&v7->__vftable + operands_offset);
  temp.__vftable = (vostok::animation::mixing::n_ary_tree_weight_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
  temp.m_interpolator = interpolator;
  LODWORD(temp.m_weight) = v12;
  comparer.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  comparer.result = equal;
  if ( v16 == v15 )
  {
LABEL_17:
    if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))v14->transition_time)(v14) != 0.0 )
    {
      v21 = vostok::animation::mixing::n_ary_tree_cloner::clone(
              (vostok::animation::mixing::n_ary_tree_cloner *)interpolator,
              (int)&animation->m_cloner,
              interpolator,
              v34.result);
      *new_operandsa = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
                         v22,
                         (bool)v4,
                         (int)animation,
                         v21,
                         v37,
                         v39);
    }
  }
  else
  {
    while ( 1 )
    {
      v17 = *v16;
      comparer.result = equal;
      v17->accept(v17, &comparer, &temp);
      if ( comparer.result == more )
        break;
      v18 = ((int (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::comparison_result_enum))(*v16)->is_time_scale)(
              *v16,
              v34.result);
      v19 = *v16;
      p_m_weight_interpolator = &weight_driving_animation->m_weight_interpolator;
      if ( v18 )
      {
        v20 = clear_value;
        weight_driving_animation->m_animated_object = 0;
        weight_driving_animation->m_start_cycle_interval_id = (const unsigned int)v20;
        weight_driving_animation->m_time_synchronization_group_id = 0;
        v19->accept(v19, (vostok::animation::mixing::n_ary_tree_visitor *)p_m_weight_interpolator);
        weight_driving_animation->m_start_cycle_interval_id = (const unsigned int)clear_value;
      }
      else
      {
        weight_driving_animation->m_animated_object = 0;
        weight_driving_animation->m_next_time_animation = 0;
        v19->accept(v19, (vostok::animation::mixing::n_ary_tree_visitor *)p_m_weight_interpolator);
        weight_driving_animation->m_next_time_animation = 0;
      }
      *new_operandsa = (vostok::animation::mixing::n_ary_tree_base_node *)weight_driving_animation->m_animated_object;
      v4 = weight_driving_animation;
      ++v16;
      ++new_operandsa;
      if ( v16 == v15 )
      {
        v14 = interpolator;
        goto LABEL_17;
      }
    }
    if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))interpolator->transition_time)(interpolator) != 0.0 )
    {
      v28 = vostok::animation::mixing::n_ary_tree_cloner::clone(
              v27,
              (int)&animation->m_cloner,
              interpolator,
              v34.result);
      *new_operandsa++ = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
                           v29,
                           (bool)v4,
                           (int)animation,
                           v28,
                           v38,
                           v39);
    }
    if ( v16 != v15 )
    {
      do
      {
        v30 = *v16;
        animation->m_cloner.m_result = 0;
        animation->m_cloner.m_animation_interpolator = 0;
        v30->accept(v30, &animation->m_cloner);
        m_result = animation->m_cloner.m_result;
        animation->m_cloner.m_animation_interpolator = 0;
        *new_operandsa = m_result;
        ++v16;
        ++new_operandsa;
      }
      while ( v16 != v15 );
      v4 = weight_driving_animation;
    }
  }
  if ( &v4[1] != (vostok::animation::mixing::n_ary_tree_animation_node *)v15 )
  {
    v23 = ((char *)v15 - (char *)&v4[1]) >> 2;
    v33.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v33.result = equal;
    v24 = v23;
    for ( i = 0; v24 != 1; ++i )
      v24 >>= 1;
    v26 = (vostok::animation::mixing::n_ary_tree_base_node **)&v4[1];
    stlp_std::priv::__introsort_loop<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,int,vostok::animation::mixing::n_ary_tree_node_comparer>(
      v26,
      v15,
      0,
      2 * i,
      v33);
    v34.__vftable = 0;
    if ( v23 <= 16 )
    {
      stlp_std::priv::__insertion_sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,vostok::animation::mixing::n_ary_tree_node_comparer>(
        v15,
        v26,
        (vostok::animation::mixing::n_ary_tree_base_node **)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable',
        v34);
    }
    else
    {
      stlp_std::priv::__insertion_sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,vostok::animation::mixing::n_ary_tree_node_comparer>(
        v26 + 16,
        v26,
        (vostok::animation::mixing::n_ary_tree_base_node **)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable',
        v34);
      v35.__vftable = 0;
      stlp_std::priv::__unguarded_insertion_sort_aux<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,vostok::animation::mixing::n_ary_tree_node_comparer>(
        v26 + 16,
        v15,
        (vostok::animation::mixing::n_ary_tree_base_node **)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable',
        v35);
    }
    v4 = weight_driving_animation;
  }
  return vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
           (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)animation_interval_id,
           (int)animation,
           result,
           v4->m_animation_state,
           animation_interval_id,
           animation_interval_time,
           1);
}
