bool __thiscall vostok::sound::search::search_restrictor::accessible<vostok::sound::search::search_service::vertex_type>(
        vostok::sound::search::search_restrictor *this,
        const vostok::sound::search::vertex_id_type *neighbour_vertex_id,
        const vostok::sound::search::search_service::vertex_type *current_vertex,
        const unsigned int *const *edge_iterator)
{
  unsigned int v5; // [esp+0h] [ebp-24h]
  const vostok::render::culling::portal *portal; // [esp+1Ch] [ebp-8h]

  if ( current_vertex->m_id.portal_id == **(_DWORD **)edge_iterator )
    return 0;
  portal = &this->m_graph->m_object->m_portals.m_begin[current_vertex->m_id.portal_id];
  if ( current_vertex->m_id.incoming_sector_index )
    v5 = portal->m_sectors[0];
  else
    v5 = portal->m_sectors[1];
  return this->m_target_sector_id != v5;
}
