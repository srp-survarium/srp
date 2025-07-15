boost::intrusive::rbtree_node<void *> *__usercall boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::erase@<eax>(
        boost::intrusive::rbtree_node<void *> *z@<esi>,
        boost::intrusive::rbtree_node<void *> *header)
{
  boost::intrusive::rbtree_node<void *>::color color; // ecx
  boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0> >::data_for_rebalance info; // [esp+0h] [ebp-Ch] BYREF

  boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::erase_impl(
    z,
    header,
    &info);
  if ( info.y != z )
  {
    color = info.y->color_;
    info.y->color_ = z->color_;
    z->color_ = color;
  }
  if ( z->color_ )
    boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rebalance_after_erasure(
      header,
      info.x_parent,
      info.x);
  return z;
}
