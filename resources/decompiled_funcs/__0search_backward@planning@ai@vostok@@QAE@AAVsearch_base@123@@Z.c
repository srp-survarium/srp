void __thiscall vostok::ai::planning::search_backward::search_backward(
        vostok::ai::planning::search_backward *this,
        vostok::ai::planning::search_base *search)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->m_search = search;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_graph_wrapper);
  this->m_graph_wrapper.m_new_state.m_properties._M_impl._M_start = 0;
  this->m_graph_wrapper.m_new_state.m_properties._M_impl._M_finish = 0;
  this->m_graph_wrapper.m_new_state.m_properties._M_impl._M_end_of_storage._M_data = 0;
  this->m_graph_wrapper.m_new_state.m_hash = 0;
  this->m_graph_wrapper.m_graph = 0;
}
