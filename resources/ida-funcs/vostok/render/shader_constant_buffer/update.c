void __usercall vostok::render::shader_constant_buffer::update(
        vostok::render::shader_constant_buffer *this@<ecx>,
        int a2@<esi>)
{
  HRESULT v2; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  bool *d3d11_error_string; // eax
  unsigned __int8 *dst; // [esp+8h] [ebp-10h] BYREF
  char v6; // [esp+17h] [ebp-1h] BYREF

  if ( *(_BYTE *)(a2 + 100) )
  {
    v2 = vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Map(
           vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
           *(ID3D11Resource **)(a2 + 96),
           0,
           D3D11_MAP_WRITE_DISCARD,
           0,
           (D3D11_MAPPED_SUBRESOURCE *)&dst);
    if ( !ignore_always_43 && v2 < 0 )
    {
      v6 = 1;
      d3d11_error_string = (bool *)make_d3d11_error_string(v2, v3);
      vostok::debug::on_error(
        (bool *)&v6,
        process_error_true,
        d3d11_error_string,
        ".\\shader_constant_buffer.cpp",
        "vostok::render::shader_constant_buffer::update",
        (const char *)0x5C);
      if ( vostok::debug::is_debugger_present() || v6 )
        __debugbreak();
    }
    memcpy(dst, *(unsigned __int8 **)(a2 + 88), *(_DWORD *)(a2 + 92));
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Unmap(
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
      *(ID3D11Resource **)(a2 + 96),
      0);
    *(_BYTE *)(a2 + 100) = 0;
  }
}
