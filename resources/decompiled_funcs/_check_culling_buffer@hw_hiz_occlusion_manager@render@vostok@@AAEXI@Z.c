void __usercall vostok::render::hw_hiz_occlusion_manager::check_culling_buffer(
        vostok::render::hw_hiz_occlusion_manager *this@<edi>,
        unsigned int in_num_bounds@<eax>,
        bool a3@<bl>,
        unsigned int a4@<esi>)
{
  unsigned int v4; // ecx
  unsigned int v5; // eax
  vostok::render::res_texture *v6; // ecx
  vostok::render::res_texture *m_object; // esi
  vostok::render::res_texture *texture2d; // eax
  vostok::render::res_texture *v9; // ecx
  vostok::render::res_texture *v10; // esi
  vostok::render::render_target *v11; // eax
  vostok::render::render_target *render_target; // eax
  vostok::render::render_target *v13; // ecx
  const char *v14; // eax
  bool v15; // zf
  vostok::render::res_texture *v16; // eax
  vostok::render::res_texture *v17; // ebx
  vostok::render::res_texture *v18; // eax
  vostok::render::res_texture *v19; // esi
  float value; // [esp+0h] [ebp-10h]
  unsigned int v22; // [esp+4h] [ebp-Ch]
  unsigned int v23; // [esp+8h] [ebp-8h]

  v4 = this->m_culling_buffer_height * this->m_culling_buffer_width;
  this->m_current_num_bounds = in_num_bounds;
  if ( in_num_bounds > v4 )
  {
    this->m_culling_buffer_width = 256;
    value = (double)in_num_bounds * 0.00390625 + *(float *)&clear_value;
    v5 = vostok::math::floor(value);
    this->m_culling_buffer_height = v5;
    vostok::render::hw_hiz_point_list::initialize(&this->m_hw_hiz_point_list, v5 << 8);
    m_object = this->m_t_culling_result_lockable.m_object;
    this->m_t_culling_result_lockable.m_object = 0;
    if ( m_object )
    {
      if ( !--m_object->m_reference_count )
        vostok::render::res_texture::destroy_impl(v6, m_object);
    }
    texture2d = vostok::render::resource_manager::create_texture2d(
                  D3D11_USAGE_STAGING,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  (const char *)&stru_967C04.m_rescale_min.elements[1],
                  (vostok::render::resource_manager *)this->m_culling_buffer_width,
                  this->m_culling_buffer_height,
                  (ID3D11Texture2D *)0x3D,
                  (const D3D11_SUBRESOURCE_DATA *)1,
                  DXGI_FORMAT_UNKNOWN,
                  a4,
                  a3);
    v9 = 0;
    if ( texture2d )
    {
      ++texture2d->m_reference_count;
      v9 = texture2d;
    }
    v10 = this->m_t_culling_result_lockable.m_object;
    this->m_t_culling_result_lockable.m_object = v9;
    if ( v10 )
    {
      if ( !--v10->m_reference_count )
        vostok::render::res_texture::destroy_impl(v9, v10);
    }
    v11 = this->m_rt_culling_result.m_object;
    this->m_rt_culling_result.m_object = 0;
    if ( v11 )
    {
      if ( !--v11->m_reference_count )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)v9,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v11);
    }
    render_target = vostok::render::resource_manager::create_render_target(
                      (vostok::render::resource_manager *)this->m_culling_buffer_width,
                      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                      (const char *)&stru_967C04.m_rescale_max.elements[2],
                      (vostok::render::res_texture *)this->m_culling_buffer_width,
                      (ID3D11Texture2D **)this->m_culling_buffer_height,
                      (const char *)0x3D,
                      enum_rt_usage_render_target,
                      0,
                      0,
                      v22,
                      v23);
    v13 = 0;
    if ( render_target )
    {
      ++render_target->m_reference_count;
      v13 = render_target;
    }
    v14 = (const char *)this->m_rt_culling_result.m_object;
    this->m_rt_culling_result.m_object = v13;
    if ( v14 )
    {
      v15 = (*(_DWORD *)v14)-- == 1;
      if ( v15 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)v13,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v14);
    }
    v16 = this->m_rt_culling_result.m_object->m_texture.m_object;
    v17 = 0;
    if ( v16 )
    {
      v17 = this->m_rt_culling_result.m_object->m_texture.m_object;
      ++v16->m_reference_count;
    }
    v18 = 0;
    if ( v17 )
    {
      ++v17->m_reference_count;
      v18 = v17;
    }
    v19 = this->m_t_culling_result.m_object;
    this->m_t_culling_result.m_object = v18;
    if ( v19 )
    {
      v15 = v19->m_reference_count-- == 1;
      if ( v15 )
        vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v13, v19);
    }
    if ( v17 )
    {
      v15 = v17->m_reference_count-- == 1;
      if ( v15 )
        vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v13, v17);
    }
  }
}
