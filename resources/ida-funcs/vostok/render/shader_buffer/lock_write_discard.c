void *__thiscall vostok::render::shader_buffer::lock_write_discard(vostok::render::shader_buffer *this)
{
  HRESULT v1; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v2; // ecx
  bool *d3d11_error_string; // eax
  _DWORD v5[3]; // [esp+8h] [ebp-10h] BYREF
  char v6; // [esp+17h] [ebp-1h] BYREF

  v1 = vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Map(
         vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
         this->m_buffer.m_object->m_hardware_buffer,
         0,
         D3D11_MAP_WRITE_DISCARD,
         0,
         (D3D11_MAPPED_SUBRESOURCE *)v5);
  if ( !ignore_always_34 && v1 < 0 )
  {
    v6 = 1;
    d3d11_error_string = (bool *)make_d3d11_error_string(v1, v2);
    vostok::debug::on_error(
      (bool *)&v6,
      process_error_true,
      d3d11_error_string,
      ".\\shader_buffer.cpp",
      "vostok::render::shader_buffer::lock_write_discard",
      (const char *)0x2E);
    if ( vostok::debug::is_debugger_present() || v6 )
      __debugbreak();
  }
  return (void *)v5[0];
}
