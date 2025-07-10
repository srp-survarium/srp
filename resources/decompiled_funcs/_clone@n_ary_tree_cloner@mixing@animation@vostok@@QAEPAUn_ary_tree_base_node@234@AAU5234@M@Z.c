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
