void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  vostok::animation::mixing::n_ary_tree_visitor_vtbl *v2; // eax

  v2 = this->vostok::animation::mixing::n_ary_tree_visitor::__vftable;
  if ( v2 )
    v2->visit = (void (__thiscall *)(vostok::animation::mixing::n_ary_tree_visitor *, vostok::animation::mixing::n_ary_tree_weight_transition_node *))((char *)v2->visit + 12);
  else
    this->m_comparer = (vostok::animation::mixing::n_ary_tree_comparer *)((char *)this->m_comparer + 12);
}
