void __thiscall vostok::resources::game_resources_manager::add_new_resource_to_increase_quality_tree(
        vostok::resources::game_resources_manager *this,
        vostok::resources::game_resources_manager *resource,
        vostok::resources::quality_increase_functionality quality_increase)
{
  vostok::resources::resource_base *m_data; // ebx
  double v4; // st7

  m_data = (vostok::resources::resource_base *)quality_increase.m_data;
  v4 = *(float *)&quality_increase.m_data[1].memory_types.m_size;
  LODWORD(quality_increase.m_data[1].memory_types.m_mutex.m_mutex[1]) = HIDWORD(quality_increase.m_data[1].memory_types.m_mutex.m_mutex[0]);
  m_data->m_target_satisfaction = v4;
  vostok::resources::quality_increase_functionality::quality_increase_functionality(
    &quality_increase,
    &resource->m_data);
  vostok::threading::interlocked_or(&m_data->m_flags.m_flags, 0x80u);
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0>>::insert_equal(
    &quality_increase.m_data->increase_quality_tree.tree_,
    m_data,
    (boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none> **)&quality_increase);
}
