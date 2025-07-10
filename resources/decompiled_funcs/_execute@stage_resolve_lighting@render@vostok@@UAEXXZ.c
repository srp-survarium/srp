void __thiscall vostok::render::stage_resolve_lighting::execute(vostok::render::stage_resolve_lighting *this)
{
  vostok::render::res_effect *m_object; // eax
  int v3; // ecx
  vostok::math::float3 *m_eye_rays; // esi
  const char *m_conflicted_key_name; // esi
  vostok::render::render_target *v6; // eax
  vostok::render::render_target *v7; // eax
  vostok::render::resource_manager *v8; // ecx
  ID3D11RenderTargetView *m_rt; // edx
  const char *v10; // eax
  bool v11; // zf
  int v12; // ecx
  vostok::render::backend *v13; // ecx
  void **M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::render_target *v16; // [esp-1Ch] [ebp-4Ch]
  const vostok::math::float3 *v17; // [esp+Ch] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *p_m_parent; // [esp+Ch] [ebp-24h]
  unsigned int v19; // [esp+10h] [ebp-20h]
  unsigned int num_rendered; // [esp+20h] [ebp-10h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> visible_models; // [esp+24h] [ebp-Ch] BYREF

  if ( this->m_resolve_lighting_effect.m_object )
  {
    if ( this->is_enabled(this) )
    {
      m_object = this->m_resolve_lighting_effect.m_object;
      v3 = m_object->m_techniques._M_impl._M_finish - m_object->m_techniques._M_impl._M_start;
      m_eye_rays = this->m_context->m_eye_rays;
      if ( v3 )
      {
        m_object->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v3, v19);
      }
      v17 = m_eye_rays;
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        this->m_eye_ray_corner_parameter,
        (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
      + 123,
        v17);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      v16 = 0;
      v6 = this->m_context->m_targets->m_family[47].target.m_object;
      if ( v6 )
      {
        v16 = this->m_context->m_targets->m_family[47].target.m_object;
        ++v6->m_reference_count;
      }
      vostok::render::system_renderer::fill_surface(
        (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v16,
        0,
        0,
        0,
        0,
        (D3D11_VIEWPORT *)1,
        0.0,
        0.0,
        0.0,
        1.0);
      v7 = this->m_context->m_targets->m_family[47].target.m_object;
      v8 = 0;
      memset(&visible_models, 0, sizeof(visible_models));
      if ( v7 )
      {
        v8 = (vostok::render::resource_manager *)v7;
        ++v7->m_reference_count;
        m_rt = v7->m_rt;
      }
      else
      {
        m_rt = 0;
      }
      v10 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
           + 535) != m_rt )
      {
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
        *((_BYTE *)v10 + 163) = 1;
      }
      if ( *((_DWORD *)v10 + 536) )
      {
        *((_DWORD *)v10 + 536) = 0;
        *((_BYTE *)v10 + 164) = 1;
      }
      if ( *((_DWORD *)v10 + 537) )
      {
        *((_DWORD *)v10 + 537) = 0;
        *((_BYTE *)v10 + 165) = 1;
      }
      if ( *((_DWORD *)v10 + 538) )
      {
        *((_DWORD *)v10 + 538) = 0;
        *((_BYTE *)v10 + 166) = 1;
      }
      if ( v8 )
      {
        v11 = v8->sh_created-- == 1;
        if ( v11 )
        {
          vostok::render::resource_manager::release(
            v8,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (const char *)v8);
          v10 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        }
      }
      v12 = *((_DWORD *)v10 + 547);
      v11 = *((_DWORD *)v10 + 539) == v12;
      *((_DWORD *)v10 + 539) = v12;
      *((_BYTE *)v10 + 167) |= !v11;
      p_m_parent = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)&this->m_context->m_scene_view.m_object[4].m_sub_fat.m_parent;
      stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=(
        p_m_parent,
        (int)&visible_models,
        (unsigned int)p_m_parent);
      num_rendered = 0;
      vostok::render::stage_resolve_lighting::render_models(&visible_models, this, &num_rendered);
      vostok::render::backend::reset_render_targets(
        v13,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      M_start = visible_models._M_impl._M_start;
      if ( visible_models._M_impl._M_start )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
      }
    }
    else
    {
      this->execute_disabled(this);
    }
  }
}
