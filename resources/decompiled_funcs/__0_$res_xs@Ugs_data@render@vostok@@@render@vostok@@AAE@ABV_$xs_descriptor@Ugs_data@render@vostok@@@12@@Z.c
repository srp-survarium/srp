void __usercall vostok::render::res_xs<vostok::render::gs_data>::res_xs<vostok::render::gs_data>(
        vostok::render::res_xs<vostok::render::gs_data> *this@<esi>,
        const vostok::render::xs_descriptor<vostok::render::gs_data> *binder@<edi>)
{
  vostok::render::res_xs_hw<vostok::render::gs_data> *m_object; // eax
  vostok::render::res_xs_hw<vostok::render::gs_data> *v3; // ecx
  vostok::render::res_xs_hw<vostok::render::gs_data> *v4; // eax
  bool v5; // zf
  vostok::render::shader_constant_table *const_table; // eax
  vostok::render::shader_constant_table *v7; // ecx
  vostok::render::shader_constant_table *v8; // eax
  vostok::render::res_texture_list *texture_list; // eax
  vostok::render::res_texture_list *v10; // ecx
  vostok::render::res_texture_list *v11; // eax
  vostok::render::res_sampler_list *sampler_list; // eax
  vostok::render::res_sampler_list *v13; // ecx
  vostok::render::res_sampler_list *v14; // eax

  this->m_reference_count = 0;
  this->m_hardware_shader.m_object = 0;
  this->m_constants.m_object = 0;
  this->m_textures.m_object = 0;
  this->m_samplers.m_object = 0;
  this->m_is_registered = 0;
  m_object = 0;
  if ( binder->m_hardware_shader.m_object )
  {
    m_object = binder->m_hardware_shader.m_object;
    ++binder->m_hardware_shader.m_object->m_reference_count;
  }
  v3 = m_object;
  v4 = this->m_hardware_shader.m_object;
  this->m_hardware_shader.m_object = v3;
  if ( v4 )
  {
    v5 = v4->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release_impl<vostok::render::gs_data>(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v4);
  }
  const_table = vostok::render::resource_manager::create_const_table(
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  &binder->m_shader_data.constants);
  v7 = 0;
  if ( const_table )
  {
    ++const_table->m_reference_count;
    v7 = const_table;
  }
  v8 = this->m_constants.m_object;
  this->m_constants.m_object = v7;
  if ( v8 )
  {
    v5 = v8->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v8);
  }
  texture_list = vostok::render::resource_manager::create_texture_list(
                   (vostok::render::resource_manager *)v7,
                   &binder->m_shader_data.textures);
  v10 = 0;
  if ( texture_list )
  {
    ++texture_list->m_reference_count;
    v10 = texture_list;
  }
  v11 = this->m_textures.m_object;
  this->m_textures.m_object = v10;
  if ( v11 )
  {
    v5 = v11->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v11);
  }
  sampler_list = vostok::render::resource_manager::create_sampler_list(
                   (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                   &binder->m_shader_data.samplers);
  v13 = 0;
  if ( sampler_list )
  {
    ++sampler_list->m_reference_count;
    v13 = sampler_list;
  }
  v14 = this->m_samplers.m_object;
  this->m_samplers.m_object = v13;
  if ( v14 )
  {
    v5 = v14->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v14);
  }
}
