void __thiscall vostok::render::stage_accumulate_distortion::execute(vostok::render::stage_accumulate_distortion *this)
{
  vostok::render::renderer_context *m_context; // eax
  vostok::render::renderer_context *v3; // eax
  int *m_object; // ecx
  int v5; // edx
  void (__thiscall *v6)(int *, int, vostok::vectora<vostok::particle::render_particle_emitter_instance *> *); // eax
  int y; // eax
  vostok::render::render_target *v8; // eax
  vostok::render::render_target *v9; // ecx
  bool v10; // zf
  vostok::render::render_target *v11; // eax
  vostok::render::resource_manager *v12; // ecx
  vostok::render::render_target *v13; // eax
  vostok::render::render_target *v14; // edi
  vostok::render::render_target *v15; // eax
  vostok::render::resource_manager *v16; // ecx
  ID3D11RenderTargetView *m_rt; // eax
  vostok::render::backend *m_conflicted_key_name; // esi
  ID3D11RenderTargetView *v19; // eax
  int v20; // eax
  vostok::render::backend *v21; // ecx
  vostok::render::backend *v22; // eax
  int v23; // esi
  vostok::render::renderer_context *v24; // edx
  vostok::render::render_surface_instance **v25; // ecx
  vostok::render::render_surface_instance *v26; // eax
  vostok::render::render_model_instance_impl *m_parent; // edx
  void **M_start; // eax
  vostok::render::render_surface_instance **v29; // edx
  vostok::render::render_surface_instance *v30; // edi
  unsigned int m_size; // eax
  vostok::render::material_effects *material_effects; // eax
  vostok::render::renderer_context *v33; // esi
  vostok::math::float3 *v34; // ebp
  vostok::math::float3 *v35; // eax
  const vostok::math::float4x4 *m_transform; // edx
  __int64 v37; // xmm0_8
  __int64 v38; // xmm0_8
  vostok::particle::enum_particle_locked_axis z_low; // ecx
  int v40; // esi
  float z; // edx
  __int64 v42; // xmm0_8
  float v43; // eax
  int v44; // ecx
  vostok::render::render_surface_instance **v45; // edx
  vostok::render::render_surface *m_render_surface; // esi
  vostok::render::material_effects_instance *v47; // eax
  vostok::render::material_effects *p_m_material_effects; // edi
  _DWORD *v49; // eax
  int v50; // ecx
  const char *v51; // edi
  unsigned int v52; // ebp
  bool v53; // al
  const char *v54; // esi
  const char *v55; // esi
  vostok::render::backend *v56; // ecx
  int v57; // eax
  const vostok::math::float4x4 *v58; // eax
  int v59; // ecx
  char *v60; // eax
  vostok::render::grass_render_model *v61; // ecx
  vostok::math::float3 v62; // [esp+0h] [ebp-F0h] BYREF
  vostok::math::float3 v63; // [esp+Ch] [ebp-E4h]
  vostok::math::float3 v64; // [esp+18h] [ebp-D8h]
  vostok::particle::enum_particle_locked_axis locked_axis; // [esp+24h] [ebp-CCh]
  int g; // [esp+28h] [ebp-C8h]
  vostok::vectora<vostok::particle::render_particle_emitter_instance *> *time; // [esp+2Ch] [ebp-C4h]
  bool need_execute; // [esp+43h] [ebp-ADh]
  vostok::render::render_surface_instance **it_d; // [esp+44h] [ebp-ACh] BYREF
  vostok::render::render_surface_instance *const *end_d; // [esp+48h] [ebp-A8h]
  vostok::vectora<vostok::particle::render_particle_emitter_instance *> emitters; // [esp+4Ch] [ebp-A4h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> m_dynamic_visuals; // [esp+5Ch] [ebp-94h] BYREF
  vostok::math::float3_pod v73; // [esp+68h] [ebp-88h] BYREF
  vostok::math::float3_pod v74; // [esp+74h] [ebp-7Ch] BYREF
  D3D11_VIEWPORT view_port; // [esp+80h] [ebp-70h] BYREF
  D3D11_VIEWPORT prev_view_port; // [esp+98h] [ebp-58h] BYREF
  vostok::math::float4x4 v77; // [esp+B0h] [ebp-40h] BYREF

  if ( this->is_enabled(this) )
  {
    m_context = this->m_context;
    time = 0;
    g = 1;
    memset(&m_dynamic_visuals, 0, sizeof(m_dynamic_visuals));
    vostok::render::scene::select_models(
      &m_dynamic_visuals,
      m_context->m_scene,
      &m_context->m_vp,
      (vostok::render::culling::portal_sector_system *)&m_context->m_view_pos,
      1u,
      0);
    need_execute = (((char *)m_dynamic_visuals._M_impl._M_finish - (char *)m_dynamic_visuals._M_impl._M_start)
                  & 0xFFFFFFFC) != 0;
    v3 = this->m_context;
    m_object = (int *)v3->m_scene->m_particle_world.m_object;
    if ( m_object )
    {
      emitters._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object;
      v5 = *m_object;
      time = &emitters;
      g = (int)&v3->m_vp;
      v6 = *(void (__thiscall **)(int *, int, vostok::vectora<vostok::particle::render_particle_emitter_instance *> *))(v5 + 36);
      emitters._M_impl._M_start = 0;
      emitters._M_impl._M_finish = 0;
      emitters._M_impl._M_end_of_storage._M_data = 0;
      v6(m_object, g, &emitters);
      if ( (((char *)emitters._M_impl._M_finish - (char *)emitters._M_impl._M_start) & 0xFFFFFFFC) != 0 )
        need_execute = 1;
      if ( emitters._M_impl._M_start )
        emitters._M_impl._M_end_of_storage.m_allocator->call_free(
          emitters._M_impl._M_end_of_storage.m_allocator,
          emitters._M_impl._M_start);
    }
    if ( need_execute )
    {
      y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
      it_d = (vostok::render::render_surface_instance **)1;
      (*(void (__stdcall **)(int, vostok::render::render_surface_instance ***, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(
        y,
        &it_d,
        &prev_view_port);
      v8 = this->m_context->m_targets->m_family[14].target.m_object;
      v9 = 0;
      if ( v8 )
      {
        v9 = this->m_context->m_targets->m_family[14].target.m_object;
        ++v8->m_reference_count;
      }
      view_port.Width = (float)v9->m_width;
      v10 = v9->m_reference_count-- == 1;
      if ( v10 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)v9,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v9);
      v11 = this->m_context->m_targets->m_family[14].target.m_object;
      v12 = 0;
      if ( v11 )
      {
        v12 = (vostok::render::resource_manager *)this->m_context->m_targets->m_family[14].target.m_object;
        ++v11->m_reference_count;
      }
      view_port.Height = (float)LODWORD(v12->m_num_bytes_of_texture_video_memory);
      v10 = v12->sh_created-- == 1;
      if ( v10 )
        vostok::render::resource_manager::release(
          v12,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v12);
      view_port.MinDepth = 0.0;
      LODWORD(view_port.MaxDepth) = clear_value;
      view_port.TopLeftX = 0.0;
      view_port.TopLeftY = 0.0;
      (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                        + 176))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        1,
        &view_port);
      v13 = this->m_context->m_targets->m_family[15].target.m_object;
      v14 = 0;
      if ( v13 )
      {
        v14 = this->m_context->m_targets->m_family[15].target.m_object;
        ++v13->m_reference_count;
      }
      v15 = this->m_context->m_targets->m_family[14].target.m_object;
      v16 = 0;
      if ( v15 )
      {
        v16 = (vostok::render::resource_manager *)this->m_context->m_targets->m_family[14].target.m_object;
        ++v15->m_reference_count;
        m_rt = v15->m_rt;
      }
      else
      {
        m_rt = 0;
      }
      m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
           + 535) != m_rt )
      {
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
        m_conflicted_key_name->m_dirty_targets.render_targets[0] = 1;
      }
      if ( v14 )
        v19 = v14->m_rt;
      else
        v19 = 0;
      if ( m_conflicted_key_name->m_targets[1] != v19 )
      {
        m_conflicted_key_name->m_targets[1] = v19;
        m_conflicted_key_name->m_dirty_targets.render_targets[1] = 1;
      }
      if ( m_conflicted_key_name->m_targets[2] )
      {
        m_conflicted_key_name->m_targets[2] = 0;
        m_conflicted_key_name->m_dirty_targets.render_targets[2] = 1;
      }
      if ( m_conflicted_key_name->m_targets[3] )
      {
        m_conflicted_key_name->m_targets[3] = 0;
        m_conflicted_key_name->m_dirty_targets.render_targets[3] = 1;
      }
      if ( v16 )
      {
        v10 = v16->sh_created-- == 1;
        if ( v10 )
        {
          vostok::render::resource_manager::release(
            v16,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (const char *)v16);
          m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        }
      }
      if ( v14 )
      {
        v10 = v14->m_reference_count-- == 1;
        if ( v10 )
        {
          vostok::render::resource_manager::release(
            v16,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (const char *)v14);
          m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        }
      }
      v20 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 0.0);
      vostok::render::backend::clear_render_targets(v21, m_conflicted_key_name, (vostok::math::color)v20);
      v22 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v23 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 547);
      v10 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == v23;
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = v23;
      v22->m_dirty_targets.depth_stencil |= !v10;
      v24 = this->m_context;
      v25 = (vostok::render::render_surface_instance **)v24->m_scene->m_particle_world.m_object;
      if ( v25 )
      {
        emitters._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object;
        v26 = *v25;
        time = &emitters;
        g = (int)&v24->m_vp;
        m_parent = v26[1].m_parent;
        emitters._M_impl._M_start = 0;
        emitters._M_impl._M_finish = 0;
        emitters._M_impl._M_end_of_storage._M_data = 0;
        ((void (__thiscall *)(vostok::render::render_surface_instance **, int, vostok::vectora<vostok::particle::render_particle_emitter_instance *> *))m_parent)(
          v25,
          g,
          &emitters);
        M_start = emitters._M_impl._M_start;
        v29 = (vostok::render::render_surface_instance **)emitters._M_impl._M_start;
        it_d = (vostok::render::render_surface_instance **)emitters._M_impl._M_start;
        if ( emitters._M_impl._M_start != emitters._M_impl._M_finish )
        {
          do
          {
            v30 = *v29;
            m_size = (*v29)[39].m_parent->m_children_resources.m_size;
            v25 = 0;
            if ( m_size )
            {
              do
              {
                m_size = *(_DWORD *)(m_size + 128);
                v25 = (vostok::render::render_surface_instance **)((char *)v25 + 1);
              }
              while ( m_size );
              end_d = v25;
              if ( v25 )
              {
                if ( vostok::render::render_particle_emitter_instance::get_material_effects((vostok::render::render_particle_emitter_instance *)v30)->stage_enable[2]
                  && vostok::render::render_particle_emitter_instance::get_material_effects((vostok::render::render_particle_emitter_instance *)v25)->m_effects[2].m_object )
                {
                  material_effects = vostok::render::render_particle_emitter_instance::get_material_effects((vostok::render::render_particle_emitter_instance *)v25);
                  vostok::render::res_effect::apply(0, &material_effects->m_effects[2].m_object->__vftable);
                  v33 = this->m_context;
                  v73.x = (float)((float)(v33->m_v_inverted.k.x + v33->m_v_inverted.j.x) * 0.0)
                        + (float)(v33->m_v_inverted.i.x * 1000.0);
                  v73.y = (float)((float)(v33->m_v_inverted.k.y + v33->m_v_inverted.j.y) * 0.0)
                        + (float)(v33->m_v_inverted.i.y * 1000.0);
                  v73.z = (float)((float)(v33->m_v_inverted.k.z + v33->m_v_inverted.j.z) * 0.0)
                        + (float)(v33->m_v_inverted.i.z * 1000.0);
                  v74.x = (float)((float)(v33->m_v_inverted.k.x + v33->m_v_inverted.i.x) * 0.0)
                        + (float)(v33->m_v_inverted.j.x * 1000.0);
                  v74.y = (float)((float)(v33->m_v_inverted.k.y + v33->m_v_inverted.i.y) * 0.0)
                        + (float)(v33->m_v_inverted.j.y * 1000.0);
                  v74.z = (float)((float)(v33->m_v_inverted.k.z + v33->m_v_inverted.i.z) * 0.0)
                        + (float)(v33->m_v_inverted.j.z * 1000.0);
                  v34 = vostok::math::float3_pod::normalize(&v73);
                  v35 = vostok::math::float3_pod::normalize(&v74);
                  m_transform = v30[40].m_transform;
                  v37 = *(_QWORD *)&v33->m_v_inverted.lines[3].x;
                  time = (vostok::vectora<vostok::particle::render_particle_emitter_instance *> *)v30[40].m_parent;
                  g = (int)m_transform;
                  *(_QWORD *)&v64.elements[1] = v37;
                  v38 = *(_QWORD *)&v34->x;
                  z_low = LODWORD(v33->m_v_inverted.c.z);
                  v40 = *(_DWORD *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_is_active;
                  locked_axis = z_low;
                  z = v34->z;
                  *(_QWORD *)&v63.elements[1] = v38;
                  v42 = *(_QWORD *)&v35->x;
                  v43 = v35->z;
                  v64.x = z;
                  *(_QWORD *)&v62.elements[1] = v42;
                  v62.x = *(float *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_is_active;
                  v63.x = v43;
                  vostok::render::particle_shader_constants::set(
                    (vostok::render::particle_shader_constants *)&v62.elements[1],
                    v62,
                    v63,
                    v64,
                    z_low,
                    (const vostok::math::float4x4 *)g,
                    (vostok::particle::enum_particle_screen_alignment)time);
                  vostok::render::particle_shader_constants::set_time(
                    (vostok::render::particle_shader_constants *)this->m_context,
                    v40,
                    this->m_context->m_current_time);
                  vostok::render::renderer_context::set_w(
                    v44,
                    (const vostok::math::float4x4 *)&v30[33].m_flags,
                    this->m_context);
                  vostok::render::render_particle_emitter_instance::render(
                    (vostok::render::render_particle_emitter_instance *)end_d,
                    (const vostok::math::float3 *)&this->m_context->m_v_inverted.lines[3],
                    (vostok::render::render_particle_emitter_instance *)v30);
                  v29 = it_d;
                }
              }
            }
            it_d = ++v29;
          }
          while ( v29 != (vostok::render::render_surface_instance **)emitters._M_impl._M_finish );
          M_start = emitters._M_impl._M_start;
        }
        if ( M_start )
          emitters._M_impl._M_end_of_storage.m_allocator->call_free(
            emitters._M_impl._M_end_of_storage.m_allocator,
            M_start);
        v22 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
      vostok::render::backend::flush_rt_shader_resources((vostok::render::backend *)v25, v22);
      v45 = (vostok::render::render_surface_instance **)m_dynamic_visuals._M_impl._M_start;
      it_d = (vostok::render::render_surface_instance **)m_dynamic_visuals._M_impl._M_start;
      for ( end_d = (vostok::render::render_surface_instance *const *)m_dynamic_visuals._M_impl._M_finish;
            v45 != end_d;
            it_d = v45 )
      {
        m_render_surface = (*v45)->m_render_surface;
        v47 = m_render_surface->m_materail_effects_instance.m_object;
        if ( !v47 || s_use_one_material_value )
          p_m_material_effects = s_nomaterial_material_effects[m_render_surface->m_vertex_input_type];
        else
          p_m_material_effects = &v47->m_material_effects;
        if ( p_m_material_effects->stage_enable[2] )
        {
          vostok::render::renderer_context::set_w((int)*v45, (*v45)->m_transform, this->m_context);
          v49 = &p_m_material_effects->m_effects[2].m_object->__vftable;
          v50 = (v49[71] - v49[70]) >> 2;
          if ( v50 )
          {
            v49[69] = 0;
            vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v50, (int)v49);
          }
          vostok::render::res_geometry::apply(m_render_surface->m_render_geometry.geom.m_object);
          v51 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          v52 = 3 * m_render_surface->m_render_geometry.primitive_count;
          v53 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                + 529) != 4;
          v54 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v53;
          if ( v53 )
            *((_DWORD *)v51 + 529) = 4;
          vostok::render::backend::flush((vostok::render::backend *)4, (int)v51);
          if ( v54[104] )
          {
            ++*((_DWORD *)v54 + 25);
            v52 += 3 * s_max_triagles_per_dip_value < v52 ? 3 * s_max_triagles_per_dip_value - v52 : 0;
          }
          if ( !v54[37] )
            (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                     + 48))(
              `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
              v52,
              0,
              0);
          *((_DWORD *)v54 + 21) += v52 / 3;
          v45 = it_d;
        }
        ++v45;
      }
      (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                        + 176))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        1,
        &prev_view_port);
      v55 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::reset_render_targets(
        v56,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      v57 = *((_DWORD *)v55 + 547);
      v10 = *((_DWORD *)v55 + 539) == v57;
      *((_DWORD *)v55 + 539) = v57;
      *((_BYTE *)v55 + 167) |= !v10;
      v58 = vostok::math::float4x4::identity(&v77);
      vostok::render::renderer_context::set_w(v59, v58, this->m_context);
    }
    else
    {
      this->execute_disabled(this);
    }
    v60 = (char *)m_dynamic_visuals._M_impl._M_start;
    if ( m_dynamic_visuals._M_impl._M_start )
    {
      v61 = vostok::render::g_allocator.m_object;
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free((malloc_state *)HIDWORD(v61->m_reconstruction_info_actuality_tick), v60);
    }
  }
  else
  {
    this->execute_disabled(this);
  }
}
