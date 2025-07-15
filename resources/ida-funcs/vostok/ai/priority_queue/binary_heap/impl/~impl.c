void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::~impl<vostok::ai::planning::search_base::vertex_manager_impl_type>(
        vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type> *this)
{
  vostok::memory::base_allocator *v1; // eax
  void **p_m_heap; // [esp+4h] [ebp-18h]

  p_m_heap = (void **)&this->m_heap;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_manager->m_allocator);
  if ( *p_m_heap )
  {
    vostok::memory::base_allocator::free_impl(v1, *p_m_heap);
    *p_m_heap = 0;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
