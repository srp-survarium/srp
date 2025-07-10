boost::intrusive::rbtree_node<void *> **__usercall vostok::resources::quality_increase_functionality::find_next_to_select_to_increase_quality@<eax>(
        vostok::resources::quality_increase_functionality *this@<ecx>,
        int *a2@<eax>)
{
  int v2; // eax
  boost::intrusive::rbtree_node<void *> *nodeptr; // ecx
  boost::intrusive::rbtree_node<void *> *v4; // edx
  boost::intrusive::rbtree_node<void *> **result; // eax
  boost::intrusive::rbtree_node<void *> *right; // eax
  boost::intrusive::rbtree_node<void *> *i; // eax
  boost::intrusive::rbtree_node<void *> *j; // eax
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0> >,0> it; // [esp+0h] [ebp-4h]

  v2 = *a2;
  nodeptr = *(boost::intrusive::rbtree_node<void *> **)(v2 + 60);
  v4 = (boost::intrusive::rbtree_node<void *> *)(v2 + 56);
  it.members_.nodeptr_ = nodeptr;
  if ( nodeptr == (boost::intrusive::rbtree_node<void *> *)(v2 + 56) )
    return 0;
  while ( 1 )
  {
    result = &nodeptr[-9].right_;
    if ( nodeptr[-1].left_ )
      break;
LABEL_8:
    right = nodeptr->right_;
    if ( right )
    {
      nodeptr = nodeptr->right_;
      for ( i = right->left_; i; i = i->left_ )
        nodeptr = i;
    }
    else
    {
      for ( j = nodeptr->parent_; nodeptr == j->right_; j = j->parent_ )
        nodeptr = j;
      if ( nodeptr->right_ != j )
        nodeptr = j;
    }
    it.members_.nodeptr_ = nodeptr;
    if ( nodeptr == v4 )
      return 0;
  }
  if ( ((unsigned int)result[2] & 0x200) != 0x200 && result[31] != result[32]
    || (float)(*((float *)result + 30) + 2.0) > vostok::resources::quality_increase_functionality::s_elapsed_sec_from_start
    || !result[32] )
  {
    nodeptr = it.members_.nodeptr_;
    goto LABEL_8;
  }
  if ( *((float *)result + 29) >= 1024.0 )
    return 0;
  return result;
}
