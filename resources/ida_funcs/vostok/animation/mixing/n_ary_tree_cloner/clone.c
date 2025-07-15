struct vostok::animation::mixing::n_ary_tree_base_node *__usercall vostok::animation::mixing::n_ary_tree_cloner::clone@<eax>(
        vostok::animation::mixing::n_ary_tree_cloner *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_addition_node *a2@<esi>,
        vostok::animation::mixing::n_ary_tree_addition_node_vtbl *a3@<xmm0>)
{
  struct vostok::animation::mixing::n_ary_tree_base_node *result; // eax

  a2->m_operands_count = 0;
  a2[4].__vftable = a3;
  a2[2].m_operands_count = 0;
  this->visit(this, a2);
  result = (struct vostok::animation::mixing::n_ary_tree_base_node *)a2->m_operands_count;
  a2[4].__vftable = (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)clear_value;
  return result;
}


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


vostok::animation::mixing::n_ary_tree_base_node *__usercall vostok::animation::mixing::n_ary_tree_cloner::clone@<eax>(
        vostok::animation::mixing::n_ary_tree_cloner *this@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node *node_to_clone@<ecx>,
        const vostok::animation::base_interpolator *animation_interpolator@<eax>)
{
  vostok::animation::mixing::n_ary_tree_base_node *result; // eax

  this->m_animation_interpolator = animation_interpolator;
  this->m_result = 0;
  node_to_clone->accept(node_to_clone, this);
  result = this->m_result;
  this->m_animation_interpolator = 0;
  return result;
}


const vostok::animation::base_interpolator *__userpurge vostok::animation::mixing::n_ary_tree_cloner::clone@<eax>(
        vostok::animation::mixing::n_ary_tree_cloner *this@<ecx>,
        int a2@<eax>,
        const vostok::animation::base_interpolator *interpolator,
        bool assert_on_failure)
{
  const vostok::animation::base_interpolator *v4; // ebx
  _DWORD *v5; // esi
  _DWORD *v6; // edi

  v4 = interpolator;
  v5 = *(_DWORD **)(a2 + 16);
  v6 = &v5[*(_DWORD *)(a2 + 28)];
  if ( v5 == v6 )
    return 0;
  while ( 1 )
  {
    v4->accept(
      v4,
      (vostok::animation::interpolator_comparer *)&interpolator,
      (const vostok::animation::base_interpolator *)*v5);
    if ( !interpolator )
      break;
    if ( ++v5 == v6 )
      return 0;
  }
  return (const vostok::animation::base_interpolator *)*v5;
}
