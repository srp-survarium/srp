HRESULT __userpurge vostok::render::res_xs_hw<vostok::render::gs_data>::create_hw_shader@<eax>(
        ID3D10Blob *shader_code@<eax>,
        vostok::render::res_xs_hw<vostok::render::gs_data> *this,
        ID3D11GeometryShader **hardware_shader)
{
  void *v4; // edi
  unsigned int v5; // eax

  v4 = shader_code->GetBufferPointer(shader_code);
  v5 = shader_code->GetBufferSize(shader_code);
  return (*(int (__stdcall **)(int, void *, unsigned int, _DWORD, vostok::render::res_xs_hw<vostok::render::gs_data> *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x + 52))(
           `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
           v4,
           v5,
           0,
           this);
}


HRESULT __usercall vostok::render::res_xs_hw<vostok::render::gs_data>::create_hw_shader@<eax>(
        vostok::render::res_xs_hw<vostok::render::gs_data> *this@<ecx>,
        ID3D10Blob *shader_code@<eax>)
{
  void *(__stdcall *GetBufferPointer)(ID3D10Blob *); // ecx
  const void *v5; // ebx
  ID3D11ShaderReflection *v6; // eax
  void *(__stdcall *v7)(ID3D10Blob *); // edx
  int v8; // ebp
  unsigned int v9; // eax
  HRESULT v10; // esi
  vostok::render::shader_constant_table *v11; // ecx
  void (__cdecl *v13)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  char v14; // bl
  void (__cdecl *v15)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  ID3D11ShaderReflection *v16; // [esp+14h] [ebp-DCh]
  ID3D11ShaderReflection *shader_reflection; // [esp+2Ch] [ebp-C4h] BYREF
  int v18; // [esp+30h] [ebp-C0h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+34h] [ebp-BCh] BYREF
  _D3D11_SHADER_DESC shader_desc; // [esp+54h] [ebp-9Ch] BYREF

  GetBufferPointer = shader_code->GetBufferPointer;
  v18 = 0;
  v5 = GetBufferPointer(shader_code);
  v6 = (ID3D11ShaderReflection *)shader_code->GetBufferSize(shader_code);
  v7 = shader_code->GetBufferPointer;
  shader_reflection = v6;
  v8 = (int)v7(shader_code);
  v9 = shader_code->GetBufferSize(shader_code);
  v10 = (*(int (__stdcall **)(int, int, unsigned int, _DWORD, ID3D11GeometryShader **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                                                      + 52))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
          v8,
          v9,
          0,
          &this->m_shader_data.hardware_shader);
  if ( v10 < 0 )
  {
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
    {
      v14 = v18;
    }
    else
    {
      v13 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v13 )
      {
        log_callback.functor.obj_ptr = v13;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v14 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        (const char *)&stru_984D24.m_available_macros.m_buffer[84],
        0x60u,
        (const char *)&stru_984D24.m_available_macros.m_buffer[101],
        "render:",
        error,
        (const char *)&stru_984D24.m_available_macros.m_buffer[47],
        v10);
    }
    if ( (v14 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v15 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v15 )
        v15(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  else
  {
    v10 = D3DReflect(v5, (SIZE_T)shader_reflection, &IID_ID3D11ShaderReflection, (void **)&shader_reflection);
    shader_reflection->GetDesc(shader_reflection, &shader_desc);
    LOWORD(v11) = shader_desc.InstructionCount;
    v16 = shader_reflection;
    this->m_shader_data.instruction_count = shader_desc.InstructionCount;
    vostok::render::shader_constant_table::parse(
      v11,
      (ID3D11ShaderReflection *)&this->m_shader_data.constants,
      (vostok::render::enum_shader_type)v16);
    vostok::render::res_xs_hw<vostok::render::ps_data>::parse_resources(
      (vostok::render::res_xs_hw<vostok::render::ps_data> *)&this->m_shader_data.textures,
      shader_reflection,
      &this->m_shader_data.samplers,
      &this->m_shader_data.textures);
    if ( shader_reflection )
    {
      shader_reflection->Release(shader_reflection);
      return v10;
    }
  }
  return v10;
}


HRESULT __userpurge vostok::render::res_xs_hw<vostok::render::ps_data>::create_hw_shader@<eax>(
        ID3D10Blob *shader_code@<eax>,
        vostok::render::res_xs_hw<vostok::render::ps_data> *this,
        ID3D11PixelShader **hardware_shader)
{
  void *v4; // edi
  unsigned int v5; // eax

  v4 = shader_code->GetBufferPointer(shader_code);
  v5 = shader_code->GetBufferSize(shader_code);
  return (*(int (__stdcall **)(int, void *, unsigned int, _DWORD, vostok::render::res_xs_hw<vostok::render::ps_data> *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x + 60))(
           `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
           v4,
           v5,
           0,
           this);
}


HRESULT __usercall vostok::render::res_xs_hw<vostok::render::ps_data>::create_hw_shader@<eax>(
        vostok::render::res_xs_hw<vostok::render::ps_data> *this@<ecx>,
        ID3D10Blob *shader_code@<eax>)
{
  void *(__stdcall *GetBufferPointer)(ID3D10Blob *); // ecx
  const void *v5; // ebx
  ID3D11ShaderReflection *v6; // eax
  void *(__stdcall *v7)(ID3D10Blob *); // edx
  int v8; // ebp
  unsigned int v9; // eax
  HRESULT v10; // esi
  vostok::render::shader_constant_table *v11; // ecx
  void (__cdecl *v13)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  char v14; // bl
  void (__cdecl *v15)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  ID3D11ShaderReflection *v16; // [esp+14h] [ebp-DCh]
  ID3D11ShaderReflection *shader_reflection; // [esp+2Ch] [ebp-C4h] BYREF
  int v18; // [esp+30h] [ebp-C0h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+34h] [ebp-BCh] BYREF
  _D3D11_SHADER_DESC shader_desc; // [esp+54h] [ebp-9Ch] BYREF

  GetBufferPointer = shader_code->GetBufferPointer;
  v18 = 0;
  v5 = GetBufferPointer(shader_code);
  v6 = (ID3D11ShaderReflection *)shader_code->GetBufferSize(shader_code);
  v7 = shader_code->GetBufferPointer;
  shader_reflection = v6;
  v8 = (int)v7(shader_code);
  v9 = shader_code->GetBufferSize(shader_code);
  v10 = (*(int (__stdcall **)(int, int, unsigned int, _DWORD, ID3D11PixelShader **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                                                   + 60))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
          v8,
          v9,
          0,
          &this->m_shader_data.hardware_shader);
  if ( v10 < 0 )
  {
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
    {
      v14 = v18;
    }
    else
    {
      v13 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v13 )
      {
        log_callback.functor.obj_ptr = v13;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v14 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        (const char *)&stru_984D24.m_available_macros.m_buffer[84],
        0x60u,
        &stru_984D24.m_working_macro_list.m_buffer[0].m_store[4],
        "render:",
        error,
        (const char *)&stru_984D24.m_available_macros.m_buffer[47],
        v10);
    }
    if ( (v14 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v15 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v15 )
        v15(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  else
  {
    v10 = D3DReflect(v5, (SIZE_T)shader_reflection, &IID_ID3D11ShaderReflection, (void **)&shader_reflection);
    shader_reflection->GetDesc(shader_reflection, &shader_desc);
    LOWORD(v11) = shader_desc.InstructionCount;
    v16 = shader_reflection;
    this->m_shader_data.instruction_count = shader_desc.InstructionCount;
    vostok::render::shader_constant_table::parse(
      v11,
      (ID3D11ShaderReflection *)&this->m_shader_data.constants,
      (vostok::render::enum_shader_type)v16);
    vostok::render::res_xs_hw<vostok::render::ps_data>::parse_resources(
      (vostok::render::res_xs_hw<vostok::render::ps_data> *)&this->m_shader_data.textures,
      shader_reflection,
      &this->m_shader_data.samplers,
      &this->m_shader_data.textures);
    if ( shader_reflection )
    {
      shader_reflection->Release(shader_reflection);
      return v10;
    }
  }
  return v10;
}


HRESULT __userpurge vostok::render::res_xs_hw<vostok::render::vs_data>::create_hw_shader@<eax>(
        vostok::render::res_xs_hw<vostok::render::vs_data> *this@<edi>,
        ID3D10Blob *shader_code@<esi>,
        ID3D11VertexShader **hardware_shader)
{
  void *v3; // ebx
  unsigned int v4; // ebp
  vostok::render::resource_manager *signature; // eax
  const vostok::render::res_signature *v6; // ecx
  const vostok::render::res_signature *m_object; // eax

  v3 = shader_code->GetBufferPointer(shader_code);
  v4 = shader_code->GetBufferSize(shader_code);
  signature = vostok::render::resource_manager::create_signature(
                shader_code,
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v6 = 0;
  if ( signature )
  {
    ++signature->sh_created;
    v6 = (const vostok::render::res_signature *)signature;
  }
  m_object = this->m_shader_data.signature.m_object;
  this->m_shader_data.signature.m_object = v6;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  return (*(int (__stdcall **)(int, void *, unsigned int, _DWORD, ID3D11VertexShader **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                                                        + 48))(
           `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
           v3,
           v4,
           0,
           hardware_shader);
}


HRESULT __usercall vostok::render::res_xs_hw<vostok::render::vs_data>::create_hw_shader@<eax>(
        vostok::render::res_xs_hw<vostok::render::vs_data> *this@<ecx>,
        ID3D10Blob *shader_code@<eax>)
{
  const void *v4; // ebp
  SIZE_T v5; // ebx
  HRESULT hw_shader; // esi
  vostok::render::shader_constant_table *v7; // ecx
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  char v10; // bl
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  ID3D11ShaderReflection *v12; // [esp-8h] [ebp-DCh]
  ID3D11ShaderReflection *shader_reflection; // [esp+14h] [ebp-C0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-BCh] BYREF
  _D3D11_SHADER_DESC shader_desc; // [esp+38h] [ebp-9Ch] BYREF

  shader_reflection = 0;
  v4 = shader_code->GetBufferPointer(shader_code);
  v5 = shader_code->GetBufferSize(shader_code);
  hw_shader = vostok::render::res_xs_hw<vostok::render::vs_data>::create_hw_shader(
                this,
                shader_code,
                &this->m_shader_data.hardware_shader);
  if ( hw_shader < 0 )
  {
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", error) )
    {
      v10 = (char)shader_reflection;
    }
    else
    {
      v9 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v9 )
      {
        log_callback.functor.obj_ptr = v9;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v10 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        (const char *)&stru_984D24.m_available_macros.m_buffer[84],
        0x60u,
        (const char *)&stru_984D24.m_available_macros.m_buffer[55],
        "render:",
        error,
        (const char *)&stru_984D24.m_available_macros.m_buffer[47],
        hw_shader);
    }
    if ( (v10 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v11 )
        v11(&log_callback.functor, &log_callback.functor, 2);
    }
  }
  else
  {
    hw_shader = D3DReflect(v4, v5, &IID_ID3D11ShaderReflection, (void **)&shader_reflection);
    shader_reflection->GetDesc(shader_reflection, &shader_desc);
    LOWORD(v7) = shader_desc.InstructionCount;
    v12 = shader_reflection;
    this->m_shader_data.instruction_count = shader_desc.InstructionCount;
    vostok::render::shader_constant_table::parse(
      v7,
      (ID3D11ShaderReflection *)&this->m_shader_data.constants,
      (vostok::render::enum_shader_type)v12);
    vostok::render::res_xs_hw<vostok::render::ps_data>::parse_resources(
      (vostok::render::res_xs_hw<vostok::render::ps_data> *)&this->m_shader_data.textures,
      shader_reflection,
      &this->m_shader_data.samplers,
      &this->m_shader_data.textures);
    if ( shader_reflection )
    {
      shader_reflection->Release(shader_reflection);
      return hw_shader;
    }
  }
  return hw_shader;
}
