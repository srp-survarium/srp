void __thiscall vostok::sound::search::search_service::search_service(
        vostok::sound::search::search_service *this,
        vostok::memory::base_allocator *allocator)
{
  vostok::ai::vertex_allocator::fixed_count::impl<vostok::sound::search::search_service::vertex_type>::impl<vostok::sound::search::search_service::vertex_type>(
    &this->m_vertex_allocator,
    allocator,
    0x1000u);
  vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::sound::search::search_service::vertex_allocator_impl_type,vostok::sound::search::search_service::look_up_cell_type>::impl<vostok::sound::search::search_service::vertex_allocator_impl_type,vostok::sound::search::search_service::look_up_cell_type>(
    &this->m_vertex_manager,
    &this->m_vertex_allocator,
    0x100u,
    0x1000u);
  this->m_priority_queue.m_manager = &this->m_vertex_manager;
  this->m_priority_queue.m_heap = (vostok::sound::search::search_service::vertex_type **)vostok::memory::base_allocator::malloc_impl(
                                                                                           this->m_priority_queue.m_manager->m_allocator->m_allocator,
                                                                                           0x4000u);
  vostok::memory::zero(this->m_priority_queue.m_heap, 0x4000u);
}
