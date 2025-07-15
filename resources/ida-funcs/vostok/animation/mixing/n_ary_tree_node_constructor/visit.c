void __thiscall vostok::animation::mixing::n_ary_tree_node_constructor::visit(
        vostok::animation::mixing::n_ary_tree_node_constructor *this,
        vostok::animation::mixing::binary_tree_addition_node *node)
{
  vostok::animation::mixing::n_ary_tree_base_node *m_data; // eax
  vostok::mutable_buffer *m_buffer; // eax

  m_data = (vostok::animation::mixing::n_ary_tree_base_node *)this->m_buffer->m_data;
  if ( m_data )
  {
    m_data[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)2;
    m_data->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_addition_node::`vftable';
  }
  else
  {
    m_data = 0;
  }
  this->m_result = m_data;
  m_buffer = this->m_buffer;
  m_buffer->m_data += 8;
  m_buffer->m_size -= 8;
  vostok::animation::mixing::n_ary_tree_node_constructor::propagate(this, (int)this, node);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_constructor::visit(
        vostok::animation::mixing::n_ary_tree_node_constructor *this,
        vostok::animation::mixing::binary_tree_animation_node *node)
{
  __debugbreak();
  JUMPOUT(0x568A31);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_constructor::visit(
        vostok::animation::mixing::n_ary_tree_node_constructor *this,
        vostok::animation::mixing::binary_tree_multiplication_node *node)
{
  vostok::animation::mixing::n_ary_tree_base_node *m_data; // eax
  vostok::mutable_buffer *m_buffer; // eax

  m_data = (vostok::animation::mixing::n_ary_tree_base_node *)this->m_buffer->m_data;
  if ( m_data )
  {
    m_data[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)2;
    m_data->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_multiplication_node::`vftable';
  }
  else
  {
    m_data = 0;
  }
  this->m_result = m_data;
  m_buffer = this->m_buffer;
  m_buffer->m_data += 8;
  m_buffer->m_size -= 8;
  vostok::animation::mixing::n_ary_tree_node_constructor::propagate(this, (int)this, node);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_constructor::visit(
        vostok::animation::mixing::n_ary_tree_node_constructor *this,
        vostok::animation::mixing::binary_tree_subtraction_node *node)
{
  vostok::animation::mixing::n_ary_tree_base_node *m_data; // eax
  vostok::mutable_buffer *m_buffer; // eax

  m_data = (vostok::animation::mixing::n_ary_tree_base_node *)this->m_buffer->m_data;
  if ( m_data )
  {
    m_data[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)2;
    m_data->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_subtraction_node::`vftable';
  }
  else
  {
    m_data = 0;
  }
  this->m_result = m_data;
  m_buffer = this->m_buffer;
  m_buffer->m_data += 8;
  m_buffer->m_size -= 8;
  vostok::animation::mixing::n_ary_tree_node_constructor::propagate(this, (int)this, node);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_constructor::visit(
        vostok::animation::mixing::n_ary_tree_node_constructor *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  const vostok::animation::base_interpolator *m_interpolator; // ebp
  const vostok::animation::base_interpolator *const *m_interpolators_begin; // esi
  const vostok::animation::base_interpolator *const *m_interpolators_end; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *m_data; // eax
  float m_simplified_weight; // xmm0_4
  vostok::mutable_buffer *m_buffer; // edi
  const vostok::animation::base_interpolator *found; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h] BYREF

  m_interpolator = node->m_interpolator;
  m_interpolators_begin = this->m_interpolators_begin;
  m_interpolators_end = this->m_interpolators_end;
  found = 0;
  if ( m_interpolators_begin != m_interpolators_end )
  {
    while ( 1 )
    {
      (*(void (__thiscall **)(const vostok::animation::base_interpolator *const, int *, const vostok::animation::base_interpolator *))(**(_DWORD **)m_interpolators_begin + 16))(
        *m_interpolators_begin,
        &v10,
        m_interpolator);
      if ( !v10 )
        break;
      if ( ++m_interpolators_begin == m_interpolators_end )
        goto LABEL_6;
    }
    found = *m_interpolators_begin;
  }
LABEL_6:
  m_data = (vostok::animation::mixing::n_ary_tree_base_node *)this->m_buffer->m_data;
  if ( m_data )
  {
    m_simplified_weight = node->m_simplified_weight;
    m_data->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
    m_data[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)found;
    *(float *)&m_data[2].__vftable = m_simplified_weight;
  }
  else
  {
    m_data = 0;
  }
  this->m_result = m_data;
  m_buffer = this->m_buffer;
  m_buffer->m_data += 12;
  m_buffer->m_size -= 12;
}
