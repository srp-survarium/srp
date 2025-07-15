boost::intrusive::rbtree_node<void *> *__cdecl boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::erase(
        boost::intrusive::rbtree_node<void *> *header,
        boost::intrusive::rbtree_node<void *> *z)
{
  boost::intrusive::rbtree_node<void *>::color color; // ecx
  boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0> >::data_for_rebalance info; // [esp+8h] [ebp-Ch] BYREF

  boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::erase_impl(
    header,
    z,
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
      info.x,
      info.x_parent);
  return z;
}
