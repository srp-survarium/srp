void __thiscall vostok::render::renderer::foreground_begin(vostok::render::renderer *this, int a2)
{
  int z_low; // eax
  float v3; // xmm0_4
  int v4; // eax
  float v5; // xmm1_4
  float v6; // xmm0_4
  const D3D11_VIEWPORT *v7; // [esp+0h] [ebp-68h]
  D3D11_VIEWPORT v8; // [esp+10h] [ebp-58h] BYREF
  vostok::math::float4x4 v9; // [esp+28h] [ebp-40h] BYREF

  if ( s_foreground_pass )
  {
    D3DPERF_BeginEvent(this, -8454144, (int)L"foreground");
    z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    v3 = *(float *)(a2 + 168);
    qmemcpy(
      (void *)a2,
      (const void *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 120),
      0x18u);
    qmemcpy((void *)&v8, (const void *)a2, sizeof(v8));
    v8.MaxDepth = v3;
    vostok::render::backend::set_viewports((vostok::render::backend *)&v8, z_low, &v8, v7);
    v4 = *(_DWORD *)(a2 + 480);
    v5 = *(float *)(a2 + 164);
    v6 = *(float *)(a2 + 160);
    qmemcpy(&v9, (const void *)(v4 + 19828), sizeof(v9));
    v9.k.z = v5 / (float)(v5 - v6);
    LODWORD(v9.c.z) = COERCE_UNSIGNED_INT(v6 * v9.k.z) ^ _mask__NegFloat_;
    vostok::render::renderer_context::push_set_p((vostok::render::renderer_context *)&v9, v4, &v9);
  }
}
