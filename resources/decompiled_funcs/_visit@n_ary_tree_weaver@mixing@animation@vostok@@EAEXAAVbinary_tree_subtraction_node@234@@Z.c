void __thiscall vostok::animation::mixing::n_ary_tree_weaver::visit(
        vostok::animation::mixing::n_ary_tree_weaver *this,
        vostok::animation::mixing::binary_tree_subtraction_node *node)
{
  vostok::mutable_buffer *m_buffer; // ecx
  vostok::animation::mixing::n_ary_tree_weaver right; // [esp+8h] [ebp-40h] BYREF
  vostok::animation::mixing::n_ary_tree_weaver left; // [esp+28h] [ebp-20h] BYREF

  node->m_next_weight = 0;
  m_buffer = this->m_buffer;
  memset(&left.m_animations_root, 0, 20);
  memset(&right.m_animations_root, 0, 20);
  left.m_buffer = m_buffer;
  right.m_buffer = m_buffer;
  left.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  right.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  vostok::animation::mixing::n_ary_tree_weaver::propagate<vostok::animation::mixing::binary_tree_addition_node>(
    &left,
    this,
    (vostok::animation::mixing::binary_tree_addition_node *)node,
    &left,
    &right);
  this->m_weights_root = node;
}
