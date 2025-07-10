void __userpurge vostok::render::stage_resolve_lighting::render_models(
        vostok::render::vector<vostok::render::render_surface_instance *> *models@<eax>,
        vostok::render::stage_resolve_lighting *this,
        unsigned int *out_num_rendered)
{
  vostok::render::renderer_context *m_context; // edx
  void **M_start; // ebx
  vostok::render::lights_db *m_object; // eax
  vostok::render::light *v6; // ecx
  const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_sun; // eax
  vostok::render::light *v8; // edi
  vostok::render::light *v9; // ecx
  vostok::render::grass_render_model *v11; // esi
  _DWORD *v12; // edi
  int v13; // ecx
  int v14; // eax
  vostok::render::material_effects *v15; // esi
  _DWORD *v16; // eax
  unsigned int v17; // ecx
  const char *m_conflicted_key_name; // edi
  vostok::render::base_scene_view *v19; // eax
  int v20; // xmm0_4
  int m_current_satisfaction_update_tick; // xmm0_4
  vostok::render::shader_constant_host *m_wind_info_parameters; // eax
  unsigned int v23; // ecx
  int m_buffer_index; // ecx
  vostok::render::shader_constant_host *m_sun_light_parameters; // eax
  int v26; // ecx
  unsigned int v27; // ebx
  bool v28; // al
  unsigned int v29; // kr00_4
  unsigned int v30; // [esp+7Ch] [ebp-40h]
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object; // [esp+90h] [ebp-2Ch] BYREF
  void **v32; // [esp+94h] [ebp-28h]
  void **M_finish; // [esp+98h] [ebp-24h]
  char src_ptr[16]; // [esp+9Ch] [ebp-20h] BYREF
  char v35[16]; // [esp+ACh] [ebp-10h] BYREF

  m_context = this->m_context;
  M_start = models->_M_impl._M_start;
  M_finish = models->_M_impl._M_finish;
  m_object = m_context->m_scene->m_lights.m_object;
  v6 = m_object->m_sun.m_object;
  p_m_sun = &m_object->m_sun;
  v32 = M_start;
  if ( v6
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && !v6->m_enabled )
  {
    v8 = 0;
  }
  else
  {
    object.m_object = 0;
    vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
      (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v6,
      &object,
      p_m_sun);
    v8 = object.m_object;
    if ( object.m_object )
    {
      if ( object.m_object->m_reference_count-- == 1 )
      {
        v11 = vostok::render::g_allocator.m_object;
        vostok::render::light::~light(v9, (int)v8);
        BYTE2(v11->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v11->m_reconstruction_info_actuality_tick), v8);
      }
    }
  }
  *(_DWORD *)v35 = clear_value;
  *(_DWORD *)&v35[4] = clear_value;
  *(_DWORD *)&v35[8] = clear_value;
  *(_DWORD *)&v35[12] = 0;
  if ( v8 )
  {
    *(float *)src_ptr = v8->direction.x;
    *(float *)&src_ptr[4] = v8->direction.y;
    *(float *)&src_ptr[8] = v8->direction.z;
    *(float *)&src_ptr[12] = v8->intensity;
    *(__m128i *)v35 = _mm_load_si128((const __m128i *)src_ptr);
  }
  for ( ; M_start != M_finish; v32 = M_start )
  {
    v12 = *M_start;
    v13 = *(_DWORD *)*M_start;
    v14 = *(_DWORD *)(v13 + 148);
    object.m_object = (vostok::render::light *)v13;
    if ( !v14 || s_use_one_material_value )
      v15 = s_nomaterial_material_effects[*(_DWORD *)(v13 + 4)];
    else
      v15 = (vostok::render::material_effects *)(v14 + 264);
    if ( v15->use_subsurface_scattering )
    {
      vostok::render::renderer_context::set_w(this->m_context, (const vostok::math::float4x4 *)v12[1]);
      v16 = &v15->m_effects[0].m_object->__vftable;
      v17 = (v16[71] - v16[70]) >> 2;
      if ( v17 > 7 )
      {
        v16[69] = 7;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v17, v30);
      }
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v12[2] + 56))(v12[2]);
      vostok::render::res_geometry::apply((vostok::render::res_geometry *)LODWORD(object.m_object->m_xform.k.w));
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( v15->is_wind_swings )
      {
        v19 = this->m_context->m_scene_view.m_object;
        v20 = *((_DWORD *)&v19[2].m_parent_resources + 6);
        ++v19;
        *(_DWORD *)src_ptr = v20;
        *(_DWORD *)&src_ptr[4] = v19[1].m_memory_usage_self.size;
        m_current_satisfaction_update_tick = v19[1].m_current_satisfaction_update_tick;
        m_wind_info_parameters = this->m_wind_info_parameters;
        v23 = m_wind_info_parameters->m_update_markers[0];
        *(_DWORD *)&src_ptr[8] = m_current_satisfaction_update_tick;
        if ( v23 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                    + 572) )
        {
          m_buffer_index = m_wind_info_parameters->m_shader_slots[0].m_buffer_index;
          if ( m_buffer_index != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              m_wind_info_parameters->m_shader_slots[0].m_slot_index,
              (unsigned __int8)m_wind_info_parameters->m_shader_slots[0].m_class_id,
              *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                       + 51)
                                                                     + 16)
                                                         + 4 * m_buffer_index),
              src_ptr);
        }
        ++*((_DWORD *)m_conflicted_key_name + 23);
      }
      m_sun_light_parameters = this->m_sun_light_parameters;
      if ( m_sun_light_parameters->m_update_markers[1] == *((_DWORD *)m_conflicted_key_name + 573) )
      {
        v26 = m_sun_light_parameters->m_shader_slots[1].m_buffer_index;
        if ( v26 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            m_sun_light_parameters->m_shader_slots[1].m_slot_index,
            (unsigned __int8)m_sun_light_parameters->m_shader_slots[1].m_class_id,
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                       + 4 * v26),
            v35);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      v27 = 3 * LODWORD(object.m_object->m_plane_spot_xform.i.x);
      v28 = *((_DWORD *)m_conflicted_key_name + 529) != 4;
      *((_BYTE *)m_conflicted_key_name + 162) = v28;
      if ( v28 )
        *((_DWORD *)m_conflicted_key_name + 529) = 4;
      vostok::render::backend::flush((vostok::render::backend *)4, (int)m_conflicted_key_name);
      if ( m_conflicted_key_name[104] )
      {
        ++*((_DWORD *)m_conflicted_key_name + 25);
        v27 += 3 * s_max_triagles_per_dip_value < v27 ? 3 * s_max_triagles_per_dip_value - v27 : 0;
      }
      if ( !m_conflicted_key_name[37] )
        (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                 + 48))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          v27,
          0,
          0);
      v29 = v27;
      M_start = v32;
      *((_DWORD *)m_conflicted_key_name + 21) += v29 / 3;
      ++*out_num_rendered;
    }
    ++M_start;
  }
}
