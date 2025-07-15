void __thiscall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_operands(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::animation::mixing::n_ary_tree_addition_node *from,
        vostok::animation::mixing::n_ary_tree_animation_node *to,
        vostok::animation::mixing::n_ary_tree_base_node **operands_begin,
        vostok::animation::mixing::n_ary_tree_base_node **operands_end,
        vostok::animation::mixing::n_ary_tree_base_node **skip_time_scale_node,
        char a7)
{
  const vostok::animation::base_interpolator *m_weight_interpolator; // ecx
  vostok::animation::mixing::n_ary_tree_node_cloner **p_m_operands_count; // esi
  unsigned int m_operands_count; // eax
  vostok::animation::mixing::n_ary_tree_subtraction_node **v10; // ebx
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v11; // ecx
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node **v12; // edi
  vostok::animation::mixing::n_ary_tree_node_cloner *v13; // ecx
  const vostok::animation::base_interpolator *v14; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v15; // eax
  const vostok::animation::base_interpolator *v16; // esi
  const vostok::animation::base_interpolator *v17; // eax
  vostok::animation::mixing::n_ary_tree_subtraction_node *v18; // ecx
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v19; // ecx
  vostok::animation::mixing::n_ary_tree_node_comparer v20; // [esp-8h] [ebp-48h]
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v21; // [esp+4h] [ebp-3Ch]
  vostok::animation::mixing::n_ary_tree_base_node *v22; // [esp+8h] [ebp-38h]
  _DWORD v23[3]; // [esp+14h] [ebp-2Ch] BYREF
  char v24; // [esp+20h] [ebp-20h]
  void **v25; // [esp+24h] [ebp-1Ch] BYREF
  const vostok::animation::base_interpolator *right; // [esp+28h] [ebp-18h]
  void **v27; // [esp+2Ch] [ebp-14h] BYREF
  const vostok::animation::base_interpolator *v28; // [esp+30h] [ebp-10h]
  vostok::animation::mixing::n_ary_tree_subtraction_node **v29; // [esp+34h] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_node_cloner **v30; // [esp+38h] [ebp-8h]
  vostok::animation::mixing::n_ary_tree_node_cloner **v31; // [esp+3Ch] [ebp-4h]
  const vostok::animation::base_interpolator *v32; // [esp+5Ch] [ebp+1Ch]

  m_weight_interpolator = to->m_weight_interpolator;
  v23[2] = 0;
  v28 = m_weight_interpolator;
  p_m_operands_count = (vostok::animation::mixing::n_ary_tree_node_cloner **)&to[1];
  m_operands_count = to->m_operands_count;
  v23[1] = from[10].__vftable;
  v30 = (vostok::animation::mixing::n_ary_tree_node_cloner **)(&to[1].__vftable + m_operands_count);
  v10 = (vostok::animation::mixing::n_ary_tree_subtraction_node **)(operands_begin + 22);
  v11 = (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)&operands_begin[(_DWORD)operands_begin[1]
                                                                                           + 22];
  v12 = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node **)operands_end;
  v23[0] = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v24 = 0;
  v31 = (vostok::animation::mixing::n_ary_tree_node_cloner **)&to[1];
  v29 = (vostok::animation::mixing::n_ary_tree_subtraction_node **)v11;
  if ( m_operands_count
    && ((unsigned __int8 (__thiscall *)(vostok::animation::mixing::n_ary_tree_node_cloner *))(*p_m_operands_count)->visit)(*p_m_operands_count) )
  {
    if ( operands_begin[1] && (*v10)->is_time_scale(*v10) )
    {
      if ( !a7 )
      {
        *operands_end = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition(
                          v11,
                          from,
                          to,
                          (vostok::animation::mixing::n_ary_tree_animation_node *)operands_begin,
                          *p_m_operands_count,
                          *v10);
        v12 = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node **)(operands_end + 1);
      }
      p_m_operands_count = (vostok::animation::mixing::n_ary_tree_node_cloner **)&to[1].m_operands_count;
      v31 = (vostok::animation::mixing::n_ary_tree_node_cloner **)&to[1].m_operands_count;
LABEL_15:
      v10 = (vostok::animation::mixing::n_ary_tree_subtraction_node **)(operands_begin + 23);
      goto LABEL_16;
    }
    if ( !a7 )
    {
      *operands_end = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition(
                        v11,
                        from,
                        to,
                        *p_m_operands_count,
                        *(float *)&v22);
      v12 = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node **)(operands_end + 1);
    }
    p_m_operands_count = (vostok::animation::mixing::n_ary_tree_node_cloner **)&to[1].m_operands_count;
    v31 = (vostok::animation::mixing::n_ary_tree_node_cloner **)&to[1].m_operands_count;
  }
  else if ( operands_begin[1] && (*v10)->is_time_scale(*v10) )
  {
    if ( !a7 )
    {
      *operands_end = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition(
                        v11,
                        from,
                        COERCE_VOSTOK_ANIMATION_MIXING_N_ARY_TREE_BASE_NODE_(to->m_animation_state->animation_interval_time),
                        (vostok::animation::mixing::n_ary_tree_node_cloner *)*v10,
                        v22);
      v12 = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node **)(operands_end + 1);
    }
    goto LABEL_15;
  }
LABEL_16:
  right = 0;
  v25 = &vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
  if ( p_m_operands_count != v30 )
  {
    while ( 1 )
    {
      if ( v10 == v29 )
      {
LABEL_30:
        while ( p_m_operands_count != v30 )
          *v12++ = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
                                                                                         v11,
                                                                                         from,
                                                                                         (const vostok::animation::base_interpolator *)operands_begin[8],
                                                                                         *p_m_operands_count++,
                                                                                         *(float *)&v22);
        goto LABEL_33;
      }
      if ( vostok::animation::mixing::n_ary_tree_node_comparer::compare(
             (vostok::animation::mixing::n_ary_tree_node_comparer *)*p_m_operands_count,
             (int)v23,
             *v10,
             v22) == equal )
        break;
      v16 = (const vostok::animation::base_interpolator *)operands_begin[8];
      (*v10)->accept(*v10, (vostok::animation::mixing::n_ary_tree_visitor *)&v25);
      v32 = right;
      v17 = vostok::animation::compare(right);
      if ( !v17 )
      {
        v15 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
                v21,
                from,
                *v31,
                (vostok::animation::mixing::n_ary_tree_node_cloner *)*v10);
        goto LABEL_25;
      }
      if ( v17 != (const vostok::animation::base_interpolator *)1 )
      {
        v15 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
                v21,
                from,
                v32,
                *v10,
                v22);
LABEL_26:
        *v12++ = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)v15;
        ++v10;
        goto LABEL_27;
      }
      *v12++ = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
                                                                                     v21,
                                                                                     from,
                                                                                     v16,
                                                                                     *v31++,
                                                                                     *(float *)&v22);
LABEL_27:
      p_m_operands_count = v31;
      if ( v31 == v30 )
        goto LABEL_30;
    }
    v13 = *v31;
    v14 = v28;
    from[4].m_operands_count = 0;
    from[5].m_operands_count = (unsigned int)v14;
    v13->visit(v13, from + 4);
    from[5].m_operands_count = 0;
    v15 = (vostok::animation::mixing::n_ary_tree_base_node *)from[4].m_operands_count;
LABEL_25:
    ++v31;
    goto LABEL_26;
  }
LABEL_33:
  while ( v10 != v29 )
  {
    v18 = *v10;
    v28 = 0;
    v27 = &vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
    v18->accept(v18, (vostok::animation::mixing::n_ary_tree_visitor *)&v27);
    *v12++ = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
                                                                                   v19,
                                                                                   from,
                                                                                   v28,
                                                                                   *v10++,
                                                                                   v22);
  }
  if ( v12 != operands_end )
  {
    v20.result = equal;
    v20.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v20.m_animated_object_resolver = (const boost::function<unsigned char __cdecl(void const *)> *)from[10].__vftable;
    v20.m_compare_dynamic_members = 0;
    stlp_std::sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_node_comparer>(
      skip_time_scale_node,
      operands_end,
      v20);
  }
}
