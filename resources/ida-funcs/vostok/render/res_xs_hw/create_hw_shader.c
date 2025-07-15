HRESULT __usercall vostok::render::res_xs_hw<vostok::render::gs_data>::create_hw_shader@<eax>(
        vostok::render::res_xs_hw<vostok::render::gs_data> *this@<ecx>,
        ID3D10Blob *shader_code@<eax>)
{
  const void *v4; // ebx
  unsigned int v5; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  HRESULT v7; // ebx
  vostok::render::shader_constant_table *v8; // ecx
  vostok::render::res_xs_hw<vostok::render::ps_data> *v9; // ecx
  bool has_passed_filters; // al
  void *v12; // [esp-8h] [ebp-E0h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // [esp-4h] [ebp-DCh]
  _BYTE v14[28]; // [esp+10h] [ebp-C8h] BYREF
  unsigned __int16 v15; // [esp+2Ch] [ebp-ACh]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v16; // [esp+A8h] [ebp-30h] BYREF
  SIZE_T SrcDataSize; // [esp+CCh] [ebp-Ch]
  LPCVOID pSrcData; // [esp+D0h] [ebp-8h]
  void *ppReflector; // [esp+D4h] [ebp-4h] BYREF

  ppReflector = 0;
  pSrcData = shader_code->GetBufferPointer(shader_code);
  SrcDataSize = shader_code->GetBufferSize(shader_code);
  v4 = shader_code->GetBufferPointer(shader_code);
  v5 = shader_code->GetBufferSize(shader_code);
  v7 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateGeometryShader(
         vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
         v4,
         v5,
         0,
         &this->m_shader_data.hardware_shader);
  if ( v7 < 0 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                 (const char *)2),
          v6 = v13,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v6,
        &v16);
      ppReflector = (void *)1;
      vostok::logging::append(
        &v16,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        "c:\\survarium.deploy\\sources\\vostok/render/core/dx11/res_xs_hw_impl.h",
        0x60u,
        "long __thiscall vostok::render::res_xs_hw<struct vostok::render::gs_data>::create_hw_shader(struct ID3D10Blob *)",
        (char *)&initiator_raw.initiator_tree,
        error,
        "! CreateVertexShader hr == %08x",
        v7);
    }
    if ( ((unsigned __int8)ppReflector & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
        (int *)&v16);
  }
  else
  {
    v7 = D3DReflect(pSrcData, SrcDataSize, &IID_ID3D11ShaderReflection, &ppReflector);
    (*(void (__stdcall **)(void *, _BYTE *))(*(_DWORD *)ppReflector + 12))(ppReflector, v14);
    v12 = ppReflector;
    this->m_shader_data.instruction_count = v15;
    vostok::render::shader_constant_table::parse(
      v8,
      (ID3D11ShaderReflection *)&this->m_shader_data.constants,
      (vostok::render::enum_shader_type)v12,
      enum_shader_type_geometry);
    vostok::render::res_xs_hw<vostok::render::ps_data>::parse_resources(
      v9,
      (ID3D11ShaderReflection *)ppReflector,
      &this->m_shader_data.samplers,
      &this->m_shader_data.textures,
      &this->m_shader_data.buffers);
    if ( ppReflector )
      (*(void (__stdcall **)(void *))(*(_DWORD *)ppReflector + 8))(ppReflector);
  }
  return v7;
}


HRESULT __usercall vostok::render::res_xs_hw<vostok::render::ps_data>::create_hw_shader@<eax>(
        vostok::render::res_xs_hw<vostok::render::ps_data> *this@<ecx>,
        ID3D10Blob *shader_code@<eax>)
{
  const void *v4; // ebx
  unsigned int v5; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  HRESULT v7; // ebx
  vostok::render::shader_constant_table *v8; // ecx
  vostok::render::res_xs_hw<vostok::render::ps_data> *v9; // ecx
  bool has_passed_filters; // al
  void *v12; // [esp-8h] [ebp-E0h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // [esp-4h] [ebp-DCh]
  _BYTE v14[28]; // [esp+10h] [ebp-C8h] BYREF
  unsigned __int16 v15; // [esp+2Ch] [ebp-ACh]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v16; // [esp+A8h] [ebp-30h] BYREF
  SIZE_T SrcDataSize; // [esp+CCh] [ebp-Ch]
  LPCVOID pSrcData; // [esp+D0h] [ebp-8h]
  void *ppReflector; // [esp+D4h] [ebp-4h] BYREF

  ppReflector = 0;
  pSrcData = shader_code->GetBufferPointer(shader_code);
  SrcDataSize = shader_code->GetBufferSize(shader_code);
  v4 = shader_code->GetBufferPointer(shader_code);
  v5 = shader_code->GetBufferSize(shader_code);
  v7 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreatePixelShader(
         vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
         v4,
         v5,
         0,
         &this->m_shader_data.hardware_shader);
  if ( v7 < 0 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                 (const char *)2),
          v6 = v13,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v6,
        &v16);
      ppReflector = (void *)1;
      vostok::logging::append(
        &v16,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        "c:\\survarium.deploy\\sources\\vostok/render/core/dx11/res_xs_hw_impl.h",
        0x60u,
        "long __thiscall vostok::render::res_xs_hw<struct vostok::render::ps_data>::create_hw_shader(struct ID3D10Blob *)",
        (char *)&initiator_raw.initiator_tree,
        error,
        "! CreateVertexShader hr == %08x",
        v7);
    }
    if ( ((unsigned __int8)ppReflector & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
        (int *)&v16);
  }
  else
  {
    v7 = D3DReflect(pSrcData, SrcDataSize, &IID_ID3D11ShaderReflection, &ppReflector);
    (*(void (__stdcall **)(void *, _BYTE *))(*(_DWORD *)ppReflector + 12))(ppReflector, v14);
    v12 = ppReflector;
    this->m_shader_data.instruction_count = v15;
    vostok::render::shader_constant_table::parse(
      v8,
      (ID3D11ShaderReflection *)&this->m_shader_data.constants,
      (vostok::render::enum_shader_type)v12,
      enum_shader_type_pixel);
    vostok::render::res_xs_hw<vostok::render::ps_data>::parse_resources(
      v9,
      (ID3D11ShaderReflection *)ppReflector,
      &this->m_shader_data.samplers,
      &this->m_shader_data.textures,
      &this->m_shader_data.buffers);
    if ( ppReflector )
      (*(void (__stdcall **)(void *))(*(_DWORD *)ppReflector + 8))(ppReflector);
  }
  return v7;
}


HRESULT __userpurge vostok::render::res_xs_hw<vostok::render::vs_data>::create_hw_shader@<eax>(
        ID3D10Blob *shader_code@<eax>,
        vostok::render::res_xs_hw<vostok::render::vs_data> *this,
        ID3D11VertexShader **hardware_shader)
{
  void *v4; // ebx
  unsigned int v5; // esi
  vostok::render::res_signature *signature; // eax
  vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> *p_signature; // ecx
  vostok::render::res_signature *v8; // edx
  vostok::render::res_pass *m_object; // eax
  ID3D11Device *m_device; // eax
  ID3D11Device_vtbl *v12; // ecx

  v4 = shader_code->GetBufferPointer(shader_code);
  v5 = shader_code->GetBufferSize(shader_code);
  signature = vostok::render::resource_manager::create_signature(
                shader_code,
                (vostok::render::res_signature *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  p_signature = &this->m_shader_data.signature;
  v8 = 0;
  if ( signature )
  {
    ++signature->m_reference_count;
    v8 = signature;
  }
  m_object = (vostok::render::res_pass *)p_signature->m_object;
  p_signature->m_object = v8;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        m_object);
  }
  m_device = vostok::quasi_singleton<vostok::render::device>::pinst->m_device;
  v12 = m_device->lpVtbl;
  blobs_size_0 += v5;
  return v12->CreateVertexShader(m_device, v4, v5, 0, hardware_shader);
}


HRESULT __usercall vostok::render::res_xs_hw<vostok::render::vs_data>::create_hw_shader@<eax>(
        vostok::render::res_xs_hw<vostok::render::vs_data> *this@<ecx>,
        ID3D10Blob *shader_code@<eax>)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  HRESULT hw_shader; // ebx
  vostok::render::shader_constant_table *v6; // ecx
  vostok::render::res_xs_hw<vostok::render::ps_data> *v7; // ecx
  bool has_passed_filters; // al
  void *v10; // [esp-8h] [ebp-E0h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp-4h] [ebp-DCh]
  _BYTE v12[28]; // [esp+10h] [ebp-C8h] BYREF
  unsigned __int16 v13; // [esp+2Ch] [ebp-ACh]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+A8h] [ebp-30h] BYREF
  SIZE_T SrcDataSize; // [esp+CCh] [ebp-Ch]
  LPCVOID pSrcData; // [esp+D0h] [ebp-8h]
  void *ppReflector; // [esp+D4h] [ebp-4h] BYREF

  ppReflector = 0;
  pSrcData = shader_code->GetBufferPointer(shader_code);
  SrcDataSize = shader_code->GetBufferSize(shader_code);
  hw_shader = vostok::render::res_xs_hw<vostok::render::vs_data>::create_hw_shader(
                shader_code,
                this,
                &this->m_shader_data.hardware_shader);
  if ( hw_shader < 0 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                 (const char *)2),
          v4 = v11,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v4,
        &v14);
      ppReflector = (void *)1;
      vostok::logging::append(
        &v14,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        "c:\\survarium.deploy\\sources\\vostok/render/core/dx11/res_xs_hw_impl.h",
        0x60u,
        "long __thiscall vostok::render::res_xs_hw<struct vostok::render::vs_data>::create_hw_shader(struct ID3D10Blob *)",
        (char *)&initiator_raw.initiator_tree,
        error,
        "! CreateVertexShader hr == %08x",
        hw_shader);
    }
    if ( ((unsigned __int8)ppReflector & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
        (int *)&v14);
  }
  else
  {
    hw_shader = D3DReflect(pSrcData, SrcDataSize, &IID_ID3D11ShaderReflection, &ppReflector);
    (*(void (__stdcall **)(void *, _BYTE *))(*(_DWORD *)ppReflector + 12))(ppReflector, v12);
    v10 = ppReflector;
    this->m_shader_data.instruction_count = v13;
    vostok::render::shader_constant_table::parse(
      v6,
      (ID3D11ShaderReflection *)&this->m_shader_data.constants,
      (vostok::render::enum_shader_type)v10,
      enum_shader_type_vertex);
    vostok::render::res_xs_hw<vostok::render::ps_data>::parse_resources(
      v7,
      (ID3D11ShaderReflection *)ppReflector,
      &this->m_shader_data.samplers,
      &this->m_shader_data.textures,
      &this->m_shader_data.buffers);
    if ( ppReflector )
      (*(void (__stdcall **)(void *))(*(_DWORD *)ppReflector + 8))(ppReflector);
  }
  return hw_shader;
}
