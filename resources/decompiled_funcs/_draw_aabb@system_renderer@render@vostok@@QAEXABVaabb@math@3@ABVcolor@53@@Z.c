void __userpurge vostok::render::system_renderer::draw_aabb(
        vostok::render::system_renderer *this@<edx>,
        const vostok::math::aabb *aabb@<esi>,
        vostok::render::system_renderer *a3@<ecx>,
        const vostok::math::color *color)
{
  vostok::render::system_renderer *v4; // edx
  float y; // xmm1_4
  float z; // eax
  float v7; // xmm4_4
  float v8; // xmm3_4
  float x; // xmm0_4
  unsigned int m_value; // eax
  __int64 v11; // xmm5_8
  float v12; // ecx
  __int64 v13; // xmm0_8
  __int64 v14; // [esp+4h] [ebp-8Ch]
  unsigned __int64 v15; // [esp+4h] [ebp-8Ch]
  vostok::render::vertex_colored vertices[8]; // [esp+10h] [ebp-80h] BYREF
  _UNKNOWN *retaddr; // [esp+90h] [ebp+0h] BYREF

  if ( vostok::render::system_renderer::is_effects_ready(a3, this) )
  {
    y = aabb->min.y;
    z = aabb->min.z;
    v7 = aabb->max.y;
    v8 = aabb->max.z;
    *(_QWORD *)&vertices[0].position.x = *(_QWORD *)&aabb->min.x;
    x = aabb->min.x;
    vertices[0].position.z = z;
    m_value = color->m_value;
    vertices[1].position.z = v8;
    *((float *)&v14 + 1) = y;
    *(_QWORD *)&vertices[2].position.x = __PAIR64__(LODWORD(v7), LODWORD(x));
    *(float *)&v14 = aabb->max.x;
    v11 = v14;
    *(_QWORD *)&vertices[1].position.x = __PAIR64__(LODWORD(y), LODWORD(x));
    vertices[2].position.z = aabb->min.z;
    *(_QWORD *)&vertices[4].position.x = __PAIR64__(LODWORD(v7), LODWORD(x));
    *(float *)&v14 = aabb->max.x;
    vertices[3].position.z = vertices[2].position.z;
    *((float *)&v14 + 1) = y;
    vertices[4].position.z = v8;
    *(_QWORD *)&vertices[5].position.x = v14;
    v15 = __PAIR64__(LODWORD(v7), LODWORD(aabb->max.x));
    vertices[0].color.m_value = m_value;
    vertices[1].color.m_value = m_value;
    vertices[2].color.m_value = m_value;
    vertices[3].color.m_value = m_value;
    vertices[4].color.m_value = m_value;
    vertices[5].position.z = v8;
    vertices[5].color.m_value = m_value;
    vertices[6].color.m_value = m_value;
    vertices[7].color.m_value = m_value;
    vertices[6].position.z = vertices[2].position.z;
    v12 = aabb->max.z;
    *(_QWORD *)&vertices[6].position.x = v15;
    v13 = *(_QWORD *)&aabb->max.x;
    *(_QWORD *)&vertices[3].position.x = v11;
    *(_QWORD *)&vertices[7].position.x = v13;
    vertices[7].position.z = v12;
    vostok::render::system_renderer::draw_lines(
      (const vostok::render::vertex_colored *const)&retaddr,
      (vostok::render::system_renderer *)LODWORD(v12),
      v4,
      vertices,
      (unsigned __int8 *)vostok::render::aabb_indices,
      &s_view_mode_value,
      0);
  }
}
