void __usercall boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::erase_impl(
        boost::intrusive::rbtree_node<void *> *z@<eax>,
        boost::intrusive::rbtree_node<void *> *header,
        boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0> >::data_for_rebalance *info)
{
  boost::intrusive::rbtree_node<void *> *left; // edx
  boost::intrusive::rbtree_node<void *> *right; // ecx
  boost::intrusive::rbtree_node<void *> *parent; // edi
  boost::intrusive::rbtree_node<void *> *v6; // ecx
  boost::intrusive::rbtree_node<void *> *i; // edx
  boost::intrusive::rbtree_node<void *> *v8; // esi
  boost::intrusive::rbtree_node<void *> *v9; // esi
  boost::intrusive::rbtree_node<void *> *v10; // ecx
  boost::intrusive::rbtree_node<void *> *v11; // ecx
  boost::intrusive::rbtree_node<void *> *v12; // esi
  boost::intrusive::rbtree_node<void *> *v13; // eax
  boost::intrusive::rbtree_node<void *> *v14; // eax
  boost::intrusive::rbtree_node<void *> *v15; // ecx
  boost::intrusive::rbtree_node<void *> *v16; // [esp+Ch] [ebp-8h]
  boost::intrusive::rbtree_node<void *> *v17; // [esp+10h] [ebp-4h]

  left = z->left_;
  right = z->right_;
  v16 = z;
  if ( !left )
  {
    left = z->right_;
LABEL_3:
    parent = z->parent_;
    if ( left )
      left->parent_ = parent;
    v6 = z->parent_;
    if ( header->parent_ == z )
    {
      header->parent_ = left;
    }
    else if ( z->parent_->left_ == z )
    {
      v6->left_ = left;
    }
    else
    {
      v6->right_ = left;
    }
    if ( header->left_ == z )
    {
      if ( z->right_ )
      {
        v11 = left->left_;
        v12 = left;
        while ( v11 )
        {
          v12 = v11;
          v11 = v11->left_;
        }
        v10 = v12;
      }
      else
      {
        v10 = z->parent_;
      }
      header->left_ = v10;
    }
    if ( header->right_ == z )
    {
      if ( z->left_ )
      {
        v14 = left->right_;
        v15 = left;
        while ( v14 )
        {
          v15 = v14;
          v14 = v14->right_;
        }
        v13 = v15;
      }
      else
      {
        v13 = z->parent_;
      }
      header->right_ = v13;
    }
    goto LABEL_42;
  }
  if ( !right )
    goto LABEL_3;
  for ( i = right->left_; i; i = i->left_ )
    right = i;
  left = right->right_;
  v16 = right;
  if ( right == z )
    goto LABEL_3;
  z->left_->parent_ = right;
  right->left_ = z->left_;
  if ( right == z->right_ )
  {
    v17 = right;
  }
  else
  {
    v8 = right->parent_;
    v17 = right->parent_;
    if ( left )
      left->parent_ = v8;
    v8->left_ = left;
    right->right_ = z->right_;
    z->right_->parent_ = right;
  }
  v9 = z->parent_;
  if ( header->parent_ == z )
  {
    header->parent_ = right;
  }
  else if ( z->parent_->left_ == z )
  {
    v9->left_ = right;
  }
  else
  {
    v9->right_ = right;
  }
  parent = v17;
  right->parent_ = z->parent_;
LABEL_42:
  info->x_parent = parent;
  info->x = left;
  info->y = v16;
}
