void __thiscall vostok::ai::planning::search_base::search_base(vostok::ai::planning::search_base *this)
{
  vostok::ai::vertex_allocator::fixed_count::impl<vostok::ai::planning::search_base::vertex_type>::impl<vostok::ai::planning::search_base::vertex_type>(
    &this->m_vertex_allocator,
    vostok::ai::g_allocator,
    0x1000u);
  vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::ai::planning::search_base::vertex_allocator_impl_type,vostok::ai::planning::search_base::look_up_cell_type>::impl<vostok::ai::planning::search_base::vertex_allocator_impl_type,vostok::ai::planning::search_base::look_up_cell_type>(
    &this->m_vertex_manager,
    &this->m_vertex_allocator,
    0x100u,
    0x1000u);
  vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>(
    &this->m_priority_queue,
    &this->m_vertex_manager,
    0x1000u);
}
