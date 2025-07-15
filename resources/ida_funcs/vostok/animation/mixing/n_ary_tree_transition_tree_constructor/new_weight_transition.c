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


vostok::animation::mixing::n_ary_tree_visitor_vtbl *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_visitor *a2@<eax>,
        const vostok::animation::base_interpolator *from_animation_interpolator,
        vostok::animation::mixing::n_ary_tree_base_node *from,
        float to)
{
  vostok::animation::mixing::n_ary_tree_cloner *v6; // ecx
  const vostok::animation::base_interpolator *v7; // eax
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v8; // edi
  void (__thiscall *visit)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *); // ecx
  const vostok::math::float4x4 *v10; // xmm0_4
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *result; // eax
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_double_dispatcher *, vostok::animation::mixing::n_ary_tree_base_node *); // eax
  vostok::animation::mixing::n_ary_tree_visitor *v13; // edi
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v14; // eax
  void (__thiscall *v15)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *); // ebx
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v16; // ebp
  const vostok::animation::base_interpolator *v17; // eax
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v18; // ecx
  void (__thiscall *v19)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *); // edx
  const vostok::math::float4x4 *v20; // xmm0_4
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v21; // edi
  bool v22; // [esp+0h] [ebp-2Ch]
  void **v23; // [esp+14h] [ebp-18h] BYREF
  int v24; // [esp+18h] [ebp-14h]
  vostok::animation::mixing::n_ary_tree_weight_node weight; // [esp+1Ch] [ebp-10h] BYREF

  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))from_animation_interpolator->transition_time)(from_animation_interpolator) == 0.0 )
  {
    v7 = vostok::animation::mixing::n_ary_tree_cloner::clone(v6, (int)&a2[8], from_animation_interpolator, v22);
    v8 = a2[17].__vftable;
    visit = v8->visit;
    v8->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *))((char *)v8->visit + 12);
    v8->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_subtraction_node *))((char *)v8->visit - 12);
    if ( visit )
    {
      v10 = clear_value;
      *(_DWORD *)visit = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      *((_DWORD *)visit + 1) = v7;
      *((_DWORD *)visit + 2) = v10;
    }
    return (vostok::animation::mixing::n_ary_tree_visitor_vtbl *)visit;
  }
  else
  {
    accept = from->accept;
    weight.m_interpolator = from_animation_interpolator;
    weight.__vftable = (vostok::animation::mixing::n_ary_tree_weight_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
    LODWORD(weight.m_weight) = clear_value;
    v23 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v24 = 0;
    accept(from, (vostok::animation::mixing::n_ary_tree_double_dispatcher *)&v23, &weight);
    if ( v24 )
    {
      v14 = a2[17].__vftable;
      v15 = v14->visit;
      v14->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *))((char *)v14->visit + 20);
      v14->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_subtraction_node *))((char *)v14->visit - 20);
      a2[9].__vftable = 0;
      a2[11].__vftable = 0;
      from->accept(from, &a2[8]);
      v16 = a2[9].__vftable;
      a2[11].__vftable = 0;
      v17 = vostok::animation::mixing::n_ary_tree_cloner::clone(
              (vostok::animation::mixing::n_ary_tree_cloner *)from_animation_interpolator,
              (int)&a2[8],
              from_animation_interpolator,
              v22);
      v18 = a2[17].__vftable;
      v19 = v18->visit;
      v18->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *))((char *)v18->visit + 12);
      v18->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_subtraction_node *))((char *)v18->visit - 12);
      if ( v19 )
      {
        v20 = clear_value;
        *(_DWORD *)v19 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
        *((_DWORD *)v19 + 1) = v17;
        *((_DWORD *)v19 + 2) = v20;
      }
      if ( v15 )
      {
        v21 = a2[33].__vftable;
        *(_DWORD *)v15 = &vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
        *((_DWORD *)v15 + 1) = v16;
        *((_DWORD *)v15 + 2) = v19;
        *((_DWORD *)v15 + 3) = v17;
        *((_DWORD *)v15 + 4) = v21;
      }
      return (vostok::animation::mixing::n_ary_tree_visitor_vtbl *)v15;
    }
    else
    {
      v13 = a2 + 8;
      v13[1].__vftable = 0;
      v13[3].__vftable = 0;
      from->accept(from, v13);
      result = v13[1].__vftable;
      v13[3].__vftable = 0;
    }
  }
  return result;
}


vostok::animation::mixing::n_ary_tree_base_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition@<eax>(
        vostok::animation::mixing::n_ary_tree_base_node *to@<eax>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        const vostok::animation::base_interpolator *to_animation_interpolator,
        float from)
{
  vostok::animation::mixing::n_ary_tree_base_node *result; // eax
  vostok::mutable_buffer *m_buffer; // eax
  char *m_data; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // edi
  vostok::animation::mixing::n_ary_tree_cloner *v9; // ecx
  const vostok::animation::base_interpolator *v10; // eax
  vostok::mutable_buffer *v11; // ecx
  char *v12; // edx
  const vostok::math::float4x4 *v13; // xmm0_4
  unsigned int m_current_time_in_ms; // ebp
  bool v15; // [esp+0h] [ebp-34h]
  vostok::animation::mixing::n_ary_tree_double_dispatcher dispatcher; // [esp+14h] [ebp-20h] BYREF
  int v17; // [esp+18h] [ebp-1Ch]
  vostok::animation::mixing::n_ary_tree_interpolator_selector interpolator_selector; // [esp+1Ch] [ebp-18h] BYREF
  vostok::animation::mixing::n_ary_tree_weight_node weight; // [esp+24h] [ebp-10h] BYREF

  if ( ((double (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node_vtbl *))*((_DWORD *)to[1].~vostok::animation::mixing::n_ary_tree_base_node
                                                                                       + 3))(to[1].__vftable) == 0.0 )
  {
    this->m_cloner.m_result = 0;
    this->m_cloner.m_animation_interpolator = 0;
    to->accept(to, &this->m_cloner);
    result = this->m_cloner.m_result;
    this->m_cloner.m_animation_interpolator = 0;
  }
  else
  {
    weight.__vftable = (vostok::animation::mixing::n_ary_tree_weight_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
    weight.m_interpolator = to_animation_interpolator;
    LODWORD(weight.m_weight) = clear_value;
    dispatcher.__vftable = (vostok::animation::mixing::n_ary_tree_double_dispatcher_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v17 = 0;
    vostok::animation::mixing::n_ary_tree_weight_node::accept(&weight, &dispatcher, to);
    if ( v17 )
    {
      m_buffer = this->m_buffer;
      m_data = m_buffer->m_data;
      m_buffer->m_data += 20;
      m_buffer->m_size -= 20;
      this->m_cloner.m_result = 0;
      this->m_cloner.m_animation_interpolator = 0;
      to->accept(to, &this->m_cloner);
      m_result = this->m_cloner.m_result;
      this->m_cloner.m_animation_interpolator = 0;
      interpolator_selector.m_result = 0;
      interpolator_selector.__vftable = (vostok::animation::mixing::n_ary_tree_interpolator_selector_vtbl *)&vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
      m_result->accept(m_result, &interpolator_selector);
      v10 = vostok::animation::mixing::n_ary_tree_cloner::clone(
              v9,
              (int)&this->m_cloner,
              interpolator_selector.m_result,
              v15);
      v11 = this->m_buffer;
      v12 = v11->m_data;
      v11->m_data += 12;
      v11->m_size -= 12;
      if ( v12 )
      {
        v13 = clear_value;
        *(_DWORD *)v12 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
        *((_DWORD *)v12 + 1) = v10;
        *((_DWORD *)v12 + 2) = v13;
      }
      if ( m_data )
      {
        m_current_time_in_ms = this->m_current_time_in_ms;
        *(_DWORD *)m_data = &vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
        *((_DWORD *)m_data + 1) = v12;
        *((_DWORD *)m_data + 2) = m_result;
        *((_DWORD *)m_data + 3) = v10;
        *((_DWORD *)m_data + 4) = m_current_time_in_ms;
      }
      return (vostok::animation::mixing::n_ary_tree_base_node *)m_data;
    }
    else
    {
      this->m_cloner.m_result = 0;
      this->m_cloner.m_animation_interpolator = 0;
      to->accept(to, &this->m_cloner);
      result = this->m_cloner.m_result;
      this->m_cloner.m_animation_interpolator = 0;
    }
  }
  return result;
}


vostok::animation::mixing::n_ary_tree_base_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_transition@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        bool a2@<bl>,
        int a3@<esi>,
        const vostok::animation::base_interpolator *interpolator,
        float from,
        float to)
{
  vostok::animation::mixing::n_ary_tree_cloner *v6; // ecx
  double v7; // st6
  int v8; // eax
  _DWORD *v9; // edi
  const vostok::animation::base_interpolator *v10; // eax
  const vostok::math::float4x4 *v11; // xmm0_4
  int v13; // eax
  _DWORD *v14; // ebx
  const vostok::animation::base_interpolator *v15; // eax
  int v16; // eax
  _DWORD *v17; // ebp
  const vostok::animation::base_interpolator *v18; // eax
  const vostok::math::float4x4 *v19; // xmm0_4
  bool v20; // [esp-4h] [ebp-10h]
  bool v21; // [esp+0h] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_cloner *v22; // [esp+8h] [ebp-4h]

  v7 = ((double (__thiscall *)(const vostok::animation::base_interpolator *))interpolator->transition_time)(interpolator);
  v8 = *(_DWORD *)(a3 + 68);
  v9 = *(_DWORD **)v8;
  if ( v7 == 0.0 )
  {
    *(_DWORD *)v8 += 12;
    *(_DWORD *)(v8 + 4) -= 12;
    if ( v9 )
    {
      v10 = vostok::animation::mixing::n_ary_tree_cloner::clone(v6, a3 + 32, interpolator, v21);
      v11 = clear_value;
      v9[1] = v10;
      *v9 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v9[2] = v11;
      return (vostok::animation::mixing::n_ary_tree_base_node *)v9;
    }
  }
  else
  {
    *(_DWORD *)v8 += 20;
    *(_DWORD *)(v8 + 4) -= 20;
    v13 = *(_DWORD *)(a3 + 68);
    v20 = a2;
    v14 = *(_DWORD **)v13;
    *(_DWORD *)v13 += 12;
    *(_DWORD *)(v13 + 4) -= 12;
    if ( v14 )
    {
      v15 = vostok::animation::mixing::n_ary_tree_cloner::clone(v6, a3 + 32, interpolator, v20);
      *v14 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v14[1] = v15;
      v14[2] = 0;
    }
    v16 = *(_DWORD *)(a3 + 68);
    v17 = *(_DWORD **)v16;
    *(_DWORD *)v16 += 12;
    *(_DWORD *)(v16 + 4) -= 12;
    if ( v17 )
    {
      v18 = vostok::animation::mixing::n_ary_tree_cloner::clone(v6, a3 + 32, interpolator, v20);
      v19 = clear_value;
      *v17 = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
      v17[1] = v18;
      v17[2] = v19;
    }
    if ( v9 )
    {
      v22 = *(vostok::animation::mixing::n_ary_tree_cloner **)(a3 + 132);
      v9[3] = vostok::animation::mixing::n_ary_tree_cloner::clone(v22, a3 + 32, interpolator, v20);
      *v9 = &vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
      v9[1] = v14;
      v9[2] = v17;
      v9[4] = v22;
    }
  }
  return (vostok::animation::mixing::n_ary_tree_base_node *)v9;
}
