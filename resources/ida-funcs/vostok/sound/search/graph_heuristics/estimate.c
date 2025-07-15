float __thiscall vostok::sound::search::graph_heuristics::estimate(
        vostok::sound::search::graph_heuristics *this,
        const vostok::sound::search::vertex_id_type *const current_vertex_id_ptr,
        const vostok::sound::search::vertex_id_type *neighbour_vertex_id)
{
  _BYTE v5[12]; // [esp+28h] [ebp-30h]
  vostok::render::culling::portal *v6; // [esp+34h] [ebp-24h]
  vostok::math::float3 object; // [esp+4Ch] [ebp-Ch] BYREF

  v6 = &this->m_graph->m_object->m_portals.m_begin[neighbour_vertex_id->portal_id];
  *(float *)v5 = this->m_target_position.x - v6->m_points[0].x;
  *(float *)&v5[4] = this->m_target_position.y - v6->m_points[0].y;
  *(float *)&v5[8] = this->m_target_position.z - v6->m_points[0].z;
  object = *(vostok::math::float3 *)v5;
  return vostok::math::length(&object);
}
