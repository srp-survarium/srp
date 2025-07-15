void __thiscall vostok::render::stage_postprocess::compute_per_pixel_eye_adaptated_luminance(
        vostok::render::stage_postprocess *this,
        vostok::render::stage_postprocess *thisa)
{
  _DWORD *v2; // eax
  const vostok::render::post_process_parameters *v3; // esi
  int v4; // ecx
  vostok::render::renderer_context *m_context; // edx
  float m_time_delta; // xmm1_4
  float v7; // xmm0_4
  vostok::render::shader_constant_host *m_elapsed_time_parameter; // eax
  const char *m_conflicted_key_name; // edi
  unsigned int v10; // ecx
  int m_buffer_index; // ecx
  const vostok::math::float4x4 *v12; // xmm1_4
  vostok::render::shader_constant_host *m_adaptation_factor; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  const vostok::render::renderer_context_targets *m_targets; // eax
  vostok::render::res_texture *v17; // esi
  vostok::render::res_texture *m_object; // eax
  vostok::render::res_texture *v19; // ecx
  bool v20; // zf
  vostok::render::res_texture *v21; // eax
  vostok::render::renderer_context *v22; // edx
  vostok::render::res_texture *v23; // eax
  vostok::render::res_texture *v24; // esi
  const char *v25; // edi
  vostok::render::res_texture *v26; // ecx
  const vostok::render::renderer_context_targets *v27; // eax
  vostok::render::render_target *v28; // eax
  vostok::render::res_effect *v29; // ecx
  _DWORD *v30; // eax
  vostok::render::res_texture *v31; // eax
  vostok::render::res_texture *v32; // esi
  const char *v33; // edi
  vostok::render::res_texture *v34; // ecx
  const vostok::render::renderer_context_targets *v35; // eax
  vostok::render::render_target *v36; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v37; // [esp-4h] [ebp-1Ch] BYREF
  unsigned int v38; // [esp+0h] [ebp-18h]
  float v39; // [esp+Ch] [ebp-Ch]
  float time_delta; // [esp+10h] [ebp-8h] BYREF
  const vostok::render::post_process_parameters *pp_parameters; // [esp+14h] [ebp-4h] BYREF

  v2 = &thisa->m_sh_eye_adaptation.m_object->__vftable;
  v3 = (const vostok::render::post_process_parameters *)&thisa->m_context->m_scene_view.m_object[1];
  v4 = (v2[71] - v2[70]) >> 2;
  pp_parameters = v3;
  if ( v4 )
  {
    v2[69] = 0;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v4, v38);
  }
  m_context = thisa->m_context;
  m_time_delta = m_context->m_time_delta;
  v7 = 0.0;
  if ( m_time_delta > 0.0 )
  {
    v7 = 0.033333335;
    if ( m_time_delta <= 0.033333335 )
      v7 = m_context->m_time_delta;
  }
  m_elapsed_time_parameter = thisa->m_elapsed_time_parameter;
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v10 = m_elapsed_time_parameter->m_update_markers[1];
  v39 = v7;
  time_delta = v7;
  if ( v10 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573) )
  {
    m_buffer_index = m_elapsed_time_parameter->m_shader_slots[1].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
    {
      vostok::render::shader_constant_buffer::set_memory(
        m_elapsed_time_parameter->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_elapsed_time_parameter->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * m_buffer_index),
        (const char *)&time_delta);
      v7 = v39;
      v3 = pp_parameters;
    }
  }
  v12 = clear_value;
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_adaptation_factor = thisa->m_adaptation_factor;
  v14 = m_adaptation_factor->m_update_markers[1];
  *(float *)&pp_parameters = (float)(*(float *)&v12 / v3->adaptation_speed) * v7;
  if ( v14 == *((_DWORD *)m_conflicted_key_name + 573) )
  {
    v15 = m_adaptation_factor->m_shader_slots[1].m_buffer_index;
    if ( v15 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_adaptation_factor->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_adaptation_factor->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16) + 4 * v15),
        (const char *)&pp_parameters);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_targets = thisa->m_context->m_targets;
  v17 = 0;
  if ( fist_pass )
  {
    m_object = m_targets->m_family[56].texture.m_object;
    if ( m_object )
    {
      v17 = m_object;
      ++m_object->m_reference_count;
    }
    *((_BYTE *)m_conflicted_key_name + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                                (vostok::render::textures_handler<0> *)(m_conflicted_key_name + 1488),
                                                (char *)m_conflicted_key_name + 1488,
                                                (vostok::render::res_texture *)&stru_9656C8.m_rescale_max.elements[3],
                                                v17);
    if ( v17 )
    {
      v20 = v17->m_reference_count-- == 1;
      if ( v20 )
        vostok::render::res_texture::destroy_impl(v19, v17);
    }
    fist_pass = 0;
  }
  else
  {
    v21 = m_targets->m_family[52].texture.m_object;
    if ( v21 )
    {
      v17 = v21;
      ++v21->m_reference_count;
    }
    *((_BYTE *)m_conflicted_key_name + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                                (vostok::render::textures_handler<0> *)(m_conflicted_key_name + 1488),
                                                (char *)m_conflicted_key_name + 1488,
                                                (vostok::render::res_texture *)&stru_9656C8.m_rescale_max.elements[3],
                                                v17);
    if ( v17 )
    {
      v20 = v17->m_reference_count-- == 1;
      if ( v20 )
        vostok::render::res_texture::destroy_impl(v19, v17);
    }
  }
  v22 = thisa->m_context;
  v23 = v22->m_targets->m_family[56].texture.m_object;
  v24 = 0;
  if ( v23 )
  {
    v24 = v22->m_targets->m_family[56].texture.m_object;
    ++v23->m_reference_count;
  }
  v25 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v25 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                            (vostok::render::textures_handler<0> *)v19,
                            (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                          + 1488,
                            (vostok::render::res_texture *)&stru_9656C8.m_desc.Height,
                            v24);
  if ( v24 )
  {
    v20 = v24->m_reference_count-- == 1;
    if ( v20 )
      vostok::render::res_texture::destroy_impl(v26, v24);
  }
  v27 = thisa->m_context->m_targets;
  v37.m_object = 0;
  v28 = v27->m_family[53].target.m_object;
  if ( v28 )
  {
    v37.m_object = v28;
    ++v28->m_reference_count;
  }
  vostok::render::stage_postprocess::fill_surface2((vostok::render::stage_postprocess *)&v37, thisa, v37);
  vostok::render::backend::flush_rt_shader_resources(
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v30 = &thisa->m_sh_eye_adaptation.m_object->__vftable;
  if ( (unsigned int)((v30[71] - v30[70]) >> 2) > 1 )
  {
    v30[69] = 1;
    vostok::render::res_effect::apply_pass(v29, v38);
  }
  v31 = thisa->m_context->m_targets->m_family[53].texture.m_object;
  v32 = 0;
  if ( v31 )
  {
    v32 = thisa->m_context->m_targets->m_family[53].texture.m_object;
    ++v31->m_reference_count;
  }
  v33 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v33 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                            (vostok::render::textures_handler<0> *)v29,
                            (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                          + 1488,
                            (vostok::render::res_texture *)&stru_9656C8.m_rescale_max,
                            v32);
  if ( v32 )
  {
    v20 = v32->m_reference_count-- == 1;
    if ( v20 )
      vostok::render::res_texture::destroy_impl(v34, v32);
  }
  v35 = thisa->m_context->m_targets;
  v37.m_object = 0;
  v36 = v35->m_family[52].target.m_object;
  if ( v36 )
  {
    v37.m_object = v36;
    ++v36->m_reference_count;
  }
  vostok::render::stage_postprocess::fill_surface2((vostok::render::stage_postprocess *)&v37, thisa, v37);
}
