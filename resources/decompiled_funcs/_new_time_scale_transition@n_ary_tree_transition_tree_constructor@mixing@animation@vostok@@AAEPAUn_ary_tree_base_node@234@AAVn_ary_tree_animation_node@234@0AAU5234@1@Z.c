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
