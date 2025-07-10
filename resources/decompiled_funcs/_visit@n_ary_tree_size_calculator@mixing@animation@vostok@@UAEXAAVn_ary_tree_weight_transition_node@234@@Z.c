void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v3; // eax

  v3 = this->vostok::animation::mixing::n_ary_tree_visitor::__vftable;
  if ( v3 )
    v3->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_weight_transition_node *))((char *)v3->visit + 20);
  else
    this->m_comparer = (vostok::animation::mixing::n_ary_tree_comparer *)((char *)this->m_comparer + 20);
  node->m_from->accept(
    node->m_from,
    this != (vostok::animation::mixing::n_ary_tree_size_calculator *)4
  ? (vostok::animation::mixing::n_ary_tree_visitor *)this
  : 0);
  node->m_to->accept(
    node->m_to,
    this != (vostok::animation::mixing::n_ary_tree_size_calculator *)4
  ? (vostok::animation::mixing::n_ary_tree_visitor *)this
  : 0);
}
