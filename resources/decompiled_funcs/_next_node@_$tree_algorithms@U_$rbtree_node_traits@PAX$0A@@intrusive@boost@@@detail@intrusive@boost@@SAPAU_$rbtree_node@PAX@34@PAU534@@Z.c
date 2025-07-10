boost::intrusive::rbtree_node<void *> *__cdecl boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::next_node(
        boost::intrusive::rbtree_node<void *> *p)
{
  boost::intrusive::rbtree_node<void *> *v1; // ecx
  boost::intrusive::rbtree_node<void *> *result; // eax
  boost::intrusive::rbtree_node<void *> *i; // ecx

  v1 = p;
  result = p->right_;
  if ( result )
  {
    for ( i = result->left_; i; i = i->left_ )
      result = i;
  }
  else
  {
    result = p->parent_;
    if ( p == p->parent_->right_ )
    {
      do
      {
        v1 = result;
        result = result->parent_;
      }
      while ( v1 == result->right_ );
    }
    if ( v1->right_ == result )
      return v1;
  }
  return result;
}
