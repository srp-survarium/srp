void __thiscall vostok::render::stage_gbuffer::render_forward_models(vostok::render::stage_gbuffer *this, int a2)
{
  int v2; // edi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // eax
  float z; // esi
  vostok::render::render_target *v5; // eax
  int v6; // ecx
  bool v7; // zf
  vostok::render::render_surface *v8; // ecx
  vostok::render::render_surface_vtbl *v9; // esi
  int add_shadow_vertices; // ebx
  vostok::render::material_effects *material_effects; // eax
  vostok::render::res_pass *v12; // ecx
  unsigned int m_width; // eax
  vostok::render::res_pass *v14; // eax
  vostok::render::res_pass *v15; // edi
  vostok::render::render_target *m_reference_count; // eax
  vostok::render::effect_manager *v17; // ecx
  vostok::render::res_pass *v18; // eax
  vostok::render::res_geometry *v19; // ecx
  vostok::render::backend *v20; // ecx
  vostok::render::renderer_context *v21; // [esp-4h] [ebp-1Ch]
  vostok::render::render_surface *v22; // [esp+Ch] [ebp-Ch]
  vostok::render::render_target *rt; // [esp+10h] [ebp-8h] BYREF
  vostok::render::render_surface *v24; // [esp+14h] [ebp-4h]

  v2 = a2;
  v3 = vostok::render::renderer_context::get_rt(
         *(vostok::render::renderer_context **)(a2 + 4),
         rt_albedo,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v3->m_object,
    0,
    0,
    0);
  v5 = rt;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v5->m_reference_count )
    {
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    }
  }
  v6 = *(_DWORD *)(LODWORD(z) + 7440);
  v7 = *(_DWORD *)(LODWORD(z) + 7384) == v6;
  *(_DWORD *)(LODWORD(z) + 7384) = v6;
  *(_BYTE *)(LODWORD(z) + 117) |= !v7;
  v8 = *(vostok::render::render_surface **)(*(_DWORD *)(*(_DWORD *)(a2 + 4) + 16268) + 33980);
  v22 = v8;
  v24 = *(vostok::render::render_surface **)(*(_DWORD *)(*(_DWORD *)(a2 + 4) + 16268) + 33984);
  if ( v8 != v24 )
  {
    while ( 1 )
    {
      v9 = v8->__vftable;
      add_shadow_vertices = (int)v8->add_shadow_vertices;
      material_effects = vostok::render::render_surface::get_material_effects(v8, add_shadow_vertices);
      v21 = *(vostok::render::renderer_context **)(v2 + 4);
      rt = (vostok::render::render_target *)material_effects;
      vostok::render::renderer_context::set_w((const vostok::math::float4x4 *)v9[1].add_shadow_vertices, v21);
      m_width = rt[1].m_width;
      *(_DWORD *)(m_width + 22048) = 0;
      v14 = **(vostok::render::res_pass ***)(m_width + 22052);
      v15 = 0;
      if ( v14 )
      {
        v15 = v14;
        ++v14->m_reference_count;
      }
      m_reference_count = (vostok::render::render_target *)v15->m_vs.m_object->m_reference_count;
      rt = 0;
      if ( m_reference_count )
      {
        ++m_reference_count->m_reference_count;
        rt = m_reference_count;
      }
      vostok::render::res_pass::apply(v12, (int)rt);
      v18 = (vostok::render::res_pass *)rt;
      if ( rt )
      {
        v7 = rt->m_reference_count-- == 1;
        if ( v7 )
          vostok::render::effect_manager::delete_pass(
            v17,
            (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
            v18);
      }
      v7 = v15->m_reference_count-- == 1;
      if ( v7 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v15);
      (*(void (__thiscall **)(void (__thiscall *)(vostok::render::render_surface *), _DWORD))(*(_DWORD *)v9[1].~vostok::render::render_surface
                                                                                            + 68))(
        v9[1].~vostok::render::render_surface,
        0);
      vostok::render::res_geometry::apply(v19, *(_DWORD *)(add_shadow_vertices + 4));
      v9[1].fill_lpv_vertex_color = 0;
      vostok::render::backend::render_indexed(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        3 * *(_DWORD *)(add_shadow_vertices + 24),
        v20,
        D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
        0,
        0);
      v22 = (vostok::render::render_surface *)((char *)v22 + 4);
      if ( v22 == v24 )
        break;
      v8 = v22;
      v2 = a2;
    }
  }
}
