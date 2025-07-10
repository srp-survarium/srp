void __thiscall vostok::animation::mixing::n_ary_tree_cloner::visit(
        vostok::animation::mixing::n_ary_tree_cloner *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  const vostok::animation::base_interpolator *m_interpolator; // eax
  vostok::animation::mixing::n_ary_tree_base_node *m_data; // ecx
  float m_weight; // xmm0_4
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *m_constructor; // eax
  vostok::mutable_buffer *m_buffer; // eax
  bool v8; // [esp+0h] [ebp-8h]

  m_interpolator = vostok::animation::mixing::n_ary_tree_cloner::clone(this, (int)this, node->m_interpolator, v8);
  if ( !m_interpolator )
    m_interpolator = node->m_interpolator;
  m_data = (vostok::animation::mixing::n_ary_tree_base_node *)this->m_constructor->m_buffer->m_data;
  if ( m_data )
  {
    m_weight = node->m_weight;
    m_data->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
    m_data[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)m_interpolator;
    *(float *)&m_data[2].__vftable = m_weight;
  }
  else
  {
    m_data = 0;
  }
  m_constructor = this->m_constructor;
  this->m_result = m_data;
  m_buffer = m_constructor->m_buffer;
  m_buffer->m_data += 12;
  m_buffer->m_size -= 12;
}
