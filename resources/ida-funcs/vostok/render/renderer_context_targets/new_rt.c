void __thiscall vostok::render::renderer_context_targets::new_rt(
        vostok::render::renderer_context_targets *this,
        vostok::render::renderer_context_targets *index,
        const char *in_format,
        const vostok::math::uint2 in_size,
        vostok::math::uint2 usage)
{
  const char *v5; // eax
  int v6; // ecx
  const char **p_m_begin; // edi
  const char *v8; // ecx
  vostok::render::render_target *render_target; // eax
  vostok::render::res_texture *v10; // ecx
  const char *v11; // eax
  bool v12; // zf
  int v13; // eax
  const vostok::render::res_texture *v14; // ebx
  const char *v15; // eax
  const vostok::render::res_texture *v16; // esi
  unsigned int v17; // [esp+0h] [ebp-14h]
  unsigned int v18; // [esp+4h] [ebp-10h]

  if ( LOBYTE(in_size.elements[1]) )
  {
    v5 = vostok::render::rt_index_to_name((vostok::render::enum_render_target_index)this);
    p_m_begin = (const char **)&index->m_family[v6].orig_name.m_begin;
    v8 = *p_m_begin;
    if ( *p_m_begin != v5 )
    {
      p_m_begin[1] = v8;
      *v8 = 0;
      vostok::buffer_string::operator+=((vostok::buffer_string *)p_m_begin, v5);
    }
    vostok::buffer_string::assignf((vostok::buffer_string *)(p_m_begin + 19), "%s_%d", *p_m_begin, index->m_id);
    render_target = vostok::render::resource_manager::create_render_target(
                      (vostok::render::resource_manager *)usage.x,
                      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                      (const char *)p_m_begin + 88,
                      (vostok::render::res_texture *)usage.x,
                      (ID3D11Texture2D **)usage.y,
                      in_format,
                      (vostok::render::enum_rt_usage)in_size.x,
                      0,
                      0,
                      v17,
                      v18);
    v10 = 0;
    if ( render_target )
    {
      ++render_target->m_reference_count;
      v10 = (vostok::render::res_texture *)render_target;
    }
    v11 = p_m_begin[38];
    p_m_begin[38] = (const char *)v10;
    if ( v11 )
    {
      v12 = (*(_DWORD *)v11)-- == 1;
      if ( v12 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v11);
    }
    v13 = *((_DWORD *)p_m_begin[38] + 6);
    v14 = 0;
    if ( v13 )
    {
      v14 = (const vostok::render::res_texture *)*((_DWORD *)p_m_begin[38] + 6);
      ++*(_DWORD *)(v13 + 4);
    }
    v15 = 0;
    if ( v14 )
    {
      ++v14->m_reference_count;
      v15 = (const char *)v14;
    }
    v16 = (const vostok::render::res_texture *)p_m_begin[39];
    p_m_begin[39] = v15;
    if ( v16 )
    {
      v12 = v16->m_reference_count-- == 1;
      if ( v12 )
        vostok::render::res_texture::destroy_impl(v10, v16);
    }
    if ( v14 )
    {
      v12 = v14->m_reference_count-- == 1;
      if ( v12 )
        vostok::render::res_texture::destroy_impl(v10, v14);
    }
    index->m_memory_usage += usage.y * usage.x * vostok::render::get_format_block_size((DXGI_FORMAT)in_format);
  }
}
