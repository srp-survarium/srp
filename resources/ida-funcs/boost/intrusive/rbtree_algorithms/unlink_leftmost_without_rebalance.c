boost::intrusive::rbtree_node<void *> *__usercall boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::unlink_leftmost_without_rebalance@<eax>(
        boost::intrusive::rbtree_node<void *> *header@<eax>)
{
  boost::intrusive::rbtree_node<void *> *left; // edi
  boost::intrusive::rbtree_node<void *> *right; // ecx
  boost::intrusive::rbtree_node<void *> *parent; // esi
  bool v5; // bl
  boost::intrusive::rbtree_node<void *> *v6; // edx
  boost::intrusive::rbtree_node<void *> *v7; // esi

  left = header->left_;
  if ( left == header )
    return 0;
  right = left->right_;
  parent = left->parent_;
  v5 = left->parent_ == header;
  if ( right )
  {
    v6 = right->left_;
    right->parent_ = parent;
    v7 = right;
    while ( v6 )
    {
      v7 = v6;
      v6 = v6->left_;
    }
    header->left_ = v7;
    if ( v5 )
      header->parent_ = right;
    else
      header->parent_->left_ = right;
  }
  else if ( left->parent_ == header )
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
  return left;
}
