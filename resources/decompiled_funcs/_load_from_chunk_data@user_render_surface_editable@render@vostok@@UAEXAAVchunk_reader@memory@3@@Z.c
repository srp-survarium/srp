void __userpurge vostok::render::user_render_surface_editable::load_from_chunk_data(
        vostok::render::user_render_surface_editable *this@<ecx>,
        vostok::memory::chunk_reader::chunk_type *a2@<edi>,
        vostok::memory::chunk_reader *chunk)
{
  unsigned int v4; // eax
  const unsigned __int8 *m_pointer; // ecx
  const unsigned __int8 *v6; // eax
  const unsigned __int8 *i; // edx
  unsigned __int8 *v8; // eax
  unsigned int *v9; // ecx
  unsigned int v10; // eax
  vostok::render::untyped_buffer *v11; // eax
  vostok::render::untyped_buffer *v12; // ebx
  unsigned int *v13; // esi
  unsigned int v14; // ecx
  unsigned int v15; // kr00_4
  vostok::render::untyped_buffer *v16; // eax
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v19; // ecx
  vostok::render::res_geometry *m_object; // eax
  vostok::render::material_effects_instance_cook_data *v21; // esi
  unsigned int v22; // eax
  unsigned int v23; // ebx
  char *v24; // esi
  void (__cdecl *v25)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::res_declaration *v26; // eax
  bool v27; // zf
  vostok::render::untyped_buffer *v28; // edi
  vostok::render::untyped_buffer *v29; // edi
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::user_render_surface,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,char *>,boost::_bi::list4<boost::_bi::value<vostok::render::user_render_surface_editable *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<char *> > > v30; // [esp+878h] [ebp-1B8h]
  vostok::render::resource_manager *v31; // [esp+87Ch] [ebp-1B4h]
  vostok::memory::chunk_reader::chunk_type *v33; // [esp+890h] [ebp-1A0h]
  vostok::memory::chunk_reader::chunk_type *v34; // [esp+890h] [ebp-1A0h]
  unsigned int chunk_id; // [esp+89Ch] [ebp-194h] BYREF
  vostok::resources::request requests; // [esp+8A0h] [ebp-190h] BYREF
  float v37; // [esp+8A8h] [ebp-188h]
  vostok::render::res_declaration *dcl; // [esp+8ACh] [ebp-184h]
  vostok::render::untyped_buffer *v39; // [esp+8B0h] [ebp-180h]
  vostok::render::untyped_buffer *buffer; // [esp+8B4h] [ebp-17Ch]
  _DWORD v41[2]; // [esp+8B8h] [ebp-178h] BYREF
  unsigned int v42[8]; // [esp+8C0h] [ebp-170h] BYREF
  _DWORD *v43; // [esp+8E0h] [ebp-150h]
  int v44; // [esp+8E4h] [ebp-14Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+8E8h] [ebp-148h] BYREF
  __int64 v46; // [esp+908h] [ebp-128h]
  __int64 v47; // [esp+918h] [ebp-118h]
  char *_Src; // [esp+920h] [ebp-110h]
  _BYTE *v49; // [esp+924h] [ebp-10Ch]
  unsigned __int8 *v50; // [esp+928h] [ebp-108h]
  _BYTE v51[256]; // [esp+92Ch] [ebp-104h] BYREF
  char v52; // [esp+A2Ch] [ebp-4h] BYREF

  *(_QWORD *)&this->m_aabbox.min.x = 0xC1200000C1200000uLL;
  v37 = FLOAT_10_0;
  *(float *)&requests.path = FLOAT_10_0;
  *(float *)&requests.id = FLOAT_10_0;
  *(vostok::resources::request *)&this->m_aabbox.max.x = requests;
  this->m_aabbox.max.z = FLOAT_10_0;
  this->m_vertex_input_type = user_vertex_input_type;
  this->m_aabbox.min.z = -10.0;
  v4 = vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)2, (const unsigned int)&chunk_id, a2);
  m_pointer = chunk->m_reader.m_pointer;
  v6 = &m_pointer[v4];
  for ( i = m_pointer; i != v6; ++i )
  {
    if ( !*i )
      break;
  }
  v8 = v51;
  _Src = v51;
  v49 = v51;
  v50 = (unsigned __int8 *)&v52;
  v51[0] = 0;
  if ( m_pointer )
  {
    for ( ; *m_pointer; ++v49 )
    {
      if ( v8 >= v50 )
        break;
      *v8 = *m_pointer;
      v8 = v49 + 1;
      ++m_pointer;
    }
    *v8 = 0;
  }
  vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)3, (const unsigned int)&chunk_id, v33);
  v9 = (unsigned int *)chunk->m_reader.m_pointer;
  v10 = *v9;
  this->m_render_geometry.vertex_count = *v9;
  v11 = vostok::render::resource_manager::create_buffer(
          20 * v10,
          (bool)this,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v9 + 1,
          enum_buffer_type_vertex,
          (vostok::render::untyped_buffer *)1,
          0);
  v12 = 0;
  v39 = 0;
  if ( v11 )
  {
    ++v11->m_reference_count;
    v39 = v11;
    v12 = v11;
  }
  vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)4, (const unsigned int)&chunk_id, v34);
  v13 = (unsigned int *)chunk->m_reader.m_pointer;
  v14 = *v13;
  v15 = *v13;
  this->m_render_geometry.index_count = *v13;
  v31 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  this->m_render_geometry.primitive_count = v15 / 3;
  v16 = vostok::render::resource_manager::create_buffer(2 * v14, (bool)this, v31, v13 + 1, enum_buffer_type_index, 0, 0);
  buffer = 0;
  if ( v16 )
  {
    ++v16->m_reference_count;
    buffer = v16;
  }
  declaration = vostok::render::resource_manager::create_declaration(
                  2u,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  (stlp_std::forward_iterator_tag *)layout_editable);
  dcl = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    dcl = declaration;
  }
  geometry = vostok::render::resource_manager::create_geometry(
               dcl,
               v12,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               0x14u,
               buffer);
  v19 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v19 = geometry;
  }
  m_object = this->m_render_geometry.geom.m_object;
  this->m_render_geometry.geom.m_object = v19;
  if ( m_object )
  {
    if ( !--m_object->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  this->m_vb = v12;
  v21 = (vostok::render::material_effects_instance_cook_data *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                 (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                                 0x10u);
  if ( v21 )
  {
    vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
      v21,
      this->m_vertex_input_type,
      0,
      0,
      cull_mode_back);
    v23 = v22;
  }
  else
  {
    chunk_id = 0;
    v23 = 0;
  }
  v43 = 0;
  v44 = 0;
  v44 = vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::get();
  v42[0] = v23;
  v41[0] = &vostok::detail::concrete_type_helper<vostok::render::material_effects_instance_cook_data *>::`vftable';
  v43 = v41;
  v24 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(
                  (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                  0x100u);
  memset((int)v24, 0, 0x100u);
  strcpy_s(v24, 0x100u, _Src);
  LODWORD(v46) = vostok::render::user_render_surface::material_ready;
  HIDWORD(v46) = 0;
  requests = (vostok::resources::request)__PAIR64__(v23, (unsigned int)this);
  v30.f_.f_ = (void (__thiscall *__ptr64)(vostok::render::user_render_surface *, vostok::resources::queries_result *, vostok::render::material_effects_instance_cook_data *, char *))v46;
  v30.l_.boost::_bi::storage3<boost::_bi::value<vostok::render::user_render_surface_editable *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *> > = (boost::_bi::storage3<boost::_bi::value<vostok::render::user_render_surface_editable *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *> >)__PAIR64__(v23, (unsigned int)this);
  LODWORD(v47) = v24;
  callback.vtable = 0;
  *(_QWORD *)&v30.l_.a4_.t_ = v47;
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::user_render_surface,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,char *>,boost::_bi::list4<boost::_bi::value<vostok::render::user_render_surface_editable *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<char *>>>>(
    0,
    (int)&callback,
    (int)v24,
    v30);
  requests.path = _Src;
  chunk_id = (unsigned int)v41;
  requests.id = material_effects_instance_class;
  vostok::resources::query_resources(
    &requests,
    1u,
    &callback,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    (const vostok::variant<32> **)&chunk_id,
    0,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v25 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v25 )
        v25(&callback.functor, &callback.functor, 2);
    }
    callback.vtable = 0;
  }
  if ( v43 )
  {
    (*(void (__thiscall **)(_DWORD *, unsigned int *))(*v43 + 4))(v43, v42);
    v43 = 0;
  }
  v26 = dcl;
  if ( dcl )
  {
    v27 = dcl->m_reference_count-- == 1;
    if ( v27 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v26);
  }
  v28 = buffer;
  if ( buffer )
  {
    v27 = buffer->m_reference_count-- == 1;
    if ( v27 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v28,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v29 = v39;
  if ( v39 )
  {
    v27 = v39->m_reference_count-- == 1;
    if ( v27 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v29,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
}
