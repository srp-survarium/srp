boost::intrusive::rbtree_node<void *> *__usercall boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::unlink_leftmost_without_rebalance@<eax>(
        boost::intrusive::rbtree_node<void *> *header@<esi>)
{
  boost::intrusive::rbtree_node<void *> *result; // eax
  boost::intrusive::rbtree_node<void *> *parent; // ecx
  boost::intrusive::rbtree_node<void *> *right; // edx
  bool v4; // bl
  boost::intrusive::rbtree_node<void *> *left; // ecx
  boost::intrusive::rbtree_node<void *> *i; // edi

  result = header->left_;
  if ( result == header )
    return 0;
  parent = result->parent_;
  right = result->right_;
  v4 = result->parent_ == header;
  if ( right )
  {
    right->parent_ = parent;
    left = right->left_;
    for ( i = right; left; left = left->left_ )
      i = left;
    header->left_ = i;
    if ( v4 )
      header->parent_ = right;
    else
      header->parent_->left_ = right;
  }
  else if ( result->parent_ == header )
  {
    header->parent_ = 0;
    header->left_ = header;
    header->right_ = header;
  }
  else
  {
    parent->left_ = 0;
    header->left_ = parent;
  }
  return result;
}
