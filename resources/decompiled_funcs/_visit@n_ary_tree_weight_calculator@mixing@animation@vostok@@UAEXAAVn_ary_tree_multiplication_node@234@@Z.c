void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node)
{
  const vostok::math::float4x4 *v2; // xmm0_4
  vostok::animation::mixing::n_ary_tree_multiplication_node *v3; // esi
  vostok::animation::mixing::n_ary_tree_multiplication_node *v4; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  float weight; // [esp+4h] [ebp-4h]

  v2 = clear_value;
  v3 = node + 1;
  v4 = (vostok::animation::mixing::n_ary_tree_multiplication_node *)((char *)node + 4 * node->m_operands_count + 8);
  weight = *(float *)&clear_value;
  if ( &node[1] != v4 )
  {
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_multiplication_node_vtbl *, vostok::animation::mixing::n_ary_tree_weight_calculator *))v3->~vostok::animation::mixing::n_ary_tree_multiplication_node
       + 2))(
        v3->__vftable,
        this);
      weight = this->m_weight * weight;
      *(float *)&v2 = weight;
      if ( weight == 0.0 )
        break;
      m_result = this->m_result;
      if ( m_result )
        v3->__vftable = (vostok::animation::mixing::n_ary_tree_multiplication_node_vtbl *)m_result;
      v3 = (vostok::animation::mixing::n_ary_tree_multiplication_node *)((char *)v3 + 4);
    }
    while ( v3 != v4 );
  }
  this->m_weight = *(float *)&v2;
  this->m_result = 0;
}
