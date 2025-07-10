void __usercall boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::unlink(
        boost::intrusive::rbtree_node<void *> *node@<esi>)
{
  boost::intrusive::rbtree_node<void *> *parent; // eax
  boost::intrusive::rbtree_node<void *> *left; // ecx
  boost::intrusive::rbtree_node<void *> *right; // edx

  parent = node->parent_;
  if ( node->parent_ )
  {
    while ( 1 )
    {
      if ( parent->color_ == red_t )
      {
        left = parent->left_;
        right = parent->right_;
        if ( !parent->parent_ || left && right && (left == right || left->parent_ != parent || right->parent_ != parent) )
          break;
      }
      parent = parent->parent_;
    }
    boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::erase(parent, node);
  }
}
