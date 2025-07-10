void __thiscall vostok::render::stage_postprocess::execute_disabled(vostok::render::stage_postprocess *this)
{
  vostok::render::res_effect *m_object; // eax
  int v3; // ecx
  vostok::render::res_texture *v4; // eax
  vostok::render::res_texture *v5; // esi
  const char *m_conflicted_key_name; // edi
  vostok::render::res_texture *v7; // ecx
  const char *v8; // esi
  vostok::render::shader_constant_host *m_gamma_correction_factor; // eax
  int v10; // ecx
  unsigned __int16 m_buffer_index; // cx
  const vostok::render::renderer_context_targets *m_targets; // eax
  vostok::render::render_target *v13; // eax
  const vostok::math::float4x4 *v14; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v15; // [esp-8h] [ebp-58h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v16; // [esp-4h] [ebp-54h]
  unsigned int v17; // [esp+0h] [ebp-50h]
  char src_ptr[4]; // [esp+Ch] [ebp-44h] BYREF
  vostok::math::float4x4 v19; // [esp+10h] [ebp-40h] BYREF

  if ( vostok::render::stage_postprocess::is_effects_ready(this, this) )
  {
    m_object = this->m_sh_effect_copy_image.m_object;
    v3 = m_object->m_techniques._M_impl._M_finish - m_object->m_techniques._M_impl._M_start;
    if ( v3 )
    {
      m_object->m_cur_technique = 0;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v3, v17);
    }
    v4 = this->m_context->m_targets->m_family[47].texture.m_object;
    v5 = 0;
    if ( v4 )
    {
      v5 = this->m_context->m_targets->m_family[47].texture.m_object;
      ++v4->m_reference_count;
    }
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)m_conflicted_key_name + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                                (vostok::render::textures_handler<0> *)v3,
                                                (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                              + 1488,
                                                (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                                                v5);
    if ( v5 )
    {
      if ( !--v5->m_reference_count )
        vostok::render::res_texture::destroy_impl(v7, v5);
    }
    v8 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    m_gamma_correction_factor = this->m_gamma_correction_factor;
    v10 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573);
    *(_DWORD *)src_ptr = clear_value;
    if ( m_gamma_correction_factor->m_update_markers[1] == v10 )
    {
      m_buffer_index = m_gamma_correction_factor->m_shader_slots[1].m_buffer_index;
      if ( m_buffer_index != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_gamma_correction_factor->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_gamma_correction_factor->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 371)
                                                                 + 16)
                                                     + 4 * m_buffer_index),
          src_ptr);
    }
    ++*((_DWORD *)v8 + 23);
    v16.m_object = 0;
    m_targets = this->m_context->m_targets;
    v15.m_object = 0;
    v13 = m_targets->m_family[45].target.m_object;
    if ( v13 )
    {
      v15.m_object = v13;
      ++v13->m_reference_count;
    }
    vostok::render::stage_postprocess::fill_surface((vostok::render::stage_postprocess *)&v15, this, v15, v16);
    v14 = vostok::math::float4x4::identity(&v19);
    vostok::render::renderer_context::set_w(this->m_context, v14);
    qmemcpy((void *)&this->m_prev_view_matrix, &this->m_context->m_v, sizeof(this->m_prev_view_matrix));
  }
}
