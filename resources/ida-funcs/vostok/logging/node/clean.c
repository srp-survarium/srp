void __thiscall vostok::logging::node::clean(vostok::logging::node *this, vostok::logging::base_allocator *allocator)
{
  vostok::logging::node *v2; // eax
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> > *v3; // ecx
  boost::intrusive::rbtree_node<void *> *v4; // esi
  vostok::logging::node *v5; // ecx
  boost::intrusive::multiset<vostok::logging::node_base,boost::intrusive::member_hook<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,boost::intrusive::compare<vostok::logging::compare_nodes>,boost::intrusive::constant_time_size<0>,boost::intrusive::none> *header; // [esp+8h] [ebp-4h]

  header = &this->m_children;
  while ( 1 )
  {
    v2 = (vostok::logging::node *)boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::unlink_leftmost_without_rebalance(&header->tree_.data_.node_plus_pred_.header_plus_size_.header_);
    v4 = (boost::intrusive::rbtree_node<void *> *)v2;
    if ( !v2 )
      break;
    v2->tree_hook.parent_ = 0;
    v2->tree_hook.left_ = 0;
    v2->tree_hook.right_ = 0;
    vostok::logging::node::clean(v2, allocator);
    vostok::logging::node::`scalar deleting destructor'(v5, v4);
    allocator->deallocate(allocator, v4);
  }
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>::clear_and_dispose<boost::intrusive::detail::null_disposer>(
    v3,
    (int)header,
    0);
}
