// local variable allocation has failed, the output may be wrong!
void __thiscall vostok::animation::mixing::n_ary_tree_comparer::add_operands(
        vostok::animation::mixing::n_ary_tree_comparer *this,
        vostok::animation::mixing::n_ary_tree_comparer *from,
        vostok::animation::mixing::n_ary_tree_animation_node *to,
        vostok::animation::mixing::n_ary_tree_animation_node *skip_time_scale_node,
        int skip_time_scale_nodea)
{
  vostok::animation::mixing::n_ary_tree_base_node **p_m_operands_count; // ebp
  unsigned int m_operands_count; // eax
  vostok::animation::mixing::n_ary_tree_base_node **v7; // ebx
  int v8; // edx
  vostok::animation::mixing::n_ary_tree_base_node **v9; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v10; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v11; // ecx
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_visitor *); // edx
  const vostok::animation::base_interpolator *m_result; // esi
  const vostok::animation::base_interpolator *v14; // edi
  vostok::animation::mixing::n_ary_tree_base_node *v15; // [esp+4h] [ebp-40h]
  float v16; // [esp+8h] [ebp-3Ch]
  vostok::animation::mixing::n_ary_tree_base_node *const *i_e; // [esp+18h] [ebp-2Ch]
  vostok::animation::mixing::n_ary_tree_base_node *const *j_e; // [esp+1Ch] [ebp-28h]
  vostok::animation::mixing::n_ary_tree_interpolator_selector interpolator_selector; // [esp+20h] [ebp-24h] BYREF
  vostok::animation::mixing::n_ary_tree_node_comparer comparer; // [esp+28h] [ebp-1Ch] BYREF
  void **v21; // [esp+30h] [ebp-14h]
  _DWORD v22[4]; // [esp+34h] [ebp-10h] BYREF

  p_m_operands_count = (vostok::animation::mixing::n_ary_tree_base_node **)&to[1];
  m_operands_count = to->m_operands_count;
  i_e = (vostok::animation::mixing::n_ary_tree_base_node *const *)(&to[1].__vftable + m_operands_count);
  v7 = (vostok::animation::mixing::n_ary_tree_base_node **)&skip_time_scale_node[1];
  v8 = (int)&skip_time_scale_node[1] + 4 * skip_time_scale_node->m_operands_count;
  comparer.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  comparer.result = equal;
  j_e = (vostok::animation::mixing::n_ary_tree_base_node *const *)v8;
  if ( m_operands_count && (*p_m_operands_count)->is_time_scale(*p_m_operands_count) )
  {
    if ( skip_time_scale_node->m_operands_count && (*v7)->is_time_scale(*v7) )
    {
      if ( !(_BYTE)skip_time_scale_nodea )
        vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(from, *v7, *p_m_operands_count);
      p_m_operands_count = (vostok::animation::mixing::n_ary_tree_base_node **)&to[1].m_operands_count;
LABEL_15:
      v7 = (vostok::animation::mixing::n_ary_tree_base_node **)&skip_time_scale_node[1].m_operands_count;
      goto LABEL_16;
    }
    if ( !(_BYTE)skip_time_scale_nodea )
      vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(from, *p_m_operands_count);
    p_m_operands_count = (vostok::animation::mixing::n_ary_tree_base_node **)&to[1].m_operands_count;
  }
  else if ( skip_time_scale_node->m_operands_count && (*v7)->is_time_scale(*v7) )
  {
    if ( !(_BYTE)skip_time_scale_nodea )
      vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(from, *v7);
    goto LABEL_15;
  }
LABEL_16:
  v9 = (vostok::animation::mixing::n_ary_tree_base_node **)i_e;
  interpolator_selector.__vftable = (vostok::animation::mixing::n_ary_tree_interpolator_selector_vtbl *)&vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
  interpolator_selector.m_result = 0;
  if ( p_m_operands_count == i_e )
    goto LABEL_31;
  while ( v7 != j_e )
  {
    v10 = *p_m_operands_count;
    v15 = *v7;
    comparer.result = equal;
    v10->accept(v10, &comparer, v15);
    v11 = *p_m_operands_count;
    if ( comparer.result == equal )
    {
      accept = v11->accept;
      v22[1] = from;
      v21 = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::binary_tree_visitor'};
      v22[0] = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
      v22[2] = 0;
      accept(v11, (vostok::animation::mixing::n_ary_tree_visitor *)v22);
LABEL_25:
      ++p_m_operands_count;
      goto LABEL_26;
    }
    v11->accept(v11, &interpolator_selector);
    m_result = interpolator_selector.m_result;
    (*v7)->accept(*v7, &interpolator_selector);
    v14 = interpolator_selector.m_result;
    m_result->accept(
      m_result,
      (vostok::animation::interpolator_comparer *)&skip_time_scale_nodea,
      interpolator_selector.m_result);
    if ( !skip_time_scale_nodea )
    {
      vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(from, *v7, *p_m_operands_count);
      goto LABEL_25;
    }
    if ( skip_time_scale_nodea != 1 )
    {
      vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(from, *v7, v14, v16);
LABEL_26:
      ++v7;
      goto LABEL_27;
    }
    vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(from, *p_m_operands_count++, m_result, v16);
LABEL_27:
    v9 = (vostok::animation::mixing::n_ary_tree_base_node **)i_e;
    if ( p_m_operands_count == i_e )
      goto LABEL_31;
  }
  if ( p_m_operands_count != v9 )
  {
    do
      vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(
        from,
        *p_m_operands_count++,
        to->m_weight_interpolator,
        v16);
    while ( p_m_operands_count != i_e );
  }
LABEL_31:
  while ( v7 != j_e )
    vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(
      from,
      *v7++,
      skip_time_scale_node->m_weight_interpolator,
      v16);
}
