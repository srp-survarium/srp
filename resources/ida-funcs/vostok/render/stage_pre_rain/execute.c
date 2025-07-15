void __thiscall vostok::render::stage_pre_rain::execute(vostok::render::stage_pre_rain *this)
{
  vostok::render::renderer_context *m_context; // eax
  vostok::render::base_scene_view *m_object; // ecx
  float v4; // xmm0_4
  double v5; // st7
  vostok::render::stage_pre_rain *v6; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *t; // eax
  const char *m_conflicted_key_name; // esi
  vostok::render::enum_render_target_index v9; // ecx
  vostok::render::system_renderer *v10; // ecx
  vostok::render::backend *v11; // ecx
  vostok::render::backend *v12; // esi
  const vostok::math::float3 *v13; // eax
  vostok::render::enum_render_target_index v14; // ecx
  vostok::render::system_renderer *v15; // ecx
  const vostok::math::float4x4 *v16; // eax
  const char *v17; // esi
  vostok::render::backend *v18; // ecx
  vostok::render::backend *v19; // ecx
  vostok::render::vector<vostok::render::render_surface_instance *> *v20; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v21; // [esp-1Ch] [ebp-CCh] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v22; // [esp-18h] [ebp-C8h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v23; // [esp-14h] [ebp-C4h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v24; // [esp-10h] [ebp-C0h]
  BOOL v25; // [esp-Ch] [ebp-BCh]
  int v26; // [esp-8h] [ebp-B8h]
  float v27; // [esp-4h] [ebp-B4h]
  float pos_y; // [esp+0h] [ebp-B0h]
  float size_x; // [esp+4h] [ebp-ACh]
  float size_y; // [esp+8h] [ebp-A8h]
  float range; // [esp+Ch] [ebp-A4h]
  vostok::render::enum_render_target_index v32; // [esp+10h] [ebp-A0h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v33; // [esp+20h] [ebp-90h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> m_caster_model; // [esp+24h] [ebp-8Ch] BYREF
  vostok::math::float4x4 view_to_shadow; // [esp+30h] [ebp-80h] BYREF
  vostok::math::float4x4 result; // [esp+70h] [ebp-40h] BYREF

  if ( this->m_wet_surface_effect.m_object && this->m_effect_shadow_direct.m_object )
  {
    if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 53)
      && this->is_enabled(this)
      && (m_context = this->m_context,
          m_object = m_context->m_scene_view.m_object,
          LOBYTE(m_object[2].m_children_resources.m_thread_id))
      && LOBYTE(m_object[4].m_memory_usage_self.size)
      && *((_DWORD *)&m_object[4].m_parent_resources + 6) != 2 )
    {
      v4 = (float)(m_context->m_time_delta * 2.0) + this->m_rain_offset_counter;
      range = 0.5;
      memset(&m_caster_model, 0, sizeof(m_caster_model));
      this->m_rain_offset_counter = v4;
      if ( this->m_rain_offset_counter >= vostok::math::random32::random_f(&s_random, range) + *(float *)&clear_value )
      {
        v5 = vostok::math::random32::random_f(&s_random, 0.75) + this->m_rain_offset;
        this->m_rain_offset_counter = 0.0;
        this->m_rain_offset = v5;
      }
      vostok::render::backend::flush_rt_shader_resources(
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      vostok::render::stage_pre_rain::render_rain_shadow_map(v6, this, &view_to_shadow);
      if ( s_rain_debug1 )
      {
        vostok::render::res_effect::apply(
          (vostok::render::res_effect *)4,
          &this->m_wet_surface_effect.m_object->__vftable);
        t = vostok::render::renderer_context::get_t((vostok::render::renderer_context *)0xA, &v33, this->m_context, v32);
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        *((_BYTE *)m_conflicted_key_name + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                                    (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                                          + 1488),
                                                    (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                  + 1488,
                                                    (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                                                    t->m_object);
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(&v33);
        range = 1.0;
        size_y = 1.0;
        size_x = 0.0;
        pos_y = 0.0;
        v27 = 0.0;
        v26 = 1;
        v25 = 0;
        v24.m_object = 0;
        v23.m_object = 0;
        v22.m_object = 0;
        vostok::render::renderer_context::get_rt((vostok::render::renderer_context *)0xB, &v21, this->m_context, v9);
        vostok::render::system_renderer::fill_surface(
          v10,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          v21,
          v22,
          v23,
          v24,
          v25,
          (D3D11_VIEWPORT *)v26,
          v27,
          pos_y,
          size_x,
          size_y);
        vostok::render::backend::flush_rt_shader_resources(
          v11,
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
        vostok::render::res_effect::apply(0, &this->m_wet_surface_effect.m_object->__vftable);
        v12 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
          this->m_context->m_eye_rays,
          this->m_eye_ray_corner_parameter);
        v13 = (const vostok::math::float3 *)vostok::math::transpose(&result, &view_to_shadow);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(v12, v13, this->m_view_to_shadow_parameter);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v12,
          (const vostok::math::float3 *)&this->m_rain_offset,
          this->m_rain_offset_parameter);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v12,
          (const vostok::math::float3 *)&this->m_context->m_scene_view.m_object[3].m_memory_usage_self,
          this->m_rain_density_parameter);
        range = 1.0;
        size_y = 1.0;
        size_x = 0.0;
        pos_y = 0.0;
        v27 = 0.0;
        v26 = 1;
        v25 = 0;
        v24.m_object = 0;
        v23.m_object = 0;
        v22.m_object = 0;
        vostok::render::renderer_context::get_rt((vostok::render::renderer_context *)0xA, &v21, this->m_context, v14);
        vostok::render::system_renderer::fill_surface(
          v15,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          v21,
          v22,
          v23,
          v24,
          v25,
          (D3D11_VIEWPORT *)v26,
          v27,
          pos_y,
          size_x,
          size_y);
      }
      qmemcpy(
        (void *)&this->m_renderer->m_view_to_rain_shadow,
        &view_to_shadow,
        sizeof(this->m_renderer->m_view_to_rain_shadow));
      v16 = vostok::math::float4x4::identity(&result);
      vostok::render::renderer_context::set_w(this->m_context, v16);
      v17 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::reset_render_targets(
        v18,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      vostok::render::backend::reset_depth_stencil_target(v19, (int)v17);
      vostok::render::vector<vostok::render::render_surface_instance *>::~vector<vostok::render::render_surface_instance *>(
        v20,
        (void **)&m_caster_model._M_impl._M_start);
    }
    else
    {
      this->execute_disabled(this);
    }
  }
}
