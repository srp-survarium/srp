void __usercall boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_left(
        boost::intrusive::rbtree_node<void *> *p@<eax>,
        boost::intrusive::rbtree_node<void *> *header@<edi>)
{
  boost::intrusive::rbtree_node<void *> *parent; // edx
  boost::intrusive::rbtree_node<void *> *right; // ecx
  boost::intrusive::rbtree_node<void *> *left; // esi
  bool v5; // bl

  parent = p->parent_;
  right = p->right_;
  left = right->left_;
  v5 = p->parent_->left_ == p;
  p->right_ = left;
  if ( left )
    left->parent_ = p;
  right->left_ = p;
  p->parent_ = right;
  right->parent_ = parent;
  if ( header->parent_ == p )
  {
    header->parent_ = right;
  }
  else if ( v5 )
  {
    parent->left_ = right;
  }
  else
  {
    parent->right_ = right;
  }
}
