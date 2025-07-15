void __thiscall vostok::render::renderer_context::set_static_frame_parameters(
        vostok::render::renderer_context *this,
        int a2)
{
  int v3; // eax
  int v4; // eax
  float v5; // xmm0_4
  int v6; // xmm1_4
  vostok::math::float3 *sun_direction; // eax
  float v8; // xmm0_4
  float z; // esi
  vostok::render::backend *v10; // ecx
  vostok::render::backend *v11; // ecx
  vostok::render::backend *v12; // ecx
  vostok::render::backend *v13; // ecx
  vostok::render::backend *v14; // ecx
  vostok::render::backend *v15; // ecx
  int v16; // [esp+10h] [ebp-2Ch]
  int v17; // [esp+10h] [ebp-2Ch]
  int v18; // [esp+10h] [ebp-2Ch]
  float v19; // [esp+14h] [ebp-28h] BYREF
  int v20; // [esp+18h] [ebp-24h]
  float v21; // [esp+1Ch] [ebp-20h]
  float v22; // [esp+20h] [ebp-1Ch]
  float v23; // [esp+24h] [ebp-18h]
  float v24; // [esp+28h] [ebp-14h]
  float v25; // [esp+2Ch] [ebp-10h]
  float v26; // [esp+30h] [ebp-Ch]
  float v27; // [esp+34h] [ebp-8h]
  float *v28; // [esp+44h] [ebp+8h]

  v3 = *(_DWORD *)(a2 + 16268);
  if ( v3 )
  {
    v4 = v3 + 280;
    v16 = *(_DWORD *)(v4 + 284);
    v19 = *(float *)(v4 + 288);
    v20 = *(_DWORD *)(v4 + 292);
    v21 = *(float *)(v4 + 308);
    v5 = epsilon_3_4;
    *(_DWORD *)(a2 + 21004) = v16;
    *(float *)(a2 + 21008) = v19;
    *(_DWORD *)(a2 + 21012) = v20;
    *(float *)(a2 + 21016) = v21;
    v28 = (float *)v4;
    if ( *(float *)(v4 + 344) > 0.001 )
      v5 = *(float *)(v4 + 344);
    v6 = *(_DWORD *)(v4 + 304);
    v21 = v5;
    v19 = *(float *)(v4 + 300);
    v20 = *(_DWORD *)(v4 + 340);
    *(_DWORD *)(a2 + 21020) = v6;
    *(float *)(a2 + 21024) = v19;
    *(_DWORD *)(a2 + 21028) = v20;
    *(float *)(a2 + 21032) = v21;
    v17 = *(_DWORD *)(v4 + 312);
    v19 = *(float *)(v4 + 316);
    v20 = *(_DWORD *)(v4 + 320);
    v21 = *(float *)(v4 + 336);
    *(_DWORD *)(a2 + 21036) = v17;
    *(float *)(a2 + 21040) = v19;
    *(_DWORD *)(a2 + 21044) = v20;
    *(float *)(a2 + 21048) = v21;
    v18 = *(_DWORD *)(v4 + 328);
    v19 = s_bm_current_air_resistance / *(float *)(v4 + 348);
    v20 = 0;
    v21 = 0.0;
    *(_DWORD *)(a2 + 21052) = v18;
    *(float *)(a2 + 21056) = v19;
    *(_DWORD *)(a2 + 21060) = v20;
    *(float *)(a2 + 21064) = v21;
    sun_direction = vostok::render::environment_properties::get_sun_direction(
                      (vostok::render::environment_properties *)(v4 + 312),
                      v4,
                      &v19);
    LODWORD(v25) = LODWORD(sun_direction->x) ^ _mask__NegFloat_;
    LODWORD(v26) = LODWORD(sun_direction->y) ^ _mask__NegFloat_;
    LODWORD(v27) = LODWORD(sun_direction->z) ^ _mask__NegFloat_;
    *(float *)(a2 + 20980) = v25;
    *(float *)(a2 + 20984) = v26;
    *(float *)(a2 + 20988) = v27;
    v8 = v28[17];
    v25 = v28[18];
    v26 = v28[19];
    v27 = v28[20];
    v22 = v8 * v25;
    v23 = v8 * v26;
    v24 = v8 * v27;
    *(float *)(a2 + 20992) = v8 * v25;
    *(float *)(a2 + 20996) = v23;
    *(float *)(a2 + 21000) = v24;
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *(const vostok::render::shader_constant_host **)(a2 + 21212),
      (const unsigned int *)(a2 + 20992));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v10,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(a2 + 21212),
      (const vostok::math::float3 *)(a2 + 20992));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v11,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(a2 + 21208),
      (const vostok::math::float3 *)(a2 + 20980));
    vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
      (vostok::render::backend *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(a2 + 21208),
      (const unsigned int *)(a2 + 20980));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v12,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(a2 + 21204),
      (const vostok::math::float3 *)(a2 + 21004));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v13,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(a2 + 21216),
      (const vostok::math::float3 *)(a2 + 21020));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v14,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(a2 + 21220),
      (const vostok::math::float3 *)(a2 + 21036));
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v15,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(a2 + 21224),
      (const vostok::math::float3 *)(a2 + 21052));
    vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
      (vostok::render::backend *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(a2 + 21204),
      (const unsigned int *)(a2 + 21004));
    vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
      (vostok::render::backend *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(a2 + 21216),
      (const unsigned int *)(a2 + 21020));
    vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
      (vostok::render::backend *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(a2 + 21220),
      (const unsigned int *)(a2 + 21036));
    vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
      (vostok::render::backend *)LODWORD(z),
      *(const vostok::render::shader_constant_host **)(a2 + 21224),
      (const unsigned int *)(a2 + 21052));
  }
}
