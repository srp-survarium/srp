void __thiscall vostok::animation::mixing::n_ary_tree_offset_adder::visit(
        vostok::animation::mixing::n_ary_tree_offset_adder *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  vostok::animation::mixing::n_ary_tree_addition_node *v2; // esi
  vostok::animation::mixing::n_ary_tree_addition_node *v4; // edi

  v2 = node + 1;
  v4 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)node + 4 * node->m_operands_count + 8);
  while ( v2 != v4 )
  {
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_addition_node_vtbl *, vostok::animation::mixing::n_ary_tree_offset_adder *))v2->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 2))(
      v2->__vftable,
      this);
    v2 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)v2 + 4);
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_offset_adder::visit(
        vostok::animation::mixing::n_ary_tree_offset_adder *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  node->m_time_scale_start_time_in_ms += this->m_offset_time_in_ms;
}


void __thiscall vostok::animation::mixing::n_ary_tree_offset_adder::visit(
        vostok::animation::mixing::n_ary_tree_offset_adder *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  unsigned int m_offset_time_in_ms; // eax
  vostok::animation::mixing::n_ary_tree_base_node *m_from; // ecx

  m_offset_time_in_ms = this->m_offset_time_in_ms;
  m_from = node->m_from;
  node->m_start_time_in_ms += m_offset_time_in_ms;
  m_from->accept(m_from, this);
  node->m_to->accept(node->m_to, this);
}
