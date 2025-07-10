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
