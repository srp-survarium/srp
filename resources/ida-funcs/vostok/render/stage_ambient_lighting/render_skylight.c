void __usercall vostok::render::stage_ambient_lighting::render_skylight(
        vostok::render::stage_ambient_lighting *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  vostok::render::res_effect *v4; // ecx
  float v5; // xmm0_4
  vostok::render::backend *v6; // ecx
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v8; // eax
  vostok::render::system_renderer *v9; // [esp-1Ch] [ebp-44h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v10; // [esp-18h] [ebp-40h] BYREF
  vostok::render::render_target *v11; // [esp-14h] [ebp-3Ch]
  vostok::render::render_target *v12; // [esp-10h] [ebp-38h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v13; // [esp-Ch] [ebp-34h]
  const vostok::render::shader_constant_host *v14; // [esp-8h] [ebp-30h]
  int v15; // [esp-4h] [ebp-2Ch]
  float v16; // [esp+0h] [ebp-28h]
  float v17; // [esp+4h] [ebp-24h]
  float v18; // [esp+8h] [ebp-20h]
  vostok::math::float3 v19; // [esp+Ch] [ebp-1Ch] BYREF
  int v20; // [esp+18h] [ebp-10h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v21; // [esp+1Ch] [ebp-Ch]
  vostok::render::render_target *rt; // [esp+20h] [ebp-8h] BYREF
  wchar_t wszName; // [esp+27h] [ebp-1h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&wszName,
    (int)L"render_skylight");
  v3 = *(_DWORD *)(a2 + 40);
  *(_DWORD *)(v3 + 22048) = 1;
  vostok::render::res_effect::apply_pass(v4, v3);
  v5 = *(float *)(a2 + 116);
  v15 = (int)&v19;
  v14 = *(const vostok::render::shader_constant_host **)(a2 + 164);
  v19.z = v5;
  v19.x = v5;
  v19.y = v5;
  v20 = 0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v6,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v14,
    &v19);
  v15 = 1;
  v14 = 0;
  v13.m_object = 0;
  v12 = 0;
  v11 = 0;
  m_object = vostok::render::renderer_context::get_rt(
               *(vostok::render::renderer_context **)(a2 + 4),
               rt_accumulator_diffuse,
               (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt)->m_object;
  v10.m_object = (vostok::render::render_target *)vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
  v9 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
  v21.m_object = (vostok::render::render_target *)vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v10,
    m_object);
  vostok::render::system_renderer::fill_surface(
    v9,
    v21,
    v10.m_object,
    v11,
    v12,
    v13,
    (vostok::render::render_target *)v14,
    (D3D11_VIEWPORT *)v15,
    v16,
    v17,
    v18,
    v19.x);
  v8 = rt;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v8->m_reference_count )
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  D3DPERF_EndEvent();
}
