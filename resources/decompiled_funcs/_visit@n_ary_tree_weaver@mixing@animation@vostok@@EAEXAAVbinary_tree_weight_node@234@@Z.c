void __thiscall vostok::animation::mixing::n_ary_tree_weaver::visit(
        vostok::animation::mixing::n_ary_tree_weaver *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  vostok::animation::mixing::binary_tree_base_node *m_weights_root; // edx
  vostok::animation::mixing::binary_tree_base_node *m_interpolators_root; // edx

  m_weights_root = this->m_weights_root;
  this->m_new_node = node;
  node->m_next_weight = m_weights_root;
  m_interpolators_root = this->m_interpolators_root;
  ++this->m_interpolators_count;
  this->m_weights_root = node;
  node->m_next_unique_interpolator = m_interpolators_root;
  this->m_interpolators_root = node;
}
