vostok::math::float3 *__userpurge vostok::collision::terrain_data::position@<eax>(
        unsigned __int16 vertex_id@<di>,
        vostok::math::float3 *a2@<ecx>,
        vostok::collision::terrain_data *this)
{
  signed int m_vertex_row_size; // esi
  double v4; // st7
  const float *m_heightfield; // eax
  double v6; // st7
  vostok::math::float3 *result; // eax

  m_vertex_row_size = this->m_vertex_row_size;
  v4 = this->m_physical_size / (double)(unsigned int)(m_vertex_row_size - 1);
  m_heightfield = this->m_heightfield;
  a2->x = (double)(vertex_id % m_vertex_row_size) * v4;
  a2->z = -(v4 * (double)(vertex_id / m_vertex_row_size));
  v6 = m_heightfield[vertex_id];
  result = a2;
  a2->y = v6;
  return result;
}
