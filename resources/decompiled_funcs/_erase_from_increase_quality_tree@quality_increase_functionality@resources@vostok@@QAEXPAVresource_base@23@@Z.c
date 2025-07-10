void __usercall vostok::resources::quality_increase_functionality::erase_from_increase_quality_tree(
        vostok::resources::quality_increase_functionality *this@<ecx>,
        vostok::resources::compare_by_target_satisfaction **a2@<eax>)
{
  void *v3; // [esp+0h] [ebp-4h]

  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0>>::erase<vostok::resources::resource_base,vostok::resources::compare_by_target_satisfaction>(
    (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0> > *)this,
    (const boost::intrusive::rbtree_node<void *> *)&(*a2)[56],
    (*a2)[56],
    v3);
  vostok::threading::interlocked_and((volatile int *)&this[2], 0xFFFFFF7F);
}
