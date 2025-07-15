void __thiscall vostok::render::stage_lights::execute_disabled(vostok::render::stage_lights *this)
{
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v2; // edi
  vostok::render::render_target *v3; // eax
  vostok::render::resource_manager *v4; // ecx
  ID3D11RenderTargetView *m_rt; // eax
  char *m_conflicted_key_name; // esi
  ID3D11RenderTargetView *v7; // eax
  bool v8; // zf
  int v9; // eax
  int v10; // edi
  int v11; // eax
  vostok::render::backend *v12; // ecx
  float packed_color; // [esp+14h] [ebp-4h]

  m_object = this->m_context->m_targets->m_family[28].target.m_object;
  v2 = 0;
  if ( m_object )
  {
    v2 = this->m_context->m_targets->m_family[28].target.m_object;
    ++m_object->m_reference_count;
  }
  v3 = this->m_context->m_targets->m_family[26].target.m_object;
  v4 = 0;
  if ( v3 )
  {
    v4 = (vostok::render::resource_manager *)v3;
    ++v3->m_reference_count;
    m_rt = v3->m_rt;
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
  if ( v2 )
    v7 = v2->m_rt;
  else
    v7 = 0;
  if ( *((ID3D11RenderTargetView **)m_conflicted_key_name + 536) != v7 )
  {
    *((_DWORD *)m_conflicted_key_name + 536) = v7;
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
  if ( v4 )
  {
    v8 = v4->sh_created-- == 1;
    if ( v8 )
    {
      vostok::render::resource_manager::release(
        v4,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v4);
      m_conflicted_key_name = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
  }
  if ( v2 )
  {
    v8 = v2->m_reference_count-- == 1;
    if ( v8 )
    {
      vostok::render::resource_manager::release(
        v4,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v2);
      m_conflicted_key_name = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
  }
  v9 = *((_DWORD *)m_conflicted_key_name + 547);
  v8 = *((_DWORD *)m_conflicted_key_name + 539) == v9;
  *((_DWORD *)m_conflicted_key_name + 539) = v9;
  m_conflicted_key_name[167] |= !v8;
  packed_color = powf(0.125, 0.5);
  v10 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 0.0);
  v11 = vostok::math::color_rgba(packed_color, (vostok::math *)LODWORD(packed_color), packed_color, packed_color);
  vostok::render::backend::clear_render_targets(
    v12,
    m_conflicted_key_name,
    (vostok::math::color)v11,
    (vostok::math::color)v10,
    (vostok::math::color)v10,
    (vostok::math::color)v10);
}
