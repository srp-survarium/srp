void __cdecl boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::erase_impl(
        boost::intrusive::rbtree_node<void *> *header,
        boost::intrusive::rbtree_node<void *> *z,
        boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0> >::data_for_rebalance *info)
{
  boost::intrusive::rbtree_node<void *> *v3; // ecx
  boost::intrusive::rbtree_node<void *> *left; // edx
  boost::intrusive::rbtree_node<void *> *right; // eax
  boost::intrusive::rbtree_node<void *> *parent; // ebp
  boost::intrusive::rbtree_node<void *> *v7; // eax
  boost::intrusive::rbtree_node<void *> *k; // edx
  boost::intrusive::rbtree_node<void *> *v9; // ebp
  boost::intrusive::rbtree_node<void *> *v10; // esi
  boost::intrusive::rbtree_node<void *> *i; // esi
  boost::intrusive::rbtree_node<void *> *v12; // eax
  boost::intrusive::rbtree_node<void *> *j; // ecx
  boost::intrusive::rbtree_node<void *> *v14; // eax

  v3 = z;
  left = z->left_;
  right = z->right_;
  if ( !left )
  {
    left = z->right_;
LABEL_3:
    parent = v3->parent_;
    if ( left )
      left->parent_ = parent;
    v7 = v3->parent_;
    if ( header->parent_ == v3 )
    {
      header->parent_ = left;
    }
    else if ( v3->parent_->left_ == v3 )
    {
      v7->left_ = left;
    }
    else
    {
      v7->right_ = left;
    }
    if ( header->left_ == v3 )
    {
      if ( v3->right_ )
      {
        v12 = left->left_;
        for ( i = left; v12; v12 = v12->left_ )
          i = v12;
      }
      else
      {
        i = v3->parent_;
      }
      header->left_ = i;
    }
    if ( header->right_ == v3 )
    {
      if ( v3->left_ )
      {
        v14 = left->right_;
        for ( j = left; v14; v14 = v14->right_ )
          j = v14;
      }
      else
      {
        j = v3->parent_;
      }
      header->right_ = j;
    }
    info->x = left;
    info->x_parent = parent;
    info->y = z;
    return;
  }
  if ( !right )
    goto LABEL_3;
  for ( k = right->left_; k; k = k->left_ )
    right = k;
  left = right->right_;
  z = right;
  if ( right == v3 )
    goto LABEL_3;
  v3->left_->parent_ = right;
  right->left_ = v3->left_;
  if ( right == v3->right_ )
  {
    v9 = right;
  }
  else
  {
    v9 = right->parent_;
    if ( left )
      left->parent_ = v9;
    v9->left_ = left;
    right->right_ = v3->right_;
    v3->right_->parent_ = right;
  }
  v10 = v3->parent_;
  if ( header->parent_ == v3 )
  {
    header->parent_ = right;
    right->parent_ = v3->parent_;
    info->x = left;
    info->x_parent = v9;
    info->y = right;
  }
  else
  {
    if ( v3->parent_->left_ == v3 )
      v10->left_ = right;
    else
      v10->right_ = right;
    right->parent_ = v3->parent_;
    info->x = left;
    info->x_parent = v9;
    info->y = right;
  }
}
