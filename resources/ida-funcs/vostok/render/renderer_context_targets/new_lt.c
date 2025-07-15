void __userpurge vostok::render::renderer_context_targets::new_lt(
        vostok::render::renderer_context_targets *this@<ecx>,
        vostok::render::renderer_context_targets *index,
        DXGI_FORMAT in_format,
        vostok::math::uint2 in_size)
{
  const char *v4; // eax
  int v5; // ecx
  const char **p_m_begin; // edi
  const char *v7; // ecx
  vostok::render::resource_manager *v8; // ecx
  const char *v9; // eax
  bool v10; // zf
  vostok::render::res_texture *texture2d; // eax
  vostok::render::res_texture *v12; // ecx
  const vostok::render::res_texture *v13; // esi
  unsigned int v14; // [esp+0h] [ebp-10h]
  bool v15; // [esp+4h] [ebp-Ch]

  v4 = vostok::render::rt_index_to_name((vostok::render::enum_render_target_index)this);
  p_m_begin = (const char **)&index->m_family[v5].orig_name.m_begin;
  v7 = *p_m_begin;
  if ( *p_m_begin != v4 )
  {
    p_m_begin[1] = v7;
    *v7 = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)p_m_begin, v4);
  }
  vostok::buffer_string::assignf((vostok::buffer_string *)(p_m_begin + 19), "%s_%d", *p_m_begin, index->m_id);
  v9 = p_m_begin[38];
  p_m_begin[38] = 0;
  if ( v9 )
  {
    v10 = (*(_DWORD *)v9)-- == 1;
    if ( v10 )
      vostok::render::resource_manager::release(
        v8,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v9);
  }
  texture2d = vostok::render::resource_manager::create_texture2d(
                D3D11_USAGE_STAGING,
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                (const char *)p_m_begin + 88,
                (vostok::render::resource_manager *)in_format,
                in_size.x,
                (ID3D11Texture2D *)2,
                (const D3D11_SUBRESOURCE_DATA *)1,
                DXGI_FORMAT_UNKNOWN,
                v14,
                v15);
  v12 = 0;
  if ( texture2d )
  {
    ++texture2d->m_reference_count;
    v12 = texture2d;
  }
  v13 = (const vostok::render::res_texture *)p_m_begin[39];
  p_m_begin[39] = (const char *)v12;
  if ( v13 )
  {
    v10 = v13->m_reference_count-- == 1;
    if ( v10 )
      vostok::render::res_texture::destroy_impl(v12, v13);
  }
  index->m_memory_usage += in_size.x * in_format * vostok::render::get_format_block_size(DXGI_FORMAT_R32G32B32A32_FLOAT);
}
