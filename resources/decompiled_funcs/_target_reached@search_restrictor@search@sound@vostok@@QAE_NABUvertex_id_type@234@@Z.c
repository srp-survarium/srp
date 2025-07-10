bool __thiscall vostok::sound::search::search_restrictor::target_reached(
        vostok::sound::search::search_restrictor *this,
        const vostok::sound::search::vertex_id_type *vertex_id)
{
  unsigned int v3; // [esp+4h] [ebp-30h]
  vostok::sound::search::vertex_id_type *m_end; // [esp+10h] [ebp-24h]
  const vostok::render::culling::portal *portal; // [esp+2Ch] [ebp-8h]

  portal = &this->m_graph->m_object->m_portals.m_begin[vertex_id->portal_id];
  if ( vertex_id->incoming_sector_index )
    v3 = portal->m_sectors[0];
  else
    v3 = portal->m_sectors[1];
  if ( this->m_target_sector_id == v3 )
  {
    --this->m_different_paths_left;
    m_end = this->m_vertex_ids.m_end;
    if ( m_end )
      *m_end = *vertex_id;
    ++this->m_vertex_ids.m_end;
  }
  return 0;
}
