void __userpurge vostok::render::system_renderer::draw_triangles(
        const vostok::render::vertex_colored *const vertices_end@<eax>,
        vostok::render::system_renderer *a2@<ecx>,
        unsigned int this,
        unsigned int vertices_begin,
        unsigned __int8 *indices_begin,
        char *indices_end,
        bool covering_effect)
{
  vostok::render::system_renderer *v7; // ebx
  unsigned __int8 *v9; // eax
  vostok::render::vertex_buffer *v10; // ecx
  unsigned __int8 *v11; // eax
  int m_object; // edx
  vostok::render::untyped_buffer *v13; // ecx
  vostok::render::res_geometry *v14; // ecx
  int v15; // eax
  float z; // esi
  vostok::render::backend *v17; // ecx
  vostok::render::backend *v18; // ecx
  int v19; // eax
  vostok::render::res_effect *v20; // ecx
  vostok::render::res_geometry *v21; // ecx
  float v22; // esi
  vostok::render::backend *v23; // ecx
  vostok::render::backend *v24; // ecx
  unsigned int v_offset; // [esp+10h] [ebp-4h] BYREF

  v7 = (vostok::render::system_renderer *)this;
  if ( vostok::render::system_renderer::is_effects_ready(a2, (_DWORD *)this) )
  {
    this = (int)((int)vertices_end - vertices_begin) >> 4;
    v9 = (unsigned __int8 *)vostok::render::vertex_buffer::lock(&v7->m_vertex_stream, &v_offset, this, 0x10u);
    memcpy(v9, (unsigned __int8 *)vertices_begin, 16 * this);
    vostok::render::vertex_buffer::unlock(v10, (int *)&v7->m_vertex_stream);
    vertices_begin = (indices_end - (char *)indices_begin) >> 1;
    v11 = (unsigned __int8 *)vostok::render::index_buffer::lock(&v7->m_index_stream, &this, vertices_begin);
    memcpy(v11, indices_begin, 2 * vertices_begin);
    m_object = (int)v7->m_index_stream.m_buffer.m_object;
    v7->m_index_stream.m_position += v7->m_index_stream.m_lock_size;
    vostok::render::untyped_buffer::unmap(v13, m_object);
    vostok::render::res_geometry::apply(v14, (int)v7->m_colored_geom.m_object);
    v15 = (int)v7->m_sh_vcolor.m_object;
    if ( covering_effect )
    {
      *(_DWORD *)(v15 + 22048) = 3;
    }
    else if ( v7->m_color_write )
    {
      *(_DWORD *)(v15 + 22048) = v7->m_grid_mode;
    }
    else
    {
      *(_DWORD *)(v15 + 22048) = 2;
    }
    vostok::render::res_effect::apply_pass(0, v15);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v17,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v7->m_grid_density_constant,
      (const vostok::math::float3 *)&v7->m_grid_density);
    vostok::render::backend::render_indexed(
      (vostok::render::backend *)LODWORD(z),
      vertices_begin,
      v18,
      D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
      this,
      v_offset);
    v19 = (int)v7->m_sh_vcolor.m_object;
    *(_DWORD *)(v19 + 22048) = 4;
    vostok::render::res_effect::apply_pass(v20, v19);
    vostok::render::res_geometry::apply(v21, (int)v7->m_colored_geom.m_object);
    v22 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v23,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v7->m_grid_density_constant,
      (const vostok::math::float3 *)&v7->m_grid_density);
    vostok::render::backend::render_indexed(
      (vostok::render::backend *)LODWORD(v22),
      vertices_begin,
      v24,
      D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
      this,
      v_offset);
  }
}
