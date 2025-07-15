void __thiscall vostok::ai::planning::search::~search(vostok::ai::planning::search *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( s_head == this )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)s_head);
    s_head = this->m_next_search;
  }
  else
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)s_head);
    this->m_previous_search->m_next_search = this->m_next_search;
    if ( this->m_next_search )
      this->m_next_search->m_previous_search = this->m_previous_search;
  }
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(&this->m_search_forward.m_graph_wrapper.m_new_state.m_properties._M_impl);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_search_forward.m_graph_wrapper);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_search_forward);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(&this->m_search_backward.m_graph_wrapper.m_new_state.m_properties._M_impl);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_search_backward.m_graph_wrapper);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_search_backward);
  vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::~impl<vostok::ai::planning::search_base::vertex_manager_impl_type>(&this->m_search.m_priority_queue);
  vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::ai::planning::search_base::vertex_allocator_impl_type,vostok::ai::planning::search_base::look_up_cell_type>::~impl<vostok::ai::planning::search_base::vertex_allocator_impl_type,vostok::ai::planning::search_base::look_up_cell_type>(&this->m_search.m_vertex_manager);
  vostok::ai::vertex_allocator::fixed_count::impl<vostok::ai::planning::search_base::vertex_type>::~impl<vostok::ai::planning::search_base::vertex_type>(&this->m_search.m_vertex_allocator);
  stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::~_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>(&this->m_plan._M_impl);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
