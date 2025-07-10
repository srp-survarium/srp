void __thiscall vostok::ai::vertex_allocator::fixed_count::impl<vostok::sound::search::search_service::vertex_type>::~impl<vostok::sound::search::search_service::vertex_type>(
        vostok::ai::vertex_allocator::fixed_count::impl<vostok::sound::search::search_service::vertex_type> *this)
{
  void **p_m_vertices; // [esp+4h] [ebp-10h]
  vostok::sound::search::search_service::vertex_type *iter; // [esp+10h] [ebp-4h]

  for ( iter = this->m_vertices; iter != this->m_vertices_end; ++iter )
    ;
  p_m_vertices = (void **)&this->m_vertices;
  if ( this->m_vertices )
  {
    vostok::memory::base_allocator::free_impl(this->m_allocator, *p_m_vertices);
    *p_m_vertices = 0;
  }
}
