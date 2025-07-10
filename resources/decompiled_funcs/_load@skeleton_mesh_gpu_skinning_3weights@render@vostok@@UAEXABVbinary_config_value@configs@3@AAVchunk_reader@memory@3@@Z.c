void __userpurge vostok::render::skeleton_mesh_gpu_skinning_3weights::load(
        vostok::render::skeleton_mesh_gpu_skinning_3weights *this@<ecx>,
        float a2@<xmm0>,
        const vostok::configs::binary_config_value *properties,
        vostok::memory::chunk_reader *r)
{
  vostok::memory::chunk_reader *v4; // esi
  unsigned int *m_pointer; // ebp
  unsigned int v7; // eax
  unsigned int *v8; // ebp
  unsigned int *v9; // esi
  unsigned int v10; // ecx
  unsigned int v11; // kr00_4
  vostok::render::res_declaration *v12; // edi
  const void *v13; // esi
  vostok::render::untyped_buffer *buffer; // eax
  vostok::memory::chunk_reader *declaration; // eax
  vostok::render::untyped_buffer *v16; // eax
  vostok::render::untyped_buffer *v17; // ecx
  vostok::render::res_state *m_object; // eax
  bool v19; // zf
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v21; // ecx
  vostok::render::res_geometry *v22; // eax
  vostok::render::resource_manager *v23; // [esp-14h] [ebp-24h]
  vostok::memory::chunk_reader::chunk_type *v24; // [esp+0h] [ebp-10h]
  vostok::memory::chunk_reader::chunk_type *v25; // [esp+0h] [ebp-10h]
  unsigned int v26; // [esp+0h] [ebp-10h]
  vostok::render::untyped_buffer *ib; // [esp+14h] [ebp+4h]

  v4 = r;
  vostok::render::render_surface::load(this, properties, r);
  vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)3, (const unsigned int)&r, v24);
  m_pointer = (unsigned int *)v4->m_reader.m_pointer;
  v7 = *m_pointer;
  v8 = m_pointer + 1;
  this->m_render_geometry.vertex_count = v7;
  vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)4, (const unsigned int)&r, v25);
  v9 = (unsigned int *)v4->m_reader.m_pointer;
  v10 = *v9;
  v11 = *v9;
  v12 = 0;
  v13 = v9 + 1;
  this->m_render_geometry.index_count = v10;
  v23 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  this->m_render_geometry.primitive_count = v11 / 3;
  buffer = vostok::render::resource_manager::create_buffer(2 * v10, 0, v23, v13, enum_buffer_type_index, 0, 0);
  ib = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    ib = buffer;
  }
  declaration = (vostok::memory::chunk_reader *)vostok::render::resource_manager::create_declaration(
                                                  7u,
                                                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                                                  (stlp_std::forward_iterator_tag *)hardware_3weights_skinning_vertex_layout);
  r = 0;
  if ( declaration )
  {
    ++*(_DWORD *)&declaration->gap0;
    r = declaration;
    v12 = (vostok::render::res_declaration *)declaration;
  }
  v16 = vostok::render::resource_manager::create_buffer(
          44 * this->m_render_geometry.vertex_count,
          (bool)v12,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v8,
          enum_buffer_type_vertex,
          (vostok::render::untyped_buffer *)1,
          0);
  v17 = 0;
  if ( v16 )
  {
    ++v16->m_reference_count;
    v17 = v16;
  }
  m_object = (vostok::render::res_state *)this->m_vertex_buffer.m_object;
  this->m_vertex_buffer.m_object = v17;
  if ( m_object )
  {
    v19 = m_object->m_reference_count-- == 1;
    if ( v19 )
    {
      vostok::render::resource_manager::release(
        m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
      v12 = (vostok::render::res_declaration *)r;
    }
  }
  geometry = vostok::render::resource_manager::create_geometry(
               v12,
               this->m_vertex_buffer.m_object,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               0x2Cu,
               ib);
  v21 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v21 = geometry;
  }
  v22 = this->m_render_geometry.geom.m_object;
  this->m_render_geometry.geom.m_object = v21;
  if ( v22 )
  {
    v19 = v22->m_reference_count-- == 1;
    if ( v19 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v22);
  }
  vostok::render::calculate_streaming_texture_factor(
    (const vostok::math::float3 *)v8,
    (const vostok::math::float2 *)(v8 + 9),
    0x2Cu,
    (const unsigned int)v13,
    (const unsigned __int16 *)this->m_render_geometry.index_count,
    v26);
  this->m_streaming_texture_factor = a2;
  if ( v12 )
  {
    v19 = v12->m_reference_count-- == 1;
    if ( v19 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v12);
  }
  if ( ib )
  {
    v19 = ib->m_reference_count-- == 1;
    if ( v19 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)ib,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
}
