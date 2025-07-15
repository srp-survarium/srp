void __usercall vostok::render::stage_shadow_direct::end_depth_accumulation(
        vostok::render::stage_shadow_direct *this@<ecx>,
        int a2@<eax>)
{
  int z_low; // esi
  vostok::render::backend *v4; // ecx
  bool v5; // zf
  const D3D11_VIEWPORT *v6; // [esp+0h] [ebp-8h]

  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::reset_render_targets(
    (vostok::render::backend *)this,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  v4 = *(vostok::render::backend **)(z_low + 7440);
  v5 = *(_DWORD *)(z_low + 7384) == (_DWORD)v4;
  *(_DWORD *)(z_low + 7384) = v4;
  *(_BYTE *)(z_low + 117) |= !v5;
  *((_BYTE *)&loc_40C7F + a2 + 1) = 0;
  vostok::render::backend::set_viewports(v4, z_low, (const D3D11_VIEWPORT *)(a2 + 16), v6);
}
