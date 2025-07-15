void __thiscall vostok::render::stage_shadow_direct::flush_cascade_cache(
        vostok::render::stage_shadow_direct *this,
        const unsigned int cascade_index,
        int a3)
{
  int z_low; // esi
  vostok::render::backend *v4; // ecx
  int v5; // esi
  vostok::render::backend *v6; // ecx
  int v7; // eax
  _DWORD *v8; // eax
  float v9; // [esp+0h] [ebp-18h]
  float v10; // [esp+0h] [ebp-18h]
  unsigned __int8 v11; // [esp+4h] [ebp-14h]
  unsigned __int8 v12; // [esp+4h] [ebp-14h]

  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::set_depth_stencil_target(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *(const vostok::render::render_target **)((char *)&loc_40BF9 + 4 * a3 + cascade_index + 3));
  vostok::render::backend::clear_depth_stencil(v4, z_low, 1u, v9, v11);
  v5 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::set_depth_stencil_target(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *(const vostok::render::render_target **)((char *)&loc_40C0C + 4 * a3 + cascade_index));
  vostok::render::backend::clear_depth_stencil(v6, v5, 1u, v10, v12);
  v7 = 12 * a3 + cascade_index;
  *(_DWORD *)((char *)&loc_40C1A + v7 + 2) = 0;
  *(_DWORD *)((char *)&loc_40C1A + v7 + 6) = 0;
  *(_DWORD *)((char *)&loc_40C1A + v7 + 10) = 0;
  *(_DWORD *)((char *)&loc_40C4C + v7) = 0;
  *(_DWORD *)((char *)&loc_40C4C + v7 + 4) = 0;
  *(_DWORD *)((char *)&loc_40C4C + v7 + 8) = 0;
  v8 = (_DWORD *)(cascade_index + 16396 * a3);
  v8[38] = v8[37];
  v8[16434] = v8[16433];
  v8[32830] = v8[32829];
  v8[49226] = v8[49225];
  *((_BYTE *)&loc_40C7C + a3 + cascade_index) = 1;
}
