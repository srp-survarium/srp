void __usercall boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::init_header(
        boost::intrusive::rbtree_node<void *> *header@<eax>)
{
  header->parent_ = 0;
  header->left_ = header;
  header->right_ = header;
}
