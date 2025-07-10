void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  float v2; // xmm0_4
  vostok::animation::mixing::n_ary_tree_addition_node *v3; // esi
  vostok::animation::mixing::n_ary_tree_addition_node *v4; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  float weight; // [esp+4h] [ebp-4h]

  v2 = 0.0;
  v3 = node + 1;
  v4 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)node + 4 * node->m_operands_count + 8);
  weight = 0.0;
  if ( &node[1] != v4 )
  {
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_addition_node_vtbl *, vostok::animation::mixing::n_ary_tree_weight_calculator *))v3->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v3->__vftable,
        this);
      m_result = this->m_result;
      v2 = this->m_weight + weight;
      weight = v2;
      if ( m_result )
        v3->__vftable = (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)m_result;
      v3 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)v3 + 4);
    }
    while ( v3 != v4 );
  }
  this->m_weight = v2;
  this->m_result = 0;
}
