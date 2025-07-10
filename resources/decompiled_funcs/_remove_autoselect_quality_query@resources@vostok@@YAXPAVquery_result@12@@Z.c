void __usercall vostok::resources::remove_autoselect_quality_query(
        boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0> > *query@<eax>)
{
  void *v2; // [esp+0h] [ebp-Ch]
  vostok::resources::quality_increase_functionality v3; // [esp+8h] [ebp-4h] BYREF

  vostok::resources::quality_increase_functionality::quality_increase_functionality(
    &v3,
    &vostok::resources::g_game_resources_manager.m_variable->m_data);
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0>>::erase<vostok::resources::resource_base,vostok::resources::compare_by_target_satisfaction>(
    query,
    &v3.m_data->increase_quality_tree.tree_.data_.node_plus_pred_.header_plus_size_.header_,
    (vostok::resources::compare_by_target_satisfaction)v3.m_data->increase_quality_tree.tree_.data_.node_plus_pred_.header_plus_size_.header_.parent_,
    v2);
  vostok::threading::interlocked_and(
    (volatile int *)&query->data_.node_plus_pred_.header_plus_size_.header_.right_,
    0xFFFFFF7F);
}
