char __thiscall vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::ai::planning::search_base::vertex_allocator_impl_type,vostok::ai::planning::search_base::look_up_cell_type>::visited(
        vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::ai::planning::search_base::vertex_allocator_impl_type,vostok::ai::planning::search_base::look_up_cell_type> *this,
        const vostok::ai::planning::world_state *vertex_id)
{
  unsigned int index; // [esp+34h] [ebp-8h]
  vostok::ai::planning::search_base::look_up_cell_type *vertex; // [esp+38h] [ebp-4h]

  index = vertex_id->m_hash % this->m_hash_size;
  vertex = this->m_hash[index];
  if ( !vertex )
    return 0;
  if ( vertex->m_path_id != this->m_current_path_id )
    return 0;
  if ( vertex->m_hash != index )
    return 0;
  while ( vertex )
  {
    if ( !vostok::ai::planning::world_state::operator!=(&vertex->m_vertex->m_id, vertex_id) )
      return 1;
    vertex = vertex->m_next;
  }
  return 0;
}
