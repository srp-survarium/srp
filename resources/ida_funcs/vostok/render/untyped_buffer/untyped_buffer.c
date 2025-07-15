void __userpurge vostok::render::untyped_buffer::untyped_buffer(
        vostok::render::untyped_buffer *this@<esi>,
        vostok::render::enum_buffer_type type@<eax>,
        bool is_dynamic@<dl>,
        unsigned int size,
        const void *data,
        bool staging)
{
  int x; // eax
  HRESULT v7; // eax
  const char *d3d11_error_string; // eax
  D3D11_SUBRESOURCE_DATA init_data; // [esp+Ch] [ebp-24h] BYREF
  D3D11_BUFFER_DESC desc; // [esp+18h] [ebp-18h] BYREF

  this->m_size = size;
  desc.ByteWidth = size;
  this->m_type = type;
  desc.BindFlags = 2 - (type != enum_buffer_type_index);
  this->m_reference_count = 0;
  desc.Usage = is_dynamic ? D3D11_USAGE_DYNAMIC : D3D11_USAGE_DEFAULT;
  desc.CPUAccessFlags = is_dynamic ? (unsigned int)&_sbh_sizeHeaderList : 0;
  desc.MiscFlags = 0;
  if ( staging )
  {
    desc.Usage = D3D11_USAGE_STAGING;
    desc.BindFlags = 0;
    desc.CPUAccessFlags = (unsigned int)&loc_20000;
  }
  x = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x;
  init_data.pSysMem = data;
  init_data.SysMemPitch = 0;
  init_data.SysMemSlicePitch = 0;
  v7 = (*(int (__stdcall **)(int, D3D11_BUFFER_DESC *, D3D11_SUBRESOURCE_DATA *, ID3D11Buffer **))(*(_DWORD *)x + 12))(
         x,
         &desc,
         data != 0 ? &init_data : 0,
         &this->m_hardware_buffer);
  if ( !LOBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_to_bind)
    && v7 < 0 )
  {
    staging = 1;
    d3d11_error_string = make_d3d11_error_string(v7);
    vostok::debug::on_error(
      &staging,
      process_error_true,
      (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_to_bind,
      assert_untyped,
      "assertion_failed",
      d3d11_error_string,
      ".\\untyped_buffer.cpp",
      "vostok::render::untyped_buffer::untyped_buffer",
      0x2Au);
    if ( vostok::debug::is_debugger_present() || staging )
      __debugbreak();
  }
}
