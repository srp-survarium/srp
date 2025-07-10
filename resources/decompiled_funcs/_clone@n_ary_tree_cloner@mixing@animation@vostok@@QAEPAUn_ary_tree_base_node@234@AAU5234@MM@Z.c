vostok::animation::mixing::n_ary_tree_base_node *__userpurge vostok::animation::mixing::n_ary_tree_cloner::clone@<eax>(
        vostok::animation::mixing::n_ary_tree_cloner *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_addition_node *a2@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node *node_to_clone,
        float time_scale_factor,
        float animation_interval_time)
{
  const vostok::math::float4x4 *v5; // xmm0_4
  const vostok::math::float4x4 *v6; // xmm0_4
  vostok::animation::mixing::n_ary_tree_base_node *result; // eax

  v5 = clear_value;
  a2[2].m_operands_count = (unsigned int)&node_to_clone;
  a2->m_operands_count = 0;
  a2[4].__vftable = (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)v5;
  this->visit(this, a2);
  v6 = clear_value;
  result = (vostok::animation::mixing::n_ary_tree_base_node *)a2->m_operands_count;
  a2[2].m_operands_count = 0;
  a2[4].__vftable = (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)v6;
  return result;
}
