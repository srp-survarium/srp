void __usercall boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::init_header(
        boost::intrusive::rbtree_node<void *> *header@<eax>)
{
  header->parent_ = 0;
  header->left_ = header;
  header->right_ = header;
  header->color_ = red_t;
}
