void __usercall vostok::animation::mixing::n_ary_tree_weaver::propagate<vostok::animation::mixing::binary_tree_base_node>(
        vostok::animation::mixing::n_ary_tree_weaver *this@<esi>,
        vostok::animation::mixing::binary_tree_base_node *node@<ecx>,
        vostok::animation::mixing::n_ary_tree_weaver *weaver@<edi>)
{
  weaver->m_interpolators_root = this->m_interpolators_root;
  weaver->m_weights_root = this->m_weights_root;
  weaver->m_current_animations_root = this->m_current_animations_root;
  node->accept(node, weaver);
  this->m_interpolators_root = weaver->m_interpolators_root;
  this->m_interpolators_count += weaver->m_interpolators_count;
  this->m_weights_root = weaver->m_weights_root;
}
