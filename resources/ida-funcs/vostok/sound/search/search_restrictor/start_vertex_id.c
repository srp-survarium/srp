vostok::sound::search::vertex_id_type *__thiscall vostok::sound::search::search_restrictor::start_vertex_id(
        vostok::sound::search::search_restrictor *this,
        vostok::sound::search::vertex_id_type *result,
        unsigned int start_vertex_id)
{
  const vostok::math::float3 *m_source_position; // [esp+28h] [ebp-98h]
  _BYTE v5[12]; // [esp+30h] [ebp-90h]
  vostok::math::float3 object; // [esp+A4h] [ebp-1Ch] BYREF
  vostok::sound::search::vertex_id_type resulta; // [esp+B0h] [ebp-10h]
  const vostok::render::culling::portal *p; // [esp+BCh] [ebp-4h]

  resulta.portal_id = -1;
  resulta.incoming_sector_index = -1;
  resulta.source_to_portal_distance = *(float *)&FLOAT_0_0;
  p = &this->m_graph->m_object->m_portals.m_begin[this->m_graph->m_object->m_sectors.m_begin[this->m_start_sector_id].m_portal_ids[start_vertex_id]];
  resulta.portal_id = this->m_graph->m_object->m_sectors.m_begin[this->m_start_sector_id].m_portal_ids[start_vertex_id];
  resulta.incoming_sector_index = p->m_sectors[0] != this->m_graph->m_object->m_sectors.m_begin[this->m_start_sector_id].m_portal_ids[start_vertex_id];
  m_source_position = this->m_source_position;
  *(float *)v5 = p->m_points[0].x - m_source_position->x;
  *(float *)&v5[4] = p->m_points[0].y - m_source_position->y;
  *(float *)&v5[8] = p->m_points[0].z - m_source_position->z;
  object = *(vostok::math::float3 *)v5;
  resulta.source_to_portal_distance = vostok::math::length(&object);
  *result = resulta;
  return result;
}
