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
