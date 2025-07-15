double __thiscall vostok::sound::search::graph_heuristics::evaluate<vostok::sound::search::search_service::vertex_type>(
        vostok::sound::search::graph_heuristics *this,
        const vostok::sound::search::search_service::vertex_type *current_vertex,
        const vostok::sound::search::search_service::vertex_type *neighbour_vertex,
        const unsigned int *const *iterator)
{
  _BYTE v5[12]; // [esp+2Ch] [ebp-48h]
  vostok::render::culling::portal *v6; // [esp+38h] [ebp-3Ch]
  vostok::render::culling::portal *v7; // [esp+50h] [ebp-24h]
  vostok::math::float3 object; // [esp+68h] [ebp-Ch] BYREF

  v7 = &this->m_graph->m_object->m_portals.m_begin[neighbour_vertex->m_id.portal_id];
  v6 = &this->m_graph->m_object->m_portals.m_begin[current_vertex->m_id.portal_id];
  *(float *)v5 = v6->m_points[0].x - v7->m_points[0].x;
  *(float *)&v5[4] = v6->m_points[0].y - v7->m_points[0].y;
  *(float *)&v5[8] = v6->m_points[0].z - v7->m_points[0].z;
  object = *(vostok::math::float3 *)v5;
  return vostok::math::length(&object) + current_vertex->m_g + current_vertex->m_id.source_to_portal_distance;
}
