void __userpurge vostok::render::stage_postprocess::measure_per_pixel_luminance(
        vostok::render::stage_postprocess *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> a2@<edi>,
        vostok::render::enum_render_target_index scene_texture,
        vostok::math::float4 *out_avrg_min_max)
{
  unsigned int m_memory_usage; // eax
  vostok::render::backend *v5; // ecx
  vostok::render::render_target *v6; // ecx
  vostok::render::stage_postprocess *v7; // ecx
  vostok::render::res_pass *v8; // ecx
  unsigned int v9; // eax
  vostok::render::res_pass *v10; // esi
  vostok::render::res_pass **v11; // eax
  vostok::render::res_pass *v12; // eax
  _DWORD *m_reference_count; // eax
  vostok::render::res_pass *v14; // ebx
  vostok::render::effect_manager *v15; // ecx
  bool v16; // zf
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *t; // eax
  vostok::render::backend *v18; // ecx
  vostok::render::resource_manager *v19; // ecx
  vostok::render::stage_postprocess *v20; // ecx
  int m_order; // eax
  vostok::render::res_pass *v22; // eax
  vostok::render::res_pass *v23; // esi
  _DWORD *v24; // eax
  vostok::render::res_pass *v25; // ebx
  vostok::render::effect_manager *v26; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v27; // eax
  vostok::render::backend *v28; // ecx
  vostok::render::resource_manager *v29; // ecx
  vostok::render::stage_postprocess *v30; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v31[3]; // [esp-4h] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v32; // [esp+8h] [ebp-4h] BYREF

  m_memory_usage = a2.m_object[1].m_memory_usage;
  *(_DWORD *)(m_memory_usage + 22048) = 0;
  vostok::render::res_effect::apply_pass((vostok::render::res_effect *)this, m_memory_usage);
  vostok::render::backend::set_ps_texture(
    v5,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_frame_color0",
    (vostok::render::res_texture *)scene_texture);
  v31[0].m_object = v6;
  vostok::render::renderer_context::get_rt(
    (vostok::render::renderer_context *)a2.m_object->m_name.m_pointer.m_object,
    rt_frame_luminance8,
    v31);
  vostok::render::stage_postprocess::fill_surface2(v7, a2, v31[0].m_object);
  for ( scene_texture = rt_frame_luminance7; scene_texture >= rt_frame_luminance0; --scene_texture )
  {
    v9 = a2.m_object[1].m_memory_usage;
    v10 = 0;
    if ( scene_texture == rt_frame_luminance0 )
    {
      *(_DWORD *)(v9 + 22048) = 2;
      v11 = (vostok::render::res_pass **)(*(_DWORD *)(v9 + 22052) + 8);
    }
    else
    {
      *(_DWORD *)(v9 + 22048) = 1;
      v11 = (vostok::render::res_pass **)(*(_DWORD *)(v9 + 22052) + 4);
    }
    v12 = *v11;
    if ( v12 )
    {
      v10 = v12;
      ++v12->m_reference_count;
    }
    m_reference_count = (_DWORD *)v10->m_vs.m_object->m_reference_count;
    v14 = 0;
    if ( m_reference_count )
    {
      v14 = (vostok::render::res_pass *)v10->m_vs.m_object->m_reference_count;
      ++*m_reference_count;
    }
    vostok::render::res_pass::apply(v8, (int)v14);
    if ( v14 )
    {
      v16 = v14->m_reference_count-- == 1;
      if ( v16 )
        vostok::render::effect_manager::delete_pass(
          v15,
          (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
          v14);
    }
    v16 = v10->m_reference_count-- == 1;
    if ( v16 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v10);
    t = vostok::render::renderer_context::get_t(
          (vostok::render::renderer_context *)a2.m_object->m_name.m_pointer.m_object,
          (vostok::render::enum_render_target_index)(scene_texture + 1),
          &v32);
    vostok::render::backend::set_ps_texture(
      v18,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_frame_color1",
      t->m_object);
    if ( v32.m_object )
    {
      v16 = v32.m_object->m_reference_count-- == 1;
      if ( v16 )
        vostok::render::resource_manager::release(
          v19,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v32.m_object);
    }
    v31[0].m_object = (vostok::render::render_target *)v19;
    vostok::render::renderer_context::get_rt(
      (vostok::render::renderer_context *)a2.m_object->m_name.m_pointer.m_object,
      scene_texture,
      v31);
    vostok::render::stage_postprocess::fill_surface2(v20, a2, v31[0].m_object);
  }
  scene_texture = *(_DWORD *)(a2.m_object->m_name.m_pointer.m_object[1016].m_checksum + 772) & 0x7FFFFFFF;
  if ( *(float *)&scene_texture < 0.050000001 )
  {
    m_order = a2.m_object[1].m_order;
    *(_DWORD *)(m_order + 22048) = 1;
    v22 = *(vostok::render::res_pass **)(*(_DWORD *)(m_order + 22052) + 4);
    v23 = 0;
    if ( v22 )
    {
      v23 = v22;
      ++v22->m_reference_count;
    }
    v24 = (_DWORD *)v23->m_vs.m_object->m_reference_count;
    v25 = 0;
    if ( v24 )
    {
      v25 = (vostok::render::res_pass *)v23->m_vs.m_object->m_reference_count;
      ++*v24;
    }
    vostok::render::res_pass::apply(v8, (int)v25);
    if ( v25 )
    {
      v16 = v25->m_reference_count-- == 1;
      if ( v16 )
        vostok::render::effect_manager::delete_pass(
          v26,
          (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
          v25);
    }
    v16 = v23->m_reference_count-- == 1;
    if ( v16 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v23);
    v27 = vostok::render::renderer_context::get_t(
            (vostok::render::renderer_context *)a2.m_object->m_name.m_pointer.m_object,
            rt_frame_luminance0,
            (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&scene_texture);
    vostok::render::backend::set_ps_texture(
      v28,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_luminance",
      v27->m_object);
    if ( *(float *)&scene_texture != 0.0 )
    {
      v16 = (*(_DWORD *)(scene_texture + 4))-- == 1;
      if ( v16 )
        vostok::render::resource_manager::release(
          v29,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_texture *)scene_texture);
    }
    v31[0].m_object = (vostok::render::render_target *)v29;
    vostok::render::renderer_context::get_rt(
      (vostok::render::renderer_context *)a2.m_object->m_name.m_pointer.m_object,
      rt_frame_luminance_current,
      v31);
    vostok::render::stage_postprocess::fill_surface2(v30, a2, v31[0].m_object);
  }
}
