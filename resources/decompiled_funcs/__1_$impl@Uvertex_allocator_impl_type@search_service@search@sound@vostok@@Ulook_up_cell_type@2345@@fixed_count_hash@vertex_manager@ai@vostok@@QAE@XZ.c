void __thiscall vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::sound::search::search_service::vertex_allocator_impl_type,vostok::sound::search::search_service::look_up_cell_type>::~impl<vostok::sound::search::search_service::vertex_allocator_impl_type,vostok::sound::search::search_service::look_up_cell_type>(
        vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::sound::search::search_service::vertex_allocator_impl_type,vostok::sound::search::search_service::look_up_cell_type> *this)
{
  void **p_m_vertices; // [esp+4h] [ebp-20h]
  void **p_m_hash; // [esp+14h] [ebp-10h]

  p_m_hash = (void **)&this->m_hash;
  if ( this->m_hash )
  {
    vostok::memory::base_allocator::free_impl(this->m_allocator->m_allocator, *p_m_hash);
    *p_m_hash = 0;
  }
  p_m_vertices = (void **)&this->m_vertices;
  if ( this->m_vertices )
  {
    vostok::memory::base_allocator::free_impl(this->m_allocator->m_allocator, *p_m_vertices);
    *p_m_vertices = 0;
  }
}
