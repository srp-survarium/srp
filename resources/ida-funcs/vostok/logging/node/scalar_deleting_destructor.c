boost::intrusive::rbtree_node<void *> *__usercall vostok::logging::node::`scalar deleting destructor'@<eax>(
        vostok::logging::node *this@<ecx>,
        boost::intrusive::rbtree_node<void *> *a2@<esi>)
{
  boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,2,0> *v2; // ecx

  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>::clear_and_dispose<boost::intrusive::detail::null_disposer>(
    (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> > *)this,
    (int)&a2[3],
    0);
  boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,2,0>::~generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,2,0>(
    v2,
    a2);
  return a2;
}
