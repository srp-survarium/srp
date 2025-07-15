void __thiscall vostok::render::lpv_batched_geometry::add_vertex(
        vostok::render::lpv_batched_geometry *this,
        const vostok::render::batched_vertex_source *in_vertex,
        const vostok::math::float3 *__formal)
{
  unsigned int m_value; // edx
  unsigned int v4; // eax
  __int64 v5; // [esp+8h] [ebp-14h] BYREF
  float z; // [esp+10h] [ebp-Ch]
  unsigned int v7; // [esp+14h] [ebp-8h]
  unsigned int v8; // [esp+18h] [ebp-4h]

  m_value = in_vertex->normal.m_value;
  v4 = in_vertex->clr.m_value;
  v5 = *(_QWORD *)&in_vertex->position.x;
  z = in_vertex->position.z;
  v8 = v4;
  v7 = m_value;
  vostok::buffer_vector<vostok::render::lpv_vertex>::push_back(
    &this->m_vertices,
    (const vostok::render::lpv_vertex *)&this->m_vertices,
    &v5);
}
