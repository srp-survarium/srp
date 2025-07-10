char __thiscall vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::sound::search::search_service::vertex_allocator_impl_type,vostok::sound::search::search_service::look_up_cell_type>::visited(
        vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::sound::search::search_service::vertex_allocator_impl_type,vostok::sound::search::search_service::look_up_cell_type> *this,
        const vostok::sound::search::vertex_id_type *vertex_id)
{
  unsigned int index; // [esp+10h] [ebp-8h]
  vostok::sound::search::search_service::look_up_cell_type *vertex; // [esp+14h] [ebp-4h]

  index = vertex_id->portal_id % this->m_hash_size;
  vertex = this->m_hash[index];
  if ( !vertex )
    return 0;
  if ( vertex->m_path_id != this->m_current_path_id )
    return 0;
  if ( vertex->m_hash != index )
    return 0;
  while ( vertex )
  {
    if ( vertex->m_vertex->m_id.portal_id == vertex_id->portal_id
      && vertex->m_vertex->m_id.incoming_sector_index == vertex_id->incoming_sector_index )
    {
      return 1;
    }
    vertex = vertex->m_next;
  }
  return 0;
}
