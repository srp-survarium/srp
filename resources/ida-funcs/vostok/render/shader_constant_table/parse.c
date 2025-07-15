char __thiscall vostok::render::shader_constant_table::parse(
        vostok::render::shader_constant_table *this,
        ID3D11ShaderReflection *shader_reflection,
        vostok::render::enum_shader_type destination,
        vostok::render::enum_shader_type a4)
{
  ID3D11ShaderReflectionConstantBuffer *v4; // ebx
  ID3D11ShaderReflection *v5; // esi
  vostok::render::enum_shader_type v6; // edi
  int (__stdcall ***v7)(_DWORD, char **); // esi
  HRESULT v8; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // ecx
  bool *d3d11_error_string; // eax
  vostok::fixed_string<64> *v11; // ecx
  vostok::render::resource_manager *v12; // ecx
  ID3D11ShaderReflection *v13; // eax
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v14; // ecx
  vostok::render::res_pass *v15; // esi
  vostok::render::resource_manager *v16; // ecx
  vostok::render::shader_constant *v18; // esi
  vostok::render::shader_constant *v19; // ebx
  int v20; // eax
  int v21; // ecx
  _BYTE v23[12]; // [esp+10h] [ebp-104h] BYREF
  unsigned int v24; // [esp+1Ch] [ebp-F8h]
  vostok::fixed_string<64> v25; // [esp+A8h] [ebp-6Ch] BYREF
  char *v26[5]; // [esp+F4h] [ebp-20h] BYREF
  int v27; // [esp+108h] [ebp-Ch]
  int v28; // [esp+10Ch] [ebp-8h]

  v4 = (ID3D11ShaderReflectionConstantBuffer *)shader_reflection;
  v5 = shader_reflection + 196;
  shader_reflection[2].lpVtbl = shader_reflection[1].lpVtbl;
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::destroy(
    (vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v5->lpVtbl,
    (vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *const *)&v5[1]);
  v5[1].lpVtbl = v5->lpVtbl;
  v6 = destination;
  (*(void (__stdcall **)(vostok::render::enum_shader_type, _BYTE *))(*(_DWORD *)destination + 12))(destination, v23);
  if ( v24 )
  {
    v28 = 0;
    v27 = 0;
    while ( 1 )
    {
      v7 = (int (__stdcall ***)(_DWORD, char **))(*(int (__stdcall **)(vostok::render::enum_shader_type, int))(*(_DWORD *)v6 + 16))(
                                                   v6,
                                                   v27);
      v8 = (**v7)(v7, v26);
      if ( !ignore_always_37 && v8 < 0 )
      {
        HIBYTE(shader_reflection) = 1;
        d3d11_error_string = (bool *)make_d3d11_error_string(v8, v9);
        vostok::debug::on_error(
          (bool *)&shader_reflection + 3,
          process_error_true,
          d3d11_error_string,
          ".\\shader_constant_table.cpp",
          "vostok::render::shader_constant_table::parse",
          (const char *)0x10E);
        if ( vostok::debug::is_debugger_present() || HIBYTE(shader_reflection) )
          __debugbreak();
      }
      vostok::render::shader_constant_table::parse_constant_buffer(
        (vostok::render::shader_constant_table *)v9,
        v4,
        (int (__stdcall ***)(_DWORD, _BYTE *))v7,
        v27);
      vostok::fixed_string<64>::fixed_string<64>(v11, &v25, v26[0]);
      v13 = (ID3D11ShaderReflection *)vostok::render::resource_manager::create_constant_buffer(
                                        v12,
                                        (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                        &v25,
                                        a4,
                                        (_D3D_CBUFFER_TYPE)v26[1],
                                        (unsigned int)v26[3]);
      v15 = 0;
      shader_reflection = 0;
      if ( v13 )
      {
        ++v13->lpVtbl;
        v15 = (vostok::render::res_pass *)v13;
        shader_reflection = v13;
      }
      vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::push_back(
        v14,
        (int)&v4[196],
        (const vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&shader_reflection);
      if ( v15 )
      {
        if ( v15->m_reference_count-- == 1 )
          vostok::render::resource_manager::release(
            v16,
            (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v15);
      }
      v27 = (unsigned __int16)++v28;
      if ( (unsigned __int16)v28 >= v24 )
        break;
      v6 = destination;
    }
  }
  v18 = (vostok::render::shader_constant *)v4[2].__vftable;
  v19 = (vostok::render::shader_constant *)v4[1].__vftable;
  if ( v19 != v18 )
  {
    v20 = v18 - v19;
    v21 = 0;
    while ( v20 != 1 )
    {
      ++v21;
      v20 >>= 1;
    }
    stlp_std::priv::__introsort_loop<vostok::render::shader_constant *,vostok::render::shader_constant,int,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      v19,
      v18,
      0,
      2 * v21,
      (bool (__cdecl *)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))vostok::render::res_const_table_predicates::sort);
    stlp_std::priv::__final_insertion_sort<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      v19,
      v18);
  }
  return 1;
}
