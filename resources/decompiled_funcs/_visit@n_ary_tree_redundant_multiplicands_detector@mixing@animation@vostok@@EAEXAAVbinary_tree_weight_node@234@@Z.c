void __thiscall vostok::animation::mixing::n_ary_tree_redundant_multiplicands_detector::visit(
        vostok::animation::mixing::n_ary_tree_redundant_multiplicands_detector *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  if ( node->m_weight == *(float *)&clear_value )
  {
    this->m_interpolator->accept(
      this->m_interpolator,
      (vostok::animation::interpolator_comparer *)&node,
      node->m_interpolator);
    this->m_result = node == 0;
  }
}
