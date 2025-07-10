vostok::animation::mixing::n_ary_tree_time_scale_transition_node *__thiscall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        const float animation_time,
        float from,
        vostok::animation::mixing::n_ary_tree_base_node *to)
{
  vostok::animation::mixing::n_ary_tree_base_node *v4; // ebp
  const vostok::math::float4x4 *v5; // xmm0_4
  const vostok::math::float4x4 *v6; // xmm0_4
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *result; // eax
  int v8; // eax
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v9; // edi
  const vostok::math::float4x4 *v10; // xmm0_4
  vostok::animation::mixing::n_ary_tree_base_node *v11; // ebp
  vostok::animation::mixing::n_ary_tree_cloner *v12; // ecx
  const vostok::animation::base_interpolator *v13; // eax
  int v14; // ecx
  float *v15; // edx
  int v16; // ecx
  float v17; // xmm0_4
  unsigned int v18; // ebx
  bool v19; // [esp+0h] [ebp-18h]
  vostok::animation::mixing::n_ary_tree_interpolator_selector interpolator_selector; // [esp+10h] [ebp-8h] BYREF

  v4 = to;
  if ( ((double (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node_vtbl *))*((_DWORD *)to[1].~vostok::animation::mixing::n_ary_tree_base_node
                                                                                       + 3))(to[1].__vftable) == 0.0 )
  {
    v5 = clear_value;
    *(_DWORD *)(LODWORD(animation_time) + 52) = &from;
    *(_DWORD *)(LODWORD(animation_time) + 36) = 0;
    *(_DWORD *)(LODWORD(animation_time) + 64) = v5;
    v4->accept(v4, (vostok::animation::mixing::n_ary_tree_visitor *)(LODWORD(animation_time) + 32));
    v6 = clear_value;
    result = *(vostok::animation::mixing::n_ary_tree_time_scale_transition_node **)(LODWORD(animation_time) + 36);
    *(_DWORD *)(LODWORD(animation_time) + 52) = 0;
    *(_DWORD *)(LODWORD(animation_time) + 64) = v6;
  }
  else
  {
    v8 = *(_DWORD *)(LODWORD(animation_time) + 68);
    v9 = *(vostok::animation::mixing::n_ary_tree_time_scale_transition_node **)v8;
    *(_DWORD *)v8 += 20;
    *(_DWORD *)(v8 + 4) -= 20;
    v10 = clear_value;
    *(_DWORD *)(LODWORD(animation_time) + 36) = 0;
    *(_DWORD *)(LODWORD(animation_time) + 52) = 0;
    *(_DWORD *)(LODWORD(animation_time) + 64) = v10;
    v4->accept(v4, (vostok::animation::mixing::n_ary_tree_visitor *)(LODWORD(animation_time) + 32));
    v11 = *(vostok::animation::mixing::n_ary_tree_base_node **)(LODWORD(animation_time) + 36);
    *(_DWORD *)(LODWORD(animation_time) + 64) = clear_value;
    interpolator_selector.__vftable = (vostok::animation::mixing::n_ary_tree_interpolator_selector_vtbl *)&vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
    interpolator_selector.m_result = 0;
    v11->accept(v11, &interpolator_selector);
    v13 = vostok::animation::mixing::n_ary_tree_cloner::clone(
            v12,
            LODWORD(animation_time) + 32,
            interpolator_selector.m_result,
            v19);
    v14 = *(_DWORD *)(LODWORD(animation_time) + 68);
    v15 = *(float **)v14;
    *(_DWORD *)v14 += 20;
    *(_DWORD *)(v14 + 4) -= 20;
    if ( v15 )
    {
      v16 = *(_DWORD *)(LODWORD(animation_time) + 132);
      *((_DWORD *)v15 + 2) = clear_value;
      v17 = from;
      *(_DWORD *)v15 = &vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
      *((_DWORD *)v15 + 1) = v13;
      v15[3] = v17;
      *((_DWORD *)v15 + 4) = v16;
    }
    if ( v9 )
    {
      v18 = *(_DWORD *)(LODWORD(animation_time) + 132);
      v9->m_from = (vostok::animation::mixing::n_ary_tree_base_node *)v15;
      v9->m_to = v11;
      v9->m_interpolator = v13;
      v9->m_start_time_in_ms = v18;
      v9->__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_transition_node::`vftable';
      from = COERCE_FLOAT(&vostok::animation::mixing::time_scale_transition_debug::`vftable');
      vostok::animation::mixing::n_ary_tree_time_scale_transition_node::accept(
        v9,
        (vostok::animation::mixing::n_ary_tree_visitor *)&from);
    }
    return v9;
  }
  return result;
}
