void __userpurge vostok::render::shader_constant_buffer::shader_constant_buffer(
        const vostok::fixed_string<64> *name@<eax>,
        unsigned int size@<ecx>,
        vostok::render::shader_constant_buffer *this,
        vostok::render::enum_shader_type dest,
        _D3D_CBUFFER_TYPE type)
{
  vostok::render::shader_constant_buffer *v5; // ebx
  vostok::render::device *v7; // eax
  HRESULT v8; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // ecx
  bool *d3d11_error_string; // eax
  vostok::memory::doug_lea_allocator *v11; // esi
  char *v12; // eax
  char *v13; // eax
  unsigned int m_buffer_size; // [esp-4h] [ebp-30h]
  const char *v15; // [esp+0h] [ebp-2Ch]
  const char *v16; // [esp+4h] [ebp-28h]
  unsigned int v17; // [esp+8h] [ebp-24h]
  _DWORD v18[7]; // [esp+10h] [ebp-1Ch] BYREF

  v5 = this;
  this->m_reference_count = 0;
  vostok::fixed_string<64>::fixed_string<64>(&v5->m_name, name);
  v18[4] = 0;
  v5->m_type = type;
  v5->m_dest = dest;
  v7 = vostok::quasi_singleton<vostok::render::device>::pinst;
  v5->m_buffer_size = size;
  v5->m_changed = 1;
  v5->m_is_registered = 0;
  v18[0] = size;
  v18[1] = 2;
  v18[2] = 4;
  v18[3] = &_sbh_sizeHeaderList;
  v8 = v7->m_device->CreateBuffer(v7->m_device, (const D3D11_BUFFER_DESC *)v18, 0, &v5->m_hardware_buffer);
  if ( !ignore_always_42 && v8 < 0 )
  {
    HIBYTE(this) = 1;
    d3d11_error_string = (bool *)make_d3d11_error_string(v8, v9);
    vostok::debug::on_error(
      (bool *)&this + 3,
      process_error_true,
      d3d11_error_string,
      ".\\shader_constant_buffer.cpp",
      "vostok::render::shader_constant_buffer::shader_constant_buffer",
      (const char *)0x2D);
    if ( vostok::debug::is_debugger_present() || HIBYTE(this) )
      __debugbreak();
  }
  v11 = vostok::render::g_allocator;
  v12 = type_info::raw_name(&unsigned char `RTTI Type Descriptor');
  v13 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)v5->m_buffer_size,
          (int)v11,
          v5->m_buffer_size,
          v12,
          v15,
          v16,
          v17);
  m_buffer_size = v5->m_buffer_size;
  v5->m_buffer_data = v13;
  memset((int)v13, 0, m_buffer_size);
}
