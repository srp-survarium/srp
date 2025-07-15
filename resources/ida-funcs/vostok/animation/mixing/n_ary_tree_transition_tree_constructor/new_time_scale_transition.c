vostok::animation::mixing::n_ary_tree_time_scale_transition_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition@<eax>(
        vostok::animation::mixing::n_ary_tree_animation_node *to_animation@<ecx>,
        vostok::animation::mixing::n_ary_tree_base_node *to@<eax>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *from_animation,
        vostok::animation::mixing::n_ary_tree_base_node *from)
{
  vostok::animation::mixing::n_ary_tree_base_node *v5; // ebp
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_double_dispatcher *, vostok::animation::mixing::n_ary_tree_base_node *); // edx
  float v9; // xmm0_4
  const vostok::math::float4x4 *v10; // xmm0_4
  const vostok::math::float4x4 *v11; // xmm0_4
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *result; // eax
  float animation_interval_time; // xmm0_4
  const vostok::math::float4x4 *v14; // xmm0_4
  const vostok::math::float4x4 *v15; // xmm0_4
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_data; // ecx
  const vostok::math::float4x4 *v18; // xmm0_4
  void (__thiscall *v19)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_visitor *); // eax
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // ecx
  const vostok::math::float4x4 *v21; // xmm0_4
  void (__thiscall *v22)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_visitor *); // eax
  vostok::animation::mixing::n_ary_tree_base_node *v23; // ebp
  vostok::animation::mixing::n_ary_tree_cloner *v24; // ecx
  const vostok::animation::base_interpolator *v25; // eax
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v26; // esi
  bool v27; // [esp+0h] [ebp-20h]
  void **v28; // [esp+10h] [ebp-10h] BYREF
  int v29; // [esp+14h] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_interpolator_selector interpolator_selector; // [esp+18h] [ebp-8h] BYREF

  v5 = from;
  accept = from->accept;
  v28 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v29 = 0;
  accept(from, (vostok::animation::mixing::n_ary_tree_double_dispatcher *)&v28, to);
  if ( v29 )
  {
    if ( ((double (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node_vtbl *))*((_DWORD *)to[1].~vostok::animation::mixing::n_ary_tree_base_node
                                                                                         + 3))(to[1].__vftable) == 0.0 )
    {
      if ( to_animation->m_override_existing_animation )
        animation_interval_time = to_animation->m_animation_state->animation_interval_time;
      else
        animation_interval_time = *(float *)&from_animation[1].m_to[25].__vftable;
      from_animation = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)LODWORD(animation_interval_time);
      v14 = clear_value;
      this->m_cloner.m_animation_interval_time = (const float *)&from_animation;
      this->m_cloner.m_result = 0;
      LODWORD(this->m_cloner.m_time_scale_factor) = v14;
      to->accept(to, &this->m_cloner);
      v15 = clear_value;
      result = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)this->m_cloner.m_result;
      this->m_cloner.m_animation_interval_time = 0;
      LODWORD(this->m_cloner.m_time_scale_factor) = v15;
    }
    else
    {
      m_buffer = this->m_buffer;
      m_data = (vostok::animation::mixing::n_ary_tree_animation_node *)m_buffer->m_data;
      m_buffer->m_data += 20;
      m_buffer->m_size -= 20;
      v18 = clear_value;
      this->m_cloner.m_result = 0;
      LODWORD(this->m_cloner.m_time_scale_factor) = v18;
      this->m_cloner.m_animation_interval_time = 0;
      v19 = v5->accept;
      from_animation = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)m_data;
      v19(v5, &this->m_cloner);
      m_result = this->m_cloner.m_result;
      v21 = clear_value;
      this->m_cloner.m_result = 0;
      LODWORD(this->m_cloner.m_time_scale_factor) = v21;
      this->m_cloner.m_animation_interval_time = 0;
      v22 = to->accept;
      from = m_result;
      v22(to, &this->m_cloner);
      v23 = this->m_cloner.m_result;
      LODWORD(this->m_cloner.m_time_scale_factor) = clear_value;
      interpolator_selector.__vftable = (vostok::animation::mixing::n_ary_tree_interpolator_selector_vtbl *)&vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
      interpolator_selector.m_result = 0;
      v23->accept(v23, &interpolator_selector);
      v25 = vostok::animation::mixing::n_ary_tree_cloner::clone(
              v24,
              (int)&this->m_cloner,
              interpolator_selector.m_result,
              v27);
      v26 = from_animation;
      if ( from_animation )
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node::n_ary_tree_time_scale_transition_node(
          from_animation,
          from,
          v23,
          v25,
          this->m_current_time_in_ms);
      return v26;
    }
  }
  else
  {
    if ( to_animation->m_override_existing_animation )
      v9 = to_animation->m_animation_state->animation_interval_time;
    else
      v9 = *(float *)&from_animation[1].m_to[25].__vftable;
    from_animation = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)LODWORD(v9);
    v10 = clear_value;
    this->m_cloner.m_animation_interval_time = (const float *)&from_animation;
    this->m_cloner.m_result = 0;
    LODWORD(this->m_cloner.m_time_scale_factor) = v10;
    v5->accept(v5, &this->m_cloner);
    v11 = clear_value;
    result = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)this->m_cloner.m_result;
    this->m_cloner.m_animation_interval_time = 0;
    LODWORD(this->m_cloner.m_time_scale_factor) = v11;
  }
  return result;
}


vostok::animation::mixing::n_ary_tree_time_scale_transition_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_time_scale_transition@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_visitor *a2@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *from_animation,
        vostok::animation::mixing::n_ary_tree_base_node *from,
        float to)
{
  vostok::animation::mixing::n_ary_tree_base_node *v5; // ebp
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_visitor *); // edx
  vostok::animation::mixing::n_ary_tree_cloner *v8; // ecx
  const vostok::animation::base_interpolator *v9; // eax
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v10; // ecx
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *v11; // edx
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *result; // eax
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *v13; // edi
  float animation_interval_time; // xmm0_4
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *v15; // xmm1_4
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v16; // eax
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *visit; // ebx
  const vostok::math::float4x4 *v18; // xmm0_4
  vostok::animation::mixing::n_ary_tree_cloner *m_result; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *v20; // ebp
  const vostok::animation::base_interpolator *v21; // eax
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v22; // ecx
  float *v23; // edx
  float v24; // xmm0_4
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v25; // ecx
  const vostok::math::float4x4 *v26; // xmm1_4
  unsigned int v27; // edi
  const vostok::animation::base_interpolator *v28; // [esp-4h] [ebp-20h]
  bool v29; // [esp+0h] [ebp-1Ch]
  vostok::animation::mixing::n_ary_tree_interpolator_selector interpolator_selector; // [esp+10h] [ebp-Ch] BYREF

  v5 = from;
  accept = from->accept;
  interpolator_selector.__vftable = (vostok::animation::mixing::n_ary_tree_interpolator_selector_vtbl *)&vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
  interpolator_selector.m_result = 0;
  accept(from, &interpolator_selector);
  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))interpolator_selector.m_result->transition_time)(interpolator_selector.m_result) == 0.0 )
  {
    v9 = vostok::animation::mixing::n_ary_tree_cloner::clone(v8, (int)&a2[8], interpolator_selector.m_result, v29);
    v10 = a2[17].__vftable;
    v11 = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v9;
    result = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)v10->visit;
    v10->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *))((char *)v10->visit + 20);
    v10->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_subtraction_node *))((char *)v10->visit - 20);
    if ( result )
    {
      v13 = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)a2[33].__vftable;
      animation_interval_time = from_animation->m_animation_state->animation_interval_time;
      v15 = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)clear_value;
      result->__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
      result->m_from = (vostok::animation::mixing::n_ary_tree_base_node *)v11;
      result->m_to = (vostok::animation::mixing::n_ary_tree_base_node *)v15;
      *(float *)&result->m_interpolator = animation_interval_time;
      result->m_start_time_in_ms = (unsigned int)v13;
    }
  }
  else
  {
    v16 = a2[17].__vftable;
    visit = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)v16->visit;
    v16->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *))((char *)v16->visit + 20);
    v16->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_subtraction_node *))((char *)v16->visit - 20);
    v18 = clear_value;
    a2[9].__vftable = 0;
    a2[13].__vftable = 0;
    a2[16].__vftable = (vostok::animation::mixing::n_ary_tree_visitor_vtbl *)v18;
    v5->accept(v5, a2 + 8);
    m_result = (vostok::animation::mixing::n_ary_tree_cloner *)interpolator_selector.m_result;
    v20 = (vostok::animation::mixing::n_ary_tree_base_node *)a2[9].__vftable;
    v28 = interpolator_selector.m_result;
    a2[16].__vftable = (vostok::animation::mixing::n_ary_tree_visitor_vtbl *)clear_value;
    v21 = vostok::animation::mixing::n_ary_tree_cloner::clone(m_result, (int)&a2[8], v28, v29);
    v22 = a2[17].__vftable;
    v23 = (float *)v22->visit;
    v22->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_multiplication_node *))((char *)v22->visit + 20);
    v22->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_subtraction_node *))((char *)v22->visit - 20);
    if ( v23 )
    {
      v24 = from_animation->m_animation_state->animation_interval_time;
      v25 = a2[33].__vftable;
      v26 = clear_value;
      *(_DWORD *)v23 = &vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
      *((_DWORD *)v23 + 1) = v21;
      *((_DWORD *)v23 + 2) = v26;
      v23[3] = v24;
      *((_DWORD *)v23 + 4) = v25;
    }
    if ( visit )
    {
      v27 = (unsigned int)a2[33].__vftable;
      visit->m_to = (vostok::animation::mixing::n_ary_tree_base_node *)v23;
      visit->m_from = v20;
      visit->m_interpolator = v21;
      visit->m_start_time_in_ms = v27;
      visit->__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_transition_node::`vftable';
      from_animation = (vostok::animation::mixing::n_ary_tree_animation_node *)&vostok::animation::mixing::time_scale_transition_debug::`vftable';
      vostok::animation::mixing::n_ary_tree_time_scale_transition_node::accept(
        visit,
        (vostok::animation::mixing::n_ary_tree_visitor *)&from_animation);
    }
    return visit;
  }
  return result;
}


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
