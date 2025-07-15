unsigned int __thiscall vostok::sound::search::search_restrictor::get_start_vertices_count(
        vostok::sound::search::search_restrictor *this)
{
  return this->m_graph->m_object->m_sectors.m_begin[this->m_start_sector_id].m_portals_count;
}
