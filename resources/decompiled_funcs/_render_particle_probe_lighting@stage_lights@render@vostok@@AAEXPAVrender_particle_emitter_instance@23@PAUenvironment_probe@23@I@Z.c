void __userpurge vostok::render::stage_lights::render_particle_probe_lighting(
        vostok::render::stage_lights *this@<edi>,
        vostok::render::environment_probe *probe@<eax>,
        vostok::render::render_particle_emitter_instance *instance,
        vostok::render::render_particle_emitter_instance *num_particles)
{
  vostok::render::res_effect *m_object; // eax
  unsigned int v6; // ecx
  const char *m_conflicted_key_name; // ebx
  vostok::render::shader_constant_host *m_probe_parameters0; // eax
  vostok::render::base_scene_view *v9; // ebp
  const char *v10; // ebx
  unsigned int v11; // ecx
  vostok::render::base_scene_view *v12; // ebp
  int m_buffer_index; // ecx
  double m_num_mips; // st7
  vostok::render::shader_constant_host *m_probe_parameters1; // eax
  unsigned int v16; // edx
  int v17; // ecx
  vostok::render::renderer_context *m_context; // esi
  float v19; // xmm0_4
  float v20; // xmm1_4
  long double v21; // st7
  vostok::particle::enum_particle_locked_axis m_locked_axis; // eax
  vostok::particle::enum_particle_locked_axis v23; // ecx
  vostok::render::particle_shader_constants *v24; // ecx
  vostok::math::float3 v25; // [esp-2Ch] [ebp-64h]
  vostok::math::float3 v26; // [esp-20h] [ebp-58h]
  vostok::math::float3 v27; // [esp-14h] [ebp-4Ch]
  unsigned int v28; // [esp+4h] [ebp-34h]
  float v29; // [esp+14h] [ebp-24h]
  float v30; // [esp+14h] [ebp-24h]
  float v31; // [esp+18h] [ebp-20h]
  __int64 v32; // [esp+18h] [ebp-20h]
  float v33; // [esp+1Ch] [ebp-1Ch]
  float v34; // [esp+20h] [ebp-18h]
  float v35; // [esp+20h] [ebp-18h]
  char src_ptr[8]; // [esp+24h] [ebp-14h] BYREF
  vostok::render::particle_shader_constants *z_low; // [esp+2Ch] [ebp-Ch]
  float radius; // [esp+30h] [ebp-8h]

  m_object = vostok::render::render_particle_emitter_instance::get_material_effects(instance)->m_effects[22].m_object;
  if ( m_object )
  {
    v6 = m_object->m_techniques._M_impl._M_finish - m_object->m_techniques._M_impl._M_start;
    if ( v6 > 1 )
    {
      m_object->m_cur_technique = 1;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v6, v28);
    }
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)m_conflicted_key_name + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                                (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                                      + 1488),
                                                (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                              + 1488,
                                                (vostok::render::res_texture *)&stru_9642F8,
                                                probe->m_texture.m_object);
    m_probe_parameters0 = this->m_probe_parameters0;
    v9 = this->m_context->m_scene_view.m_object;
    v10 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v11 = m_probe_parameters0->m_update_markers[1];
    *(float *)src_ptr = probe->m_properties.location.x;
    *(float *)&src_ptr[4] = probe->m_properties.location.y;
    v12 = v9 + 1;
    z_low = (vostok::render::particle_shader_constants *)LODWORD(probe->m_properties.location.z);
    radius = probe->m_properties.radius;
    if ( v11 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                + 573) )
    {
      m_buffer_index = m_probe_parameters0->m_shader_slots[1].m_buffer_index;
      if ( m_buffer_index != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_probe_parameters0->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_probe_parameters0->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 371)
                                                                 + 16)
                                                     + 4 * m_buffer_index),
          src_ptr);
    }
    ++*((_DWORD *)v10 + 23);
    m_num_mips = (double)probe->m_num_mips;
    *(float *)src_ptr = *(float *)&v12[2].m_parent_resources.m_last * probe->m_properties.diffuse_multiplier;
    *(float *)&src_ptr[4] = *((float *)&v12[2].m_parent_resources + 6) * probe->m_properties.specular_multiplier;
    m_probe_parameters1 = this->m_probe_parameters1;
    *(float *)&z_low = m_num_mips;
    v16 = m_probe_parameters1->m_update_markers[1];
    radius = 0.0;
    if ( v16 == *((_DWORD *)v10 + 573) )
    {
      v17 = m_probe_parameters1->m_shader_slots[1].m_buffer_index;
      if ( v17 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_probe_parameters1->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_probe_parameters1->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v10 + 371) + 16) + 4 * v17),
          src_ptr);
    }
    ++*((_DWORD *)v10 + 23);
    m_context = this->m_context;
    v31 = (float)((float)(m_context->m_v_inverted.k.x + m_context->m_v_inverted.j.x) * 0.0)
        + (float)(m_context->m_v_inverted.i.x * 1000.0);
    v33 = (float)((float)(m_context->m_v_inverted.k.y + m_context->m_v_inverted.j.y) * 0.0)
        + (float)(m_context->m_v_inverted.i.y * 1000.0);
    v34 = (float)((float)(m_context->m_v_inverted.k.z + m_context->m_v_inverted.j.z) * 0.0)
        + (float)(m_context->m_v_inverted.i.z * 1000.0);
    v29 = 1.0 / sqrtf((float)((float)(v31 * v31) + (float)(v34 * v34)) + (float)(v33 * v33));
    *(float *)&v32 = v29 * v31;
    *((float *)&v32 + 1) = v33 * v29;
    v35 = v34 * v29;
    v19 = (float)((float)(m_context->m_v_inverted.k.x + m_context->m_v_inverted.i.x) * 0.0)
        + (float)(m_context->m_v_inverted.j.x * 1000.0);
    v20 = (float)((float)(m_context->m_v_inverted.k.y + m_context->m_v_inverted.i.y) * 0.0)
        + (float)(m_context->m_v_inverted.j.y * 1000.0);
    *(float *)&z_low = (float)((float)(m_context->m_v_inverted.k.z + m_context->m_v_inverted.i.z) * 0.0)
                     + (float)(m_context->m_v_inverted.j.z * 1000.0);
    *(float *)&src_ptr[4] = v20;
    *(float *)src_ptr = v19;
    v21 = sqrtf((float)((float)(*(float *)&z_low * *(float *)&z_low) + (float)(v20 * v20)) + (float)(v19 * v19));
    m_locked_axis = instance->m_locked_axis;
    v23 = LODWORD(m_context->m_v_inverted.c.z);
    v30 = 1.0 / v21;
    *(float *)src_ptr = v30 * *(float *)src_ptr;
    *(float *)&src_ptr[4] = *(float *)&src_ptr[4] * v30;
    *(float *)&z_low = *(float *)&z_low * v30;
    *(_QWORD *)&v27.elements[1] = *(_QWORD *)&m_context->m_v_inverted.lines[3].x;
    *(_QWORD *)&v26.elements[1] = v32;
    v27.x = v35;
    *(_QWORD *)&v25.elements[1] = *(_QWORD *)src_ptr;
    v25.x = *(float *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_is_active;
    LODWORD(v26.x) = z_low;
    vostok::render::particle_shader_constants::set(
      z_low,
      v25,
      v26,
      v27,
      v23,
      (vostok::particle::enum_particle_screen_alignment)m_locked_axis);
    vostok::render::particle_shader_constants::set_time(v24, this->m_context->m_current_time);
    vostok::render::renderer_context::set_w(this->m_context, &instance->m_transform);
    vostok::render::render_particle_emitter_instance::render(
      num_particles,
      (const vostok::math::float3 *)&this->m_context->m_v_inverted.lines[3],
      instance);
  }
}
