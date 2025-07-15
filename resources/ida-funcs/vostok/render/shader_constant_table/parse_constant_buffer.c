char __thiscall vostok::render::shader_constant_table::parse_constant_buffer(
        vostok::render::shader_constant_table *this,
        ID3D11ShaderReflectionConstantBuffer *src_table,
        int (__stdcall ***buffer_index)(_DWORD, _BYTE *),
        unsigned __int16 a4)
{
  int (__stdcall ***v4)(_DWORD, _BYTE *); // esi
  HRESULT v5; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool *d3d11_error_string; // eax
  int v8; // esi
  void (__stdcall ***v9)(_DWORD, int *); // eax
  vostok::render::shader_constant_table *v10; // ecx
  char *v11; // esi
  unsigned __int16 v12; // di
  unsigned __int16 v13; // bx
  vostok::shared_string *v14; // ecx
  vostok::render::backend *v15; // ecx
  vostok::render::shader_constant_host *v16; // esi
  unsigned __int16 v17; // ax
  __int16 v19; // [esp-4h] [ebp-A0h]
  char *v20; // [esp+10h] [ebp-8Ch] BYREF
  unsigned __int16 v21; // [esp+14h] [ebp-88h]
  char v22; // [esp+1Ch] [ebp-80h]
  _BYTE v23[8]; // [esp+34h] [ebp-68h] BYREF
  unsigned int v24; // [esp+3Ch] [ebp-60h]
  int v25; // [esp+48h] [ebp-54h] BYREF
  int v26; // [esp+4Ch] [ebp-50h]
  int v27; // [esp+50h] [ebp-4Ch]
  int v28; // [esp+54h] [ebp-48h]
  unsigned __int16 v29; // [esp+58h] [ebp-44h]
  vostok::render::shader_constant value; // [esp+68h] [ebp-34h] BYREF
  int v31; // [esp+84h] [ebp-18h]
  _BYTE *v32; // [esp+88h] [ebp-14h]
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> v33; // [esp+8Ch] [ebp-10h] BYREF
  int v34; // [esp+90h] [ebp-Ch]
  char v35; // [esp+97h] [ebp-5h] BYREF

  v4 = buffer_index;
  v5 = (**buffer_index)(buffer_index, v23);
  if ( !ignore_always_36 && v5 < 0 )
  {
    v35 = 1;
    d3d11_error_string = (bool *)make_d3d11_error_string(v5, v6);
    vostok::debug::on_error(
      (bool *)&v35,
      process_error_true,
      d3d11_error_string,
      ".\\shader_constant_table.cpp",
      "vostok::render::shader_constant_table::parse_constant_buffer",
      (const char *)0x51);
    if ( vostok::debug::is_debugger_present() || v35 )
      __debugbreak();
  }
  v32 = 0;
  if ( v24 )
  {
    while ( 1 )
    {
      v8 = (*v4)[1](v4, v32);
      (**(void (__stdcall ***)(int, char **))v8)(v8, &v20);
      if ( (v22 & 2) == 0 )
        goto LABEL_48;
      v9 = (void (__stdcall ***)(_DWORD, int *))(*(int (__stdcall **)(int))(*(_DWORD *)v8 + 4))(v8);
      (**v9)(v9, &v25);
      v11 = v20;
      v12 = -1;
      v34 = 0xFFFF;
      switch ( v26 )
      {
        case 1:
          v34 = 2;
          break;
        case 2:
          v34 = 1;
          break;
        case 3:
          v34 = 0;
          break;
        default:
          vostok::render::shader_constant_table::fatal(v10, "R_constant_table::parse: unexpected shader variable type.");
          break;
      }
      v13 = v21;
      v31 = v29;
      if ( !v25 )
        break;
      switch ( v25 )
      {
        case 1:
          switch ( v28 )
          {
            case 2:
              v19 = 8;
              break;
            case 3:
              v19 = 12;
              break;
            case 4:
              v19 = 16;
              break;
            default:
              vostok::render::shader_constant_table::fatal(
                v10,
                "Vector: 1 components is scalar - there is special case for this!!!!!");
              goto LABEL_42;
          }
          goto LABEL_41;
        case 2:
          if ( v28 == 4 )
          {
            switch ( v27 )
            {
              case 2:
                v12 = 288;
                break;
              case 3:
                v12 = 304;
                break;
              case 4:
                v12 = 320;
                break;
              default:
                vostok::render::shader_constant_table::fatal(v10, "MATRIX_ROWS: unsupported number of Rows");
                break;
            }
          }
          else
          {
            vostok::render::shader_constant_table::fatal(v10, "MATRIX_ROWS: unsupported number of Columns");
          }
          break;
        case 3:
          vostok::render::shader_constant_table::fatal(v10, "Pclass MATRIX_COLUMNS unsupported");
          break;
        case 5:
          vostok::render::shader_constant_table::fatal(v10, "Pclass D3DXPC_STRUCT unsupported");
          break;
        default:
          goto LABEL_48;
      }
LABEL_42:
      vostok::render::shader_constant_table::get(v10, (int)src_table, v11);
      vostok::shared_string::shared_string(v14, &v33, v11);
      v16 = vostok::render::backend::register_constant_host(
              v15,
              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
              (const vostok::shared_string *)&v33,
              (vostok::strings::shared::profile *)v34);
      if ( v33.m_object && !_InterlockedExchangeAdd(&v33.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::strings::shared::detail::intrusive_base::destroy(
          0,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v33.m_object);
      value.m_source.m_pointer = 0;
      value.m_source.m_size = 0;
      value.m_slot.m_buffer_index = a4;
      v17 = v31;
      value.m_host = v16;
      value.m_slot.m_class_id = v12;
      value.m_slot.m_slot_index = v13;
      if ( !(_WORD)v31 )
        v17 = 1;
      value.m_slot.m_array_size = v17;
      vostok::buffer_vector<vostok::render::shader_constant>::push_back(
        (vostok::buffer_vector<vostok::render::shader_constant> *)&src_table[1],
        &value);
LABEL_48:
      if ( (unsigned int)++v32 >= v24 )
        return 1;
      v4 = buffer_index;
    }
    v19 = 4;
LABEL_41:
    v12 = v19;
    goto LABEL_42;
  }
  return 1;
}
