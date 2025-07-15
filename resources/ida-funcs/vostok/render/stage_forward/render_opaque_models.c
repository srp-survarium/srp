void __thiscall vostok::render::stage_forward::render_opaque_models(vostok::render::stage_forward *this, int a2)
{
  vostok::render::renderer_context *v2; // ecx
  volatile int m_flags; // edi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v4; // eax
  float z; // esi
  vostok::render::render_target *v6; // eax
  bool v7; // zf
  int v8; // esi
  int v9; // ebx
  vostok::render::material_effects *material_effects; // eax
  vostok::render::material_effects *v11; // edi
  int v12; // eax
  vostok::render::res_effect *v13; // ecx
  vostok::render::res_geometry *v14; // ecx
  vostok::render::backend *v15; // ecx
  vostok::resources::vfs_sub_fat_resource *v16; // [esp+Ch] [ebp-Ch]
  vostok::render::render_target *rt; // [esp+10h] [ebp-8h] BYREF
  vostok::resources::vfs_sub_fat_resource *m_object; // [esp+14h] [ebp-4h]

  v2 = *(vostok::render::renderer_context **)(a2 + 4);
  m_flags = v2->m_scene_view.m_object[62].vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags;
  v16 = (vostok::resources::vfs_sub_fat_resource *)m_flags;
  m_object = v2->m_scene_view.m_object[62].m_sub_fat.m_object;
  if ( (vostok::resources::vfs_sub_fat_resource *)m_flags != m_object )
  {
    v4 = vostok::render::renderer_context::get_rt(
           v2,
           rt_generic_0,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v4->m_object,
      0,
      0,
      0);
    v6 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v6->m_reference_count )
      {
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      }
    }
    v2 = *(vostok::render::renderer_context **)(LODWORD(z) + 7440);
    v7 = *(_DWORD *)(LODWORD(z) + 7384) == (_DWORD)v2;
    *(_DWORD *)(LODWORD(z) + 7384) = v2;
    *(_BYTE *)(LODWORD(z) + 117) |= !v7;
  }
  if ( (vostok::resources::vfs_sub_fat_resource *)m_flags != m_object )
  {
    while ( 1 )
    {
      v8 = *(_DWORD *)m_flags;
      v9 = *(_DWORD *)(*(_DWORD *)m_flags + 16);
      material_effects = vostok::render::render_surface::get_material_effects((vostok::render::render_surface *)v2, v9);
      v11 = material_effects;
      if ( material_effects->is_emissive )
      {
        if ( material_effects->m_effects[1].m_object )
        {
          vostok::render::renderer_context::set_w(
            *(const vostok::math::float4x4 **)(v8 + 36),
            *(vostok::render::renderer_context **)(a2 + 4));
          v12 = (int)v11->m_effects[1].m_object;
          *(_DWORD *)(v12 + 22048) = 6;
          vostok::render::res_effect::apply_pass(v13, v12);
          vostok::render::res_geometry::apply(v14, *(_DWORD *)(v9 + 4));
          (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(v8 + 20) + 68))(*(_DWORD *)(v8 + 20), 0);
          *(_DWORD *)(v8 + 32) = 0;
          vostok::render::backend::render_indexed(
            (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            3 * *(_DWORD *)(v9 + 24),
            v15,
            D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
            0,
            0);
        }
      }
      v16 = (vostok::resources::vfs_sub_fat_resource *)((char *)v16 + 4);
      if ( v16 == m_object )
        break;
      m_flags = (volatile int)v16;
    }
  }
}
