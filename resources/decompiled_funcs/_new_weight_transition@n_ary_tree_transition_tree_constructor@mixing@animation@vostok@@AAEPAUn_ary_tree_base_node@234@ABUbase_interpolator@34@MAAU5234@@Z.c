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
