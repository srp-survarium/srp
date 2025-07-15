struct vostok::animation::mixing::binary_tree_weight_node *__userpurge vostok::animation::mixing::binary_tree_expression_simplifier::new_weight@<eax>(
        vostok::animation::mixing::binary_tree_expression_simplifier *this@<ecx>,
        int a2@<eax>,
        float a3@<xmm0>,
        const vostok::animation::base_interpolator *interpolator,
        const struct vostok::animation::base_interpolator *a5)
{
  int v5; // ecx
  struct vostok::animation::mixing::binary_tree_weight_node *result; // eax

  v5 = *(_DWORD *)(a2 + 4);
  result = *(struct vostok::animation::mixing::binary_tree_weight_node **)v5;
  *(_DWORD *)v5 += 32;
  *(_DWORD *)(v5 + 4) -= 32;
  if ( result )
  {
    result->m_next_weight = 0;
    result->m_same_weight = 0;
    result->m_next_unique_interpolator = 0;
    result->m_reference_count = 0;
    result->__vftable = (vostok::animation::mixing::binary_tree_weight_node_vtbl *)&vostok::animation::mixing::binary_tree_weight_node::`vftable';
    result->m_interpolator = interpolator;
    result->m_weight = a3;
    result->m_simplified_weight = a3;
  }
  return result;
}
