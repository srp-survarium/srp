void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *left,
        vostok::animation::mixing::n_ary_tree_weight_node *right)
{
  vostok::animation::mixing::n_ary_tree_weight_node *v3; // esi
  vostok::animation::mixing::n_ary_tree_weight_node *v4; // edi

  v3 = left;
  v4 = right;
  left->m_interpolator->accept(
    left->m_interpolator,
    (vostok::animation::interpolator_comparer *)&left,
    right->m_interpolator);
  if ( !left )
  {
    if ( v4->m_weight <= v3->m_weight )
      goto LABEL_3;
LABEL_7:
    this->result = less;
    return;
  }
  if ( left == (vostok::animation::mixing::n_ary_tree_weight_node *)1 )
    goto LABEL_7;
LABEL_3:
  v4->m_interpolator->accept(v4->m_interpolator, (vostok::animation::interpolator_comparer *)&left, v3->m_interpolator);
  if ( left )
  {
    if ( left == (vostok::animation::mixing::n_ary_tree_weight_node *)1 )
    {
LABEL_5:
      this->result = more;
      return;
    }
  }
  else if ( v3->m_weight > v4->m_weight )
  {
    goto LABEL_5;
  }
  this->result = equal;
}
