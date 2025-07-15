bool __thiscall vostok::sound::search::search_restrictor::limit_reached<vostok::sound::search::search_service::priority_queue_impl_type>(
        vostok::sound::search::search_restrictor *this,
        const vostok::sound::search::search_service::priority_queue_impl_type *queue,
        unsigned int iteration_count)
{
  if ( iteration_count >= this->m_max_iteration_count )
    return 1;
  if ( (float)(**(float **)queue->m_heap_head + (*queue->m_heap_head)->m_h) >= this->m_max_range )
    return 1;
  if ( queue->m_manager->m_allocator->m_vertex_current - queue->m_manager->m_allocator->m_vertices < this->m_max_visited_vertex_count )
    return this->m_different_paths_left == 0;
  return 1;
}
