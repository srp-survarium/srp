void __thiscall vostok::render::stage_lights::fill_surface(
        vostok::render::stage_lights *this,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> surf,
        vostok::render::render_target *rt)
{
  float z; // esi
  char *v4; // eax
  float v5; // xmm0_4
  float *v6; // edi
  float v7; // eax
  vostok::render::res_geometry *v8; // ecx
  vostok::render::backend *v9; // ecx
  float v10; // [esp+18h] [ebp-10h]
  unsigned int v_offset; // [esp+24h] [ebp-4h] BYREF

  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    rt,
    0,
    0,
    0);
  *(_BYTE *)(LODWORD(z) + 117) |= *(_DWORD *)(LODWORD(z) + 7384) != 0;
  *(_DWORD *)(LODWORD(z) + 7384) = 0;
  v4 = vostok::render::vertex_buffer::lock((vostok::render::vertex_buffer *)LODWORD(z), &v_offset, 4u, 0x18u);
  v5 = s_bm_current_air_resistance;
  v10 = s_bm_current_air_resistance;
  *(float *)v4 = FLOAT_N1_0;
  *((float *)v4 + 1) = FLOAT_N1_0;
  *((_DWORD *)v4 + 2) = 0;
  *((float *)v4 + 3) = v10;
  *((_DWORD *)v4 + 4) = 0;
  *((float *)v4 + 5) = v5;
  v4 += 24;
  *(float *)v4 = FLOAT_N1_0;
  *((float *)v4 + 1) = v5;
  *((_DWORD *)v4 + 2) = 0;
  *((float *)v4 + 3) = v5;
  *((_DWORD *)v4 + 4) = 0;
  *((_DWORD *)v4 + 5) = 0;
  v4 += 24;
  *(float *)v4 = v5;
  *((float *)v4 + 1) = FLOAT_N1_0;
  *((_DWORD *)v4 + 2) = 0;
  *((float *)v4 + 3) = v5;
  *((float *)v4 + 4) = v5;
  *((float *)v4 + 5) = v5;
  v4 += 24;
  *(float *)v4 = v5;
  *((float *)v4 + 1) = v5;
  *((float *)v4 + 4) = v5;
  *((_DWORD *)v4 + 2) = 0;
  v6 = (float *)(v4 + 12);
  *((_DWORD *)v4 + 5) = 0;
  v7 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  *v6 = v5;
  vostok::render::vertex_buffer::unlock(0, (int *)LODWORD(v7));
  vostok::render::res_geometry::apply(v8, *(&surf.m_object[30].m_memory_usage + 1));
  vostok::render::backend::render_indexed(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    6u,
    v9,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    v_offset);
  if ( rt )
  {
    if ( !--rt->m_reference_count )
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
}
