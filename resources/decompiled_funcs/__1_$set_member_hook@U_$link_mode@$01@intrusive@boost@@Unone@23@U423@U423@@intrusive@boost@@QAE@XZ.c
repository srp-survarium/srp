void __usercall boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>::~set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>(
        boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none> *this@<ecx>,
        boost::intrusive::rbtree_node<void *> *a2@<eax>)
{
  boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::unlink(a2);
  a2->parent_ = 0;
  a2->left_ = 0;
  a2->right_ = 0;
}
