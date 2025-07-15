void __userpurge vostok::render::shader_constant_buffer::shader_constant_buffer(
        vostok::render::shader_constant_buffer *this@<esi>,
        const vostok::fixed_string<64> *name@<eax>,
        vostok::render::enum_shader_type dest,
        _D3D_CBUFFER_TYPE type,
        unsigned int size)
{
  unsigned int v5; // ebp
  unsigned __int8 *m_begin; // edx
  unsigned int v7; // ecx
  unsigned int v8; // edi
  survarium::game *m_game; // edx
  HRESULT v10; // eax
  const char *d3d11_error_string; // eax
  int *v12; // eax
  unsigned int m_buffer_size; // [esp-4h] [ebp-2Ch]
  D3D11_BUFFER_DESC desc; // [esp+10h] [ebp-18h] BYREF

  v5 = size;
  this->m_reference_count = 0;
  m_begin = (unsigned __int8 *)name->m_begin;
  v7 = name->m_end - name->m_begin;
  this->m_name.m_max_end = (char *)&this->m_type;
  v8 = v7;
  this->m_name.m_begin = this->m_name.m_buffer;
  this->m_name.m_end = this->m_name.m_buffer;
  memcpy((unsigned __int8 *)this->m_name.m_buffer, m_begin, v7);
  this->m_name.m_end += v8;
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  *this->m_name.m_end = 0;
  this->m_type = type;
  this->m_dest = dest;
  this->m_buffer_size = v5;
  this->m_changed = 1;
  this->m_is_registered = 0;
  desc.ByteWidth = v5;
  desc.Usage = D3D11_USAGE_DEFAULT;
  desc.BindFlags = 4;
  desc.CPUAccessFlags = 0;
  desc.MiscFlags = 0;
  v10 = (*(int (__stdcall **)(int, D3D11_BUFFER_DESC *, _DWORD, ID3D11Buffer **))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.x
                                                                                + 12))(
          m_game->m_game_world.m_mouse_pos.x,
          &desc,
          0,
          &this->m_hardware_buffer);
  if ( !ignore_always_34 && v10 < 0 )
  {
    LOBYTE(size) = 1;
    d3d11_error_string = make_d3d11_error_string(v10);
    vostok::debug::on_error(
      0,
      (bool *)&size,
      process_error_true,
      &ignore_always_34,
      assert_untyped,
      "assertion_failed",
      d3d11_error_string,
      (const char *)&stru_984D24.m_available_macros.m_buffer[39],
      (const char *)&stru_984D24.m_available_macros.m_buffer[23],
      0x29u);
    if ( vostok::debug::is_debugger_present() || (_BYTE)size )
      __debugbreak();
  }
  v12 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          this->m_buffer_size);
  m_buffer_size = this->m_buffer_size;
  this->m_buffer_data = v12;
  memset((int)v12, 0, m_buffer_size);
}
