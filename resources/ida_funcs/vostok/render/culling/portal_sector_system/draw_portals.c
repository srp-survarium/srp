void __userpurge vostok::render::culling::portal_sector_system::draw_portals(
        const unsigned int active_sector_id@<eax>,
        vostok::render::culling::portal_sector_system *this,
        vostok::render::system_renderer *r)
{
  vostok::render::culling::portal_sector_system *m_object; // ecx
  unsigned int v4; // eax
  _DWORD *v5; // esi
  _DWORD *i; // edi
  int v7; // eax
  unsigned __int16 frustum_indices[12]; // [esp+10h] [ebp-5Ch] BYREF
  vostok::render::vertex_colored vertices[4]; // [esp+28h] [ebp-44h] BYREF
  unsigned __int16 indices_begin; // [esp+68h] [ebp-4h] BYREF

  frustum_indices[0] = 0;
  frustum_indices[1] = 1;
  frustum_indices[3] = 0;
  frustum_indices[2] = 2;
  frustum_indices[4] = 2;
  frustum_indices[6] = 0;
  frustum_indices[5] = 3;
  frustum_indices[7] = 2;
  frustum_indices[8] = 1;
  frustum_indices[9] = 0;
  frustum_indices[10] = 3;
  m_object = (vostok::render::culling::portal_sector_system *)this->m_structure.m_object;
  frustum_indices[11] = 2;
  v4 = (unsigned int)m_object->m_occlusion_bounds_buffer + 32 * active_sector_id;
  v5 = *(_DWORD **)(v4 + 24);
  for ( i = &v5[*(_DWORD *)(v4 + 28)]; v5 != i; ++v5 )
  {
    m_object = (vostok::render::culling::portal_sector_system *)this->m_structure.m_object;
    v7 = (int)m_object->m_quads._M_impl._M_finish + 76 * *v5;
    if ( *(_BYTE *)(v7 + 72) )
    {
      *(_QWORD *)&vertices[0].position.x = *(_QWORD *)(v7 + 24);
      vertices[0].position.z = *(float *)(v7 + 32);
      vertices[0].color.m_value = 1684326500;
      *(_QWORD *)&vertices[1].position.x = *(_QWORD *)(v7 + 36);
      vertices[1].position.z = *(float *)(v7 + 44);
      vertices[1].color.m_value = 1684326500;
      *(_QWORD *)&vertices[2].position.x = *(_QWORD *)(v7 + 48);
      vertices[2].position.z = *(float *)(v7 + 56);
      vertices[2].color.m_value = 1684326500;
      *(_QWORD *)&vertices[3].position.x = *(_QWORD *)(v7 + 60);
      vertices[3].position.z = *(float *)(v7 + 68);
      vertices[3].color.m_value = 1684326500;
      vostok::render::system_renderer::draw_triangles(
        (vostok::render::system_renderer *)vertices,
        (const vostok::render::vertex_colored *const)r,
        vertices,
        &indices_begin,
        frustum_indices,
        (bool)vertices);
    }
  }
  vostok::render::culling::portal_sector_system::draw_quads(m_object, (int)this, r);
}
