void __userpurge vostok::render::system_renderer::draw_lines(
        const vostok::render::vertex_colored *const vertices_end@<eax>,
        vostok::render::system_renderer *a2@<ecx>,
        vostok::render::system_renderer *this,
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
  vostok::render::res_effect *v15; // ecx
  int v16; // eax
  float z; // esi
  vostok::render::backend *v18; // ecx
  vostok::render::backend *v19; // ecx
  unsigned int v_offset; // [esp+10h] [ebp-4h] BYREF

  v7 = this;
  if ( vostok::render::system_renderer::is_effects_ready(a2, this) )
  {
    this = (vostok::render::system_renderer *)(16 * ((int)((int)vertices_end - vertices_begin) >> 4));
    v9 = (unsigned __int8 *)vostok::render::vertex_buffer::lock(
                              &v7->m_vertex_stream,
                              &v_offset,
                              (int)((int)vertices_end - vertices_begin) >> 4,
                              0x10u);
    memcpy(v9, (unsigned __int8 *)vertices_begin, (unsigned int)this);
    vostok::render::vertex_buffer::unlock(v10, (int *)&v7->m_vertex_stream);
    vertices_begin = (indices_end - (char *)indices_begin) >> 1;
    v11 = (unsigned __int8 *)vostok::render::index_buffer::lock(
                               &v7->m_index_stream,
                               (unsigned int *)&this,
                               vertices_begin);
    memcpy(v11, indices_begin, 2 * vertices_begin);
    m_object = (int)v7->m_index_stream.m_buffer.m_object;
    v7->m_index_stream.m_position += v7->m_index_stream.m_lock_size;
    vostok::render::untyped_buffer::unmap(v13, m_object);
    vostok::render::res_geometry::apply(v14, (int)v7->m_colored_geom.m_object);
    v16 = (int)v7->m_sh_vcolor.m_object;
    if ( covering_effect )
      *(_DWORD *)(v16 + 22048) = 3;
    else
      *(_DWORD *)(v16 + 22048) = 0;
    vostok::render::res_effect::apply_pass(v15, v16);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v18,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v7->m_grid_density_constant,
      (const vostok::math::float3 *)&v7->m_grid_density);
    vostok::render::backend::render_indexed(
      (vostok::render::backend *)LODWORD(z),
      vertices_begin,
      v19,
      D3D_PRIMITIVE_TOPOLOGY_LINELIST,
      (unsigned int)this,
      v_offset);
  }
}
