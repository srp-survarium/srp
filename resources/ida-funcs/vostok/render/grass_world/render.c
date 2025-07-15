void __userpurge vostok::render::grass_world::render(
        vostok::render::grass_world *this@<ecx>,
        vostok::render::scene *context,
        vostok::math::float3 *viewer_position,
        vostok::render::enum_render_stage_type stage_type,
        unsigned int tech_index,
        vostok::render::res_effect *draw_distance,
        vostok::render::res_effect *__formal,
        vostok::render::res_effect *debug_effect,
        vostok::render::grass_patch *const shadow_pass,
        const unsigned int cascade_index)
{
  vostok::render::grass_world *v11; // ecx
  vostok::particle::particle_system_instance_impl **v12; // esi
  vostok::particle::particle_system_instance_impl **v13; // edi
  void *v14; // esp
  int v15; // eax
  void *v16; // esp
  vostok::buffer_vector<vostok::render::grass_patch *> *v17; // ecx
  int v18; // eax
  vostok::render::renderer_context *v19; // edi
  vostok::particle::particle_system_instance_impl **v20; // esi
  vostok::render::sort_grass_patch_by_distance_predicate v21; // [esp+8h] [ebp-ACh]
  _DWORD v22[4]; // [esp+14h] [ebp-A0h] BYREF
  vostok::math::frustum v23; // [esp+24h] [ebp-90h] BYREF
  vostok::render::renderer_context *v24; // [esp+9Ch] [ebp-18h] BYREF
  vostok::render::renderer_context *v25; // [esp+A0h] [ebp-14h]
  _DWORD *v26; // [esp+A4h] [ebp-10h]
  vostok::render::grass_patch **__first; // [esp+A8h] [ebp-Ch] BYREF
  vostok::render::grass_patch **__last; // [esp+ACh] [ebp-8h]
  _DWORD *v29; // [esp+B0h] [ebp-4h]
  vostok::render::renderer_context *contexta; // [esp+BCh] [ebp+8h]

  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_draw_grass )
  {
    pix_event_wrapper_dx11::pix_event_wrapper_dx11(
      (pix_event_wrapper_dx11 *)this,
      (pix_event_wrapper_dx11 *)&shadow_pass + 3,
      (int)L"grass");
    if ( context->m_streaming_texture_instance_allocator.m_buffer[136] )
    {
      context->m_streaming_texture_instance_allocator.m_buffer[136] = 0;
      vostok::render::grass_world::populate(v11, context, (vostok::render::scene *)LODWORD(viewer_position[1355].y));
    }
    if ( (_BYTE)shadow_pass )
    {
      v14 = alloca(
              4
            * ((*(_DWORD *)&context->m_streaming_texture_instance_allocator.m_buffer[4]
              - *(_DWORD *)context->m_streaming_texture_instance_allocator.m_buffer)
             / 16568));
      v15 = (*(_DWORD *)&context->m_streaming_texture_instance_allocator.m_buffer[4]
           - *(_DWORD *)context->m_streaming_texture_instance_allocator.m_buffer)
          / 16568;
      v24 = (vostok::render::renderer_context *)v22;
      v25 = (vostok::render::renderer_context *)v22;
      v26 = &v22[v15];
      vostok::math::frustum::frustum(&v23, (const vostok::math::float4x4 *)&viewer_position[1679]);
      (*(void (__thiscall **)(_DWORD, int, vostok::math::frustum *, vostok::render::renderer_context **))(**(_DWORD **)&context->m_streaming_texture_instance_allocator.m_buffer[120] + 28))(
        *(_DWORD *)&context->m_streaming_texture_instance_allocator.m_buffer[120],
        -1,
        &v23,
        &v24);
      v16 = alloca(
              4
            * ((*(_DWORD *)&context->m_streaming_texture_instance_allocator.m_buffer[4]
              - *(_DWORD *)context->m_streaming_texture_instance_allocator.m_buffer)
             / 16568));
      v17 = (vostok::buffer_vector<vostok::render::grass_patch *> *)v22;
      v18 = (*(_DWORD *)&context->m_streaming_texture_instance_allocator.m_buffer[4]
           - *(_DWORD *)context->m_streaming_texture_instance_allocator.m_buffer)
          / 16568;
      v19 = v24;
      __first = (vostok::render::grass_patch **)v22;
      __last = (vostok::render::grass_patch **)v22;
      v29 = &v22[v18];
      for ( contexta = v25; v19 != contexta; v19 = (vostok::render::renderer_context *)((char *)v19 + 4) )
      {
        shadow_pass = *(vostok::render::grass_patch *const *)&v19->m_targets->m_family[0].orig_name.m_buffer[24];
        vostok::buffer_vector<vostok::render::grass_patch *>::push_back(
          v17,
          (int)&__first,
          (vostok::render::grass_patch **)&shadow_pass);
      }
      if ( s_use_grass_patches_sorting_value )
      {
        v21.m_view_pos.x = *(float *)stage_type;
        *(_QWORD *)&v21.m_view_pos.elements[1] = *(_QWORD *)(stage_type + 4);
        stlp_std::sort<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_by_distance_predicate>(
          __first,
          __last,
          v21);
      }
      v20 = (vostok::particle::particle_system_instance_impl **)__first;
      if ( s_draw_grass_debug_value_0 )
      {
        while ( v20 != (vostok::particle::particle_system_instance_impl **)__last )
          vostok::render::grass_patch::render(
            (vostok::render::grass_patch *)v17,
            *v20++,
            (vostok::render::renderer_context *)context,
            (vostok::render::renderer_context *)viewer_position,
            (const vostok::math::float3 *)stage_type,
            tech_index,
            draw_distance,
            __formal,
            (int)debug_effect);
      }
    }
    else
    {
      v12 = *(vostok::particle::particle_system_instance_impl ***)&context->m_streaming_texture_instance_allocator.m_buffer[12];
      v13 = *(vostok::particle::particle_system_instance_impl ***)&context->m_streaming_texture_instance_allocator.m_buffer[16];
      while ( v12 != v13 )
        vostok::render::grass_patch::render(
          (vostok::render::grass_patch *)v11,
          *v12++,
          (vostok::render::renderer_context *)context,
          (vostok::render::renderer_context *)viewer_position,
          (const vostok::math::float3 *)stage_type,
          tech_index,
          draw_distance,
          __formal,
          (int)debug_effect);
    }
    D3DPERF_EndEvent();
  }
}
