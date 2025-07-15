void __usercall boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rebalance_after_erasure(
        boost::intrusive::rbtree_node<void *> *header@<ecx>,
        boost::intrusive::rbtree_node<void *> *x_parent@<eax>,
        boost::intrusive::rbtree_node<void *> *x)
{
  boost::intrusive::rbtree_node<void *> *left; // eax
  boost::intrusive::rbtree_node<void *> *v6; // ecx
  boost::intrusive::rbtree_node<void *> *v7; // ecx
  boost::intrusive::rbtree_node<void *> *right; // ecx
  boost::intrusive::rbtree_node<void *> *v9; // eax
  boost::intrusive::rbtree_node<void *> *v10; // ecx
  boost::intrusive::rbtree_node<void *> *v11; // ecx
  boost::intrusive::rbtree_node<void *> *v12; // ecx
  boost::intrusive::rbtree_node<void *> *v13; // eax

  while ( x != header->parent_ && (!x || x->color_ == black_t) )
  {
    left = x_parent->left_;
    if ( x == left )
    {
      left = x_parent->right_;
      if ( left->color_ == red_t )
      {
        left->color_ = black_t;
        x_parent->color_ = red_t;
        boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_left(
          x_parent,
          header);
        left = x_parent->right_;
      }
      v6 = left->left_;
      if ( v6 && v6->color_ != black_t || (v7 = left->right_) != 0 && v7->color_ != black_t )
      {
        right = left->right_;
        if ( !right || right->color_ == black_t )
        {
          left->left_->color_ = black_t;
          left->color_ = red_t;
          boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_right(
            left,
            header);
          left = x_parent->right_;
        }
        left->color_ = x_parent->color_;
        x_parent->color_ = black_t;
        v9 = left->right_;
        if ( v9 )
          v9->color_ = black_t;
        boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_left(
          x_parent,
          header);
        break;
      }
    }
    else
    {
      if ( left->color_ == red_t )
      {
        left->color_ = black_t;
        x_parent->color_ = red_t;
        boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_right(
          x_parent,
          header);
        left = x_parent->left_;
      }
      v10 = left->right_;
      if ( v10 && v10->color_ != black_t || (v11 = left->left_) != 0 && v11->color_ != black_t )
      {
        v12 = left->left_;
        if ( !v12 || v12->color_ == black_t )
        {
          left->right_->color_ = black_t;
          left->color_ = red_t;
          boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_left(
            left,
            header);
          left = x_parent->left_;
        }
        left->color_ = x_parent->color_;
        x_parent->color_ = black_t;
        v13 = left->left_;
        if ( v13 )
          v13->color_ = black_t;
        boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_right(
          x_parent,
          header);
        break;
      }
    }
    left->color_ = red_t;
    x = x_parent;
    x_parent = x_parent->parent_;
  }
  if ( x )
    x->color_ = black_t;
}
