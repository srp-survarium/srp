void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  float v2; // xmm0_4
  unsigned int m_operands_count; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  const vostok::math::float4x4 *weight; // [esp+4h] [ebp-4h]

  v2 = *(float *)&clear_value;
  m_operands_count = node->m_operands_count;
  v4 = node + 1;
  weight = clear_value;
  v6 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)node + 4 * m_operands_count + 88);
  if ( m_operands_count )
  {
    v2 = *(float *)&clear_value;
    if ( (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v4->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
          + 3))(v4->__vftable) )
      v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)node + 92);
  }
  for ( ; v4 != v6; v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v4 + 4) )
  {
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_weight_calculator *))v4->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 2))(
      v4->__vftable,
      this);
    m_result = this->m_result;
    v2 = *(float *)&weight * this->m_weight;
    *(float *)&weight = v2;
    if ( m_result )
    {
      if ( node->m_operands_count == m_operands_count )
      {
        v4->__vftable = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)m_result;
      }
      else
      {
        v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v4 - 4);
        v6 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v6 - 4);
      }
    }
    if ( v2 == 0.0 )
      break;
  }
  this->m_weight = v2;
  this->m_result = 0;
}
