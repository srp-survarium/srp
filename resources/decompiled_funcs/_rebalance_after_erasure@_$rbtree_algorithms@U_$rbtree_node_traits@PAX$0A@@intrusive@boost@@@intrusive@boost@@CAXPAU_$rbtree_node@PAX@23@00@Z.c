void __cdecl boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rebalance_after_erasure(
        boost::intrusive::rbtree_node<void *> *header,
        boost::intrusive::rbtree_node<void *> *x,
        boost::intrusive::rbtree_node<void *> *x_parent)
{
  boost::intrusive::rbtree_node<void *> *v3; // ebx
  boost::intrusive::rbtree_node<void *> *left; // eax
  boost::intrusive::rbtree_node<void *> *parent; // edx
  boost::intrusive::rbtree_node<void *> *right; // eax
  boost::intrusive::rbtree_node<void *> *v8; // ecx
  bool v9; // bl
  boost::intrusive::rbtree_node<void *> *v10; // ecx
  boost::intrusive::rbtree_node<void *> *v11; // ecx
  boost::intrusive::rbtree_node<void *> *v12; // ecx
  boost::intrusive::rbtree_node<void *> *v13; // eax
  boost::intrusive::rbtree_node<void *> *v14; // edx
  boost::intrusive::rbtree_node<void *> *v15; // eax
  boost::intrusive::rbtree_node<void *> *v16; // ecx
  bool v17; // bl
  boost::intrusive::rbtree_node<void *> *v18; // ecx
  boost::intrusive::rbtree_node<void *> *v19; // ecx
  boost::intrusive::rbtree_node<void *> *v20; // ecx
  boost::intrusive::rbtree_node<void *> *v21; // ecx
  boost::intrusive::rbtree_node<void *> *v22; // eax

  v3 = x;
  if ( x != header->parent_ )
  {
    while ( !v3 || v3->color_ == black_t )
    {
      left = x_parent->left_;
      if ( v3 == left )
      {
        left = x_parent->right_;
        if ( left->color_ == red_t )
        {
          left->color_ = black_t;
          parent = x_parent->parent_;
          right = x_parent->right_;
          x_parent->color_ = red_t;
          v8 = right->left_;
          v9 = parent->left_ == x_parent;
          x_parent->right_ = v8;
          if ( v8 )
            v8->parent_ = x_parent;
          right->left_ = x_parent;
          x_parent->parent_ = right;
          right->parent_ = parent;
          if ( header->parent_ == x_parent )
          {
            header->parent_ = right;
          }
          else if ( v9 )
          {
            parent->left_ = right;
          }
          else
          {
            parent->right_ = right;
          }
          left = x_parent->right_;
          v3 = x;
        }
        v10 = left->left_;
        if ( v10 && v10->color_ != black_t || (v11 = left->right_) != 0 && v11->color_ != black_t )
        {
          v12 = left->right_;
          if ( !v12 || v12->color_ == black_t )
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
          v13 = left->right_;
          if ( v13 )
            v13->color_ = black_t;
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
          v14 = x_parent->parent_;
          v15 = x_parent->left_;
          x_parent->color_ = red_t;
          v16 = v15->right_;
          v17 = v14->left_ == x_parent;
          x_parent->left_ = v16;
          if ( v16 )
            v16->parent_ = x_parent;
          v15->right_ = x_parent;
          x_parent->parent_ = v15;
          v15->parent_ = v14;
          if ( header->parent_ == x_parent )
          {
            header->parent_ = v15;
          }
          else if ( v17 )
          {
            v14->left_ = v15;
          }
          else
          {
            v14->right_ = v15;
          }
          left = x_parent->left_;
          v3 = x;
        }
        v18 = left->right_;
        if ( v18 && v18->color_ != black_t || (v19 = left->left_) != 0 && v19->color_ != black_t )
        {
          v21 = left->left_;
          if ( !v21 || v21->color_ == black_t )
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
          v22 = left->left_;
          if ( v22 )
            v22->color_ = black_t;
          boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_right(
            x_parent,
            header);
          break;
        }
      }
      x = x_parent;
      v20 = x_parent;
      left->color_ = red_t;
      x_parent = x_parent->parent_;
      v3 = v20;
      if ( v20 == header->parent_ )
        break;
    }
  }
  if ( v3 )
    v3->color_ = black_t;
}
