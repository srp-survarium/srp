void __thiscall vostok::animation::mixing::n_ary_tree_cloner::visit(
        vostok::animation::mixing::n_ary_tree_cloner *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::n_ary_tree_base_node *m_data; // edi
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // ebp
  const vostok::animation::base_interpolator *m_interpolator; // eax
  unsigned int m_start_time_in_ms; // ebx
  bool v9; // [esp+0h] [ebp-10h]
  vostok::animation::mixing::n_ary_tree_base_node *to; // [esp+14h] [ebp+4h]

  m_buffer = this->m_constructor->m_buffer;
  m_data = (vostok::animation::mixing::n_ary_tree_base_node *)m_buffer->m_data;
  m_buffer->m_data += 20;
  m_buffer->m_size -= 20;
  node->m_from->accept(node->m_from, this);
  m_result = this->m_result;
  node->m_to->accept(node->m_to, this);
  to = this->m_result;
  m_interpolator = vostok::animation::mixing::n_ary_tree_cloner::clone(
                     (vostok::animation::mixing::n_ary_tree_cloner *)to,
                     (int)this,
                     node->m_interpolator,
                     v9);
  if ( !m_interpolator )
    m_interpolator = node->m_interpolator;
  if ( m_data )
  {
    m_start_time_in_ms = node->m_start_time_in_ms;
    m_data->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
    m_data[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)m_result;
    m_data[2].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)to;
    m_data[3].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)m_interpolator;
    m_data[4].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)m_start_time_in_ms;
  }
  this->m_result = m_data;
}
