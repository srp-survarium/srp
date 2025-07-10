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
