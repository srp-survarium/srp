vostok::animation::mixing::n_ary_tree_time_scale_transition_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_addition_node *a2@<edi>,
        vostok::animation::mixing::n_ary_tree_base_node *animation_time,
        vostok::animation::mixing::n_ary_tree_node_cloner *from,
        vostok::animation::mixing::n_ary_tree_base_node *to)
{
  vostok::animation::mixing::n_ary_tree_addition_node *v6; // esi
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node **m_operands_count; // eax
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v9; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v10; // ebx
  vostok::animation::mixing::n_ary_tree_node_cloner *v11; // ecx
  const vostok::animation::base_interpolator *v12; // eax
  int *v13; // ecx
  const vostok::animation::base_interpolator *v14; // edx
  int v15; // eax
  unsigned int v16; // ecx
  BOOL v17; // [esp+4h] [ebp-10h]
  float v18; // [esp+8h] [ebp-Ch]
  void **v19; // [esp+Ch] [ebp-8h] BYREF
  const vostok::animation::base_interpolator *interpolator; // [esp+10h] [ebp-4h]
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v21; // [esp+20h] [ebp+Ch]

  v6 = a2 + 4;
  if ( ((double (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node *))from->m_result->is_weight)(from->m_result) == 0.0 )
    return (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)vostok::animation::mixing::n_ary_tree_node_cloner::clone(
                                                                                 from,
                                                                                 v6,
                                                                                 animation_time,
                                                                                 *(float *)&v17,
                                                                                 v18);
  m_operands_count = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node **)a2[8].m_operands_count;
  v9 = (*m_operands_count)++;
  --m_operands_count[1];
  v21 = v9;
  interpolator = 0;
  v10 = (vostok::animation::mixing::n_ary_tree_base_node *)vostok::animation::mixing::n_ary_tree_node_cloner::clone(
                                                             from,
                                                             v6,
                                                             (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)LODWORD(s_bm_current_air_resistance));
  v19 = &vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
  v10->accept(v10, (vostok::animation::mixing::n_ary_tree_visitor *)&v19);
  v12 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v11, (int)&a2[4], interpolator, v17);
  v13 = (int *)a2[8].m_operands_count;
  v14 = v12;
  v15 = *v13;
  *v13 += 20;
  v13[1] -= 20;
  if ( v15 )
  {
    v16 = a2[16].m_operands_count;
    *(float *)(v15 + 8) = s_bm_current_air_resistance;
    *(_DWORD *)v15 = &vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
    *(_DWORD *)(v15 + 4) = v14;
    *(_DWORD *)(v15 + 12) = animation_time;
    *(_DWORD *)(v15 + 16) = v16;
  }
  if ( v21 )
    vostok::animation::mixing::n_ary_tree_time_scale_transition_node::n_ary_tree_time_scale_transition_node(
      v21,
      (vostok::animation::mixing::n_ary_tree_base_node *)v15,
      v10,
      v14,
      a2[16].m_operands_count);
  return v21;
}
