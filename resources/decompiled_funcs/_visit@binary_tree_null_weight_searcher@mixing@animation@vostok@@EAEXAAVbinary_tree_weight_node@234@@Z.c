void __thiscall vostok::animation::mixing::binary_tree_null_weight_searcher::visit(
        vostok::animation::mixing::binary_tree_null_weight_searcher *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  this->m_result = this->m_result || node->m_weight == 0.0;
}
