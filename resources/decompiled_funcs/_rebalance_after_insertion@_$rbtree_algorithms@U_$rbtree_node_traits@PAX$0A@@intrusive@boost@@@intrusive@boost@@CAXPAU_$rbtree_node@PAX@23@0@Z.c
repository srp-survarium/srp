void __cdecl boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rebalance_after_insertion(
        boost::intrusive::rbtree_node<void *> *header,
        boost::intrusive::rbtree_node<void *> *p)
{
  boost::intrusive::rbtree_node<void *> *v2; // edi
  boost::intrusive::rbtree_node<void *> *parent; // eax
  boost::intrusive::rbtree_node<void *> *v4; // ecx
  boost::intrusive::rbtree_node<void *> *right; // edx
  boost::intrusive::rbtree_node<void *> *v6; // edx
  boost::intrusive::rbtree_node<void *> *left; // esi
  boost::intrusive::rbtree_node<void *> *v8; // eax
  boost::intrusive::rbtree_node<void *> *v9; // esi
  boost::intrusive::rbtree_node<void *> *v10; // ecx
  boost::intrusive::rbtree_node<void *> *v11; // edx
  bool v12; // bl
  boost::intrusive::rbtree_node<void *> *v13; // edx
  boost::intrusive::rbtree_node<void *> *v14; // esi
  boost::intrusive::rbtree_node<void *> *v15; // edx

  v2 = p;
  p->color_ = red_t;
  if ( p == header->parent_ )
  {
    header->parent_->color_ = black_t;
    return;
  }
  while ( 1 )
  {
    parent = v2->parent_;
    if ( v2->parent_->color_ )
      break;
    v4 = parent->parent_;
    if ( parent->parent_->left_ == parent )
    {
      right = v4->right_;
      if ( !right || right->color_ )
      {
        if ( parent->left_ != v2 )
        {
          v6 = parent->right_;
          left = v6->left_;
          v2 = v2->parent_;
          parent->right_ = left;
          if ( left )
            left->parent_ = parent;
          v6->left_ = parent;
          parent->parent_ = v6;
          v6->parent_ = v4;
          if ( header->parent_ == parent )
            header->parent_ = v6;
          else
            v4->left_ = v6;
        }
        v8 = v2->parent_->parent_;
        v2->parent_->color_ = black_t;
        v9 = v8->parent_;
        v10 = v8->left_;
        v8->color_ = red_t;
        v11 = v10->right_;
        v12 = v9->left_ == v8;
        v8->left_ = v11;
        if ( v11 )
          v11->parent_ = v8;
        v10->right_ = v8;
LABEL_27:
        v8->parent_ = v10;
        v10->parent_ = v9;
        if ( header->parent_ == v8 )
        {
          header->parent_ = v10;
        }
        else if ( v12 )
        {
          v9->left_ = v10;
        }
        else
        {
          v9->right_ = v10;
        }
        goto LABEL_32;
      }
    }
    else
    {
      right = v4->left_;
      if ( !right || right->color_ )
      {
        if ( parent->left_ == v2 )
        {
          v13 = parent->left_;
          v14 = v13->right_;
          v2 = v2->parent_;
          parent->left_ = v14;
          if ( v14 )
            v14->parent_ = parent;
          v13->right_ = parent;
          parent->parent_ = v13;
          v13->parent_ = v4;
          if ( header->parent_ == parent )
            header->parent_ = v13;
          else
            v4->right_ = v13;
        }
        v8 = v2->parent_->parent_;
        v2->parent_->color_ = black_t;
        v9 = v8->parent_;
        v10 = v8->right_;
        v8->color_ = red_t;
        v15 = v10->left_;
        v12 = v9->left_ == v8;
        v8->right_ = v15;
        if ( v15 )
          v15->parent_ = v8;
        v10->left_ = v8;
        goto LABEL_27;
      }
    }
    parent->color_ = black_t;
    v4->color_ = red_t;
    right->color_ = black_t;
    v2 = v4;
LABEL_32:
    if ( v2 == header->parent_ )
    {
      header->parent_->color_ = black_t;
      return;
    }
  }
  header->parent_->color_ = black_t;
}
