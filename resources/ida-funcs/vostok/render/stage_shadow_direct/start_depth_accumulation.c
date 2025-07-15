void __usercall vostok::render::stage_shadow_direct::start_depth_accumulation(
        vostok::render::stage_shadow_direct *this@<ecx>,
        int a2@<edx>,
        const D3D11_VIEWPORT *a3@<edi>)
{
  int z_low; // eax
  double v4; // st7
  int v5; // ecx
  D3D11_VIEWPORT v6; // [esp+4h] [ebp-1Ch] BYREF

  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  v4 = (double)*(int *)((char *)&loc_40BF4 + a2 + 4);
  qmemcpy(
    (void *)(a2 + 16),
    (const void *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 120),
    0x18u);
  v5 = *(_DWORD *)((char *)&loc_40BF4 + a2 + 4);
  v6.TopLeftX = 0.0;
  v6.TopLeftY = 0.0;
  if ( v5 < 0 )
    v4 = v4 + 4294967300.0;
  v6.Width = v4;
  v6.MinDepth = 0.0;
  v6.Height = v4;
  v6.MaxDepth = s_bm_current_air_resistance;
  vostok::render::backend::set_viewports((vostok::render::backend *)&v6, z_low, &v6, a3);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    0,
    0,
    0,
    0);
}
