void __thiscall vostok::render::stage_decals_accumulate::execute_disabled(
        vostok::render::stage_decals_accumulate *this)
{
  vostok::render::render_target *m_object; // eax
  const char *v2; // ecx
  ID3D11RenderTargetView *m_rt; // eax
  char *m_conflicted_key_name; // esi
  int v6; // eax
  vostok::render::backend *v7; // ecx

  m_object = this->m_context->m_targets->m_family[25].target.m_object;
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
  m_conflicted_key_name = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
       + 535) != m_rt )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
    m_conflicted_key_name[163] = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 536) )
  {
    *((_DWORD *)m_conflicted_key_name + 536) = 0;
    m_conflicted_key_name[164] = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 537) )
  {
    *((_DWORD *)m_conflicted_key_name + 537) = 0;
    m_conflicted_key_name[165] = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 538) )
  {
    *((_DWORD *)m_conflicted_key_name + 538) = 0;
    m_conflicted_key_name[166] = 1;
  }
  if ( v2 )
  {
    if ( (*(_DWORD *)v2)-- == 1 )
    {
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v2);
      m_conflicted_key_name = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
  }
  v6 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 0.0);
  vostok::render::backend::clear_render_targets(
    v7,
    m_conflicted_key_name,
    (vostok::math::color)v6,
    (vostok::math::color)v6,
    (vostok::math::color)v6,
    (vostok::math::color)v6);
}
