void __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_weight_driving_animation(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_comparer *a2@<edi>,
        vostok::animation::mixing::n_ary_tree_animation_node *animation)
{
  bool v4; // zf
  const vostok::animation::base_interpolator *m_weight_interpolator; // ebx
  unsigned int v6; // esi
  float (__thiscall *transition_time)(vostok::animation::base_interpolator *); // eax
  unsigned int v8; // ebx
  const vostok::animation::base_interpolator *v9; // ecx
  const vostok::math::float4x4 *v10; // xmm0_4
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl **v11; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl **v12; // esi
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v13; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v14; // ecx
  void (__thiscall *v15)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, void ***); // eax
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v16; // ecx
  void (__thiscall *v17)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, void ***); // edx
  unsigned int time_scale_operands_count; // [esp+Ch] [ebp-2Ch] BYREF
  unsigned int operands_offset; // [esp+10h] [ebp-28h] BYREF
  vostok::animation::mixing::n_ary_tree_node_comparer comparer; // [esp+14h] [ebp-24h] BYREF
  vostok::animation::mixing::n_ary_tree_weight_node temp; // [esp+1Ch] [ebp-1Ch] BYREF
  void **v22; // [esp+28h] [ebp-10h]
  void **v23; // [esp+2Ch] [ebp-Ch] BYREF
  vostok::animation::mixing::n_ary_tree_comparer *v24; // [esp+30h] [ebp-8h]
  int v25; // [esp+34h] [ebp-4h]
  const vostok::animation::base_interpolator *interpolator; // [esp+3Ch] [ebp+4h]

  a2->m_equal = 0;
  v4 = animation->m_operands_count == 0;
  m_weight_interpolator = animation->m_weight_interpolator;
  interpolator = m_weight_interpolator;
  v6 = !v4
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))animation[1].~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(animation[1].__vftable) != 0;
  transition_time = m_weight_interpolator->transition_time;
  time_scale_operands_count = v6;
  v8 = (((double (__thiscall *)(const vostok::animation::base_interpolator *))transition_time)(m_weight_interpolator) != 0.0)
     + animation->m_operands_count
     - v6;
  vostok::animation::mixing::n_ary_tree_comparer::new_animation(
    &operands_offset,
    (vostok::animation::mixing::n_ary_tree_comparer *)&time_scale_operands_count,
    a2,
    animation,
    &time_scale_operands_count);
  v9 = interpolator;
  v10 = clear_value;
  a2->m_needed_buffer_size += 4 * (time_scale_operands_count + v8);
  v11 = &animation[1].__vftable + animation->m_operands_count;
  v12 = &animation[1].__vftable + (v6 != 0 ? operands_offset : 0);
  temp.__vftable = (vostok::animation::mixing::n_ary_tree_weight_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
  temp.m_interpolator = interpolator;
  LODWORD(temp.m_weight) = v10;
  comparer.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  comparer.result = equal;
  if ( v12 == v11 )
  {
LABEL_8:
    if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))v9->transition_time)(v9) != 0.0 )
    {
      a2->m_needed_buffer_size += 44;
      a2->m_equal = 0;
    }
  }
  else
  {
    while ( 1 )
    {
      v13 = *v12;
      comparer.result = equal;
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_node_comparer *, vostok::animation::mixing::n_ary_tree_weight_node *))v13->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 1))(
        v13,
        &comparer,
        &temp);
      if ( comparer.result == more )
        break;
      v14 = *v12;
      v15 = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, void ***))*((_DWORD *)(*v12)->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node + 2);
      v22 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
      v23 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
      v24 = a2;
      v25 = 0;
      v15(v14, &v23);
      if ( ++v12 == v11 )
      {
        v9 = interpolator;
        goto LABEL_8;
      }
    }
    if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))interpolator->transition_time)(interpolator) != 0.0 )
    {
      a2->m_needed_buffer_size += 44;
      a2->m_equal = 0;
    }
    for ( ; v12 != v11; ++v12 )
    {
      v16 = *v12;
      v17 = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, void ***))*((_DWORD *)(*v12)->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node + 2);
      v22 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
      v23 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
      v24 = a2;
      v25 = 0;
      v17(v16, &v23);
    }
  }
}
