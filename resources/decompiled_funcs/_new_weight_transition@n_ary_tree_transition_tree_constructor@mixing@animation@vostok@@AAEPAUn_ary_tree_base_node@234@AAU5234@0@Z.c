vostok::animation::mixing::n_ary_tree_base_node_vtbl *__thiscall vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *from,
        vostok::animation::mixing::n_ary_tree_base_node *to,
        vostok::animation::mixing::n_ary_tree_base_node *weight_from)
{
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *result; // eax
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *m_buffer; // eax
  void (__thiscall *v7)(vostok::animation::mixing::n_ary_tree_base_node *); // edi
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *m_result; // eax
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *v9; // ebp
  vostok::animation::mixing::n_ary_tree_cloner *v10; // ecx
  const vostok::animation::base_interpolator *v11; // eax
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *m_current_time_in_ms; // ecx
  bool v13; // [esp+0h] [ebp-18h]
  vostok::animation::mixing::n_ary_tree_interpolator_selector interpolator_selector; // [esp+10h] [ebp-8h] BYREF
  vostok::animation::mixing::n_ary_tree_base_node *weight_froma; // [esp+24h] [ebp+Ch]

  if ( ((double (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node_vtbl *))*((_DWORD *)weight_from[1].~vostok::animation::mixing::n_ary_tree_base_node
                                                                                       + 3))(weight_from[1].__vftable) == 0.0 )
  {
    from->m_cloner.m_result = 0;
    from->m_cloner.m_animation_interpolator = 0;
    weight_from->accept(weight_from, &from->m_cloner);
    result = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)from->m_cloner.m_result;
    from->m_cloner.m_animation_interpolator = 0;
  }
  else
  {
    m_buffer = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)from->m_buffer;
    v7 = m_buffer->~vostok::animation::mixing::n_ary_tree_base_node;
    m_buffer->~vostok::animation::mixing::n_ary_tree_base_node = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node *))((char *)m_buffer->~vostok::animation::mixing::n_ary_tree_base_node + 20);
    m_buffer->accept = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_double_dispatcher *, vostok::animation::mixing::n_ary_tree_base_node *))((char *)m_buffer->accept - 20);
    from->m_cloner.m_result = 0;
    from->m_cloner.m_animation_interpolator = 0;
    to->accept(to, &from->m_cloner);
    m_result = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)from->m_cloner.m_result;
    from->m_cloner.m_result = 0;
    from->m_cloner.m_animation_interpolator = 0;
    weight_froma = (vostok::animation::mixing::n_ary_tree_base_node *)m_result;
    weight_from->accept(weight_from, &from->m_cloner);
    v9 = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)from->m_cloner.m_result;
    from->m_cloner.m_animation_interpolator = 0;
    interpolator_selector.__vftable = (vostok::animation::mixing::n_ary_tree_interpolator_selector_vtbl *)&vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
    interpolator_selector.m_result = 0;
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_base_node_vtbl *, vostok::animation::mixing::n_ary_tree_interpolator_selector *))v9->~vostok::animation::mixing::n_ary_tree_base_node
     + 2))(
      v9,
      &interpolator_selector);
    v11 = vostok::animation::mixing::n_ary_tree_cloner::clone(
            v10,
            (int)&from->m_cloner,
            interpolator_selector.m_result,
            v13);
    if ( v7 )
    {
      m_current_time_in_ms = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)from->m_current_time_in_ms;
      *(_DWORD *)v7 = &vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
      *((_DWORD *)v7 + 1) = weight_froma;
      *((_DWORD *)v7 + 2) = v9;
      *((_DWORD *)v7 + 3) = v11;
      *((_DWORD *)v7 + 4) = m_current_time_in_ms;
    }
    return (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v7;
  }
  return result;
}
