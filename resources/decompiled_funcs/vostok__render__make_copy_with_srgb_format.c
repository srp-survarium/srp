ID3D11Texture2D *__usercall vostok::render::make_copy_with_srgb_format@<eax>(ID3D11Resource *in_texture@<edi>)
{
  char v1; // bl
  int x; // eax
  HRESULT v4; // eax
  const char *d3d11_error_string; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  bool do_debug_break; // [esp+37h] [ebp-49h] BYREF
  ID3D11Texture2D *copy; // [esp+38h] [ebp-48h] BYREF
  D3D11_RESOURCE_DIMENSION type; // [esp+3Ch] [ebp-44h] BYREF
  ID3D11Query *out_empty_query_ptr; // [esp+40h] [ebp-40h] BYREF
  D3D11_QUERY_DESC query_desc; // [esp+44h] [ebp-3Ch] BYREF
  D3D11_TEXTURE2D_DESC texDesc; // [esp+4Ch] [ebp-34h] BYREF

  v1 = 0;
  out_empty_query_ptr = 0;
  if ( !in_texture )
    return 0;
  in_texture->GetType(in_texture, &type);
  if ( type == D3D11_RESOURCE_DIMENSION_TEXTURE2D )
  {
    x = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x;
    query_desc.MiscFlags = 0;
    query_desc.Query = D3D11_QUERY_EVENT;
    (*(void (__stdcall **)(int, D3D11_QUERY_DESC *, ID3D11Query **))(*(_DWORD *)x + 96))(
      x,
      &query_desc,
      &out_empty_query_ptr);
    ((void (__stdcall *)(ID3D11Resource *, D3D11_TEXTURE2D_DESC *))in_texture->lpVtbl[1].QueryInterface)(
      in_texture,
      &texDesc);
    texDesc.Format = vostok::render::get_typeless_format(texDesc.Format);
    copy = 0;
    v4 = (*(int (__stdcall **)(int, D3D11_TEXTURE2D_DESC *, _DWORD, ID3D11Texture2D **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                                                       + 20))(
           `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
           &texDesc,
           0,
           &copy);
    if ( !HIBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_mouse_pos.elements[1])
      && v4 < 0 )
    {
      do_debug_break = 1;
      d3d11_error_string = make_d3d11_error_string(v4);
      vostok::debug::on_error(
        &do_debug_break,
        process_error_true,
        (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_mouse_pos.elements[1]
      + 3,
        assert_untyped,
        "assertion_failed",
        d3d11_error_string,
        ".\\resource_manager.cpp",
        "vostok::render::make_copy_with_srgb_format",
        0x107u);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
    (*(void (__stdcall **)(int, ID3D11Texture2D *, ID3D11Resource *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                    + 188))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      copy,
      in_texture);
    vostok::render::end_command_list(&out_empty_query_ptr);
    return copy;
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", warning) )
    {
      v7 = vostok::core::g_log_callback;
      texDesc.Width = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          (const boost::detail::function::function_buffer *)&texDesc.MipLevels,
          (boost::detail::function::function_buffer *)&texDesc.MipLevels,
          destroy_functor_tag);
      if ( v7 )
      {
        texDesc.MipLevels = (unsigned int)v7;
        texDesc.Width = (unsigned int)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                      + 1;
      }
      else
      {
        texDesc.Width = 0;
      }
      v1 = 1;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&texDesc,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resource_manager.cpp",
        0x112u,
        "struct ID3D11Resource *__cdecl vostok::render::make_copy_with_srgb_format(struct ID3D11Resource *)",
        "render:",
        warning,
        "sRGB for 3d and 1d types not implemented yet.");
    }
    if ( (v1 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v6,
        (int *)&texDesc);
    return (ID3D11Texture2D *)in_texture;
  }
}
