char __cdecl vostok::render::read_diffuse_colors_64_(
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> m_materail_effects_instance,
        vostok::math::color (*results)[64][64])
{
  char v2; // bl
  vostok::render::resource_manager *v4; // ecx
  const char *v5; // esi
  stlp_std::priv::_Rb_tree_node_base *render_target; // eax
  const char *v7; // edi
  int v8; // ecx
  bool v9; // cf
  bool v10; // zf
  int v11; // eax
  vostok::render::res_texture *texture; // eax
  vostok::render::resource_manager *v13; // esi
  vostok::fixed_string<260> *m_max_end; // eax
  vostok::render::res_effect *v15; // ecx
  vostok::render::render_target *v16; // ecx
  vostok::render::backend *v17; // ecx
  vostok::render::resource_manager *v18; // ecx
  vostok::render::res_texture *texture2d; // eax
  vostok::render::res_texture *v20; // esi
  vostok::render::backend *v21; // ecx
  vostok::render::res_texture *v22; // ecx
  char *v23; // eax
  vostok::render::resource_manager *v24; // ecx
  vostok::render::res_texture *v25; // eax
  vostok::render::render_target *v26; // eax
  vostok::render::res_texture *v27; // ecx
  vostok::render::res_texture_vtbl *v28; // edx
  vostok::render::resource_manager *v29; // ecx
  vostok::render::res_texture *v30; // eax
  vostok::render::render_target *v31; // eax
  vostok::render::system_renderer *v32; // [esp-1Ch] [ebp-44h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v33; // [esp-18h] [ebp-40h] BYREF
  vostok::render::render_target *v34; // [esp-14h] [ebp-3Ch]
  vostok::render::render_target *v35; // [esp-10h] [ebp-38h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v36; // [esp-Ch] [ebp-34h]
  vostok::render::render_target *v37; // [esp-8h] [ebp-30h]
  D3D11_VIEWPORT *v38; // [esp-4h] [ebp-2Ch]
  unsigned int *v39; // [esp+0h] [ebp-28h]
  vostok::render::res_texture *v40; // [esp+4h] [ebp-24h]
  float v41; // [esp+8h] [ebp-20h]
  float v42; // [esp+Ch] [ebp-1Ch]
  unsigned int v43; // [esp+10h] [ebp-18h]
  unsigned int dest_mip; // [esp+14h] [ebp-14h]
  vostok::math::color *v45; // [esp+18h] [ebp-10h]
  vostok::render::res_texture *dest; // [esp+1Ch] [ebp-Ch] BYREF
  vostok::render::resource_manager *material_effects; // [esp+20h] [ebp-8h] BYREF
  D3D11_MAP mode; // [esp+24h] [ebp-4h] BYREF

  v2 = 0;
  if ( m_materail_effects_instance.m_object
    && (material_effects = (vostok::render::resource_manager *)vostok::render::material_effects_instance::get_material_effects(
                                                                 (vostok::render::material_effects_instance *)m_materail_effects_instance.m_object,
                                                                 static_mesh_vertex_input_type),
        material_effects->m_loaded_texture_names.m_max_end) )
  {
    v5 = "$user$diffuse_color";
    render_target = vostok::render::resource_manager::create_render_target(
                      v4,
                      (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                      "$user$diffuse_color",
                      0x40u,
                      0x40u,
                      (char *)0x1C,
                      DXGI_FORMAT_R32G32B32A32_TYPELESS,
                      0,
                      0,
                      0,
                      (unsigned int)v39);
    dest_mip = 0;
    if ( render_target )
    {
      ++*(_DWORD *)&render_target->_M_color;
      dest_mip = (unsigned int)render_target;
    }
    v7 = "null";
    v8 = 20;
    v11 = 0;
    v9 = 0;
    v10 = 1;
    do
    {
      if ( !v8 )
        break;
      v9 = *v5 < (unsigned int)*v7;
      v10 = *v5++ == *v7++;
      --v8;
    }
    while ( v10 );
    if ( !v10 )
      v11 = -v9 - (v9 - 1);
    if ( v11 )
    {
      v13 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
      texture = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                                 (vostok::render::resource_manager *)v8,
                                                 (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                                 "$user$diffuse_color");
      if ( !texture )
        texture = vostok::render::resource_manager::load_texture(
                    v13,
                    "$user$diffuse_color",
                    0,
                    0,
                    0,
                    1,
                    1,
                    0xFFFFFFFF,
                    1,
                    0);
    }
    else
    {
      texture = 0;
    }
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&dest,
      texture);
    m_max_end = material_effects->m_loaded_texture_names.m_max_end;
    *(_DWORD *)&m_max_end[81].m_buffer[4] = 4;
    vostok::render::res_effect::apply_pass(v15, (int)m_max_end);
    v38 = 0;
    v37 = 0;
    v36.m_object = 0;
    v35 = 0;
    v33.m_object = v16;
    v34 = 0;
    v32 = (vostok::render::system_renderer *)v16;
    material_effects = (vostok::render::resource_manager *)vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      &v33,
      (vostok::render::render_target *)dest_mip);
    vostok::render::system_renderer::fill_surface(
      v32,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)material_effects,
      v33.m_object,
      v34,
      v35,
      v36,
      v37,
      v38,
      *(float *)&v39,
      *(float *)&v40,
      v41,
      v42);
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Flush(vostok::quasi_singleton<vostok::render::device>::pinst->m_context);
    vostok::render::backend::flush(
      v17,
      LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    texture2d = vostok::render::resource_manager::create_texture2d(
                  v18,
                  (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  "$user$diffuse_color_lockable",
                  0x40u,
                  (const D3D11_SUBRESOURCE_DATA *)0x40,
                  0,
                  DXGI_FORMAT_R8G8B8A8_UNORM,
                  D3D11_USAGE_STAGING,
                  1u,
                  0);
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&material_effects,
      texture2d);
    v20 = (vostok::render::res_texture *)material_effects;
    vostok::render::resource_manager::copy2D(
      0x40u,
      material_effects,
      dest,
      0x40u,
      (unsigned int)v39,
      v40,
      LODWORD(v41),
      LODWORD(v42),
      v43,
      dest_mip,
      (unsigned int)v45);
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Flush(vostok::quasi_singleton<vostok::render::device>::pinst->m_context);
    vostok::render::backend::flush(
      v21,
      LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    v23 = (char *)vostok::render::res_texture::map2D(v22, (int)v20, &mode, 0, v39, (bool)v40);
    if ( v23 )
    {
      v45 = (vostok::math::color *)results;
      material_effects = (vostok::render::resource_manager *)64;
      do
      {
        v27 = (vostok::render::res_texture *)v45;
        v43 = 0;
        do
        {
          v28 = *(vostok::render::res_texture_vtbl **)&v23[4 * v43++];
          v27->__vftable = v28;
          v27 = (vostok::render::res_texture *)((char *)v27 + 256);
        }
        while ( v43 < 0x40 );
        v23 += mode;
        ++v45;
        material_effects = (vostok::render::resource_manager *)((char *)material_effects - 1);
      }
      while ( material_effects );
      vostok::render::res_texture::unmap2D(v27, (int)v20);
      if ( v20 )
      {
        v10 = v20->m_reference_count-- == 1;
        if ( v10 )
          vostok::render::resource_manager::release(
            v29,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v20);
      }
      v30 = dest;
      if ( dest )
      {
        v10 = dest->m_reference_count-- == 1;
        if ( v10 )
          vostok::render::resource_manager::release(
            v29,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v30);
      }
      v31 = (vostok::render::render_target *)dest_mip;
      if ( dest_mip )
      {
        v10 = (*(_DWORD *)dest_mip)-- == 1;
        if ( v10 )
          vostok::render::resource_manager::release(
            v31,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      }
      v2 = 1;
    }
    else
    {
      if ( v20 )
      {
        v10 = v20->m_reference_count-- == 1;
        if ( v10 )
          vostok::render::resource_manager::release(
            v24,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v20);
      }
      v25 = dest;
      if ( dest )
      {
        v10 = dest->m_reference_count-- == 1;
        if ( v10 )
          vostok::render::resource_manager::release(
            v24,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v25);
      }
      v26 = (vostok::render::render_target *)dest_mip;
      if ( dest_mip )
      {
        v10 = (*(_DWORD *)dest_mip)-- == 1;
        if ( v10 )
          vostok::render::resource_manager::release(
            v26,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      }
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&m_materail_effects_instance);
    return v2;
  }
  else
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&m_materail_effects_instance);
    return 0;
  }
}
