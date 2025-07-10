void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>(
        vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type> *this,
        vostok::ai::planning::search_base::vertex_manager_impl_type *manager,
        unsigned int vertex_count)
{
  vostok::memory::base_allocator *v3; // eax

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->m_manager = manager;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_manager->m_allocator);
  this->m_heap = (vostok::ai::planning::search_base::vertex_type **)vostok::memory::malloc_helper<vostok::memory::base_allocator>(
                                                                      v3,
                                                                      4 * vertex_count);
  vostok::memory::zero(this->m_heap, 4 * vertex_count);
}
