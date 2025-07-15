void __cdecl boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::insert_commit(
        boost::intrusive::rbtree_node<void *> *header,
        boost::intrusive::rbtree_node<void *> *new_node,
        const boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0> >::insert_commit_data *commit_data)
{
  boost::intrusive::rbtree_node<void *> *node; // ecx

  node = commit_data->node;
  if ( node == header )
  {
    header->parent_ = new_node;
    header->left_ = new_node;
    header->right_ = new_node;
    new_node->parent_ = node;
    new_node->right_ = 0;
    new_node->left_ = 0;
    return;
  }
  if ( commit_data->link_left )
  {
    node->left_ = new_node;
    if ( node == header->left_ )
    {
      header->left_ = new_node;
      new_node->parent_ = node;
      new_node->right_ = 0;
      new_node->left_ = 0;
      return;
    }
  }
  else
  {
    node->right_ = new_node;
    if ( node == header->right_ )
      header->right_ = new_node;
  }
  new_node->parent_ = node;
  new_node->right_ = 0;
  new_node->left_ = 0;
}
