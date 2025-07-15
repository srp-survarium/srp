void __thiscall vostok::render::render_output_window::render_output_window(
        vostok::render::render_output_window *this,
        vostok::render::render_output_window *window_configuration,
        survarium::flash_renderer *a3)
{
  unsigned int m_output_width; // edi
  char *p_m_targets; // edi
  unsigned int x; // ecx
  vostok::render::resource_manager *v7; // ecx
  vostok::render::res_render_output *render_output; // eax
  Scaleform::Render::D3D1x::HAL *m_HALRenderer; // eax
  float z; // esi
  vostok::render::backend *v11; // ecx
  vostok::memory::doug_lea_allocator *v12; // esi
  char *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // ecx
  char *v15; // eax
  survarium::flash_renderer *v16; // eax
  survarium::flash_renderer *v17; // ecx
  vostok::render::device *v18; // eax
  vostok::math::uint2 v19; // [esp-Ch] [ebp-2Ch]
  const char *v20; // [esp+0h] [ebp-20h]
  const char *v21; // [esp+4h] [ebp-1Ch]
  unsigned int v22; // [esp+8h] [ebp-18h]
  vostok::math::uint2 result; // [esp+10h] [ebp-10h] BYREF
  int i; // [esp+1Ch] [ebp-4h]
  vostok::render::render_target_instance *m_family; // [esp+28h] [ebp+8h]

  m_output_width = a3->m_output_width;
  vostok::resources::unmanaged_resource::unmanaged_resource(this, window_configuration, fs_iterator_class);
  window_configuration->m_window = (HWND__ *)m_output_width;
  window_configuration->__vftable = (vostok::render::render_output_window_vtbl *)&vostok::render::render_output_window::`vftable';
  vostok::render::render_output_window::get_window_client_size(
    &result,
    (HWND__ *)a3->m_output_width,
    BYTE1(a3[1].m_output_width));
  p_m_targets = (char *)&window_configuration->m_targets;
  m_family = window_configuration->m_targets.m_family;
  for ( i = 72; i >= 0; --i )
    vostok::render::render_target_instance::render_target_instance(m_family++);
  window_configuration->m_targets.m_size.y = 0;
  window_configuration->m_targets.m_memory_usage = 0;
  x = result.x;
  window_configuration->m_targets.m_size.x = 0;
  v19.y = x;
  v19.x = 1;
  vostok::render::renderer_context_targets::create_targets(
    (vostok::render::renderer_context_targets *)result.y,
    (vostok::render::enum_render_target_index)p_m_targets,
    v19,
    (DXGI_FORMAT)result.y);
  render_output = vostok::render::resource_manager::create_render_output(
                    v7,
                    (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    (HWND__ *)a3->m_output_width,
                    BYTE1(a3[1].m_output_width));
  window_configuration->m_output.m_object = 0;
  if ( render_output )
  {
    window_configuration->m_output.m_object = render_output;
    ++render_output->m_reference_count;
  }
  window_configuration->m_flash_renderer = 0;
  window_configuration->m_windowed = BYTE1(a3[1].m_output_width);
  window_configuration->m_current_size = *vostok::render::render_output_window::get_window_client_size(
                                            &result,
                                            (HWND__ *)a3->m_output_width,
                                            BYTE1(a3[1].m_output_width));
  window_configuration->m_windowed_changed = 1;
  m_HALRenderer = a3->m_HALRenderer;
  if ( m_HALRenderer )
    vostok::render::render_output_window::set_size(
      (unsigned int)m_HALRenderer,
      BYTE1(a3[1].m_output_width) == 0,
      window_configuration,
      (unsigned int)a3->m_R2dRenderer,
      BYTE1(a3[1].m_output_width) == 0,
      0,
      (bool)v20);
  if ( LOBYTE(a3[1].m_output_width) )
  {
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      window_configuration->m_targets.m_family[51].target.m_object,
      window_configuration->m_targets.m_family[50].target.m_object,
      0,
      0);
    vostok::render::backend::flush(v11, LODWORD(z));
    v12 = vostok::render::g_allocator;
    v13 = type_info::raw_name(&survarium::flash_renderer `RTTI Type Descriptor');
    v15 = vostok::memory::doug_lea_allocator::malloc_impl(v14, (int)v12, 0x10u, v13, v20, v21, v22);
    if ( v15 )
    {
      survarium::flash_renderer::flash_renderer(
        a3,
        (int)v15,
        (Scaleform::Render::D3D1x::HAL *)a3->m_output_height,
        vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context);
      v17 = v16;
    }
    else
    {
      v17 = 0;
    }
    v18 = vostok::quasi_singleton<vostok::render::device>::pinst;
    window_configuration->m_flash_renderer = v17;
    survarium::flash_renderer::on_reset_device(
      v17,
      window_configuration->m_current_size.x,
      window_configuration->m_current_size.y,
      v18->m_device,
      v18->m_context);
  }
  else
  {
    window_configuration->m_flash_renderer = 0;
  }
}
