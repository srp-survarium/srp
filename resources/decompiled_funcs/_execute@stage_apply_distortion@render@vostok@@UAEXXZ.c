void __thiscall vostok::render::stage_apply_distortion::execute(vostok::render::stage_apply_distortion *this)
{
  vostok::render::res_effect *m_object; // eax
  int v3; // ecx
  const vostok::render::renderer_context_targets *m_targets; // eax
  vostok::render::render_target *v5; // eax
  vostok::render::backend *v6; // ecx
  vostok::render::res_effect *v7; // eax
  unsigned int v8; // ecx
  const vostok::render::renderer_context_targets *v9; // eax
  vostok::render::render_target *v10; // eax
  const char *m_conflicted_key_name; // esi
  vostok::render::backend *v12; // ecx
  int v13; // eax
  bool v14; // zf
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v15; // [esp-1Ch] [ebp-34h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v16; // [esp-18h] [ebp-30h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v17; // [esp-14h] [ebp-2Ch]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v18; // [esp-10h] [ebp-28h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v19; // [esp-Ch] [ebp-24h]
  int v20; // [esp-8h] [ebp-20h]
  float v21; // [esp-4h] [ebp-1Ch]
  float pos_y; // [esp+0h] [ebp-18h]
  float size_x; // [esp+4h] [ebp-14h]
  float size_y; // [esp+8h] [ebp-10h]
  float v25; // [esp+Ch] [ebp-Ch]

  if ( this->m_sh_apply_distortion.m_object )
  {
    if ( this->is_enabled(this) )
    {
      m_object = this->m_sh_apply_distortion.m_object;
      v3 = m_object->m_techniques._M_impl._M_finish - m_object->m_techniques._M_impl._M_start;
      if ( v3 )
      {
        m_object->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v3, (int)m_object);
      }
      v25 = 1.0;
      size_y = 1.0;
      size_x = 0.0;
      pos_y = 0.0;
      v21 = 0.0;
      v20 = 1;
      v19.m_object = 0;
      v18.m_object = 0;
      v17.m_object = 0;
      v16.m_object = 0;
      m_targets = this->m_context->m_targets;
      v15.m_object = 0;
      v5 = m_targets->m_family[48].target.m_object;
      if ( v5 )
      {
        v15.m_object = v5;
        ++v5->m_reference_count;
      }
      vostok::render::system_renderer::fill_surface(
        (vostok::render::system_renderer *)&v15,
        (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
        v15,
        v16,
        v17,
        v18,
        v19,
        (D3D11_VIEWPORT *)v20,
        v21,
        pos_y,
        size_x,
        size_y,
        v25);
      vostok::render::backend::flush_rt_shader_resources(
        v6,
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      v7 = this->m_sh_apply_distortion.m_object;
      v8 = v7->m_techniques._M_impl._M_finish - v7->m_techniques._M_impl._M_start;
      if ( v8 > 1 )
      {
        v7->m_cur_technique = 1;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v8, (int)v7);
      }
      v25 = 1.0;
      size_y = 1.0;
      size_x = 0.0;
      pos_y = 0.0;
      v21 = 0.0;
      v20 = 1;
      v19.m_object = 0;
      v18.m_object = 0;
      v17.m_object = 0;
      v16.m_object = 0;
      v9 = this->m_context->m_targets;
      v15.m_object = 0;
      v10 = v9->m_family[47].target.m_object;
      if ( v10 )
      {
        v15.m_object = v10;
        ++v10->m_reference_count;
      }
      vostok::render::system_renderer::fill_surface(
        (vostok::render::system_renderer *)&v15,
        (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
        v15,
        v16,
        v17,
        v18,
        v19,
        (D3D11_VIEWPORT *)v20,
        v21,
        pos_y,
        size_x,
        size_y,
        v25);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::reset_render_targets(
        v12,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      v13 = *((_DWORD *)m_conflicted_key_name + 547);
      v14 = *((_DWORD *)m_conflicted_key_name + 539) == v13;
      *((_DWORD *)m_conflicted_key_name + 539) = v13;
      *((_BYTE *)m_conflicted_key_name + 167) |= !v14;
    }
    else
    {
      this->execute_disabled(this);
    }
  }
}
