void __usercall vostok::resources::game_resources_manager::remove_autoselect_quality_query(
        vostok::resources::game_resources_manager *this@<ecx>,
        int a2@<eax>)
{
  void *v3; // [esp+0h] [ebp-Ch]
  vostok::resources::quality_increase_functionality quality_increase; // [esp+8h] [ebp-4h] BYREF

  vostok::resources::quality_increase_functionality::quality_increase_functionality(
    &quality_increase,
    (vostok::resources::game_resources_manager_data *)(a2 + 96));
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0>>::erase<vostok::resources::resource_base,vostok::resources::compare_by_target_satisfaction>(
    (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0> > *)this,
    &quality_increase.m_data->increase_quality_tree.tree_.data_.node_plus_pred_.header_plus_size_.header_,
    (vostok::resources::compare_by_target_satisfaction)quality_increase.m_data->increase_quality_tree.tree_.data_.node_plus_pred_.header_plus_size_.header_.parent_,
    v3);
  vostok::threading::interlocked_and((volatile int *)&this->m_resources_to_capture.vostok::threading::mutex, 0xFFFFFF7F);
}
