vostok::animation::mixing::n_ary_tree_time_scale_transition_node *__thiscall vostok::animation::mixing::n_ary_tree_deserializer::get_operand(
        vostok::animation::mixing::n_ary_tree_deserializer *this)
{
  int v2; // eax
  vostok::animation::mixing::n_ary_tree_deserializer *v3; // ecx
  int v4; // eax
  unsigned int v5; // ebx
  vostok::mutable_buffer *v6; // eax
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *m_data; // edi
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v8; // eax
  unsigned int v9; // ebx
  vostok::mutable_buffer *v10; // eax
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v11; // eax
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v12; // ecx
  const vostok::animation::base_interpolator *v13; // eax
  const vostok::animation::base_interpolator *v14; // ecx
  float *v15; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v16; // xmm0_4
  vostok::mutable_buffer *v17; // esi
  const vostok::animation::base_interpolator *interpolator; // edx
  float *m_end; // eax
  float *v20; // eax
  const vostok::animation::base_interpolator *v21; // xmm1_4
  unsigned int v22; // eax
  vostok::mutable_buffer *m_buffer; // esi
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *operand; // [esp+Ch] [ebp-8h] BYREF
  const vostok::animation::base_interpolator *v26; // [esp+10h] [ebp-4h]

  v2 = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 2u);
  if ( !v2 )
  {
    interpolator = vostok::animation::mixing::n_ary_tree_deserializer::get_interpolator(v3, this);
    m_end = this->m_floats.m_end;
    v16 = (vostok::animation::mixing::n_ary_tree_base_node *)*((_DWORD *)m_end - 1);
    _InterlockedExchange((volatile __int32 *)&operand, (__int32)m_end);
    v20 = --this->m_floats.m_end;
    v21 = (const vostok::animation::base_interpolator *)*((_DWORD *)v20 - 1);
    _InterlockedExchange((volatile __int32 *)&operand, (__int32)v20);
    --this->m_floats.m_end;
    v22 = *--this->m_times_in_ms.m_end;
    m_buffer = this->m_buffer;
    m_data = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)m_buffer->m_data;
    m_buffer->m_data += 20;
    m_buffer->m_size -= 20;
    if ( !m_data )
      return m_data;
    m_data->__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
    m_data->m_from = (vostok::animation::mixing::n_ary_tree_base_node *)interpolator;
    m_data->m_interpolator = v21;
    m_data->m_start_time_in_ms = v22;
    goto LABEL_12;
  }
  v4 = v2 - 1;
  if ( !v4 )
  {
    v14 = vostok::animation::mixing::n_ary_tree_deserializer::get_interpolator(v3, this);
    v15 = this->m_floats.m_end;
    v16 = (vostok::animation::mixing::n_ary_tree_base_node *)*((_DWORD *)v15 - 1);
    _InterlockedExchange((volatile __int32 *)&operand, (__int32)v15);
    --this->m_floats.m_end;
    v17 = this->m_buffer;
    m_data = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)v17->m_data;
    v17->m_data += 12;
    v17->m_size -= 12;
    if ( !m_data )
      return m_data;
    m_data->__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
    m_data->m_from = (vostok::animation::mixing::n_ary_tree_base_node *)v14;
LABEL_12:
    m_data->m_to = v16;
    return m_data;
  }
  if ( v4 == 1 )
  {
    v26 = vostok::animation::mixing::n_ary_tree_deserializer::get_interpolator(v3, this);
    v9 = *--this->m_times_in_ms.m_end;
    v10 = this->m_buffer;
    m_data = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)v10->m_data;
    v10->m_data += 20;
    v10->m_size -= 20;
    operand = vostok::animation::mixing::n_ary_tree_deserializer::get_operand(this);
    v11 = vostok::animation::mixing::n_ary_tree_deserializer::get_operand(this);
    if ( m_data )
    {
      v12 = operand;
      m_data->m_to = v11;
      v13 = v26;
      m_data->__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
      m_data->m_from = v12;
      m_data->m_interpolator = v13;
      m_data->m_start_time_in_ms = v9;
    }
  }
  else
  {
    v26 = vostok::animation::mixing::n_ary_tree_deserializer::get_interpolator(v3, this);
    v5 = *--this->m_times_in_ms.m_end;
    v6 = this->m_buffer;
    m_data = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)v6->m_data;
    v6->m_data += 20;
    v6->m_size -= 20;
    operand = vostok::animation::mixing::n_ary_tree_deserializer::get_operand(this);
    v8 = vostok::animation::mixing::n_ary_tree_deserializer::get_operand(this);
    if ( m_data )
      vostok::animation::mixing::n_ary_tree_time_scale_transition_node::n_ary_tree_time_scale_transition_node(
        m_data,
        operand,
        v8,
        v26,
        v5);
  }
  return m_data;
}
