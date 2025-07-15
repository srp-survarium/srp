void __userpurge vostok::render::stage_gbuffer::render_models(
        vostok::render::vector<vostok::render::render_surface_instance *> *models@<eax>,
        vostok::render::stage_gbuffer *this,
        unsigned int shader_lod_index,
        unsigned int *out_num_rendered,
        bool z_only)
{
  void **M_start; // ebx
  _DWORD *v6; // esi
  int v7; // ebp
  int v8; // eax
  vostok::render::material_effects *v9; // edi
  _DWORD *v10; // eax
  unsigned int v11; // ecx
  bool v12; // zf
  const char *m_conflicted_key_name; // edi
  vostok::render::stage_gbuffer *v14; // edx
  vostok::render::base_scene_view *m_object; // eax
  float v16; // xmm0_4
  float v17; // xmm0_4
  vostok::render::shader_constant_host *m_wind_info_parameters; // eax
  unsigned int v19; // ecx
  int m_buffer_index; // ecx
  vostok::render::shader_constant_host *m_smoothness_multiplier; // eax
  unsigned int v22; // ecx
  int v23; // ecx
  vostok::render::shader_constant_buffer *v24; // esi
  float *p_wet_intensity; // ecx
  unsigned int v26; // edx
  int v27; // ecx
  unsigned int v28; // ebp
  bool v29; // al
  unsigned int v30; // [esp+0h] [ebp-2Ch]
  float wet_intensity; // [esp+14h] [ebp-18h] BYREF
  const vostok::math::float4x4 *v32; // [esp+18h] [ebp-14h] BYREF
  vostok::render::render_surface_instance *const *end; // [esp+1Ch] [ebp-10h]
  vostok::math::float3 wind_info_parameters; // [esp+20h] [ebp-Ch] BYREF

  M_start = models->_M_impl._M_start;
  for ( end = (vostok::render::render_surface_instance *const *)models->_M_impl._M_finish;
        M_start != (void **)end;
        ++M_start )
  {
    v6 = *M_start;
    v7 = *(_DWORD *)*M_start;
    v8 = *(_DWORD *)(v7 + 148);
    if ( !v8 || s_use_one_material_value )
      v9 = s_nomaterial_material_effects[*(_DWORD *)(v7 + 4)];
    else
      v9 = (vostok::render::material_effects *)(v8 + 264);
    vostok::render::renderer_context::set_w(this->m_context, (const vostok::math::float4x4 *)v6[1]);
    v10 = &v9->m_effects[0].m_object->__vftable;
    if ( z_only )
    {
      v11 = (v10[71] - v10[70]) >> 2;
      if ( v11 <= 8 )
        goto LABEL_12;
      v10[69] = 8;
    }
    else
    {
      v11 = shader_lod_index;
      if ( shader_lod_index >= (v10[71] - v10[70]) >> 2 )
        goto LABEL_12;
      v10[69] = shader_lod_index;
    }
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v11, v30);
LABEL_12:
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v6[2] + 56))(v6[2]);
    vostok::render::res_geometry::apply(*(vostok::render::res_geometry **)(v7 + 48));
    v12 = !v9->is_wind_swings;
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v14 = this;
    if ( !v12 )
    {
      m_object = this->m_context->m_scene_view.m_object;
      v16 = *((float *)&m_object[2].m_parent_resources + 6);
      ++m_object;
      wind_info_parameters.x = v16;
      LODWORD(wind_info_parameters.y) = m_object[1].m_memory_usage_self.size;
      v17 = *(float *)&m_object[1].m_current_satisfaction_update_tick;
      m_wind_info_parameters = this->m_wind_info_parameters;
      v19 = m_wind_info_parameters->m_update_markers[0];
      wind_info_parameters.z = v17;
      if ( v19 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                  + 572) )
      {
        m_buffer_index = m_wind_info_parameters->m_shader_slots[0].m_buffer_index;
        if ( m_buffer_index != 0xFFFF )
        {
          vostok::render::shader_constant_buffer::set_memory(
            m_wind_info_parameters->m_shader_slots[0].m_slot_index,
            (unsigned __int8)m_wind_info_parameters->m_shader_slots[0].m_class_id,
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 51)
                                                                   + 16)
                                                       + 4 * m_buffer_index),
            (const char *)&wind_info_parameters);
          v14 = this;
        }
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
    }
    if ( z_only )
      goto LABEL_27;
    if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 53) )
    {
      m_smoothness_multiplier = v14->m_smoothness_multiplier;
      v26 = m_smoothness_multiplier->m_update_markers[1];
      v32 = clear_value;
      if ( v26 != *((_DWORD *)m_conflicted_key_name + 573) )
        goto LABEL_26;
      v27 = m_smoothness_multiplier->m_shader_slots[1].m_buffer_index;
      if ( v27 == 0xFFFF )
        goto LABEL_26;
      v24 = *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                       + 4 * v27);
      p_wet_intensity = (float *)&v32;
    }
    else
    {
      m_smoothness_multiplier = v14->m_smoothness_multiplier;
      v22 = m_smoothness_multiplier->m_update_markers[1];
      wet_intensity = *(float *)&v14->m_context->m_scene_view.m_object[3].m_memory_usage_self.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type;
      if ( v22 != *((_DWORD *)m_conflicted_key_name + 573) )
        goto LABEL_26;
      v23 = m_smoothness_multiplier->m_shader_slots[1].m_buffer_index;
      if ( v23 == 0xFFFF )
        goto LABEL_26;
      v24 = *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                       + 4 * v23);
      p_wet_intensity = &wet_intensity;
    }
    vostok::render::shader_constant_buffer::set_memory(
      m_smoothness_multiplier->m_shader_slots[1].m_slot_index,
      (unsigned __int8)m_smoothness_multiplier->m_shader_slots[1].m_class_id,
      v24,
      (const char *)p_wet_intensity);
LABEL_26:
    ++*((_DWORD *)m_conflicted_key_name + 23);
LABEL_27:
    v28 = 3 * *(_DWORD *)(v7 + 68);
    v29 = *((_DWORD *)m_conflicted_key_name + 529) != 4;
    *((_BYTE *)m_conflicted_key_name + 162) = v29;
    if ( v29 )
      *((_DWORD *)m_conflicted_key_name + 529) = 4;
    vostok::render::backend::flush((vostok::render::backend *)4, (int)m_conflicted_key_name);
    if ( m_conflicted_key_name[104] )
    {
      ++*((_DWORD *)m_conflicted_key_name + 25);
      v28 += 3 * s_max_triagles_per_dip_value < v28 ? 3 * s_max_triagles_per_dip_value - v28 : 0;
    }
    if ( !m_conflicted_key_name[37] )
      (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                               + 48))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v28,
        0,
        0);
    ++*out_num_rendered;
    *((_DWORD *)m_conflicted_key_name + 21) += v28 / 3;
  }
}
