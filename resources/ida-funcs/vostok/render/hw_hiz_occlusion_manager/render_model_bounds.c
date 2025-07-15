void __thiscall vostok::render::hw_hiz_occlusion_manager::render_model_bounds(
        vostok::render::hw_hiz_occlusion_manager *this,
        vostok::render::renderer_context *in_context,
        vostok::render::renderer_context *in_bounds,
        unsigned int *in_num_bounds,
        unsigned int in_num_boundsa)
{
  vostok::render::renderer_context *v5; // ebx
  vostok::render::hw_hiz_point_list *v6; // ecx
  vostok::math::float4x4 *v7; // ecx
  vostok::math::float4x4 *v8; // eax
  double v9; // st7
  int z_low; // esi
  vostok::render::backend *v11; // ecx
  int m_begin; // eax
  vostok::render::res_effect *v13; // ecx
  vostok::render::backend *v14; // ecx
  int v15; // eax
  double v16; // st7
  float z; // esi
  const vostok::render::shader_constant_host *m_end; // eax
  vostok::render::backend *v19; // ecx
  int v20; // eax
  double v21; // st7
  vostok::render::hw_hiz_point_list *v22; // ecx
  const vostok::render::shader_constant_host *m_max_end; // [esp+4h] [ebp-98h]
  unsigned int v24; // [esp+8h] [ebp-94h]
  const D3D11_VIEWPORT *v25; // [esp+Ch] [ebp-90h]
  const D3D11_VIEWPORT *v26; // [esp+Ch] [ebp-90h]
  vostok::math::float4x4 v27; // [esp+1Ch] [ebp-80h] BYREF
  D3D11_VIEWPORT v28; // [esp+5Ch] [ebp-40h] BYREF
  D3D11_VIEWPORT v29; // [esp+74h] [ebp-28h] BYREF
  vostok::math::float3 arg; // [esp+8Ch] [ebp-10h] BYREF
  int v31; // [esp+98h] [ebp-4h]

  v5 = in_context;
  if ( !s_hiz3 )
  {
    pix_event_wrapper_dx11::pix_event_wrapper_dx11(
      (pix_event_wrapper_dx11 *)this,
      (pix_event_wrapper_dx11 *)&in_context + 3,
      (int)L"render_model_bounds");
    vostok::render::hw_hiz_occlusion_manager::check_culling_buffer(
      in_num_boundsa,
      (vostok::render::hw_hiz_occlusion_manager *)v5);
    v24 = *(_DWORD *)&v5->m_family[1].name.m_buffer[8];
    in_context = (vostok::render::renderer_context *)&v5->m_family[1].name.m_buffer[28];
    vostok::render::hw_hiz_point_list::set_points(
      v6,
      (const vostok::math::float4 *)&v5->m_family[1].name.m_buffer[28],
      in_num_bounds,
      v24);
    v8 = vostok::math::float4x4::identity(v7, &v27);
    vostok::render::renderer_context::set_w(v8, in_bounds);
    v9 = (double)*(unsigned int *)&v5->m_family[1].name.m_buffer[8];
    qmemcpy(
      (void *)&v28,
      (const void *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 120),
      sizeof(v28));
    v29.Width = v9;
    v29.Height = (float)*(unsigned int *)&v5->m_family[1].name.m_buffer[12];
    v29.MinDepth = 0.0;
    v29.MaxDepth = s_bm_current_air_resistance;
    v29.TopLeftX = 0.0;
    v29.TopLeftY = 0.0;
    vostok::render::backend::set_viewports(
      (vostok::render::backend *)&v29,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      &v29,
      v25);
    z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *(const vostok::render::render_target **)&v5->m_family[1].name.m_buffer[16],
      0,
      0,
      0);
    LOBYTE(v11) = *(_DWORD *)(z_low + 7384) != 0;
    *(_DWORD *)(z_low + 7384) = 0;
    *(_BYTE *)(z_low + 117) |= (unsigned __int8)v11;
    vostok::render::backend::clear_render_targets(v11, z_low, 0, 0.0, 0.0, 0.0);
    m_begin = (int)v5->m_family[0].orig_name.m_begin;
    *(_DWORD *)(m_begin + 22048) = 6;
    vostok::render::res_effect::apply_pass(v13, m_begin);
    vostok::render::backend::set_ps_texture(
      v14,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "hiz_depth_texture",
      *(vostok::render::res_texture **)&v5->m_family[1].orig_name.m_buffer[28]);
    v15 = *(_DWORD *)&v5->m_family[1].name.m_buffer[12];
    arg.x = (float)*(unsigned int *)&v5->m_family[1].name.m_buffer[8];
    v16 = (double)*(int *)&v5->m_family[1].name.m_buffer[12];
    if ( v15 < 0 )
      v16 = v16 + 4294967300.0;
    arg.y = v16;
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    m_end = (const vostok::render::shader_constant_host *)v5->m_family[1].name.m_end;
    arg.z = 0.0;
    v31 = 0;
    vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      m_end,
      (const unsigned int *)&arg);
    v20 = *(_DWORD *)&v5->m_family[1].orig_name.m_buffer[44];
    arg.x = (float)*(unsigned int *)&v5->m_family[1].orig_name.m_buffer[40];
    v21 = (double)*(int *)&v5->m_family[1].orig_name.m_buffer[44];
    if ( v20 < 0 )
      v21 = v21 + 4294967300.0;
    arg.y = v21;
    m_max_end = (const vostok::render::shader_constant_host *)v5->m_family[1].name.m_max_end;
    arg.z = 0.0;
    v31 = 0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v19,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      m_max_end,
      &arg);
    if ( !s_hiz4 )
      vostok::render::hw_hiz_point_list::render(
        v22,
        (const unsigned int)in_context,
        *(_DWORD *)&v5->m_family[1].name.m_buffer[4]);
    vostok::render::backend::set_viewports(
      (vostok::render::backend *)v22,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      &v28,
      v26);
    D3DPERF_EndEvent();
  }
}
