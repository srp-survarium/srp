void __userpurge vostok::render::stage_screen_space_reflections::render_forward_model(
        vostok::render::stage_screen_space_reflections *this@<ecx>,
        const vostok::math::float3 instance)
{
  float x; // ebx
  float y; // edi
  int *v4; // ecx
  int v5; // eax
  vostok::render::res_geometry *v6; // ecx
  float z; // esi
  vostok::render::backend *v8; // ecx
  const vostok::math::float4x4 *v9; // ecx
  vostok::math::float4x4 *v10; // eax
  vostok::render::backend *v11; // ecx
  vostok::render::backend *v12; // ecx
  vostok::render::environment_properties *v13; // ecx
  float v14; // esi
  vostok::render::backend *v15; // ecx
  const vostok::render::shader_constant_host **v16; // edi
  const vostok::math::float4x4 *view2shadow; // eax
  vostok::math::float4x4 *v18; // eax
  vostok::render::backend *v19; // ecx
  vostok::render::backend *v20; // ecx
  float v21; // xmm0_4
  vostok::render::backend *v22; // ecx
  const vostok::render::shader_constant_host *v23; // [esp-8h] [ebp-80h]
  const vostok::render::shader_constant_host *v24; // [esp-8h] [ebp-80h]
  vostok::math::float4x4 v25; // [esp+10h] [ebp-68h] BYREF
  float v26[3]; // [esp+50h] [ebp-28h] BYREF
  vostok::math::float3 v27; // [esp+5Ch] [ebp-1Ch] BYREF
  vostok::math::float3 v28; // [esp+68h] [ebp-10h]
  int *v29; // [esp+74h] [ebp-4h]

  y = instance.y;
  x = instance.x;
  v4 = *(int **)(LODWORD(instance.y) + 20);
  v5 = *v4;
  v29 = (int *)(*(_DWORD *)(LODWORD(instance.y) + 16) + 4);
  (*(void (__thiscall **)(int *, _DWORD))(v5 + 68))(v4, 0);
  vostok::render::renderer_context::set_w(
    *(const vostok::math::float4x4 **)(LODWORD(y) + 36),
    *(vostok::render::renderer_context **)(LODWORD(x) + 4));
  vostok::render::res_geometry::apply(v6, *v29);
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v8,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 16),
    (const vostok::math::float3 *)(*(_DWORD *)(LODWORD(x) + 4) + 20932));
  v9 = (const vostok::math::float4x4 *)(*(_DWORD *)(LODWORD(x) + 8) + 96);
  instance.x = 0.0;
  v10 = vostok::math::transpose(v9, &v25);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v11,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 20),
    (const vostok::math::float3 *)v10);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v12,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 24),
    &instance);
  v28 = *vostok::render::environment_properties::get_sun_direction(
           v13,
           *(_DWORD *)(*(_DWORD *)(LODWORD(x) + 4) + 16268) + 280,
           v26);
  v14 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  LODWORD(v27.x) = LODWORD(v28.x) ^ _mask__NegFloat_;
  LODWORD(v27.y) = LODWORD(v28.y) ^ _mask__NegFloat_;
  v23 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 32);
  LODWORD(v27.z) = LODWORD(v28.z) ^ _mask__NegFloat_;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v15,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v23,
    &v27);
  instance.x = 0.0;
  v16 = (const vostok::render::shader_constant_host **)(LODWORD(x) + 40);
  do
  {
    view2shadow = vostok::render::renderer_context::get_view2shadow(
                    *(vostok::render::renderer_context **)(LODWORD(x) + 4),
                    LODWORD(instance.x));
    v18 = vostok::math::transpose(view2shadow, &v25);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v19,
      (vostok::render::constants_handler<1> *)LODWORD(v14),
      *v16,
      (const vostok::math::float3 *)v18);
    ++LODWORD(instance.x);
    ++v16;
  }
  while ( LODWORD(instance.x) < 4 );
  if ( *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(LODWORD(x) + 4) + 16268) + 700) )
    v21 = s_bm_current_air_resistance;
  else
    v21 = 0.0;
  v24 = *(const vostok::render::shader_constant_host **)(LODWORD(x) + 28);
  instance.x = v21;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v20,
    (vostok::render::constants_handler<1> *)LODWORD(v14),
    v24,
    &instance);
  *(_DWORD *)(LODWORD(instance.y) + 32) = 0;
  vostok::render::backend::render_indexed(
    (vostok::render::backend *)LODWORD(v14),
    3 * v29[5],
    v22,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    0);
}
