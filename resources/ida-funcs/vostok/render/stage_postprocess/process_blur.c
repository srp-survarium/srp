void __thiscall vostok::render::stage_postprocess::process_blur(
        vostok::render::stage_postprocess *this,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> rt0_index,
        vostok::render::enum_render_target_index rt1_index,
        vostok::render::res_texture *kernel_index,
        int a5)
{
  vostok::render::render_target *v6; // eax
  vostok::render::render_target *v7; // eax
  vostok::render::resource_manager *v8; // ecx
  bool v9; // zf
  vostok::render::resource_manager *v10; // ecx
  void *v11; // esp
  void *v12; // esp
  void *v13; // esp
  void *v14; // esp
  long double v15; // rdi
  vostok::render::res_pass *v16; // ecx
  void *v17; // esp
  unsigned int *v18; // eax
  int v19; // edx
  unsigned int *v20; // edi
  int v21; // eax
  vostok::render::res_pass *v22; // edi
  vostok::render::res_pass *v23; // eax
  vostok::render::res_pass *v24; // esi
  _DWORD *m_reference_count; // eax
  vostok::render::effect_manager *v26; // ecx
  vostok::render::render_target *v27; // ecx
  vostok::render::backend *v28; // ecx
  vostok::render::res_pass *v29; // ecx
  int v30; // eax
  vostok::render::res_pass *v31; // eax
  vostok::render::res_pass *v32; // esi
  _DWORD *v33; // eax
  vostok::render::res_pass *v34; // edi
  vostok::render::effect_manager *v35; // ecx
  vostok::render::render_target *v36; // ecx
  vostok::render::stage_postprocess *v37; // [esp-8h] [ebp-54h]
  vostok::render::stage_postprocess *v38; // [esp-8h] [ebp-54h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v39; // [esp-4h] [ebp-50h] BYREF
  vostok::render::effect_manager *v40; // [esp+0h] [ebp-4Ch]
  unsigned int v41[3]; // [esp+4h] [ebp-48h] BYREF
  unsigned int v42; // [esp+10h] [ebp-3Ch]
  unsigned int v43; // [esp+14h] [ebp-38h]
  unsigned int v44; // [esp+18h] [ebp-34h]
  unsigned int v45; // [esp+1Ch] [ebp-30h]
  unsigned int m_width; // [esp+20h] [ebp-2Ch]
  vostok::render::res_texture *v47; // [esp+24h] [ebp-28h]
  vostok::render::render_target *v48; // [esp+28h] [ebp-24h]
  vostok::render::res_texture *v49; // [esp+2Ch] [ebp-20h]
  vostok::math::float4 *arg; // [esp+30h] [ebp-1Ch]
  float *v51; // [esp+34h] [ebp-18h]
  float *v52; // [esp+38h] [ebp-14h]
  unsigned int *v53; // [esp+3Ch] [ebp-10h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v54; // [esp+40h] [ebp-Ch] BYREF
  vostok::render::render_target *v55; // [esp+44h] [ebp-8h] BYREF
  vostok::render::render_target *rt; // [esp+48h] [ebp-4h] BYREF
  vostok::render::render_target *m_object; // [esp+54h] [ebp+8h]
  float v58; // [esp+58h] [ebp+Ch]
  unsigned int *v59; // [esp+58h] [ebp+Ch]
  int *v60; // [esp+58h] [ebp+Ch]

  vostok::render::backend::flush_rt_shader_resources(
    (vostok::render::backend *)this,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  m_object = vostok::render::renderer_context::get_rt(
               (vostok::render::renderer_context *)rt0_index.m_object->m_name.m_pointer.m_object,
               rt1_index,
               (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt)->m_object;
  v6 = rt;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v6->m_reference_count )
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  v48 = vostok::render::renderer_context::get_rt(
          (vostok::render::renderer_context *)rt0_index.m_object->m_name.m_pointer.m_object,
          (vostok::render::enum_render_target_index)kernel_index,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v55)->m_object;
  v7 = v55;
  if ( v55 )
  {
    --v55->m_reference_count;
    if ( !v7->m_reference_count )
      vostok::render::resource_manager::release(v55, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  v49 = vostok::render::renderer_context::get_t(
          (vostok::render::renderer_context *)rt0_index.m_object->m_name.m_pointer.m_object,
          rt1_index,
          &v54)->m_object;
  if ( v54.m_object )
  {
    v9 = v54.m_object->m_reference_count-- == 1;
    if ( v9 )
      vostok::render::resource_manager::release(
        v8,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v54.m_object);
  }
  v47 = vostok::render::renderer_context::get_t(
          (vostok::render::renderer_context *)rt0_index.m_object->m_name.m_pointer.m_object,
          (vostok::render::enum_render_target_index)kernel_index,
          (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&kernel_index)->m_object;
  if ( kernel_index )
  {
    v9 = kernel_index->m_reference_count-- == 1;
    if ( v9 )
      vostok::render::resource_manager::release(
        v10,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        kernel_index);
  }
  HIDWORD(v15) = supported_kernels[a5];
  v11 = alloca(4 * HIDWORD(v15));
  arg = (vostok::math::float4 *)v41;
  v12 = alloca(4 * HIDWORD(v15));
  v53 = v41;
  v13 = alloca(4 * HIDWORD(v15));
  v51 = (float *)v41;
  v14 = alloca(4 * HIDWORD(v15));
  v52 = (float *)v41;
  v58 = (double)(unsigned int)(HIDWORD(v15) - 1) * 0.5;
  m_width = m_object->m_width;
  LODWORD(v15) = v41;
  vostok::render::get_gaussain_weights_offsets(
    (float *)v41,
    (unsigned __int64)(double)m_width,
    v15,
    (float *)v41,
    *((float *)&v15 + 1),
    v58);
  vostok::render::get_gaussain_weights_offsets(
    v52,
    (unsigned __int64)(double)m_object->m_height,
    v15,
    v51,
    *((float *)&v15 + 1),
    v58);
  v17 = alloca(16 * HIDWORD(v15));
  arg = (vostok::math::float4 *)v41;
  if ( HIDWORD(v15) )
  {
    v52 = (float *)((char *)v52 - (unsigned int)v41);
    v59 = v41;
    v16 = (vostok::render::res_pass *)((char *)v53 - (char *)v41);
    v18 = v41;
    v19 = (char *)v51 - (char *)v41;
    v51 = (float *)HIDWORD(v15);
    do
    {
      v20 = v59;
      v59 += 4;
      v42 = *(unsigned int *)((char *)v18 + (_DWORD)v16);
      v43 = *v18;
      v44 = *(unsigned int *)((char *)v18 + (_DWORD)v52);
      v45 = *(unsigned int *)((char *)v18 + v19);
      *v20++ = v42;
      *v20++ = v43;
      *v20 = v44;
      ++v18;
      v9 = v51 == (float *)1;
      v51 = (float *)((char *)v51 - 1);
      v20[1] = v45;
    }
    while ( !v9 );
  }
  v60 = (int *)&rt0_index.m_object[1].m_order + a5 + 1;
  v21 = *v60;
  v22 = 0;
  *(_DWORD *)(v21 + 22048) = 0;
  v23 = **(vostok::render::res_pass ***)(v21 + 22052);
  v24 = 0;
  if ( v23 )
  {
    v24 = v23;
    ++v23->m_reference_count;
  }
  m_reference_count = (_DWORD *)v24->m_vs.m_object->m_reference_count;
  if ( m_reference_count )
  {
    v22 = (vostok::render::res_pass *)v24->m_vs.m_object->m_reference_count;
    ++*m_reference_count;
  }
  vostok::render::res_pass::apply(v16, (int)v22);
  if ( v22 )
  {
    v9 = v22->m_reference_count-- == 1;
    if ( v9 )
      vostok::render::effect_manager::delete_pass(
        v26,
        (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
        v22);
  }
  v9 = v24->m_reference_count-- == 1;
  if ( v9 )
  {
    vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v24);
    v26 = v40;
  }
  vostok::render::backend::set_ps_texture(
    (vostok::render::backend *)v26,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_base",
    v49);
  vostok::render::backend::set_ps_constant<vostok::math::float4>(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *((const vostok::render::shader_constant_host **)&rt0_index.m_object[3].m_is_registered + 1),
    arg,
    v41[0]);
  v40 = 0;
  v39.m_object = v27;
  v37 = (vostok::render::stage_postprocess *)v27;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v39,
    v48);
  vostok::render::stage_postprocess::fill_surface(v37, rt0_index, v39.m_object, (vostok::render::render_target *)v40);
  vostok::render::backend::flush_rt_shader_resources(
    v28,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  v30 = *v60;
  *(_DWORD *)(v30 + 22048) = 1;
  v31 = *(vostok::render::res_pass **)(*(_DWORD *)(v30 + 22052) + 4);
  v32 = 0;
  if ( v31 )
  {
    v32 = v31;
    ++v31->m_reference_count;
  }
  v33 = (_DWORD *)v32->m_vs.m_object->m_reference_count;
  v34 = 0;
  if ( v33 )
  {
    v34 = (vostok::render::res_pass *)v32->m_vs.m_object->m_reference_count;
    ++*v33;
  }
  vostok::render::res_pass::apply(v29, (int)v34);
  if ( v34 )
  {
    v9 = v34->m_reference_count-- == 1;
    if ( v9 )
      vostok::render::effect_manager::delete_pass(
        v35,
        (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
        v34);
  }
  v9 = v32->m_reference_count-- == 1;
  if ( v9 )
  {
    vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v32);
    v35 = v40;
  }
  vostok::render::backend::set_ps_texture(
    (vostok::render::backend *)v35,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_base",
    v47);
  vostok::render::backend::set_ps_constant<vostok::math::float4>(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *((const vostok::render::shader_constant_host **)&rt0_index.m_object[3].m_is_registered + 1),
    arg,
    v41[0]);
  v40 = 0;
  v39.m_object = v36;
  v38 = (vostok::render::stage_postprocess *)v36;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v39,
    m_object);
  vostok::render::stage_postprocess::fill_surface(v38, rt0_index, v39.m_object, (vostok::render::render_target *)v40);
}
