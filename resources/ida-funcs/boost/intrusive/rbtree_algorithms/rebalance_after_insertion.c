void __usercall boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rebalance_after_insertion(
        boost::intrusive::rbtree_node<void *> *header@<ecx>,
        boost::intrusive::rbtree_node<void *> *p@<eax>)
{
  boost::intrusive::rbtree_node<void *> *v2; // esi
  boost::intrusive::rbtree_node<void *> *parent; // eax
  boost::intrusive::rbtree_node<void *> *v5; // ecx
  boost::intrusive::rbtree_node<void *> *right; // edx
  boost::intrusive::rbtree_node<void *> *v7; // eax
  boost::intrusive::rbtree_node<void *> *v8; // eax

  v2 = p;
  p->color_ = red_t;
  while ( v2 != header->parent_ )
  {
    parent = v2->parent_;
    if ( v2->parent_->color_ )
      break;
    v5 = parent->parent_;
    if ( parent->parent_->left_ == parent )
    {
      right = v5->right_;
      if ( right && right->color_ == red_t )
        goto LABEL_11;
      if ( parent->left_ != v2 )
      {
        v2 = v2->parent_;
        boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_left(
          parent,
          header);
      }
      v7 = v2->parent_->parent_;
      v2->parent_->color_ = black_t;
      v7->color_ = red_t;
      boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_right(
        v7,
        header);
    }
    else
    {
      right = v5->left_;
      if ( !right || right->color_ )
      {
        if ( parent->left_ == v2 )
        {
          v2 = v2->parent_;
          boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_right(
            parent,
            header);
        }
        v8 = v2->parent_->parent_;
        v2->parent_->color_ = black_t;
        v8->color_ = red_t;
        boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_left(
          v8,
          header);
      }
      else
      {
LABEL_11:
        parent->color_ = black_t;
        v5->color_ = red_t;
        right->color_ = black_t;
        v2 = v5;
      }
    }
  }
  header->parent_->color_ = black_t;
}
