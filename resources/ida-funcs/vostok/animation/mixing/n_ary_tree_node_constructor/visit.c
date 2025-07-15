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
  vostok::animation::mixing::n_ary_tree_node_constructor::propagate(this, this, node);
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
  vostok::animation::mixing::n_ary_tree_node_constructor::propagate(this, this, node);
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
  vostok::animation::mixing::n_ary_tree_node_constructor::propagate(this, this, node);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_constructor::visit(
        vostok::animation::mixing::n_ary_tree_node_constructor *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  const vostok::animation::base_interpolator *const *m_interpolators_end; // ebx
  const vostok::animation::base_interpolator *const *m_interpolators_begin; // edi
  vostok::animation::mixing::n_ary_tree_base_node *m_data; // eax
  float m_simplified_weight; // xmm0_4
  vostok::mutable_buffer *m_buffer; // esi
  const vostok::animation::base_interpolator *m_interpolator; // [esp+Ch] [ebp-8h]
  vostok::animation::mixing::n_ary_tree_base_node_vtbl *v9; // [esp+10h] [ebp-4h]

  v9 = 0;
  m_interpolators_end = this->m_interpolators_end;
  m_interpolators_begin = this->m_interpolators_begin;
  m_interpolator = node->m_interpolator;
  while ( m_interpolators_begin != m_interpolators_end )
  {
    if ( !vostok::animation::compare(m_interpolator) )
    {
      v9 = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)*m_interpolators_begin;
      break;
    }
    ++m_interpolators_begin;
  }
  m_data = (vostok::animation::mixing::n_ary_tree_base_node *)this->m_buffer->m_data;
  if ( m_data )
  {
    m_simplified_weight = node->m_simplified_weight;
    m_data->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
    m_data[1].__vftable = v9;
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
