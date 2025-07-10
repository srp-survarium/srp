void __thiscall vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::sound::search::search_service::vertex_allocator_impl_type,vostok::sound::search::search_service::look_up_cell_type>::on_before_search(
        vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::sound::search::search_service::vertex_allocator_impl_type,vostok::sound::search::search_service::look_up_cell_type> *this)
{
  this->m_allocator->m_vertex_current = this->m_allocator->m_vertices;
  this->m_vertex_count = 0;
  if ( !++this->m_current_path_id )
  {
    this->m_current_path_id = 1;
    vostok::memory::zero(this->m_hash, 4 * this->m_hash_size);
    vostok::memory::zero(this->m_vertices, 24 * this->m_fix_size);
  }
}
