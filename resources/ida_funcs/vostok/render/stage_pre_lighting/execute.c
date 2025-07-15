void __thiscall vostok::render::stage_pre_lighting::execute(vostok::render::stage_pre_lighting *this)
{
  vostok::render::backend *m_conflicted_key_name; // ebp
  ID3D11DepthStencilView *m_base_zb; // eax
  bool v4; // zf
  vostok::render::renderer_context *m_context; // edx
  vostok::render::render_target *m_object; // eax
  ID3D11RenderTargetView *v7; // ebx
  const vostok::render::render_target *v8; // esi
  vostok::render::render_target *v9; // eax
  vostok::render::renderer_context *v10; // ecx
  vostok::render::render_target *v11; // eax
  vostok::render::resource_manager *v12; // ecx
  int v13; // esi
  vostok::render::backend *v14; // ecx
  vostok::render::renderer_context *v15; // edx
  vostok::render::render_target *v16; // eax
  vostok::render::resource_manager *v17; // ecx
  ID3D11RenderTargetView *m_rt; // edx
  vostok::render::backend *v19; // eax
  vostok::render::render_target *v20; // eax
  vostok::render::resource_manager *v21; // ecx
  ID3D11RenderTargetView *v22; // edx
  vostok::render::backend *v23; // eax
  const vostok::math::float4x4 *v24; // eax
  const char *v25; // esi
  vostok::render::backend *v26; // ecx
  int v27; // eax
  vostok::render::render_target *rt1; // [esp+1Ch] [ebp-48h]
  vostok::math::float4x4 v30; // [esp+24h] [ebp-40h] BYREF

  if ( ((unsigned __int8 (__fastcall *)(vostok::render::stage_pre_lighting *))this->is_enabled)(this) )
  {
    m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    this->m_context->m_light_marker_id = 4;
    m_base_zb = m_conflicted_key_name->m_base_zb;
    v4 = m_conflicted_key_name->m_zb == m_base_zb;
    m_conflicted_key_name->m_zb = m_base_zb;
    m_conflicted_key_name->m_dirty_targets.depth_stencil |= !v4;
    m_context = this->m_context;
    m_object = m_context->m_targets->m_family[8].target.m_object;
    v7 = 0;
    v8 = 0;
    if ( m_object )
    {
      v8 = m_context->m_targets->m_family[8].target.m_object;
      ++m_object->m_reference_count;
    }
    v9 = this->m_context->m_targets->m_family[28].target.m_object;
    rt1 = 0;
    if ( v9 )
    {
      ++v9->m_reference_count;
      rt1 = v9;
    }
    v10 = this->m_context;
    v11 = v10->m_targets->m_family[26].target.m_object;
    if ( v11 )
    {
      v7 = (ID3D11RenderTargetView *)v10->m_targets->m_family[26].target.m_object;
      ++v11->m_reference_count;
    }
    vostok::render::backend::set_render_targets(v7, rt1, v8, 0, m_conflicted_key_name);
    if ( v7 )
    {
      v4 = v7->lpVtbl-- == (ID3D11RenderTargetView_vtbl *)1;
      if ( v4 )
      {
        vostok::render::resource_manager::release(
          v12,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v7);
        m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
    }
    if ( rt1 )
    {
      v4 = rt1->m_reference_count-- == 1;
      if ( v4 )
      {
        vostok::render::resource_manager::release(
          v12,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)rt1);
        m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
    }
    if ( v8 )
    {
      v4 = v8->m_reference_count-- == 1;
      if ( v4 )
      {
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v8);
        m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
    }
    v13 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 0.0);
    vostok::render::backend::clear_render_targets(v14, m_conflicted_key_name, (vostok::math::color)v13);
    v15 = this->m_context;
    v16 = v15->m_targets->m_family[50].target.m_object;
    v17 = 0;
    if ( v16 )
    {
      v17 = (vostok::render::resource_manager *)v15->m_targets->m_family[50].target.m_object;
      ++v16->m_reference_count;
      m_rt = v16->m_rt;
    }
    else
    {
      m_rt = 0;
    }
    v19 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
         + 535) != m_rt )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
      v19->m_dirty_targets.render_targets[0] = 1;
    }
    if ( v19->m_targets[1] )
    {
      v19->m_targets[1] = 0;
      v19->m_dirty_targets.render_targets[1] = 1;
    }
    if ( v19->m_targets[2] )
    {
      v19->m_targets[2] = 0;
      v19->m_dirty_targets.render_targets[2] = 1;
    }
    if ( v19->m_targets[3] )
    {
      v19->m_targets[3] = 0;
      v19->m_dirty_targets.render_targets[3] = 1;
    }
    if ( v17 )
    {
      v4 = v17->sh_created-- == 1;
      if ( v4 )
      {
        vostok::render::resource_manager::release(
          v17,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v17);
        v19 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
    }
    vostok::render::backend::clear_render_targets((vostok::render::backend *)v17, v19, (vostok::math::color)v13);
    v20 = this->m_context->m_targets->m_family[49].target.m_object;
    v21 = 0;
    if ( v20 )
    {
      v21 = (vostok::render::resource_manager *)this->m_context->m_targets->m_family[49].target.m_object;
      ++v20->m_reference_count;
      v22 = v20->m_rt;
    }
    else
    {
      v22 = 0;
    }
    v23 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
         + 535) != v22 )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v22;
      v23->m_dirty_targets.render_targets[0] = 1;
    }
    if ( v23->m_targets[1] )
    {
      v23->m_targets[1] = 0;
      v23->m_dirty_targets.render_targets[1] = 1;
    }
    if ( v23->m_targets[2] )
    {
      v23->m_targets[2] = 0;
      v23->m_dirty_targets.render_targets[2] = 1;
    }
    if ( v23->m_targets[3] )
    {
      v23->m_targets[3] = 0;
      v23->m_dirty_targets.render_targets[3] = 1;
    }
    if ( v21 )
    {
      v4 = v21->sh_created-- == 1;
      if ( v4 )
      {
        vostok::render::resource_manager::release(
          v21,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v21);
        v23 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
    }
    vostok::render::backend::clear_render_targets((vostok::render::backend *)v21, v23, (vostok::math::color)v13);
    v24 = vostok::math::float4x4::identity(&v30);
    vostok::render::renderer_context::set_w((int)this->m_context, v24, this->m_context);
    v25 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    vostok::render::backend::reset_render_targets(
      v26,
      (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
    v27 = *((_DWORD *)v25 + 547);
    *((_BYTE *)v25 + 167) |= *((_DWORD *)v25 + 539) != v27;
    *((_DWORD *)v25 + 539) = v27;
  }
  else
  {
    this->execute_disabled(this);
  }
}
