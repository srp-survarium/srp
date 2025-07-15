void __thiscall vostok::render::stage_forward::execute_foreground(vostok::render::stage_forward *this)
{
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *rt; // eax
  float z; // esi
  _DWORD *v4; // eax
  int v5; // ecx
  bool v6; // zf
  vostok::render::base_scene_view *m_object; // eax
  int m_reconstruction_info_actuality_tick_high; // ecx
  vostok::render::render_surface_instance **m_reconstruction_info_actuality_tick; // eax
  vostok::render::renderer *v10; // ecx
  vostok::render::res_input_layout *v11; // ecx
  vostok::render::res_input_layout *v12; // ecx
  vostok::render::renderer *v13; // ecx
  vostok::buffer_vector<vostok::render::render_surface_instance *> v14; // [esp+Ch] [ebp-2014h] BYREF
  _BYTE v15[8192]; // [esp+18h] [ebp-2008h] BYREF
  char v16; // [esp+2018h] [ebp-8h] BYREF
  pix_event_wrapper_dx11 wszName[5]; // [esp+201Bh] [ebp-5h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)this, wszName, (int)L"execute_foreground");
  rt = vostok::render::renderer_context::get_rt(
         this->m_context,
         rt_generic_0,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&wszName[1]);
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    rt->m_object,
    0,
    0,
    0);
  v4 = *(_DWORD **)&wszName[1];
  if ( *(_DWORD *)&wszName[1] )
  {
    --**(_DWORD **)&wszName[1];
    if ( !*v4 )
    {
      vostok::render::resource_manager::release(
        *(vostok::render::render_target **)&wszName[1],
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    }
  }
  v5 = *(_DWORD *)(LODWORD(z) + 7440);
  v6 = *(_DWORD *)(LODWORD(z) + 7384) == v5;
  *(_DWORD *)(LODWORD(z) + 7384) = v5;
  *(_BYTE *)(LODWORD(z) + 117) |= !v6;
  m_object = this->m_context->m_scene_view.m_object;
  m_reconstruction_info_actuality_tick_high = HIDWORD(m_object[92].m_reconstruction_info_actuality_tick);
  m_reconstruction_info_actuality_tick = (vostok::render::render_surface_instance **)m_object[92].m_reconstruction_info_actuality_tick;
  *(_DWORD *)&wszName[1] = m_reconstruction_info_actuality_tick_high;
  v14.m_begin = (vostok::render::render_surface_instance **)v15;
  v14.m_end = (vostok::render::render_surface_instance **)v15;
  v14.m_max_end = (vostok::render::render_surface_instance **)&v16;
  vostok::buffer_vector<vostok::render::render_surface_instance *>::assign<vostok::render::render_surface_instance * *>(
    m_reconstruction_info_actuality_tick,
    (vostok::render::render_surface_instance **const *)&wszName[1],
    &v14);
  vostok::render::renderer::sort_models_by_distance(this->m_renderer, &v14);
  vostok::render::renderer::foreground_begin(v10, (int)this->m_renderer);
  vostok::render::stage_forward::render_forward_models(&v14, v11, z, this, 0, 1);
  vostok::render::stage_forward::render_forward_models(&v14, v12, z, this, 1u, 1);
  vostok::render::renderer::foreground_end(v13, (int)this->m_renderer);
  v14.m_end = v14.m_begin;
  D3DPERF_EndEvent();
}
