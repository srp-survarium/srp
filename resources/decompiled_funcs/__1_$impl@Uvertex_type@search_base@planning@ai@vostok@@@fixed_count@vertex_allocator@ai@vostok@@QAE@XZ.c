void __thiscall vostok::ai::vertex_allocator::fixed_count::impl<vostok::ai::planning::search_base::vertex_type>::~impl<vostok::ai::planning::search_base::vertex_type>(
        vostok::ai::vertex_allocator::fixed_count::impl<vostok::ai::planning::search_base::vertex_type> *this)
{
  vostok::memory::base_allocator *v1; // eax
  void **p_m_vertices; // [esp+4h] [ebp-64h]
  vostok::ai::planning::search_base::vertex_type *iter; // [esp+64h] [ebp-4h]

  for ( iter = this->m_vertices; iter != this->m_vertices_end; ++iter )
    stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(&iter->m_id.m_properties._M_impl);
  p_m_vertices = (void **)&this->m_vertices;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_vertices);
  if ( this->m_vertices )
  {
    vostok::memory::base_allocator::free_impl(v1, *p_m_vertices);
    *p_m_vertices = 0;
  }
}
