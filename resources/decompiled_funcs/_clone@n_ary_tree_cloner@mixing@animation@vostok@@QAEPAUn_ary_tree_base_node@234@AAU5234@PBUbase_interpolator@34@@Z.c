vostok::animation::mixing::n_ary_tree_base_node *__usercall vostok::animation::mixing::n_ary_tree_cloner::clone@<eax>(
        vostok::animation::mixing::n_ary_tree_cloner *this@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node *node_to_clone@<ecx>,
        const vostok::animation::base_interpolator *animation_interpolator@<eax>)
{
  vostok::animation::mixing::n_ary_tree_base_node *result; // eax

  this->m_animation_interpolator = animation_interpolator;
  this->m_result = 0;
  node_to_clone->accept(node_to_clone, this);
  result = this->m_result;
  this->m_animation_interpolator = 0;
  return result;
}
