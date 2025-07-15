void __cdecl vostok::render::fill_surface_0(
        vostok::render::render_target *surf,
        vostok::render::renderer_context *context)
{
  signed int m_height; // ecx
  double v4; // st7
  float z; // esi
  char *v6; // eax
  float x; // xmm2_4
  float y; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  vostok::render::vertex_buffer *v21; // ecx
  vostok::render::res_geometry *v22; // ecx
  vostok::render::backend *v23; // ecx
  unsigned int v_offset; // [esp+10h] [ebp-8h] BYREF
  float m_width; // [esp+14h] [ebp-4h]
  unsigned int v26; // [esp+24h] [ebp+Ch]

  m_height = surf->m_height;
  m_width = (float)surf->m_width;
  v4 = (double)(int)surf->m_height;
  if ( m_height < 0 )
    v4 = v4 + 4294967300.0;
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  *(float *)&v26 = v4;
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    surf,
    0,
    0,
    0);
  *(_BYTE *)(LODWORD(z) + 117) |= *(_DWORD *)(LODWORD(z) + 7384) != 0;
  *(_DWORD *)(LODWORD(z) + 7384) = 0;
  v6 = vostok::render::vertex_buffer::lock((vostok::render::vertex_buffer *)LODWORD(z), &v_offset, 4u, 0x24u);
  x = context->m_eye_rays[1].x;
  y = context->m_eye_rays[1].y;
  v9 = context->m_eye_rays[1].z;
  *((float *)v6 + 1) = *(float *)&v26;
  *(_DWORD *)v6 = 0;
  *((_DWORD *)v6 + 2) = 0;
  v10 = s_bm_current_air_resistance;
  *((float *)v6 + 3) = s_bm_current_air_resistance;
  *((float *)v6 + 4) = x;
  *((float *)v6 + 5) = y;
  *((float *)v6 + 6) = v9;
  *((_DWORD *)v6 + 7) = 0;
  *((float *)v6 + 8) = v10;
  v11 = context->m_eye_rays[0].x;
  v12 = context->m_eye_rays[0].y;
  v13 = context->m_eye_rays[0].z;
  *((_DWORD *)v6 + 10) = 0;
  *((_DWORD *)v6 + 11) = 0;
  *((float *)v6 + 12) = v10;
  v14 = m_width;
  v6 += 36;
  *(_DWORD *)v6 = 0;
  *((float *)v6 + 4) = v11;
  *((float *)v6 + 5) = v12;
  *((float *)v6 + 6) = v13;
  *((_DWORD *)v6 + 7) = 0;
  *((_DWORD *)v6 + 8) = 0;
  v15 = context->m_eye_rays[3].x;
  v16 = context->m_eye_rays[3].y;
  v17 = context->m_eye_rays[3].z;
  *((_QWORD *)v6 + 5) = v26;
  *((float *)v6 + 12) = v10;
  v6 += 36;
  *(float *)v6 = v14;
  *((float *)v6 + 4) = v15;
  *((float *)v6 + 5) = v16;
  *((float *)v6 + 6) = v17;
  *((float *)v6 + 7) = v10;
  *((float *)v6 + 8) = v10;
  v18 = context->m_eye_rays[2].x;
  v19 = context->m_eye_rays[2].y;
  v20 = context->m_eye_rays[2].z;
  v6 += 36;
  *(float *)v6 = v14;
  *((_DWORD *)v6 + 1) = 0;
  *((_DWORD *)v6 + 2) = 0;
  *((float *)v6 + 3) = v10;
  *((float *)v6 + 4) = v18;
  *((float *)v6 + 5) = v19;
  *((float *)v6 + 6) = v20;
  *((float *)v6 + 7) = v10;
  *((_DWORD *)v6 + 8) = 0;
  vostok::render::vertex_buffer::unlock(
    v21,
    (int *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  vostok::render::res_geometry::apply(v22, (int)context->m_g_quad_eye_ray.m_object);
  vostok::render::backend::render_indexed(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    6u,
    v23,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    v_offset);
  if ( surf )
  {
    if ( !--surf->m_reference_count )
      vostok::render::resource_manager::release(surf, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
}
