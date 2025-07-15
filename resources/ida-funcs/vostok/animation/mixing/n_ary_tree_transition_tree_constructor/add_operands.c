void __thiscall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_operands(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *from,
        vostok::animation::mixing::n_ary_tree_animation_node *to,
        vostok::animation::mixing::n_ary_tree_base_node **operands_begin,
        vostok::animation::mixing::n_ary_tree_base_node **operands_end,
        vostok::animation::mixing::n_ary_tree_base_node **skip_time_scale_node,
        char i_interpolator)
{
  vostok::animation::mixing::n_ary_tree_base_node **v7; // edx
  unsigned int m_operands_count; // eax
  vostok::animation::mixing::n_ary_tree_base_node **p_m_operands_count; // esi
  vostok::animation::mixing::n_ary_tree_base_node **v10; // ebp
  vostok::animation::mixing::n_ary_tree_base_node **v11; // ecx
  vostok::animation::mixing::n_ary_tree_base_node **v12; // edi
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v13; // ecx
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v14; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *v15; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v16; // ecx
  vostok::animation::mixing::n_ary_tree_cloner *p_m_cloner; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // ecx
  void (__thiscall *accept)(vostok::animation::base_interpolator *, vostok::animation::interpolator_comparer *, const vostok::animation::base_interpolator *); // edx
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v20; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v21; // [esp+4h] [ebp-40h]
  float v22; // [esp+8h] [ebp-3Ch]
  vostok::animation::mixing::n_ary_tree_base_node *const *i_e; // [esp+1Ch] [ebp-28h]
  vostok::animation::mixing::n_ary_tree_base_node *const *j_e; // [esp+20h] [ebp-24h]
  const vostok::animation::base_interpolator *from_interpolator; // [esp+24h] [ebp-20h]
  int v26; // [esp+28h] [ebp-1Ch] BYREF
  const vostok::animation::base_interpolator *j_interpolator; // [esp+2Ch] [ebp-18h]
  vostok::animation::mixing::n_ary_tree_interpolator_selector interpolator_selector; // [esp+30h] [ebp-14h] BYREF
  vostok::animation::mixing::n_ary_tree_node_comparer comparer; // [esp+38h] [ebp-Ch] BYREF
  const vostok::animation::base_interpolator *i_interpolatora; // [esp+5Ch] [ebp+18h]

  v7 = operands_begin;
  from_interpolator = to->m_weight_interpolator;
  m_operands_count = to->m_operands_count;
  p_m_operands_count = (vostok::animation::mixing::n_ary_tree_base_node **)&to[1];
  i_e = (vostok::animation::mixing::n_ary_tree_base_node *const *)(&to[1].__vftable + m_operands_count);
  v10 = operands_begin + 22;
  v11 = &operands_begin[(_DWORD)operands_begin[1] + 22];
  v12 = operands_end;
  comparer.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  comparer.result = equal;
  j_e = v11;
  if ( !m_operands_count )
  {
LABEL_13:
    if ( v7[1] && (*v10)->is_time_scale(*v10) )
    {
      if ( !i_interpolator )
      {
        *operands_end = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition(
                          from,
                          *(const float *)&from,
                          to->m_animation_state->animation_interval_time,
                          *v10);
        v12 = operands_end + 1;
      }
      v10 = operands_begin + 23;
    }
    goto LABEL_18;
  }
  if ( !(*p_m_operands_count)->is_time_scale(*p_m_operands_count) )
  {
    v7 = operands_begin;
    goto LABEL_13;
  }
  v13 = (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)operands_begin;
  if ( !operands_begin[1] || !(*v10)->is_time_scale(*v10) )
  {
    if ( !i_interpolator )
    {
      *operands_end = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition(
                        v13,
                        (vostok::animation::mixing::n_ary_tree_visitor *)from,
                        to,
                        *p_m_operands_count,
                        v22);
      v12 = operands_end + 1;
    }
    p_m_operands_count = (vostok::animation::mixing::n_ary_tree_base_node **)&to[1].m_operands_count;
LABEL_18:
    v14 = from;
    goto LABEL_19;
  }
  v14 = from;
  if ( !i_interpolator )
  {
    *operands_end = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition(
                      (vostok::animation::mixing::n_ary_tree_animation_node *)operands_begin,
                      *v10,
                      from,
                      (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)to,
                      *p_m_operands_count);
    v12 = operands_end + 1;
  }
  p_m_operands_count = (vostok::animation::mixing::n_ary_tree_base_node **)&to[1].m_operands_count;
  v10 = operands_begin + 23;
LABEL_19:
  interpolator_selector.__vftable = (vostok::animation::mixing::n_ary_tree_interpolator_selector_vtbl *)&vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
  interpolator_selector.m_result = 0;
  if ( p_m_operands_count == i_e )
    goto LABEL_34;
  while ( v10 != j_e )
  {
    v15 = *p_m_operands_count;
    v21 = *v10;
    comparer.result = equal;
    v15->accept(v15, &comparer, v21);
    v16 = *p_m_operands_count;
    if ( comparer.result == equal )
    {
      p_m_cloner = &v14->m_cloner;
      p_m_cloner->m_animation_interpolator = from_interpolator;
      p_m_cloner->m_result = 0;
      v16->accept(v16, p_m_cloner);
      m_result = p_m_cloner->m_result;
      p_m_cloner->m_animation_interpolator = 0;
      v14 = from;
      *v12 = m_result;
LABEL_28:
      ++p_m_operands_count;
      goto LABEL_29;
    }
    v16->accept(v16, &interpolator_selector);
    i_interpolatora = interpolator_selector.m_result;
    (*v10)->accept(*v10, &interpolator_selector);
    accept = i_interpolatora->accept;
    j_interpolator = interpolator_selector.m_result;
    accept(i_interpolatora, (vostok::animation::interpolator_comparer *)&v26, interpolator_selector.m_result);
    if ( !v26 )
    {
      *v12 = (vostok::animation::mixing::n_ary_tree_base_node *)vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
                                                                  (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)*v10,
                                                                  v14,
                                                                  *p_m_operands_count,
                                                                  *v10);
      goto LABEL_28;
    }
    if ( v26 != 1 )
    {
      *v12 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
               *v10,
               v14,
               j_interpolator,
               v22);
LABEL_29:
      ++v12;
      ++v10;
      goto LABEL_30;
    }
    *v12++ = (vostok::animation::mixing::n_ary_tree_base_node *)vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
                                                                  v20,
                                                                  (vostok::animation::mixing::n_ary_tree_visitor *)v14,
                                                                  i_interpolatora,
                                                                  *p_m_operands_count++,
                                                                  v22);
LABEL_30:
    if ( p_m_operands_count == i_e )
      goto LABEL_34;
  }
  for ( ; p_m_operands_count != i_e; ++v12 )
  {
    *v12 = (vostok::animation::mixing::n_ary_tree_base_node *)vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
                                                                (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)*p_m_operands_count,
                                                                (vostok::animation::mixing::n_ary_tree_visitor *)v14,
                                                                to->m_weight_interpolator,
                                                                *p_m_operands_count,
                                                                v22);
    ++p_m_operands_count;
  }
LABEL_34:
  while ( v10 != j_e )
    *v12++ = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
               *v10++,
               v14,
               (const vostok::animation::base_interpolator *)operands_begin[8],
               v22);
  if ( v12 != operands_end )
    stlp_std::sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_node_comparer>(
      operands_end,
      skip_time_scale_node,
      (vostok::animation::mixing::n_ary_tree_node_comparer)(unsigned int)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable');
}
