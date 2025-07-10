boost::intrusive::rbtree_node<void *> *__fastcall boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::next_node(
        boost::intrusive::rbtree_node<void *> *p)
{
  boost::intrusive::rbtree_node<void *> *result; // eax
  boost::intrusive::rbtree_node<void *> *i; // ecx

  result = p->right_;
  if ( result )
  {
    for ( i = result->left_; i; i = i->left_ )
      result = i;
  }
  else
  {
    for ( result = p->parent_; p == result->right_; result = result->parent_ )
      p = result;
    if ( p->right_ == result )
      return p;
  }
  return result;
}
