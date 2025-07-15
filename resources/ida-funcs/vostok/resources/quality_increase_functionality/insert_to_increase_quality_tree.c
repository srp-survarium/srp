void __thiscall vostok::resources::quality_increase_functionality::insert_to_increase_quality_tree(
        vostok::resources::quality_increase_functionality *this,
        vostok::resources::resource_base *resource)
{
  _InterlockedOr((volatile signed __int32 *)&this[2], 0x80u);
  boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::insert_equal_upper_bound<boost::intrusive::detail::key_nodeptr_comp<vostok::resources::compare_by_target_satisfaction,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0>>>>(
    (boost::intrusive::rbtree_node<void *> *)&resource->__vftable[2],
    (boost::intrusive::rbtree_node<void *> *)&this[34]);
}
