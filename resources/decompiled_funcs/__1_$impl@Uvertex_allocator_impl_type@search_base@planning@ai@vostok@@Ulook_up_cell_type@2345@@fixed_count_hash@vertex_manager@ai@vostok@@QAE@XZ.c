void __thiscall vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::ai::planning::search_base::vertex_allocator_impl_type,vostok::ai::planning::search_base::look_up_cell_type>::~impl<vostok::ai::planning::search_base::vertex_allocator_impl_type,vostok::ai::planning::search_base::look_up_cell_type>(
        vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::ai::planning::search_base::vertex_allocator_impl_type,vostok::ai::planning::search_base::look_up_cell_type> *this)
{
  vostok::memory::base_allocator *v1; // eax
  vostok::memory::base_allocator *v2; // eax
  void **p_m_vertices; // [esp+4h] [ebp-28h]
  void **p_m_hash; // [esp+18h] [ebp-14h]

  p_m_hash = (void **)&this->m_hash;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_hash);
  if ( *p_m_hash )
  {
    vostok::memory::base_allocator::free_impl(v1, *p_m_hash);
    *p_m_hash = 0;
  }
  p_m_vertices = (void **)&this->m_vertices;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_allocator->m_allocator);
  if ( this->m_vertices )
  {
    vostok::memory::base_allocator::free_impl(v2, *p_m_vertices);
    *p_m_vertices = 0;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
