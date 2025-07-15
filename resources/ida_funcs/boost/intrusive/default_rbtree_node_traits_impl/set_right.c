void __usercall boost::intrusive::default_rbtree_node_traits_impl<void *>::set_right(
        boost::intrusive::rbtree_node<void *> *n@<ecx>,
        boost::intrusive::rbtree_node<void *> *r@<eax>)
{
  n->right_ = r;
}
