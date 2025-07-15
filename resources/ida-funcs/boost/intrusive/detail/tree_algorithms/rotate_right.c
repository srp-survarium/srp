void __usercall boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_right(
        boost::intrusive::rbtree_node<void *> *p@<eax>,
        boost::intrusive::rbtree_node<void *> *header@<edi>)
{
  boost::intrusive::rbtree_node<void *> *parent; // edx
  boost::intrusive::rbtree_node<void *> *left; // ecx
  boost::intrusive::rbtree_node<void *> *right; // esi
  bool v5; // bl

  parent = p->parent_;
  left = p->left_;
  right = left->right_;
  v5 = p->parent_->left_ == p;
  p->left_ = right;
  if ( right )
    right->parent_ = p;
  left->right_ = p;
  p->parent_ = left;
  left->parent_ = parent;
  if ( header->parent_ == p )
  {
    header->parent_ = left;
  }
  else if ( v5 )
  {
    parent->left_ = left;
  }
  else
  {
    parent->right_ = left;
  }
}
