void __userpurge vostok::render::scene::flush(
        vostok::render::scene *this@<ecx>,
        int a2@<esi>,
        boost::function<void __cdecl(bool)> *on_draw_scene,
        bool all_depth_used,
        bool all_depth_unused)
{
  boost::detail::function::vtable_base *v5; // edi
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v6; // ecx
  vostok::render::scene *v7; // ecx
  vostok::render::scene *v8; // ecx
  int z_low; // eax
  vostok::render::untyped_buffer *v10; // edi
  vostok::render::backend *v11; // ecx
  vostok::render::system_renderer *v12; // ecx
  vostok::render::system_renderer *v13; // ecx
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v14; // ecx
  vostok::render::scene *v15; // ecx
  vostok::render::scene *v16; // ecx
  float v17; // [esp+0h] [ebp-8h]
  unsigned __int8 v18; // [esp+4h] [ebp-4h]

  if ( all_depth_used )
  {
    v5 = *(boost::detail::function::vtable_base **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                                  + 7440);
    v6 = (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384);
    *(_BYTE *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 117) |= *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) != (_DWORD)v5;
    v6->vtable = v5;
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      v6,
      on_draw_scene,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)1);
    vostok::render::scene::render_lines(v7, a2, 0);
    vostok::render::scene::render_triangles(v8, a2, 0);
  }
  if ( all_depth_unused )
  {
    z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    v10 = *(vostok::render::untyped_buffer **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                             + 7440);
    v11 = (vostok::render::backend *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                    + 7384);
    *(_BYTE *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 117) |= *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) != (_DWORD)v10;
    v11->vertex_small.m_buffer.m_object = v10;
    vostok::render::backend::clear_depth_stencil(v11, z_low, 3u, v17, v18);
    vostok::render::system_renderer::draw_render_models_selection(
      (vostok::fixed_vector<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base>,2048> *)((char *)&vostok::memory::s_resources.m_buffer[4182] + a2),
      v12,
      vostok::quasi_singleton<vostok::render::system_renderer>::pinst);
    vostok::render::system_renderer::draw_particle_system_instance_selections(
      v13,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
      (int)&vostok::memory::s_resources.m_buffer[6233] + a2);
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(v14, on_draw_scene, 0);
    vostok::render::scene::render_lines(v15, a2, 1);
    vostok::render::scene::render_triangles(v16, a2, 1);
  }
}
