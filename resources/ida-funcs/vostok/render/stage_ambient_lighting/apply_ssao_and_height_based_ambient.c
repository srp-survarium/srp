void __usercall vostok::render::stage_ambient_lighting::apply_ssao_and_height_based_ambient(
        vostok::render::stage_ambient_lighting *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  int v4; // ebx
  bool v5; // zf
  vostok::render::backend *v6; // ecx
  float z; // esi
  unsigned int v8; // xmm0_4
  unsigned int v9; // xmm1_4
  float v10; // xmm2_4
  vostok::render::backend *v11; // ecx
  float v12; // xmm0_4
  vostok::render::backend *v13; // ecx
  float v14; // xmm0_4
  vostok::render::backend *v15; // ecx
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v17; // eax
  vostok::render::system_renderer *v18; // [esp-1Ch] [ebp-44h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v19; // [esp-18h] [ebp-40h] BYREF
  vostok::render::render_target *v20; // [esp-14h] [ebp-3Ch]
  vostok::render::render_target *v21; // [esp-10h] [ebp-38h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v22; // [esp-Ch] [ebp-34h]
  const vostok::render::shader_constant_host *v23; // [esp-8h] [ebp-30h]
  int v24; // [esp-4h] [ebp-2Ch]
  float v25; // [esp+0h] [ebp-28h]
  float v26; // [esp+4h] [ebp-24h]
  float v27; // [esp+8h] [ebp-20h]
  vostok::math::float3 v28; // [esp+Ch] [ebp-1Ch] BYREF
  int v29; // [esp+18h] [ebp-10h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v30; // [esp+1Ch] [ebp-Ch]
  vostok::render::render_target *rt; // [esp+20h] [ebp-8h] BYREF
  wchar_t wszName; // [esp+27h] [ebp-1h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&wszName,
    (int)L"apply_ssao_and_height_based_ambient");
  v3 = *(_DWORD *)(a2 + 4);
  v4 = *(_DWORD *)(v3 + 16268);
  v5 = *(_BYTE *)(v4 + 652) == 0;
  rt = (vostok::render::render_target *)(v3 + 20932);
  vostok::render::res_effect::apply((vostok::render::res_effect *)!v5, *(_DWORD *)(a2 + 108));
  if ( *(_BYTE *)(v4 + 652) )
  {
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v6,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *(const vostok::render::shader_constant_host **)(a2 + 132),
      (const vostok::math::float3 *)rt);
    v8 = *(_DWORD *)(v4 + 688);
    v9 = *(_DWORD *)(v4 + 692);
    v10 = *(float *)(v4 + 696);
    v24 = (int)&v28;
    v23 = *(const vostok::render::shader_constant_host **)(a2 + 136);
    *(_QWORD *)&v28.x = __PAIR64__(v9, v8);
    v28.z = v10;
    v29 = 0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v11,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      v23,
      &v28);
    *(_QWORD *)&v28.x = *(_QWORD *)(v4 + 656);
    v12 = *(float *)(v4 + 664);
    v24 = (int)&v28;
    v23 = *(const vostok::render::shader_constant_host **)(a2 + 140);
    v28.z = v12;
    v29 = 0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v13,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      v23,
      &v28);
    *(_QWORD *)&v28.x = *(_QWORD *)(v4 + 672);
    v14 = *(float *)(v4 + 680);
    v24 = (int)&v28;
    v23 = *(const vostok::render::shader_constant_host **)(a2 + 144);
    v28.z = v14;
    v29 = 0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v15,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      v23,
      &v28);
  }
  v24 = 1;
  v23 = 0;
  v22.m_object = 0;
  v21 = 0;
  v20 = 0;
  m_object = vostok::render::renderer_context::get_rt(
               *(vostok::render::renderer_context **)(a2 + 4),
               rt_accumulator_diffuse,
               (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt)->m_object;
  v19.m_object = (vostok::render::render_target *)vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
  v18 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
  v30.m_object = (vostok::render::render_target *)vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v19,
    m_object);
  vostok::render::system_renderer::fill_surface(
    v18,
    v30,
    v19.m_object,
    v20,
    v21,
    v22,
    (vostok::render::render_target *)v23,
    (D3D11_VIEWPORT *)v24,
    v25,
    v26,
    v27,
    v28.x);
  v17 = rt;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v17->m_reference_count )
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  D3DPERF_EndEvent();
}
