void __thiscall vostok::render::stage_screen_space_reflections::accumulate_models_local_reflections(
        vostok::render::stage_screen_space_reflections *this,
        const vostok::buffer_vector<vostok::render::render_surface_instance *> *reflection_models,
        int **a3)
{
  vostok::render::render_target *v3; // eax
  vostok::render::backend *v4; // ecx
  vostok::render::render_target *v5; // eax
  vostok::render::renderer_context *m_end; // ecx
  float v7; // xmm0_4
  int *v8; // edi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v9; // eax
  vostok::render::backend *v10; // ecx
  vostok::render::render_target *v11; // eax
  int z_low; // eax
  _DWORD *v13; // esi
  vostok::render::render_surface *v14; // ecx
  int v15; // esi
  int v16; // edi
  vostok::render::res_effect *m_object; // eax
  vostok::render::res_pass *v18; // ecx
  vostok::render::render_target *v19; // eax
  vostok::render::res_pass *v20; // eax
  vostok::render::effect_manager *v21; // ecx
  vostok::render::res_pass *v22; // eax
  bool v23; // zf
  vostok::render::res_pass *v24; // eax
  vostok::render::res_geometry *v25; // ecx
  float z; // esi
  vostok::render::backend *v27; // ecx
  vostok::math::float4x4 *v28; // eax
  vostok::render::backend *v29; // ecx
  vostok::render::backend *v30; // ecx
  vostok::render::backend *v31; // ecx
  vostok::render::backend *v32; // ecx
  const D3D11_VIEWPORT *v33; // [esp+Ch] [ebp-A0h]
  const D3D11_VIEWPORT *v34; // [esp+Ch] [ebp-A0h]
  vostok::render::render_target *rt; // [esp+1Ch] [ebp-90h] BYREF
  int *v36; // [esp+20h] [ebp-8Ch]
  unsigned int m_width; // [esp+24h] [ebp-88h]
  vostok::render::res_pass *pass; // [esp+28h] [ebp-84h]
  vostok::math::float3 v39; // [esp+2Ch] [ebp-80h] BYREF
  int v40; // [esp+38h] [ebp-74h]
  D3D11_VIEWPORT v41; // [esp+3Ch] [ebp-70h] BYREF
  D3D11_VIEWPORT v42; // [esp+54h] [ebp-58h] BYREF
  vostok::math::float4x4 v43; // [esp+6Ch] [ebp-40h] BYREF

  qmemcpy(
    (void *)&v42,
    (const void *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 120),
    sizeof(v42));
  m_width = vostok::render::renderer_context::get_rt(
              (vostok::render::renderer_context *)reflection_models->m_end,
              rt_local_reflection_result,
              (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt)->m_object->m_width;
  v3 = rt;
  v41.Width = (float)m_width;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v3->m_reference_count )
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  m_width = vostok::render::renderer_context::get_rt(
              (vostok::render::renderer_context *)reflection_models->m_end,
              rt_local_reflection_result,
              (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt)->m_object->m_height;
  v5 = rt;
  v41.Height = (float)m_width;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v5->m_reference_count )
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  v41.MinDepth = 0.0;
  v41.MaxDepth = s_bm_current_air_resistance;
  v41.TopLeftX = 0.0;
  v41.TopLeftY = 0.0;
  vostok::render::backend::set_viewports(
    v4,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    &v41,
    v33);
  m_end = (vostok::render::renderer_context *)reflection_models->m_end;
  if ( LOBYTE(m_end->m_scene_view.m_object[2].grm_satisfaction_tree_hook.left_) )
    v7 = s_bm_current_air_resistance;
  else
    v7 = 0.0;
  v8 = *a3;
  LODWORD(v39.y) = a3[1];
  v39.x = v7;
  v36 = v8;
  v9 = vostok::render::renderer_context::get_rt(
         m_end,
         rt_local_reflection_result,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v9->m_object,
    0,
    0,
    0);
  v11 = rt;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v11->m_reference_count )
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  vostok::render::backend::clear_render_targets(
    v10,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    0,
    0.0,
    0.0,
    0.0);
  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  v13 = (_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384);
  LOBYTE(v14) = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) != 0;
  *(_BYTE *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 117) |= (unsigned __int8)v14;
  *v13 = 0;
  if ( v8 != (int *)LODWORD(v39.y) )
  {
    v39.z = 0.0;
    while ( 1 )
    {
      v15 = *v8;
      v16 = *(_DWORD *)(*v8 + 16);
      v40 = v15;
      m_width = v16;
      m_object = vostok::render::render_surface::get_material_effects(v14, v16)->m_effects[16].m_object;
      rt = 0;
      m_object->m_cur_technique = 1;
      v19 = (vostok::render::render_target *)m_object->m_techniques.m_begin[1].m_object;
      if ( v19 )
      {
        ++v19->m_reference_count;
        rt = v19;
      }
      v20 = *(vostok::render::res_pass **)rt->m_memory_usage_type;
      pass = 0;
      if ( v20 )
      {
        ++v20->m_reference_count;
        pass = v20;
      }
      vostok::render::res_pass::apply(v18, (int)pass);
      v22 = pass;
      if ( pass )
      {
        v23 = pass->m_reference_count-- == 1;
        if ( v23 )
          vostok::render::effect_manager::delete_pass(
            v21,
            (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
            v22);
      }
      v24 = (vostok::render::res_pass *)rt;
      v23 = rt->m_reference_count-- == 1;
      if ( v23 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v24);
      (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(v15 + 20) + 68))(*(_DWORD *)(v15 + 20), 0);
      vostok::render::renderer_context::set_w(
        *(const vostok::math::float4x4 **)(v15 + 36),
        (vostok::render::renderer_context *)reflection_models->m_end);
      vostok::render::res_geometry::apply(v25, *(_DWORD *)(v16 + 4));
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v27,
        (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        (const vostok::render::shader_constant_host *)reflection_models[1].m_end,
        (const vostok::math::float3 *)(reflection_models->m_end + 5233));
      v28 = vostok::math::transpose((const vostok::math::float4x4 *)(reflection_models->m_max_end + 24), &v43);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v29,
        (vostok::render::constants_handler<1> *)LODWORD(z),
        (const vostok::render::shader_constant_host *)reflection_models[1].m_max_end,
        (const vostok::math::float3 *)v28);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v30,
        (vostok::render::constants_handler<1> *)LODWORD(z),
        (const vostok::render::shader_constant_host *)reflection_models[2].m_begin,
        (vostok::math::float3 *)&v39.elements[2]);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v31,
        (vostok::render::constants_handler<1> *)LODWORD(z),
        (const vostok::render::shader_constant_host *)reflection_models[2].m_end,
        &v39);
      *(_DWORD *)(v40 + 32) = 0;
      vostok::render::backend::render_indexed(
        (vostok::render::backend *)LODWORD(z),
        3 * *(_DWORD *)(m_width + 24),
        v32,
        D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
        0,
        0);
      if ( ++v36 == (int *)LODWORD(v39.y) )
        break;
      v8 = v36;
    }
    z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  }
  vostok::render::backend::set_viewports((vostok::render::backend *)&v42, z_low, &v42, v34);
}
