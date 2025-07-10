void __userpurge vostok::render::stage_lights::render_model_probe_lighting(
        vostok::render::environment_probe *probe@<eax>,
        vostok::render::stage_lights *this,
        vostok::render::render_surface_instance *instance,
        float min_probe_scale)
{
  vostok::render::material_effects_instance *m_object; // ecx
  vostok::render::material_effects *p_m_material_effects; // ecx
  _DWORD *v7; // eax
  const char *m_conflicted_key_name; // edi
  char v9; // al
  vostok::render::stage_lights *v10; // ecx
  float radius; // xmm0_4
  vostok::render::base_scene_view *v12; // ebx
  vostok::render::shader_constant_host *m_probe_parameters0; // eax
  const char *v14; // edi
  unsigned int v15; // edx
  int m_buffer_index; // edx
  double m_num_mips; // st7
  vostok::render::shader_constant_host *m_probe_parameters1; // eax
  unsigned int v19; // ecx
  int v20; // ecx
  unsigned int v21; // ebx
  bool v22; // al
  unsigned int v23; // [esp+0h] [ebp-24h]
  char src_ptr[4]; // [esp+10h] [ebp-14h] BYREF
  float y; // [esp+14h] [ebp-10h]
  float z; // [esp+18h] [ebp-Ch]
  float v27; // [esp+1Ch] [ebp-8h]

  m_object = instance->m_render_surface->m_materail_effects_instance.m_object;
  if ( !m_object || s_use_one_material_value )
    p_m_material_effects = s_nomaterial_material_effects[instance->m_render_surface->m_vertex_input_type];
  else
    p_m_material_effects = &m_object->m_material_effects;
  v7 = &p_m_material_effects->m_effects[22].m_object->__vftable;
  if ( (unsigned int)((v7[71] - v7[70]) >> 2) > 1 )
  {
    v7[69] = 1;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)p_m_material_effects, v23);
  }
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v9 = vostok::render::textures_handler<0>::set_overwrite(
         (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                               + 1488),
         (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 1488,
         (vostok::render::res_texture *)&stru_9642F8,
         probe->m_texture.m_object);
  v10 = this;
  *((_BYTE *)m_conflicted_key_name + 159) = v9;
  radius = probe->m_properties.radius;
  v12 = this->m_context->m_scene_view.m_object + 1;
  if ( radius <= 0.0 )
    radius = 0.0;
  m_probe_parameters0 = this->m_probe_parameters0;
  v14 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v15 = m_probe_parameters0->m_update_markers[1];
  *(float *)src_ptr = probe->m_properties.location.x;
  y = probe->m_properties.location.y;
  z = probe->m_properties.location.z;
  v27 = radius;
  if ( v15 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573) )
  {
    m_buffer_index = m_probe_parameters0->m_shader_slots[1].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
    {
      vostok::render::shader_constant_buffer::set_memory(
        m_probe_parameters0->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_probe_parameters0->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * m_buffer_index),
        src_ptr);
      v10 = this;
    }
  }
  ++*((_DWORD *)v14 + 23);
  m_num_mips = (double)probe->m_num_mips;
  *(float *)src_ptr = *(float *)&v12[2].m_parent_resources.m_last * probe->m_properties.diffuse_multiplier;
  y = *((float *)&v12[2].m_parent_resources + 6) * probe->m_properties.specular_multiplier;
  m_probe_parameters1 = v10->m_probe_parameters1;
  z = m_num_mips;
  v19 = m_probe_parameters1->m_update_markers[1];
  v27 = 0.0;
  if ( v19 == *((_DWORD *)v14 + 573) )
  {
    v20 = m_probe_parameters1->m_shader_slots[1].m_buffer_index;
    if ( v20 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_probe_parameters1->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_probe_parameters1->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v14 + 371) + 16) + 4 * v20),
        src_ptr);
  }
  ++*((_DWORD *)v14 + 23);
  v21 = 3 * instance->m_render_surface->m_render_geometry.primitive_count;
  v22 = *((_DWORD *)v14 + 529) != 4;
  *((_BYTE *)v14 + 162) = v22;
  if ( v22 )
    *((_DWORD *)v14 + 529) = 4;
  vostok::render::backend::flush((vostok::render::backend *)4, (int)v14);
  if ( v14[104] )
  {
    ++*((_DWORD *)v14 + 25);
    v21 += 3 * s_max_triagles_per_dip_value < v21 ? 3 * s_max_triagles_per_dip_value - v21 : 0;
  }
  if ( !v14[37] )
    (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                             + 48))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v21,
      0,
      0);
  *((_DWORD *)v14 + 21) += v21 / 3;
}
