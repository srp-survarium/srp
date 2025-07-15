void __userpurge vostok::render::static_render_surface::load(
        vostok::render::static_render_surface *this@<ecx>,
        float a2@<xmm0>,
        const vostok::configs::binary_config_value *properties,
        vostok::memory::chunk_reader *chunk)
{
  unsigned __int8 *v5; // esi
  _D3DVERTEXELEMENT9 *v6; // eax
  int v7; // eax
  unsigned __int8 *m_data; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::res_declaration *declaration; // eax
  unsigned int m_reference_count; // eax
  const unsigned __int8 *p_m_hardware_buffer; // esi
  void (__cdecl *v13)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v14)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  unsigned int v15; // ecx
  unsigned int v16; // eax
  vostok::render::untyped_buffer *buffer; // eax
  unsigned int *m_pointer; // esi
  unsigned int v19; // ecx
  unsigned int v20; // kr00_4
  vostok::render::untyped_buffer *v21; // eax
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v23; // ecx
  vostok::render::res_geometry *m_object; // eax
  bool v25; // zf
  D3D11_INPUT_ELEMENT_DESC *M_start; // eax
  void *v27; // esi
  vostok::render::resource_manager *v28; // [esp-14h] [ebp-74h]
  vostok::memory::chunk_reader::chunk_type *v29; // [esp+0h] [ebp-60h]
  stlp_std::priv::_STLP_alloc_proxy<_D3DVERTEXELEMENT9 *,_D3DVERTEXELEMENT9,vostok::render::std_allocator<_D3DVERTEXELEMENT9> > *v30; // [esp+0h] [ebp-60h]
  vostok::memory::chunk_reader::chunk_type *v31; // [esp+0h] [ebp-60h]
  vostok::memory::chunk_reader::chunk_type *v32; // [esp+0h] [ebp-60h]
  vostok::memory::chunk_reader::chunk_type *v33; // [esp+0h] [ebp-60h]
  vostok::memory::chunk_reader::chunk_type *v34; // [esp+0h] [ebp-60h]
  unsigned int v35; // [esp+0h] [ebp-60h]
  char ib; // [esp+10h] [ebp-50h]
  vostok::render::untyped_buffer *iba; // [esp+10h] [ebp-50h]
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> vb; // [esp+14h] [ebp-4Ch]
  vostok::render::untyped_buffer *vba; // [esp+14h] [ebp-4Ch]
  vostok::render::res_declaration *decl; // [esp+18h] [ebp-48h]
  unsigned int chunk_id; // [esp+1Ch] [ebp-44h] BYREF
  unsigned int vStride; // [esp+20h] [ebp-40h]
  const _D3DVERTEXELEMENT9 *vFormat; // [esp+24h] [ebp-3Ch] BYREF
  vostok::render::vector<D3D11_INPUT_ELEMENT_DESC> decl_code; // [esp+28h] [ebp-38h] BYREF
  vostok::memory::reader reader; // [esp+34h] [ebp-2Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+40h] [ebp-20h] BYREF

  ib = 0;
  vostok::render::render_surface::load(this, properties, chunk);
  vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)3, (const unsigned int)&vFormat, v29);
  vFormat = (const _D3DVERTEXELEMENT9 *)chunk->m_reader.m_pointer;
  v5 = (unsigned __int8 *)vFormat;
  chunk_id = 8 * (D3DXGetDeclLength((int)vFormat) + 1);
  vb.m_object = (vostok::render::untyped_buffer *)&v5[chunk_id];
  memset((void *)&decl_code, 0, sizeof(decl_code));
  vStride = (int)chunk_id >> 3;
  v6 = stlp_std::priv::_STLP_alloc_proxy<vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::state_record *,vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::state_record>>::allocate(
         (int)chunk_id >> 3,
         v30);
  reader.m_data = (const unsigned __int8 *)v6;
  reader.m_size = (unsigned int)&v6[(int)chunk_id >> 3];
  if ( &v5[chunk_id] != v5 )
  {
    memcpy((unsigned __int8 *)v6, v5, chunk_id);
    v6 = (_D3DVERTEXELEMENT9 *)(chunk_id + v7);
  }
  reader.m_pointer = (const unsigned __int8 *)v6;
  vostok::render::decl_utils::convert_vertex_declaration(
    (const vostok::render::vector<_D3DVERTEXELEMENT9> *)&reader,
    &decl_code);
  m_data = (unsigned __int8 *)reader.m_data;
  if ( reader.m_data )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, m_data);
  }
  declaration = vostok::render::resource_manager::create_declaration(
                  decl_code._M_impl._M_finish - decl_code._M_impl._M_start,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  (stlp_std::forward_iterator_tag *)decl_code._M_impl._M_start);
  decl = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    decl = declaration;
  }
  m_reference_count = vb.m_object->m_reference_count;
  p_m_hardware_buffer = (const unsigned __int8 *)&vb.m_object->m_hardware_buffer;
  reader.m_pointer = (const unsigned __int8 *)&vb.m_object->m_hardware_buffer;
  this->m_render_geometry.vertex_count = m_reference_count;
  if ( m_reference_count > (unsigned int)&_sbh_sizeHeaderList )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
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
      ib = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\render_model_static.cpp",
        0x316u,
        "void __thiscall vostok::render::static_render_surface::load(const class vostok::configs::binary_config_value &,c"
        "lass vostok::memory::chunk_reader &)",
        "render_pc_dx11:",
        error,
        "vertex buffer size > 1024 * 64!");
      p_m_hardware_buffer = reader.m_pointer;
    }
    if ( (ib & 1) != 0 )
    {
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v14 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v14 )
            v14(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
  }
  v15 = D3DXGetDeclVertexSize((int)vFormat, 0);
  v16 = v15 * this->m_render_geometry.vertex_count;
  vStride = v15;
  buffer = vostok::render::resource_manager::create_buffer(
             v16,
             (bool)chunk,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             p_m_hardware_buffer,
             enum_buffer_type_vertex,
             0,
             0);
  vba = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    vba = buffer;
  }
  vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)4, (const unsigned int)&vFormat, v31);
  m_pointer = (unsigned int *)chunk->m_reader.m_pointer;
  v19 = *m_pointer;
  v20 = *m_pointer;
  this->m_render_geometry.index_count = *m_pointer;
  v28 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  this->m_render_geometry.primitive_count = v20 / 3;
  v21 = vostok::render::resource_manager::create_buffer(
          2 * v19,
          (bool)chunk,
          v28,
          m_pointer + 1,
          enum_buffer_type_index,
          0,
          0);
  iba = 0;
  if ( v21 )
  {
    ++v21->m_reference_count;
    iba = v21;
  }
  geometry = vostok::render::resource_manager::create_geometry(
               decl,
               vba,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               vStride,
               iba);
  v23 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v23 = geometry;
  }
  m_object = this->m_render_geometry.geom.m_object;
  this->m_render_geometry.geom.m_object = v23;
  if ( m_object )
  {
    v25 = m_object->m_reference_count-- == 1;
    if ( v25 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)3, (const unsigned int)&vFormat, v32);
  vostok::render::static_render_surface::create_shadow_pass_geometry(
    (vostok::render::static_render_surface *)this->m_render_geometry.vertex_count,
    this,
    &chunk->m_reader.m_pointer[chunk_id + 4],
    this->m_render_geometry.vertex_count);
  vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)3, (const unsigned int)&vFormat, v33);
  vFormat = (const _D3DVERTEXELEMENT9 *)&chunk->m_reader.m_pointer[chunk_id + 4];
  vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)4, (const unsigned int)&chunk_id, v34);
  vostok::render::calculate_streaming_texture_factor(
    (const vostok::math::float3 *)vFormat,
    (const vostok::math::float2 *)&vFormat[3],
    vStride,
    (const unsigned int)(chunk->m_reader.m_pointer + 4),
    (const unsigned __int16 *)this->m_render_geometry.index_count,
    v35);
  this->m_streaming_texture_factor = a2;
  if ( iba )
  {
    v25 = iba->m_reference_count-- == 1;
    if ( v25 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)iba,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  if ( vba )
  {
    v25 = vba->m_reference_count-- == 1;
    if ( v25 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)vba,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  if ( decl )
  {
    v25 = decl->m_reference_count-- == 1;
    if ( v25 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        decl);
  }
  M_start = decl_code._M_impl._M_start;
  if ( decl_code._M_impl._M_start )
  {
    v27 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v27, (void *)M_start);
  }
}
