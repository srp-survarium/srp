vostok::math::float3 *__thiscall vostok::sound::sound_scene::get_portal_center(
        vostok::sound::sound_scene *this,
        vostok::math::float3 *result,
        unsigned int portal_id)
{
  *result = this->m_graph.m_object->m_portals.m_begin[portal_id].m_points[0];
  return result;
}
