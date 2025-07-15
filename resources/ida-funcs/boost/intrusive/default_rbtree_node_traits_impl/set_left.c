void __usercall boost::intrusive::default_rbtree_node_traits_impl<void *>::set_left(
        boost::intrusive::rbtree_node<void *> *n@<ecx>,
        boost::intrusive::rbtree_node<void *> *l@<eax>)
{
  n->left_ = l;
}
