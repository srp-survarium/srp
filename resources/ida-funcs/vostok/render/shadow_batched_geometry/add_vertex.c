void __thiscall vostok::render::shadow_batched_geometry::add_vertex(
        vostok::render::shadow_batched_geometry *this,
        const vostok::render::batched_vertex_source *in_vertex,
        const vostok::math::float3 *not_modified_position)
{
  float x; // edx
  float y; // eax
  __int64 v5; // [esp+8h] [ebp-20h] BYREF
  float z; // [esp+10h] [ebp-18h]
  vostok::math::float3 v7; // [esp+14h] [ebp-14h]
  float v8; // [esp+20h] [ebp-8h]
  float v9; // [esp+24h] [ebp-4h]

  x = in_vertex->uv.x;
  y = in_vertex->uv.y;
  v5 = *(_QWORD *)&in_vertex->position.x;
  z = in_vertex->position.z;
  v9 = y;
  v8 = x;
  v7 = *not_modified_position;
  vostok::buffer_vector<vostok::render::shadow_vertex>::push_back(
    &this->m_vertices,
    (const vostok::render::shadow_vertex *)&this->m_vertices,
    (float *)&v5);
}
