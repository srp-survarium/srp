void __thiscall vostok::render::stage_postprocess::process_color_grading_texture(
        vostok::render::stage_postprocess *this,
        const vostok::render::environment_properties *env_params,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object)
{
  vostok::render::resource_manager *v4; // ecx
  vostok::render::res_texture *v5; // esi
  bool v6; // zf
  int z_low; // esi
  vostok::render::backend *v8; // ecx
  int v9; // eax
  vostok::render::resource_manager *v10; // ecx
  vostok::render::res_texture *m_object; // esi
  int v12; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *color_grading_texture; // eax
  vostok::render::backend *v14; // ecx
  vostok::render::resource_manager *v15; // ecx
  vostok::render::sliced_cube_geometry *v16; // ecx
  int v17; // esi
  int v18; // edi
  vostok::render::backend *v19; // ecx
  float *p_atmosphere_miePi_multiplier; // edi
  const D3D11_VIEWPORT *v21; // [esp+Ch] [ebp-50h]
  const D3D11_VIEWPORT *v22; // [esp+Ch] [ebp-50h]
  D3D11_VIEWPORT v23; // [esp+1Ch] [ebp-40h] BYREF
  D3D11_VIEWPORT v24; // [esp+34h] [ebp-28h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v25; // [esp+4Ch] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v26; // [esp+50h] [ebp-Ch] BYREF
  const vostok::math::float3 *v27; // [esp+54h] [ebp-8h]
  vostok::render::scene_view *v28; // [esp+58h] [ebp-4h]
  bool v29; // [esp+67h] [ebp+Bh]

  if ( !LOBYTE(object.m_object[1].m_rescale_min.elements[2]) )
  {
    p_atmosphere_miePi_multiplier = &env_params[1].atmosphere_miePi_multiplier;
LABEL_21:
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)p_atmosphere_miePi_multiplier,
      (vostok::render::res_texture *)&env_params[1].atmosphere_use_sun_illumination);
    return;
  }
  if ( LODWORD(object.m_object->m_rescale_max.z) != 1 )
  {
    z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      (const vostok::render::render_target *)LODWORD(env_params->god_rays_color_1.x),
      0,
      0,
      0);
    vostok::render::backend::clear_render_targets(v8, z_low, 0, 0.0, 0.0, 0.0);
    v9 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    qmemcpy(
      (void *)&v23,
      (const void *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 120),
      sizeof(v23));
    v6 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == 0;
    *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) = 0;
    *(_BYTE *)(v9 + 117) |= !v6;
    v24.TopLeftX = 0.0;
    v24.TopLeftY = 0.0;
    v24.MinDepth = 0.0;
    v24.Width = vostok::render::grass_patch_size;
    v24.Height = vostok::render::grass_patch_size;
    v24.MaxDepth = s_bm_current_air_resistance;
    vostok::render::backend::set_viewports((vostok::render::backend *)&v24, v9, &v24, v21);
    m_object = object.m_object;
    v28 = 0;
    if ( LODWORD(object.m_object->m_rescale_max.z) )
    {
      v27 = (const vostok::math::float3 *)&object.m_object->m_rescale_min.elements[2];
      do
      {
        v29 = vostok::render::scene_view::get_color_grading_texture(
                v28,
                (int)env_params->sky_clouds_texture.m_object[61].m_fat_it.m_node,
                &v26,
                (const unsigned int)v22)->m_object == 0;
        if ( v26.m_object )
        {
          v6 = v26.m_object->m_reference_count-- == 1;
          if ( v6 )
            vostok::render::resource_manager::release(
              v10,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v26.m_object);
        }
        if ( !v29 )
        {
          v12 = *(_DWORD *)&env_params->use_sun_moon_texture;
          *(_DWORD *)(v12 + 22048) = 0;
          vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v10, v12);
          color_grading_texture = vostok::render::scene_view::get_color_grading_texture(
                                    v28,
                                    (int)env_params->sky_clouds_texture.m_object[61].m_fat_it.m_node,
                                    &v25,
                                    (const unsigned int)v22);
          vostok::render::backend::set_ps_texture(
            v14,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            "t_color_grading",
            color_grading_texture->m_object);
          if ( v25.m_object )
          {
            v6 = v25.m_object->m_reference_count-- == 1;
            if ( v6 )
              vostok::render::resource_manager::release(
                v15,
                (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                v25.m_object);
          }
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            (vostok::render::backend *)v15,
            (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            (const vostok::render::shader_constant_host *)LODWORD(env_params->sun_moon_billboard_scale),
            v27);
          vostok::render::sliced_cube_geometry::draw(v16, (int)&env_params->sun_color.z);
          m_object = object.m_object;
        }
        v28 = (vostok::render::scene_view *)((char *)v28 + 1);
        v27 = (const vostok::math::float3 *)((char *)v27 + 4);
      }
      while ( (unsigned int)v28 < LODWORD(m_object->m_rescale_max.z) );
    }
    v17 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    vostok::render::backend::reset_render_targets(
      (vostok::render::backend *)v10,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    v18 = *(_DWORD *)(v17 + 7440);
    v6 = *(_DWORD *)(v17 + 7384) == v18;
    *(_DWORD *)(v17 + 7384) = v18;
    LOBYTE(v19) = !v6;
    *(_BYTE *)(v17 + 117) |= !v6;
    vostok::render::backend::set_viewports(v19, v17, &v23, v22);
    p_atmosphere_miePi_multiplier = &env_params->god_rays_color_1.y;
    goto LABEL_21;
  }
  vostok::render::scene_view::get_color_grading_texture(
    0,
    (int)env_params->sky_clouds_texture.m_object[61].m_fat_it.m_node,
    &object,
    (const unsigned int)v21);
  v5 = object.m_object;
  if ( object.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        &object,
        (vostok::render::res_texture *)&env_params[1].atmosphere_use_sun_illumination);
    v6 = v5->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::resource_manager::release(
        v4,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v5);
  }
}
