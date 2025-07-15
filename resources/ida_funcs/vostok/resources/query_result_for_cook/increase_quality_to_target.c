void __thiscall vostok::resources::query_result_for_cook::increase_quality_to_target(
        vostok::resources::query_result_for_cook *this,
        vostok::resources::query_result_for_cook *parent_query)
{
  void *v3; // [esp+0h] [ebp-Ch]
  vostok::resources::quality_increase_functionality v4; // [esp+8h] [ebp-4h] BYREF

  vostok::resources::quality_increase_functionality::quality_increase_functionality(
    &v4,
    &vostok::resources::g_game_resources_manager.m_variable->m_data);
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0>>::erase<vostok::resources::resource_base,vostok::resources::compare_by_target_satisfaction>(
    (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0> > *)this,
    &v4.m_data->increase_quality_tree.tree_.data_.node_plus_pred_.header_plus_size_.header_,
    (vostok::resources::compare_by_target_satisfaction)v4.m_data->increase_quality_tree.tree_.data_.node_plus_pred_.header_plus_size_.header_.parent_,
    v3);
  vostok::threading::interlocked_and(&this->m_flags.m_flags, 0xFFFFFF7F);
  vostok::threading::interlocked_or(
    (volatile int *)&this[1].m_memory_usage_self,
    (unsigned int)&vostok::memory::s_CRT_arena[22351416]);
  vostok::resources::resources_manager::push_new_query(
    vostok::resources::g_resources_manager.m_variable,
    (vostok::resources::query_result *)this);
}
