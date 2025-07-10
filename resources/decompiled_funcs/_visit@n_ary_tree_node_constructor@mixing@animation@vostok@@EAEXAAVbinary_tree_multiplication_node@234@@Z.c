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
