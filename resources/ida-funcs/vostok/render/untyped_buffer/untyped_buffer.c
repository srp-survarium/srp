void __thiscall vostok::render::untyped_buffer::untyped_buffer(
        vostok::render::untyped_buffer *this,
        const unsigned int size,
        unsigned int stride,
        unsigned int data,
        unsigned __int8 *type,
        int is_dynamic,
        const bool staging,
        char a8)
{
  int v8; // esi
  vostok::render::hw_buffer_pool_range *v9; // edi
  vostok::render::resource_manager *v10; // eax
  vostok::render::hw_buffer_pool *m_indices_pool; // ecx
  ID3D11Buffer *m_hw_buffer; // eax
  int v13; // edx
  HRESULT v14; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v15; // ecx
  bool *d3d11_error_string; // eax
  const char *v17; // [esp+0h] [ebp-38h]
  char v18; // [esp+13h] [ebp-25h] BYREF
  _DWORD v19[3]; // [esp+14h] [ebp-24h] BYREF
  unsigned int v20; // [esp+20h] [ebp-18h] BYREF
  int v21; // [esp+24h] [ebp-14h]
  int v22; // [esp+28h] [ebp-10h]
  HINSTANCE__ *v23; // [esp+2Ch] [ebp-Ch]
  int v24; // [esp+30h] [ebp-8h]

  v8 = is_dynamic;
  v9 = (vostok::render::hw_buffer_pool_range *)(size + 4);
  *(_DWORD *)size = 0;
  *(_DWORD *)(size + 4) = 0;
  *(_DWORD *)(size + 8) = 0;
  *(_DWORD *)(size + 12) = 0;
  *(_DWORD *)(size + 20) = stride;
  *(_DWORD *)(size + 24) = data;
  *(_DWORD *)(size + 28) = is_dynamic;
  *(_DWORD *)(size + 8) = 0;
  if ( staging || a8 )
    goto LABEL_19;
  v10 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  if ( vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_vertices_pool )
  {
    m_indices_pool = vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_indices_pool;
    if ( m_indices_pool )
    {
      if ( is_dynamic == 1 )
      {
        if ( vostok::render::hw_buffer_pool::allocate(m_indices_pool, (int)m_indices_pool, v9, type, stride, data) )
        {
LABEL_7:
          m_hw_buffer = v9->owner->m_hw_buffer;
          *(_DWORD *)(size + 16) = m_hw_buffer;
          m_hw_buffer->AddRef(m_hw_buffer);
          return;
        }
        if ( debug_macro_helper_ignore_always_58 )
          goto LABEL_18;
        v18 = 0;
        vostok::debug::on_error(
          (bool *)&v18,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          ".\\untyped_buffer.cpp",
          "vostok::render::untyped_buffer::untyped_buffer",
          (const char *)0x33,
          "No enough memory in indices pool.",
          v17);
        if ( !vostok::debug::is_debugger_present() && !v18 )
          goto LABEL_18;
        __debugbreak();
        v10 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
        v8 = is_dynamic;
      }
      if ( !v8 )
      {
        if ( vostok::render::hw_buffer_pool::allocate(m_indices_pool, (int)v10->m_vertices_pool, v9, type, stride, data) )
          goto LABEL_7;
        if ( !debug_macro_helper_ignore_always_59 )
        {
          v18 = 0;
          vostok::debug::on_error(
            (bool *)&v18,
            process_error_true,
            0,
            "assertion_failed",
            "fatal error",
            ".\\untyped_buffer.cpp",
            "vostok::render::untyped_buffer::untyped_buffer",
            (const char *)0x4E,
            "No enough memory in vertices pool.",
            v17);
          if ( vostok::debug::is_debugger_present() || v18 )
            __debugbreak();
        }
LABEL_18:
        v8 = is_dynamic;
LABEL_19:
        v10 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
      }
    }
  }
  v20 = stride;
  v21 = staging ? 2 : 0;
  if ( v8 == 1 )
    v22 = 2;
  else
    v22 = v8 != 0 ? 8 : 1;
  v23 = staging ? &_sbh_sizeHeaderList : 0;
  v24 = 0;
  if ( a8 )
  {
    v21 = 3;
    v22 = 0;
    v23 = (HINSTANCE__ *)&loc_20000;
  }
  v19[1] = 0;
  v19[2] = 0;
  v13 = *(_DWORD *)(size + 28);
  v19[0] = type;
  if ( v13 == 1 )
  {
    v10->m_total_index_buffers_size += *(_DWORD *)(size + 20);
  }
  else if ( !v13 )
  {
    v10->m_total_vertex_buffers_size += *(_DWORD *)(size + 20);
  }
  v14 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateBuffer(
          vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
          (const D3D11_BUFFER_DESC *)&v20,
          type != 0 ? (const D3D11_SUBRESOURCE_DATA *)v19 : 0,
          (ID3D11Buffer **)(size + 16));
  if ( !ignore_always_14 && v14 < 0 )
  {
    v18 = 1;
    d3d11_error_string = (bool *)make_d3d11_error_string(v14, v15);
    vostok::debug::on_error(
      (bool *)&v18,
      process_error_true,
      d3d11_error_string,
      ".\\untyped_buffer.cpp",
      "vostok::render::untyped_buffer::untyped_buffer",
      (const char *)0x70);
    if ( vostok::debug::is_debugger_present() || v18 )
      __debugbreak();
  }
}
