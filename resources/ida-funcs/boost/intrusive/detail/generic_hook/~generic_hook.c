void __usercall boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,2,0>::~generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,2,0>(
        boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,2,0> *this@<ecx>,
        boost::intrusive::rbtree_node<void *> *a2@<eax>)
{
  boost::intrusive::rbtree_node<void *> *parent; // eax
  boost::intrusive::rbtree_node<void *> *left; // ecx
  boost::intrusive::rbtree_node<void *> *right; // edx

  parent = a2->parent_;
  if ( parent )
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
    boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::erase(a2, parent);
  }
  a2->parent_ = 0;
  a2->left_ = 0;
  a2->right_ = 0;
}
