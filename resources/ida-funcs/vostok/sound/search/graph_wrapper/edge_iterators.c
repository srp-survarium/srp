void __thiscall vostok::sound::search::graph_wrapper::edge_iterators<vostok::sound::search::search_service::vertex_type>(
        vostok::sound::search::graph_wrapper *this,
        const vostok::sound::search::search_service::vertex_type *vertex,
        unsigned int **begin,
        const unsigned int **end)
{
  unsigned int v4; // [esp+10h] [ebp-30h]
  const vostok::render::culling::portal *current_portal; // [esp+38h] [ebp-8h]
  const vostok::render::culling::spatial_sector *current_sector; // [esp+3Ch] [ebp-4h]

  current_portal = &this->m_graph->m_object->m_portals.m_begin[vertex->m_id.portal_id];
  if ( vertex->m_id.incoming_sector_index )
    v4 = current_portal->m_sectors[0];
  else
    v4 = current_portal->m_sectors[1];
  current_sector = &this->m_graph->m_object->m_sectors.m_begin[v4];
  *begin = current_sector->m_portal_ids;
  *end = &current_sector->m_portal_ids[current_sector->m_portals_count];
}
