void __thiscall vostok::render::stage_ambient_occlusion::execute_disabled(
        vostok::render::stage_ambient_occlusion *this)
{
  vostok::render::render_target *m_object; // eax
  const char *v2; // ecx
  ID3D11RenderTargetView *m_rt; // eax
  vostok::render::backend *m_conflicted_key_name; // ebx
  vostok::math::color *v6; // ecx
  vostok::math::color *v7; // eax
  vostok::render::backend *v8; // ecx
  int v9; // [esp+18h] [ebp-8h] BYREF
  unsigned int v10; // [esp+1Ch] [ebp-4h] BYREF

  m_object = this->m_context->m_targets->m_family[18].target.m_object;
  v2 = 0;
  if ( m_object )
  {
    v2 = (const char *)m_object;
    ++m_object->m_reference_count;
    m_rt = m_object->m_rt;
  }
  else
  {
    m_rt = 0;
  }
  m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
       + 535) != m_rt )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
    m_conflicted_key_name->m_dirty_targets.render_targets[0] = 1;
  }
  if ( m_conflicted_key_name->m_targets[1] )
  {
    m_conflicted_key_name->m_targets[1] = 0;
    m_conflicted_key_name->m_dirty_targets.render_targets[1] = 1;
  }
  if ( m_conflicted_key_name->m_targets[2] )
  {
    m_conflicted_key_name->m_targets[2] = 0;
    m_conflicted_key_name->m_dirty_targets.render_targets[2] = 1;
  }
  if ( m_conflicted_key_name->m_targets[3] )
  {
    m_conflicted_key_name->m_targets[3] = 0;
    m_conflicted_key_name->m_dirty_targets.render_targets[3] = 1;
  }
  if ( v2 )
  {
    if ( (*(_DWORD *)v2)-- == 1 )
    {
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v2);
      m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
  }
  v9 = vostok::math::color_rgba(*(float *)&clear_value, COERCE_VOSTOK_MATH_(1.0), 0.0, 1.0);
  v7 = vostok::math::color::operator*(v6, &v10, (unsigned __int8 *)&v9);
  vostok::render::backend::clear_render_targets(v8, m_conflicted_key_name, *v7);
}
