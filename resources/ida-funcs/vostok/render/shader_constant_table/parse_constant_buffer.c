char __userpurge vostok::render::shader_constant_table::parse_constant_buffer@<al>(
        vostok::render::shader_constant_table *this@<ecx>,
        unsigned int a2@<ebx>,
        vostok::render::shader_constant_table *src_table,
        ID3D11ShaderReflectionConstantBuffer *buffer_index,
        unsigned __int16 buffer_indexa)
{
  unsigned int v5; // esi
  HRESULT v6; // eax
  const char *d3d11_error_string; // eax
  unsigned int v8; // eax
  int v9; // esi
  void (__stdcall ***v10)(_DWORD, _D3D11_SHADER_TYPE_DESC *); // eax
  vostok::render::enum_constant_type v11; // ebp
  unsigned __int16 Elements; // bx
  unsigned __int16 v13; // di
  vostok::strings::shared::profile *v14; // eax
  vostok::render::backend *v15; // ecx
  volatile signed __int32 *p_m_reference_count; // esi
  vostok::render::shader_constant_host *v17; // ebp
  vostok::render::shader_constant *M_finish; // eax
  unsigned int v20; // [esp+Ch] [ebp-98h]
  bool v21; // [esp+10h] [ebp-94h]
  bool do_debug_break[4]; // [esp+20h] [ebp-84h] BYREF
  vostok::shared_string name; // [esp+24h] [ebp-80h] BYREF
  unsigned int i; // [esp+28h] [ebp-7Ch]
  int r_index; // [esp+2Ch] [ebp-78h]
  _D3D11_SHADER_BUFFER_DESC shader_buffer_desc; // [esp+30h] [ebp-74h] BYREF
  vostok::render::shader_constant new_const; // [esp+44h] [ebp-60h] BYREF
  _D3D11_SHADER_TYPE_DESC reflection_type_desc; // [esp+60h] [ebp-44h] BYREF
  _D3D11_SHADER_VARIABLE_DESC variable_desc; // [esp+80h] [ebp-24h] BYREF

  v5 = (unsigned int)buffer_index;
  v6 = buffer_index->GetDesc(buffer_index, &shader_buffer_desc);
  if ( !ignore_always_32 && v6 < 0 )
  {
    do_debug_break[3] = 1;
    d3d11_error_string = make_d3d11_error_string(v6);
    vostok::debug::on_error(
      a2,
      &do_debug_break[3],
      process_error_true,
      &ignore_always_32,
      assert_untyped,
      "assertion_failed",
      d3d11_error_string,
      ".\\shader_constant_table.cpp",
      "vostok::render::shader_constant_table::parse_constant_buffer",
      0x51u);
    if ( vostok::debug::is_debugger_present() || do_debug_break[3] )
      __debugbreak();
  }
  v8 = 0;
  i = 0;
  if ( shader_buffer_desc.Variables )
  {
    while ( 1 )
    {
      v9 = (*(int (__stdcall **)(unsigned int, unsigned int))(*(_DWORD *)v5 + 4))(v5, v8);
      (**(void (__stdcall ***)(int, _D3D11_SHADER_VARIABLE_DESC *))v9)(v9, &variable_desc);
      if ( (variable_desc.uFlags & 2) != 0 )
      {
        v10 = (void (__stdcall ***)(_DWORD, _D3D11_SHADER_TYPE_DESC *))(*(int (__stdcall **)(int))(*(_DWORD *)v9 + 4))(v9);
        (**v10)(v10, &reflection_type_desc);
        v11 = rc_INVALID;
        switch ( reflection_type_desc.Type )
        {
          case D3D_SVT_BOOL:
            v11 = rc_bool;
            break;
          case D3D_SVT_INT:
            v11 = rc_int;
            break;
          case D3D_SVT_FLOAT:
            v11 = rc_float;
            break;
        }
        Elements = reflection_type_desc.Elements;
        r_index = LOWORD(variable_desc.StartOffset);
        v13 = -1;
        switch ( reflection_type_desc.Class )
        {
          case D3D_SVC_SCALAR:
            v13 = 4;
            goto $LN210_1;
          case D3D_SVC_VECTOR:
            switch ( reflection_type_desc.Columns )
            {
              case 2u:
                v13 = 8;
                break;
              case 3u:
                v13 = 12;
                break;
              case 4u:
                v13 = 16;
                break;
            }
            goto $LN210_1;
          case D3D_SVC_MATRIX_ROWS:
            if ( reflection_type_desc.Columns == 4 )
            {
              switch ( reflection_type_desc.Rows )
              {
                case 2u:
                  v13 = 288;
                  break;
                case 3u:
                  v13 = 304;
                  break;
                case 4u:
                  v13 = 320;
                  break;
              }
            }
            goto $LN210_1;
          case D3D_SVC_MATRIX_COLUMNS:
          case D3D_SVC_STRUCT:
$LN210_1:
            vostok::render::shader_constant_table::get(
              (vostok::render::shader_constant_table *)variable_desc.Name,
              (int)src_table,
              variable_desc.Name);
            v14 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
            p_m_reference_count = 0;
            name.m_pointer.m_object = 0;
            if ( v14 )
            {
              p_m_reference_count = &v14->m_reference_count;
              name.m_pointer.m_object = v14;
              _InterlockedExchangeAdd(&v14->m_reference_count, 1u);
            }
            v17 = vostok::render::backend::register_constant_host(
                    v15,
                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                    &name,
                    v11);
            if ( p_m_reference_count && !_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF) )
              vostok::strings::shared::manager::remove(
                s_manager.m_variable,
                (vostok::strings::shared::profile *)s_manager.m_variable);
            new_const.m_source.m_pointer = 0;
            new_const.m_source.m_size = 0;
            new_const.m_host = v17;
            new_const.m_slot.m_class_id = v13;
            new_const.m_slot.m_buffer_index = buffer_indexa;
            new_const.m_slot.m_slot_index = r_index;
            if ( Elements )
              new_const.m_slot.m_array_size = Elements;
            else
              new_const.m_slot.m_array_size = 1;
            M_finish = src_table->m_table._M_impl._M_finish;
            if ( M_finish == src_table->m_table._M_impl._M_end_of_storage._M_data )
            {
              stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::_M_insert_overflow_aux(
                &src_table->m_table._M_impl,
                (vostok::render::shader_constant *)&src_table->m_table,
                M_finish,
                &new_const,
                v20,
                v21);
            }
            else
            {
              if ( M_finish )
              {
                M_finish->m_slot.m_value = new_const.m_slot.m_value;
                M_finish->m_source.m_pointer = 0;
                M_finish->m_source.m_size = 0;
                M_finish->m_host = v17;
              }
              ++src_table->m_table._M_impl._M_finish;
            }
            break;
          default:
            break;
        }
      }
      v8 = i + 1;
      i = v8;
      if ( v8 >= shader_buffer_desc.Variables )
        break;
      v5 = (unsigned int)buffer_index;
    }
  }
  return 1;
}
