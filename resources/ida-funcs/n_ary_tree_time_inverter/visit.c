void __thiscall n_ary_tree_time_inverter::visit(
        n_ary_tree_time_inverter *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  vostok::animation::mixing::n_ary_tree_addition_node *v2; // esi
  vostok::animation::mixing::n_ary_tree_addition_node *v3; // edi

  v2 = node + 1;
  v3 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)node + 4 * node->m_operands_count + 8);
  if ( &node[1] != v3 )
  {
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_addition_node_vtbl *, n_ary_tree_time_inverter *))v2->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v2->__vftable,
        this);
      v2 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)v2 + 4);
    }
    while ( v2 != v3 );
  }
}


void __thiscall n_ary_tree_time_inverter::visit(
        n_ary_tree_time_inverter *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  node->m_time_scale_start_time_in_ms = this->m_current_time_in_ms - node->m_time_scale_start_time_in_ms;
}


void __thiscall n_ary_tree_time_inverter::visit(
        n_ary_tree_time_inverter *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  unsigned int v3; // eax
  vostok::animation::mixing::n_ary_tree_base_node *m_from; // ecx

  v3 = this->m_current_time_in_ms - node->m_start_time_in_ms;
  m_from = node->m_from;
  node->m_start_time_in_ms = v3;
  m_from->accept(m_from, this);
  node->m_to->accept(node->m_to, this);
}
