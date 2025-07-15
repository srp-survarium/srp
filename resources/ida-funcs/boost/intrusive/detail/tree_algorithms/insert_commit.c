void __usercall boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::insert_commit(
        boost::intrusive::rbtree_node<void *> *header@<edx>,
        boost::intrusive::rbtree_node<void *> *new_node@<eax>,
        const boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0> >::insert_commit_data *commit_data@<esi>)
{
  boost::intrusive::rbtree_node<void *> *node; // ecx

  node = commit_data->node;
  if ( node == header )
  {
    header->parent_ = new_node;
    header->left_ = new_node;
LABEL_7:
    header->right_ = new_node;
    goto LABEL_8;
  }
  if ( commit_data->link_left )
  {
    node->left_ = new_node;
    if ( node == header->left_ )
      header->left_ = new_node;
  }
  else
  {
    node->right_ = new_node;
    if ( node == header->right_ )
      goto LABEL_7;
  }
LABEL_8:
  new_node->right_ = 0;
  new_node->left_ = 0;
  new_node->parent_ = node;
}
