void __userpurge vostok::render::hw_hiz_occlusion_manager::process_culling(
        vostok::render::hw_hiz_occlusion_manager *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> a2@<esi>,
        vostok::math::float4 *in_context,
        const vostok::math::float4 *in_bounds,
        unsigned int in_num_bounds_and_results)
{
  vostok::render::hw_hiz_occlusion_manager *v5; // ecx
  vostok::render::hw_hiz_occlusion_manager *v6; // ecx
  vostok::render::hw_hiz_occlusion_manager *v7; // ecx
  float z; // eax

  if ( !s_hiz0 )
  {
    pix_event_wrapper_dx11::pix_event_wrapper_dx11(
      (pix_event_wrapper_dx11 *)this,
      (pix_event_wrapper_dx11 *)&in_num_bounds_and_results + 3,
      (int)L"hw_hiz_occlusion_manager_process_culling");
    if ( in_num_bounds_and_results )
    {
      if ( a2.m_object->m_reference_count )
      {
        *(_BYTE *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7432) = 0;
        vostok::render::hw_hiz_occlusion_manager::copy_scene_depth(v5);
        vostok::render::hw_hiz_occlusion_manager::downsample_occlusion_buffer(v6, a2);
        vostok::render::hw_hiz_occlusion_manager::render_model_bounds(
          v7,
          (vostok::render::renderer_context *)a2.m_object,
          (vostok::render::renderer_context *)in_context,
          (unsigned int)in_bounds,
          in_num_bounds_and_results);
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context->CopyResource(
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
          *(ID3D11Resource **)(*(_DWORD *)&a2.m_object->m_name.m_string.m_buffer[100] + 440),
          *(ID3D11Resource **)(*(_DWORD *)&a2.m_object->m_name.m_string.m_buffer[96] + 440));
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        a2.m_object->m_name.m_string.m_buffer[52] = 0;
        *(_BYTE *)(LODWORD(z) + 7432) = 1;
      }
    }
    D3DPERF_EndEvent();
  }
}
