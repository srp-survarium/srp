void __thiscall vostok::sound::search::search_restrictor::on_before_search(
        vostok::sound::search::search_restrictor *this)
{
  vostok::sound::search::vertex_id_type *i; // [esp+4h] [ebp-28h]
  unsigned int m_portals_count; // [esp+Ch] [ebp-20h]

  m_portals_count = this->m_graph->m_object->m_sectors.m_begin[this->m_target_sector_id].m_portals_count;
  this->m_different_paths_left = m_portals_count < 4 ? m_portals_count - 4 + 4 : 4;
  for ( i = this->m_vertex_ids.m_begin; i != this->m_vertex_ids.m_end; ++i )
    ;
  this->m_vertex_ids.m_end = this->m_vertex_ids.m_begin;
}
