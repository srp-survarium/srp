void __thiscall vostok::render::grass_render_surface::load(
        vostok::render::grass_render_surface *this,
        vostok::configs::binary_config_value *properties,
        vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> chunk)
{
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v3; // ebx
  unsigned __int8 *M_finish; // ebp
  int v6; // eax
  unsigned __int8 *v7; // esi
  _D3DVERTEXELEMENT9 *v8; // eax
  int v9; // eax
  char *M_start; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  vostok::memory::chunk_reader *declaration; // eax
  int v13; // ebp
  int *v14; // eax
  vostok::render::signature_layout_pair *v15; // ebx
  unsigned int m_object; // eax
  int *v17; // eax
  vostok::render::res_declaration *v18; // eax
  char *v20; // eax
  malloc_state *v21; // esi
  unsigned int v22; // [esp-4h] [ebp-30h]
  vostok::memory::chunk_reader::chunk_type *v23; // [esp+0h] [ebp-2Ch]
  stlp_std::priv::_STLP_alloc_proxy<_D3DVERTEXELEMENT9 *,_D3DVERTEXELEMENT9,vostok::render::std_allocator<_D3DVERTEXELEMENT9> > *v24; // [esp+0h] [ebp-2Ch]
  vostok::memory::chunk_reader::chunk_type *v25; // [esp+0h] [ebp-2Ch]
  unsigned __int8 *v26; // [esp+10h] [ebp-1Ch]
  vostok::render::vector<D3D11_INPUT_ELEMENT_DESC> decl_code; // [esp+14h] [ebp-18h] BYREF
  vostok::render::vector<_D3DVERTEXELEMENT9> declIn; // [esp+20h] [ebp-Ch] BYREF

  v3.m_object = chunk.m_object;
  vostok::render::render_surface::load(this, properties, (vostok::memory::chunk_reader *)chunk.m_object);
  vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)3, (const unsigned int)&chunk, v23);
  M_finish = (unsigned __int8 *)v3.m_object->vs_to_layout._M_impl._M_finish;
  v6 = D3DXGetDeclLength((int)M_finish);
  v7 = &M_finish[8 * v6 + 8];
  chunk.m_object = (vostok::render::res_declaration *)(8 * (v6 + 1));
  memset((void *)&decl_code, 0, sizeof(decl_code));
  v26 = v7;
  properties = (vostok::configs::binary_config_value *)((int)chunk.m_object >> 3);
  v8 = stlp_std::priv::_STLP_alloc_proxy<vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::state_record *,vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::state_record>>::allocate(
         (int)chunk.m_object >> 3,
         v24);
  declIn._M_impl._M_start = v8;
  declIn._M_impl._M_end_of_storage._M_data = &v8[(_DWORD)properties];
  if ( v7 != M_finish )
  {
    memcpy((unsigned __int8 *)v8, M_finish, (unsigned int)chunk.m_object);
    v8 = (_D3DVERTEXELEMENT9 *)((char *)chunk.m_object + v9);
  }
  declIn._M_impl._M_finish = v8;
  vostok::render::decl_utils::convert_vertex_declaration(&declIn, &decl_code);
  M_start = (char *)declIn._M_impl._M_start;
  if ( declIn._M_impl._M_start )
  {
    m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
    v7 = v26;
  }
  declaration = (vostok::memory::chunk_reader *)vostok::render::resource_manager::create_declaration(
                                                  decl_code._M_impl._M_finish - decl_code._M_impl._M_start,
                                                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                                                  (stlp_std::forward_iterator_tag *)decl_code._M_impl._M_start);
  chunk.m_object = 0;
  if ( declaration )
  {
    ++*(_DWORD *)&declaration->gap0;
    chunk.m_object = (vostok::render::res_declaration *)declaration;
  }
  this->m_num_vertices = *(_DWORD *)v7;
  v13 = D3DXGetDeclVertexSize((int)M_finish, 0);
  v14 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          32 * this->m_num_vertices);
  v22 = v13 * this->m_num_vertices;
  this->m_vertices = (vostok::render::grass_source_vertex *)v14;
  memcpy((unsigned __int8 *)v14, v7 + 4, v22);
  vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)4, (const unsigned int)&properties, v25);
  v15 = v3.m_object->vs_to_layout._M_impl._M_finish;
  m_object = (unsigned int)v15->input_layout.m_object;
  this->m_num_indices = (unsigned int)v15->input_layout.m_object;
  v17 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          2 * m_object);
  this->m_indices = (unsigned __int16 *)v17;
  memcpy((unsigned __int8 *)v17, (unsigned __int8 *)&v15->signature, 2 * this->m_num_indices);
  v18 = chunk.m_object;
  if ( chunk.m_object )
  {
    if ( chunk.m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v18);
  }
  v20 = (char *)decl_code._M_impl._M_start;
  if ( decl_code._M_impl._M_start )
  {
    v21 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v21, v20);
  }
}
