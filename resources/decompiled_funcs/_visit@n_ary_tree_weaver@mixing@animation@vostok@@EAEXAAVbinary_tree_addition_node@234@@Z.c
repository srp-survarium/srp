void __thiscall vostok::animation::mixing::n_ary_tree_weaver::visit(
        vostok::animation::mixing::n_ary_tree_weaver *this,
        vostok::animation::mixing::binary_tree_addition_node *node)
{
  vostok::animation::mixing::n_ary_tree_weaver left; // [esp+10h] [ebp-40h] BYREF
  vostok::animation::mixing::n_ary_tree_weaver right; // [esp+30h] [ebp-20h] BYREF

  node->m_next_weight = 0;
  left.m_buffer = this->m_buffer;
  right.m_buffer = left.m_buffer;
  left.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  right.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  memset(&left.m_animations_root, 0, 20);
  memset(&right.m_animations_root, 0, 20);
  vostok::animation::mixing::n_ary_tree_weaver::propagate<vostok::animation::mixing::binary_tree_addition_node>(
    &left,
    this,
    node,
    &left,
    &right);
  if ( !left.m_animations_root && !right.m_animations_root )
    this->m_weights_root = node;
}
