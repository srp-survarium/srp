vostok::sound::search::vertex_id_type *__thiscall vostok::sound::search::graph_wrapper::vertex_id(
        vostok::sound::search::graph_wrapper *this,
        vostok::sound::search::vertex_id_type *result,
        const vostok::sound::search::vertex_id_type *vertex_id,
        unsigned int *iterator)
{
  unsigned int v5; // [esp+0h] [ebp-48h]
  unsigned int result_4; // [esp+38h] [ebp-10h]
  const vostok::render::culling::portal *current_portal; // [esp+40h] [ebp-8h]

  current_portal = &this->m_graph->m_object->m_portals.m_begin[vertex_id->portal_id];
  if ( vertex_id->incoming_sector_index )
    v5 = current_portal->m_sectors[0];
  else
    v5 = current_portal->m_sectors[1];
  result_4 = this->m_graph->m_object->m_portals.m_begin[*iterator].m_sectors[0] != v5;
  result->portal_id = *iterator;
  result->incoming_sector_index = result_4;
  result->source_to_portal_distance = *(float *)&FLOAT_0_0;
  return result;
}
