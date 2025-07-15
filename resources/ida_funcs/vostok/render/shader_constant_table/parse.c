// local variable allocation has failed, the output may be wrong!
char __userpurge vostok::render::shader_constant_table::parse@<al>(
        vostok::render::shader_constant_table *this@<ecx>,
        vostok::render::shader_constant *a2@<ebx>,
        vostok::render::shader_constant_table *shader_reflection,
        ID3D11ShaderReflection *destination,
        vostok::render::enum_shader_type destinationa)
{
  vostok::render::shader_constant *M_finish; // eax
  vostok::render::shader_constant *M_start; // ecx
  ID3D11ShaderReflection_vtbl *v7; // eax
  vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v8; // ecx
  vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v9; // esi
  ID3D11ShaderReflection *v10; // esi
  stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *v11; // ecx
  unsigned int v12; // edi
  ID3D11ShaderReflectionConstantBuffer *v13; // esi
  HRESULT v14; // eax
  vostok::render::shader_constant_table *v15; // ecx
  const char *d3d11_error_string; // eax
  char *m_buffer; // eax
  const char *Name; // ecx
  vostok::render::shader_constant_buffer *v19; // eax
  stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *v20; // ecx
  const vostok::render::shader_constant_buffer *v21; // esi
  vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v22; // eax
  vostok::render::shader_constant *v24; // edi
  vostok::render::shader_constant *v25; // esi
  int v26; // eax
  int i; // ecx
  const stlp_std::__false_type *v29; // [esp+6h] [ebp-118h]
  unsigned int v30; // [esp+Ah] [ebp-114h]
  bool v31; // [esp+Eh] [ebp-110h]
  bool do_debug_break[4]; // [esp+16h] [ebp-108h] BYREF
  ID3D11ShaderReflection *p_m_table; // [esp+1Ah] [ebp-104h]
  int buff_ind; // [esp+1Eh] [ebp-100h] OVERLAPPED
  vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> temp_buffer; // [esp+22h] [ebp-FCh] BYREF
  _D3D11_SHADER_BUFFER_DESC const_buffer_Desc; // [esp+26h] [ebp-F8h] BYREF
  vostok::fixed_string<64> dest; // [esp+3Ah] [ebp-E4h] BYREF
  _D3D11_SHADER_DESC shader_desc; // [esp+86h] [ebp-98h] BYREF

  M_finish = shader_reflection->m_table._M_impl._M_finish;
  M_start = shader_reflection->m_table._M_impl._M_start;
  p_m_table = (ID3D11ShaderReflection *)&shader_reflection->m_table;
  if ( M_start != M_finish )
    shader_reflection->m_table._M_impl._M_finish = stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
                                                     M_finish,
                                                     M_start,
                                                     M_finish);
  v7 = (ID3D11ShaderReflection_vtbl *)shader_reflection->m_const_buffers._M_impl._M_finish;
  v8 = shader_reflection->m_const_buffers._M_impl._M_start;
  if ( v8 != (vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v7 )
  {
    v9 = stlp_std::priv::__copy<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> const *,vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *,int>(
           (const vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v7,
           v8,
           (const vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v7);
    stlp_std::_Destroy_Range<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>(
      v9,
      shader_reflection->m_const_buffers._M_impl._M_finish);
    shader_reflection->m_const_buffers._M_impl._M_finish = v9;
  }
  v10 = destination;
  destination->GetDesc(destination, &shader_desc);
  if ( shader_desc.ConstantBuffers )
  {
    stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::reserve(
      v11,
      (int)p_m_table,
      shader_desc.ConstantBuffers);
    buff_ind = 0;
    if ( shader_desc.ConstantBuffers )
    {
      v12 = 0;
      while ( 1 )
      {
        v13 = v10->GetConstantBufferByIndex(v10, v12);
        v14 = v13->GetDesc(v13, &const_buffer_Desc);
        if ( !ignore_always_33 && v14 < 0 )
        {
          do_debug_break[3] = 1;
          d3d11_error_string = make_d3d11_error_string(v14);
          vostok::debug::on_error(
            (unsigned int)a2,
            &do_debug_break[3],
            process_error_true,
            &ignore_always_33,
            assert_untyped,
            "assertion_failed",
            d3d11_error_string,
            ".\\shader_constant_table.cpp",
            "vostok::render::shader_constant_table::parse",
            0x10Eu);
          if ( vostok::debug::is_debugger_present() || do_debug_break[3] )
            __debugbreak();
        }
        vostok::render::shader_constant_table::parse_constant_buffer(v15, (unsigned int)a2, shader_reflection, v13, v12);
        m_buffer = dest.m_buffer;
        dest.m_begin = dest.m_buffer;
        Name = const_buffer_Desc.Name;
        dest.m_end = dest.m_buffer;
        dest.m_max_end = (char *)&shader_desc;
        dest.m_buffer[0] = 0;
        if ( const_buffer_Desc.Name )
        {
          if ( *const_buffer_Desc.Name )
          {
            do
            {
              if ( m_buffer >= dest.m_max_end )
                break;
              *m_buffer = *Name;
              m_buffer = dest.m_end + 1;
              ++Name;
              ++dest.m_end;
            }
            while ( *Name );
          }
          *m_buffer = 0;
        }
        v19 = vostok::render::resource_manager::create_constant_buffer(
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                &dest,
                destinationa,
                const_buffer_Desc.Type,
                const_buffer_Desc.Size);
        v21 = 0;
        temp_buffer.m_object = 0;
        if ( v19 )
        {
          ++v19->m_reference_count;
          v21 = v19;
          temp_buffer.m_object = v19;
        }
        v22 = shader_reflection->m_const_buffers._M_impl._M_finish;
        if ( v22 == shader_reflection->m_const_buffers._M_impl._M_end_of_storage._M_data )
        {
          stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::_M_insert_overflow_aux(
            v20,
            (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *> *)&shader_reflection->m_const_buffers,
            v22,
            &temp_buffer,
            v29,
            v30,
            v31);
        }
        else
        {
          if ( v22 )
          {
            v22->m_object = 0;
            if ( v21 )
            {
              v22->m_object = (vostok::render::shader_constant_buffer *)v21;
              ++v21->m_reference_count;
            }
          }
          ++shader_reflection->m_const_buffers._M_impl._M_finish;
        }
        if ( v21 )
        {
          if ( v21->m_reference_count-- == 1 )
            vostok::render::resource_manager::release(
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              v21);
        }
        v12 = (unsigned __int16)++buff_ind;
        if ( (unsigned __int16)buff_ind >= shader_desc.ConstantBuffers )
          break;
        v10 = destination;
      }
    }
  }
  v24 = shader_reflection->m_table._M_impl._M_finish;
  v25 = (vostok::render::shader_constant *)p_m_table->lpVtbl;
  if ( (vostok::render::shader_constant *)p_m_table->lpVtbl != v24 )
  {
    v26 = v24 - v25;
    for ( i = 0; v26 != 1; ++i )
      v26 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::render::shader_constant *,vostok::render::shader_constant,int,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      v25,
      v24,
      0,
      2 * i,
      (bool (__cdecl *)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))vostok::render::res_const_table_predicates::sort);
    stlp_std::priv::__final_insertion_sort<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      v25,
      v24,
      a2);
  }
  return 1;
}
