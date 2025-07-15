stlp_std::pair<unsigned int,unsigned int> *__usercall vostok::animation::mixing::computed_operands_count@<eax>(
        vostok::animation::mixing::n_ary_tree_animation_node *from@<eax>,
        stlp_std::pair<unsigned int,unsigned int> *to,
        vostok::animation::mixing::n_ary_tree_base_node *const *i_e)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // esi
  unsigned int m_operands_count; // eax
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v6; // ebp
  vostok::animation::mixing::n_ary_tree_base_node *const *v7; // edi
  int v8; // edx
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v9; // ecx
  const vostok::animation::base_interpolator *m_result; // ebx
  stlp_std::pair<unsigned int,unsigned int> *result; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v12; // [esp-4h] [ebp-38h]
  unsigned int time_scale_nodes_count; // [esp+14h] [ebp-20h]
  vostok::animation::mixing::n_ary_tree_base_node *const *j_e; // [esp+18h] [ebp-1Ch]
  int v15; // [esp+1Ch] [ebp-18h] BYREF
  vostok::animation::mixing::n_ary_tree_interpolator_selector interpolator_selector; // [esp+20h] [ebp-14h] BYREF
  vostok::animation::mixing::n_ary_tree_node_comparer comparer; // [esp+28h] [ebp-Ch] BYREF
  vostok::animation::mixing::n_ary_tree_base_node *const *i_ea; // [esp+3Ch] [ebp+8h]

  v4 = from + 1;
  m_operands_count = from->m_operands_count;
  v6 = 0;
  i_ea = (vostok::animation::mixing::n_ary_tree_base_node *const *)(&v4->__vftable + m_operands_count);
  v7 = i_e + 22;
  v8 = (int)&i_e[*((_DWORD *)i_e + 1) + 22];
  time_scale_nodes_count = 0;
  comparer.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  comparer.result = equal;
  j_e = (vostok::animation::mixing::n_ary_tree_base_node *const *)v8;
  if ( m_operands_count
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v4->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(v4->__vftable) )
  {
    v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v4 + 4);
    time_scale_nodes_count = 1;
    if ( *((_DWORD *)i_e + 1)
      && (*(unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_base_node *const))(**(_DWORD **)v7 + 12))(*v7) )
    {
      goto LABEL_9;
    }
  }
  else if ( *((_DWORD *)i_e + 1)
         && (*(unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_base_node *const))(**(_DWORD **)v7 + 12))(*v7) )
  {
    time_scale_nodes_count = 1;
LABEL_9:
    v7 = i_e + 23;
  }
  interpolator_selector.__vftable = (vostok::animation::mixing::n_ary_tree_interpolator_selector_vtbl *)&vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
  interpolator_selector.m_result = 0;
  if ( v4 == (vostok::animation::mixing::n_ary_tree_animation_node *)i_ea )
    goto LABEL_22;
  while ( v7 != j_e )
  {
    v9 = v4->__vftable;
    v12 = *v7;
    comparer.result = equal;
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_node_comparer *, vostok::animation::mixing::n_ary_tree_base_node *))v9->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 1))(
      v9,
      &comparer,
      v12);
    if ( comparer.result == equal
      || ((*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_interpolator_selector *))v4->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
           + 2))(
            v4->__vftable,
            &interpolator_selector),
          m_result = interpolator_selector.m_result,
          (*(void (__thiscall **)(vostok::animation::mixing::n_ary_tree_base_node *const, vostok::animation::mixing::n_ary_tree_interpolator_selector *))(**(_DWORD **)v7 + 8))(
            *v7,
            &interpolator_selector),
          m_result->accept(m_result, (vostok::animation::interpolator_comparer *)&v15, interpolator_selector.m_result),
          !v15) )
    {
      v6 = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)((char *)v6 + 1);
      v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v4 + 4);
LABEL_17:
      ++v7;
      goto LABEL_18;
    }
    v6 = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)((char *)v6 + 1);
    if ( v15 != 1 )
      goto LABEL_17;
    v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v4 + 4);
LABEL_18:
    if ( v4 == (vostok::animation::mixing::n_ary_tree_animation_node *)i_ea )
      goto LABEL_22;
  }
  for ( ;
        v4 != (vostok::animation::mixing::n_ary_tree_animation_node *)i_ea;
        v6 = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)((char *)v6 + 1) )
  {
    v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v4 + 4);
  }
LABEL_22:
  while ( v7 != j_e )
  {
    ++v7;
    v6 = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)((char *)v6 + 1);
  }
  result = to;
  to->first = (unsigned int)v6;
  to->second = time_scale_nodes_count;
  return result;
}
