void __thiscall vostok::render::scene::on_texture_loaded(
        vostok::render::scene *this,
        vostok::resources::queries_result *data,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> texture,
        unsigned int num_mips,
        float distance)
{
  vostok::render::res_texture *v6; // ecx
  vostok::render::res_texture *v7; // esi
  bool v8; // zf
  vostok::resources::managed_resource *v9; // eax
  char *m_requery_path; // eax
  char *m_begin; // ecx
  vostok::render::res_texture *m_object; // [esp-4h] [ebp-13Ch]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v13; // [esp+10h] [ebp-128h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v14; // [esp+14h] [ebp-124h] BYREF
  vostok::render::streaming_ready_texture ready_texture; // [esp+18h] [ebp-120h] BYREF

  m_object = 0;
  if ( texture.m_object )
  {
    m_object = texture.m_object;
    ++texture.m_object->m_reference_count;
  }
  if ( stlp_std::find_if<vostok::render::requested_streamable_texture *,vostok::render::find_requested_texture_predicate>(
         this->requested_streamable_textures._M_impl._M_start,
         this->requested_streamable_textures._M_impl._M_finish,
         (vostok::render::find_requested_texture_predicate)m_object) != this->requested_streamable_textures._M_impl._M_finish )
  {
    v6 = 0;
    if ( data->m_queries[0].m_error_type == error_type_unset
      && data->m_queries[0].m_create_resource_result != result_error )
    {
      ready_texture.name.m_begin = ready_texture.name.m_buffer;
      ready_texture.name.m_max_end = (char *)&ready_texture.texture;
      ready_texture.name.m_end = ready_texture.name.m_buffer;
      ready_texture.name.m_buffer[0] = 0;
      ready_texture.texture.m_object = 0;
      ready_texture.data.m_object = 0;
      if ( texture.m_object )
      {
        ++texture.m_object->m_reference_count;
        v6 = texture.m_object;
      }
      v7 = ready_texture.texture.m_object;
      ready_texture.texture.m_object = v6;
      if ( v7 )
      {
        v8 = v7->m_reference_count-- == 1;
        if ( v8 )
          vostok::render::res_texture::destroy_impl(v6, v7);
      }
      v13.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        &v13,
        &data->m_queries[0].m_managed_resource);
      v9 = 0;
      if ( v13.m_object )
      {
        v9 = v13.m_object;
        _InterlockedExchangeAdd(&v13.m_object->m_reference_count, 1u);
      }
      v14.m_object = ready_texture.data.m_object;
      ready_texture.data.m_object = v9;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v14);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v13);
      m_requery_path = data->m_queries[0].m_requery_path;
      ready_texture.num_mips = num_mips;
      if ( !m_requery_path )
        m_requery_path = data->m_queries[0].m_request_path;
      m_begin = ready_texture.name.m_begin;
      if ( ready_texture.name.m_begin != m_requery_path )
      {
        ready_texture.name.m_end = ready_texture.name.m_begin;
        *ready_texture.name.m_begin = 0;
        if ( m_requery_path )
        {
          for ( m_begin = ready_texture.name.m_end; *m_requery_path; ++ready_texture.name.m_end )
          {
            if ( m_begin >= ready_texture.name.m_max_end )
              break;
            *m_begin = *m_requery_path;
            m_begin = ready_texture.name.m_end + 1;
            ++m_requery_path;
          }
          *m_begin = 0;
        }
      }
      ready_texture.distance = distance;
      stlp_std::vector<vostok::render::streaming_ready_texture,vostok::render::std_allocator<vostok::render::streaming_ready_texture>>::push_back(
        (const stlp_std::__false_type *)&ready_texture,
        (stlp_std::priv::_Impl_vector<vostok::render::streaming_ready_texture,vostok::render::std_allocator<vostok::render::streaming_ready_texture> > *)m_begin,
        &this->ready_streaming_textures);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&ready_texture.data);
      if ( ready_texture.texture.m_object )
      {
        v8 = ready_texture.texture.m_object->m_reference_count-- == 1;
        if ( v8 )
          vostok::render::res_texture::destroy_impl(v6, ready_texture.texture.m_object);
      }
    }
  }
  if ( texture.m_object )
  {
    v8 = texture.m_object->m_reference_count-- == 1;
    if ( v8 )
      vostok::render::res_texture::destroy_impl(v6, texture.m_object);
  }
}
