void __userpurge vostok::render::shader_buffer::shader_buffer(
        unsigned int size@<eax>,
        vostok::render::shader_buffer *this,
        unsigned int element_size,
        DXGI_FORMAT element_format)
{
  vostok::render::shader_buffer *v4; // ebx
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // eax
  vostok::render::untyped_buffer *m_object; // ecx
  HRESULT v8; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // ecx
  bool *d3d11_error_string; // eax
  vostok::render::resource_manager *v11; // [esp-18h] [ebp-44h]
  _DWORD v12[7]; // [esp+10h] [ebp-1Ch] BYREF

  v4 = this;
  v11 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  this->m_reference_count = 0;
  v4->m_buffer.m_object = 0;
  v4->m_size = size;
  vostok::render::resource_manager::create_buffer(size, v11, (void *)1, enum_buffer_type_vertex, 2, 1, 0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v6,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&v4->m_buffer,
    (vostok::render::hw_buffer_pool *)size);
  v12[2] = 0;
  m_object = v4->m_buffer.m_object;
  v12[3] = size >> 4;
  v12[0] = 2;
  v12[1] = 1;
  v8 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateShaderResourceView(
         vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
         m_object->m_hardware_buffer,
         (const D3D11_SHADER_RESOURCE_VIEW_DESC *)v12,
         &v4->m_buffer_shader_resource_view);
  if ( !ignore_always_33 && v8 < 0 )
  {
    HIBYTE(this) = 1;
    d3d11_error_string = (bool *)make_d3d11_error_string(v8, v9);
    vostok::debug::on_error(
      (bool *)&this + 3,
      process_error_true,
      d3d11_error_string,
      ".\\shader_buffer.cpp",
      "vostok::render::shader_buffer::shader_buffer",
      (const char *)0x1C);
    if ( vostok::debug::is_debugger_present() || HIBYTE(this) )
      __debugbreak();
  }
}
