void __thiscall vostok::animation::mixing::n_ary_tree_redundant_multiplicands_detector::visit(
        vostok::animation::mixing::n_ary_tree_redundant_multiplicands_detector *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  if ( node->m_weight == s_bm_current_air_resistance )
    this->m_result = vostok::animation::compare(node->m_interpolator) == 0;
}
