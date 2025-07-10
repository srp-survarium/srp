void __thiscall vostok::render::stage_particles::execute(vostok::render::stage_particles *this)
{
  unsigned int v2; // ecx
  vostok::render::renderer_context *m_context; // esi
  const vostok::math::float4x4 *v4; // eax
  vostok::render::renderer_context *v5; // ecx
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v7; // ecx
  bool v8; // zf
  vostok::render::render_target *v9; // eax
  vostok::render::resource_manager *v10; // ecx
  vostok::render::render_target *v11; // eax
  const char *v12; // ecx
  ID3D11RenderTargetView *m_rt; // edx
  const char *m_conflicted_key_name; // eax
  int v15; // ecx
  vostok::render::base_scene_view *v16; // ebx
  vostok::particle::render_particle_emitter_instance *const *last_command; // eax
  vostok::vectora<vostok::particle::render_particle_emitter_instance *> *p_last_command; // ebx
  vostok::particle::render_particle_emitter_instance *v19; // edi
  void (__thiscall *set_aabb)(vostok::particle::render_particle_emitter_instance *, const vostok::math::aabb *); // eax
  vostok::render::render_particle_emitter_instance *v21; // ecx
  vostok::render::renderer_context *v22; // edx
  vostok::particle::enum_particle_render_mode type; // esi
  vostok::render::material_effects *material_effects; // eax
  vostok::render::renderer_context *v25; // esi
  vostok::math::float3 *v26; // ebx
  vostok::math::float3 *v27; // eax
  const vostok::math::float4x4 *v28; // edx
  __int64 v29; // xmm0_8
  __int64 v30; // xmm0_8
  vostok::particle::enum_particle_locked_axis z_low; // ecx
  int v32; // esi
  float z; // edx
  __int64 v34; // xmm0_8
  float v35; // eax
  const vostok::math::float4x4 *v36; // eax
  const char *v37; // esi
  vostok::render::backend *v38; // ecx
  int v39; // eax
  vostok::math::float3 v40; // [esp-20h] [ebp-D8h] BYREF
  vostok::math::float3 v41; // [esp-14h] [ebp-CCh]
  vostok::math::float3 v42; // [esp-8h] [ebp-C0h]
  vostok::particle::enum_particle_locked_axis v43; // [esp+4h] [ebp-B4h]
  const vostok::math::float4x4 *v44; // [esp+8h] [ebp-B0h]
  vostok::particle::render_particle_emitter_instance_vtbl *time; // [esp+Ch] [ebp-ACh]
  vostok::render::backend *v46; // [esp+10h] [ebp-A8h]
  bool has_particles; // [esp+23h] [ebp-95h]
  unsigned int num_particles; // [esp+24h] [ebp-94h]
  vostok::vectora<vostok::particle::render_particle_emitter_instance *> *emitters; // [esp+28h] [ebp-90h]
  vostok::particle::render_particle_emitter_instance *const *it; // [esp+2Ch] [ebp-8Ch]
  vostok::math::float3_pod v51; // [esp+30h] [ebp-88h] BYREF
  vostok::math::float3_pod v52; // [esp+3Ch] [ebp-7Ch] BYREF
  D3D11_VIEWPORT tmp_viewport; // [esp+48h] [ebp-70h] BYREF
  D3D11_VIEWPORT orig_viewport; // [esp+60h] [ebp-58h] BYREF
  vostok::math::float4x4 v55; // [esp+78h] [ebp-40h] BYREF

  if ( this->is_enabled(this) && this->m_resolve_particles_effect.m_object )
  {
    m_context = this->m_context;
    if ( m_context->m_scene->m_particle_world.m_object )
    {
      vostok::render::backend::get_viewport(v2, &orig_viewport, v46);
      v5 = this->m_context;
      tmp_viewport.TopLeftX = 0.0;
      tmp_viewport.TopLeftY = 0.0;
      m_object = v5->m_targets->m_family[47].target.m_object;
      v7 = 0;
      if ( m_object )
      {
        v7 = m_object;
        ++m_object->m_reference_count;
      }
      tmp_viewport.Width = (float)v7->m_width;
      v8 = v7->m_reference_count-- == 1;
      if ( v8 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)v7,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v7);
      v9 = this->m_context->m_targets->m_family[47].target.m_object;
      v10 = 0;
      if ( v9 )
      {
        v10 = (vostok::render::resource_manager *)this->m_context->m_targets->m_family[47].target.m_object;
        ++v9->m_reference_count;
      }
      tmp_viewport.Height = (float)LODWORD(v10->m_num_bytes_of_texture_video_memory);
      v8 = v10->sh_created-- == 1;
      if ( v8 )
        vostok::render::resource_manager::release(
          v10,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v10);
      tmp_viewport.MinDepth = 0.0;
      LODWORD(tmp_viewport.MaxDepth) = clear_value;
      (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                        + 176))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        1,
        &tmp_viewport);
      v11 = this->m_context->m_targets->m_family[47].target.m_object;
      v12 = 0;
      if ( v11 )
      {
        v12 = (const char *)this->m_context->m_targets->m_family[47].target.m_object;
        ++v11->m_reference_count;
        m_rt = v11->m_rt;
      }
      else
      {
        m_rt = 0;
      }
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
           + 535) != m_rt )
      {
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
        *((_BYTE *)m_conflicted_key_name + 163) = 1;
      }
      if ( *((_DWORD *)m_conflicted_key_name + 536) )
      {
        *((_DWORD *)m_conflicted_key_name + 536) = 0;
        *((_BYTE *)m_conflicted_key_name + 164) = 1;
      }
      if ( *((_DWORD *)m_conflicted_key_name + 537) )
      {
        *((_DWORD *)m_conflicted_key_name + 537) = 0;
        *((_BYTE *)m_conflicted_key_name + 165) = 1;
      }
      if ( *((_DWORD *)m_conflicted_key_name + 538) )
      {
        *((_DWORD *)m_conflicted_key_name + 538) = 0;
        *((_BYTE *)m_conflicted_key_name + 166) = 1;
      }
      if ( v12 )
      {
        v8 = (*(_DWORD *)v12)-- == 1;
        if ( v8 )
        {
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v12);
          m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        }
      }
      v15 = *((_DWORD *)m_conflicted_key_name + 547);
      v8 = *((_DWORD *)m_conflicted_key_name + 539) == v15;
      *((_DWORD *)m_conflicted_key_name + 539) = v15;
      *((_BYTE *)m_conflicted_key_name + 167) |= !v8;
      v16 = this->m_context->m_scene_view.m_object;
      last_command = (vostok::particle::render_particle_emitter_instance *const *)v16[4].last_command;
      p_last_command = (vostok::vectora<vostok::particle::render_particle_emitter_instance *> *)&v16[4].last_command;
      emitters = p_last_command;
      has_particles = 0;
      for ( it = last_command;
            last_command != (vostok::particle::render_particle_emitter_instance *const *)p_last_command->_M_impl._M_finish;
            it = last_command )
      {
        v19 = *last_command;
        if ( !(*(unsigned __int8 (__thiscall **)(vostok::particle::render_particle_emitter_instance *const))(**(_DWORD **)last_command + 16))(*last_command) )
        {
          set_aabb = v19[275].__vftable[1].set_aabb;
          v21 = 0;
          if ( set_aabb )
          {
            do
            {
              set_aabb = (void (__thiscall *)(vostok::particle::render_particle_emitter_instance *, const vostok::math::aabb *))*((_DWORD *)set_aabb + 32);
              v21 = (vostok::render::render_particle_emitter_instance *)((char *)v21 + 1);
            }
            while ( set_aabb );
            num_particles = (unsigned int)v21;
            if ( v21 )
            {
              v22 = this->m_context;
              type = (vostok::particle::enum_particle_render_mode)v22->m_scene_view.m_object[4].m_memory_usage_self.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type;
              if ( type
                || !vostok::render::render_particle_emitter_instance::get_material_effects((vostok::render::render_particle_emitter_instance *)v19)->stage_enable[17] )
              {
                vostok::render::render_particle_emitter_instance::draw_debug(v21, (int)v19, &v22->m_v, type);
              }
              else
              {
                material_effects = vostok::render::render_particle_emitter_instance::get_material_effects(v21);
                vostok::render::res_effect::apply(0, &material_effects->m_effects[17].m_object->__vftable);
                v25 = this->m_context;
                v51.x = (float)((float)(v25->m_v_inverted.k.x + v25->m_v_inverted.j.x) * 0.0)
                      + (float)(v25->m_v_inverted.i.x * 1000.0);
                v51.y = (float)((float)(v25->m_v_inverted.k.y + v25->m_v_inverted.j.y) * 0.0)
                      + (float)(v25->m_v_inverted.i.y * 1000.0);
                v51.z = (float)((float)(v25->m_v_inverted.k.z + v25->m_v_inverted.j.z) * 0.0)
                      + (float)(v25->m_v_inverted.i.z * 1000.0);
                v52.x = (float)((float)(v25->m_v_inverted.k.x + v25->m_v_inverted.i.x) * 0.0)
                      + (float)(v25->m_v_inverted.j.x * 1000.0);
                v52.y = (float)((float)(v25->m_v_inverted.k.y + v25->m_v_inverted.i.y) * 0.0)
                      + (float)(v25->m_v_inverted.j.y * 1000.0);
                v52.z = (float)((float)(v25->m_v_inverted.k.z + v25->m_v_inverted.i.z) * 0.0)
                      + (float)(v25->m_v_inverted.j.z * 1000.0);
                v26 = vostok::math::float3_pod::normalize(&v51);
                v27 = vostok::math::float3_pod::normalize(&v52);
                v28 = (const vostok::math::float4x4 *)v19[281].__vftable;
                v29 = *(_QWORD *)&v25->m_v_inverted.lines[3].x;
                time = v19[282].__vftable;
                v44 = v28;
                *(_QWORD *)&v42.elements[1] = v29;
                v30 = *(_QWORD *)&v26->x;
                z_low = LODWORD(v25->m_v_inverted.c.z);
                v32 = *(_DWORD *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_is_active;
                v43 = z_low;
                z = v26->z;
                *(_QWORD *)&v41.elements[1] = v30;
                v34 = *(_QWORD *)&v27->x;
                v35 = v27->z;
                v42.x = z;
                *(_QWORD *)&v40.elements[1] = v34;
                v40.x = *(float *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_is_active;
                v41.x = v35;
                vostok::render::particle_shader_constants::set(
                  (vostok::render::particle_shader_constants *)&v40.elements[1],
                  v40,
                  v41,
                  v42,
                  z_low,
                  v44,
                  (vostok::particle::enum_particle_screen_alignment)time);
                vostok::render::particle_shader_constants::set_time(
                  (vostok::render::particle_shader_constants *)this->m_context,
                  v32,
                  this->m_context->m_current_time);
                vostok::render::renderer_context::set_w(this->m_context, (const vostok::math::float4x4 *)&v19[236]);
                vostok::render::render_particle_emitter_instance::render(
                  (vostok::render::render_particle_emitter_instance *)num_particles,
                  (const vostok::math::float3 *)&this->m_context->m_v_inverted.lines[3],
                  (vostok::render::render_particle_emitter_instance *)v19);
                p_last_command = emitters;
                if ( !has_particles )
                  has_particles = 1;
              }
            }
          }
        }
        last_command = it + 1;
      }
      (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                        + 176))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        1,
        &orig_viewport);
      v36 = vostok::math::float4x4::identity(&v55);
      vostok::render::renderer_context::set_w(this->m_context, v36);
      v37 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::reset_render_targets(
        v38,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      v39 = *((_DWORD *)v37 + 547);
      v8 = *((_DWORD *)v37 + 539) == v39;
      *((_DWORD *)v37 + 539) = v39;
      *((_BYTE *)v37 + 167) |= !v8;
    }
    else
    {
      v4 = vostok::math::float4x4::identity(&v55);
      vostok::render::renderer_context::set_w(m_context, v4);
    }
  }
  else
  {
    this->execute_disabled(this);
  }
}
