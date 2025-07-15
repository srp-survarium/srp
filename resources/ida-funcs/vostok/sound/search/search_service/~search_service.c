void __thiscall vostok::sound::search::search_service::~search_service(vostok::sound::search::search_service *this)
{
  void **p_m_heap; // [esp+38h] [ebp-14h]

  p_m_heap = (void **)&this->m_priority_queue.m_heap;
  if ( this->m_priority_queue.m_heap )
  {
    vostok::memory::base_allocator::free_impl(this->m_priority_queue.m_manager->m_allocator->m_allocator, *p_m_heap);
    *p_m_heap = 0;
  }
  vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::sound::search::search_service::vertex_allocator_impl_type,vostok::sound::search::search_service::look_up_cell_type>::~impl<vostok::sound::search::search_service::vertex_allocator_impl_type,vostok::sound::search::search_service::look_up_cell_type>(&this->m_vertex_manager);
  vostok::ai::vertex_allocator::fixed_count::impl<vostok::sound::search::search_service::vertex_type>::~impl<vostok::sound::search::search_service::vertex_type>(&this->m_vertex_allocator);
}
