void __thiscall vostok::animation::mixing::n_ary_tree_cloner::visit(
        vostok::animation::mixing::n_ary_tree_cloner *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v2; // ebx
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *m_data; // edi
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // ebp
  vostok::animation::mixing::n_ary_tree_base_node *v7; // ecx
  const vostok::animation::base_interpolator *v8; // eax
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *v9; // edx
  bool v10; // [esp+0h] [ebp-14h]
  vostok::animation::mixing::n_ary_tree_base_node *to; // [esp+10h] [ebp-4h]

  v2 = node;
  m_buffer = this->m_constructor->m_buffer;
  m_data = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)m_buffer->m_data;
  m_buffer->m_data += 20;
  m_buffer->m_size -= 20;
  v2->m_from->accept(v2->m_from, this);
  m_result = this->m_result;
  v2->m_to->accept(v2->m_to, this);
  v7 = this->m_result;
  to = v7;
  if ( m_data )
  {
    if ( this->m_animation_interval_time )
      node = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)this->m_start_time_in_ms;
    else
      node = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)v2->m_start_time_in_ms;
    v8 = vostok::animation::mixing::n_ary_tree_cloner::clone(
           (vostok::animation::mixing::n_ary_tree_cloner *)v7,
           (int)this,
           v2->m_interpolator,
           v10);
    v9 = node;
    m_data->m_interpolator = v8;
    m_data->m_to = to;
    m_data->m_from = m_result;
    m_data->m_start_time_in_ms = (unsigned int)v9;
    m_data->__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_transition_node::`vftable';
    node = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)&vostok::animation::mixing::time_scale_transition_debug::`vftable';
    vostok::animation::mixing::n_ary_tree_time_scale_transition_node::accept(
      m_data,
      (vostok::animation::mixing::n_ary_tree_visitor *)&node);
  }
  this->m_result = m_data;
}
