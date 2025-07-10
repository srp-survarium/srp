void __thiscall vostok::ai::vertex_allocator::fixed_count::impl<vostok::sound::search::search_service::vertex_type>::impl<vostok::sound::search::search_service::vertex_type>(
        vostok::ai::vertex_allocator::fixed_count::impl<vostok::sound::search::search_service::vertex_type> *this,
        vostok::memory::base_allocator *memory_allocator,
        unsigned int max_vertex_count)
{
  vostok::sound::search::search_service::vertex_type *iter; // [esp+18h] [ebp-4h]

  this->m_allocator = memory_allocator;
  this->m_vertices = (vostok::sound::search::search_service::vertex_type *)vostok::memory::base_allocator::malloc_impl(
                                                                             this->m_allocator,
                                                                             28 * max_vertex_count);
  this->m_vertices_end = &this->m_vertices[max_vertex_count];
  for ( iter = this->m_vertices; iter != this->m_vertices_end; ++iter )
  {
    if ( iter )
    {
      iter->m_id.portal_id = -1;
      iter->m_id.incoming_sector_index = -1;
      iter->m_id.source_to_portal_distance = *(float *)&FLOAT_0_0;
    }
  }
}
