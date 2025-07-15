void __cdecl boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rotate_right(
        boost::intrusive::rbtree_node<void *> *p,
        boost::intrusive::rbtree_node<void *> *header)
{
  boost::intrusive::rbtree_node<void *> *left; // ecx
  boost::intrusive::rbtree_node<void *> *right; // edx
  boost::intrusive::rbtree_node<void *> *parent; // esi
  bool v5; // zf

  left = p->left_;
  right = left->right_;
  parent = p->parent_;
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
