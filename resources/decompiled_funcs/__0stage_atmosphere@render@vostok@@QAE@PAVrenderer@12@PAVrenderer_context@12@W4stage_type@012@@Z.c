void __userpurge vostok::render::stage_atmosphere::stage_atmosphere(
        vostok::render::stage_atmosphere *this@<esi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>,
        vostok::strings::shared::profile *type)
{
  vostok::render::sphere_geometry *v4; // ecx
  vostok::render::stage_atmosphere::stage_type v5; // ecx
  vostok::strings::shared::manager *v6; // ecx
  vostok::strings::shared::profile *v7; // eax
  vostok::render::backend *v8; // ecx
  volatile signed __int32 *p_m_reference_count; // edi
  vostok::strings::shared::manager *v10; // ecx
  vostok::strings::shared::profile *v11; // eax
  vostok::render::backend *v12; // ecx
  volatile signed __int32 *v13; // edi
  vostok::strings::shared::manager *v14; // ecx
  vostok::strings::shared::profile *v15; // eax
  vostok::render::backend *v16; // ecx
  volatile signed __int32 *v17; // edi
  vostok::strings::shared::manager *v18; // ecx
  vostok::strings::shared::profile *v19; // eax
  vostok::render::backend *v20; // ecx
  volatile signed __int32 *v21; // edi
  vostok::strings::shared::manager *v22; // ecx
  vostok::strings::shared::profile *v23; // eax
  vostok::render::backend *v24; // ecx
  volatile signed __int32 *v25; // edi
  vostok::strings::shared::manager *v26; // ecx
  vostok::strings::shared::profile *v27; // eax
  vostok::render::backend *v28; // ecx
  volatile signed __int32 *v29; // edi
  vostok::strings::shared::manager *v30; // ecx
  vostok::strings::shared::profile *v31; // eax
  vostok::render::backend *v32; // ecx
  volatile signed __int32 *v33; // edi
  vostok::strings::shared::manager *v34; // ecx
  vostok::strings::shared::profile *v35; // eax
  vostok::render::backend *v36; // ecx
  volatile signed __int32 *v37; // edi
  vostok::strings::shared::manager *v38; // ecx
  vostok::strings::shared::profile *v39; // eax
  vostok::render::backend *v40; // ecx
  volatile signed __int32 *v41; // edi
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v43; // ecx
  vostok::render::res_state *m_object; // edi
  bool v45; // zf
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v47; // ecx
  vostok::render::res_geometry *v48; // eax
  unsigned __int16 indices[6]; // [esp+Ch] [ebp-44h] BYREF
  D3D11_INPUT_ELEMENT_DESC screen_vertex_layout[2]; // [esp+18h] [ebp-38h] BYREF

  this->m_context = context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_atmosphere_vtbl *)&stru_965008.m_name.m_string.m_buffer[88];
  vostok::render::sky_dome_geometry::sky_dome_geometry((vostok::render::sky_dome_geometry *)in_renderer);
  vostok::render::sphere_geometry::sphere_geometry(v4, &this->m_clouds_geometry, COERCE_FLOAT(16), 0x10u);
  v5 = (vostok::render::stage_atmosphere::stage_type)type;
  this->m_atmospheric_scattering_effect.m_object = 0;
  this->m_screen_vertex_ib.m_object = 0;
  this->m_screen_vertex_geometry.m_object = 0;
  this->m_type = v5;
  vostok::render::effect_manager::create_effect<vostok::render::effect_atmospheric_scattering>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_atmospheric_scattering_effect);
  v7 = vostok::strings::shared::manager::string(v6, (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  type = 0;
  if ( v7 )
  {
    p_m_reference_count = &v7->m_reference_count;
    type = v7;
    v8 = (vostok::render::backend *)_InterlockedExchangeAdd(&v7->m_reference_count, 1u);
  }
  this->m_to_sun_direction_parameter = vostok::render::backend::register_constant_host(
                                         v8,
                                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                         (const vostok::shared_string *)&type,
                                         rc_float);
  if ( p_m_reference_count )
  {
    v10 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF);
    if ( !v10 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v11 = vostok::strings::shared::manager::string(v10, (const char *)s_manager.m_variable);
  v13 = 0;
  type = 0;
  if ( v11 )
  {
    v13 = &v11->m_reference_count;
    type = v11;
    v12 = (vostok::render::backend *)_InterlockedExchangeAdd(&v11->m_reference_count, 1u);
  }
  this->m_c_inverted_view_projection_matrix = vostok::render::backend::register_constant_host(
                                                v12,
                                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                (const vostok::shared_string *)&type,
                                                rc_float);
  if ( v13 )
  {
    v14 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v13, 0xFFFFFFFF);
    if ( !v14 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v15 = vostok::strings::shared::manager::string(v14, (const char *)s_manager.m_variable);
  v17 = 0;
  type = 0;
  if ( v15 )
  {
    v17 = &v15->m_reference_count;
    type = v15;
    v16 = (vostok::render::backend *)_InterlockedExchangeAdd(&v15->m_reference_count, 1u);
  }
  this->m_c_atmosphere_parameters = vostok::render::backend::register_constant_host(
                                      v16,
                                      (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                      (const vostok::shared_string *)&type,
                                      rc_float);
  if ( v17 )
  {
    v18 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v17, 0xFFFFFFFF);
    if ( !v18 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v19 = vostok::strings::shared::manager::string(v18, (const char *)s_manager.m_variable);
  v21 = 0;
  type = 0;
  if ( v19 )
  {
    v21 = &v19->m_reference_count;
    type = v19;
    v20 = (vostok::render::backend *)_InterlockedExchangeAdd(&v19->m_reference_count, 1u);
  }
  this->m_c_inscatter_parameters = vostok::render::backend::register_constant_host(
                                     v20,
                                     (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                     (const vostok::shared_string *)&type,
                                     rc_float);
  if ( v21 )
  {
    v22 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v21, 0xFFFFFFFF);
    if ( !v22 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v23 = vostok::strings::shared::manager::string(v22, (const char *)s_manager.m_variable);
  v25 = 0;
  type = 0;
  if ( v23 )
  {
    v25 = &v23->m_reference_count;
    type = v23;
    v24 = (vostok::render::backend *)_InterlockedExchangeAdd(&v23->m_reference_count, 1u);
  }
  this->m_c_eye_ray_corner = vostok::render::backend::register_constant_host(
                               v24,
                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                               (const vostok::shared_string *)&type,
                               rc_float);
  if ( v25 )
  {
    v26 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v25, 0xFFFFFFFF);
    if ( !v26 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v27 = vostok::strings::shared::manager::string(v26, (const char *)s_manager.m_variable);
  v29 = 0;
  type = 0;
  if ( v27 )
  {
    v29 = &v27->m_reference_count;
    type = v27;
    v28 = (vostok::render::backend *)_InterlockedExchangeAdd(&v27->m_reference_count, 1u);
  }
  this->m_sky_clouds_parameters0 = vostok::render::backend::register_constant_host(
                                     v28,
                                     (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                     (const vostok::shared_string *)&type,
                                     rc_float);
  if ( v29 )
  {
    v30 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v29, 0xFFFFFFFF);
    if ( !v30 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v31 = vostok::strings::shared::manager::string(v30, (const char *)s_manager.m_variable);
  v33 = 0;
  type = 0;
  if ( v31 )
  {
    v33 = &v31->m_reference_count;
    type = v31;
    v32 = (vostok::render::backend *)_InterlockedExchangeAdd(&v31->m_reference_count, 1u);
  }
  this->m_sky_clouds_parameters1 = vostok::render::backend::register_constant_host(
                                     v32,
                                     (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                     (const vostok::shared_string *)&type,
                                     rc_float);
  if ( v33 )
  {
    v34 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v33, 0xFFFFFFFF);
    if ( !v34 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v35 = vostok::strings::shared::manager::string(v34, (const char *)s_manager.m_variable);
  v37 = 0;
  type = 0;
  if ( v35 )
  {
    v37 = &v35->m_reference_count;
    type = v35;
    v36 = (vostok::render::backend *)_InterlockedExchangeAdd(&v35->m_reference_count, 1u);
  }
  this->m_sky_clouds_parameters2 = vostok::render::backend::register_constant_host(
                                     v36,
                                     (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                     (const vostok::shared_string *)&type,
                                     rc_float);
  if ( v37 )
  {
    v38 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v37, 0xFFFFFFFF);
    if ( !v38 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v39 = vostok::strings::shared::manager::string(v38, (const char *)s_manager.m_variable);
  v41 = 0;
  type = 0;
  if ( v39 )
  {
    v41 = &v39->m_reference_count;
    type = v39;
    v40 = (vostok::render::backend *)_InterlockedExchangeAdd(&v39->m_reference_count, 1u);
  }
  this->m_sun_moon_parameters = vostok::render::backend::register_constant_host(
                                  v40,
                                  (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                  (const vostok::shared_string *)&type,
                                  rc_float);
  if ( v41 && !_InterlockedExchangeAdd(v41, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  screen_vertex_layout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
  screen_vertex_layout[1].AlignedByteOffset = 16;
  indices[0] = 0;
  indices[1] = 1;
  indices[2] = 2;
  indices[3] = 3;
  indices[4] = 2;
  screen_vertex_layout[0].SemanticName = "POSITION";
  screen_vertex_layout[0].SemanticIndex = 0;
  screen_vertex_layout[0].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
  screen_vertex_layout[0].InputSlot = 0;
  screen_vertex_layout[0].AlignedByteOffset = 0;
  screen_vertex_layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  screen_vertex_layout[0].InstanceDataStepRate = 0;
  screen_vertex_layout[1].SemanticName = "TEXCOORD";
  screen_vertex_layout[1].SemanticIndex = 0;
  screen_vertex_layout[1].InputSlot = 0;
  screen_vertex_layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  screen_vertex_layout[1].InstanceDataStepRate = 0;
  indices[5] = 1;
  buffer = vostok::render::resource_manager::create_buffer(
             0xCu,
             (bool)v41,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             indices,
             enum_buffer_type_index,
             0,
             0);
  v43 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v43 = buffer;
  }
  m_object = (vostok::render::res_state *)this->m_screen_vertex_ib.m_object;
  this->m_screen_vertex_ib.m_object = v43;
  if ( m_object )
  {
    v45 = m_object->m_reference_count-- == 1;
    if ( v45 )
      vostok::render::resource_manager::release(
        m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  geometry = vostok::render::resource_manager::create_geometry(
               (stlp_std::forward_iterator_tag *)screen_vertex_layout,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               2u,
               0x18u,
               *((vostok::render::untyped_buffer **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
               + 10),
               this->m_screen_vertex_ib.m_object);
  v47 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v47 = geometry;
  }
  v48 = this->m_screen_vertex_geometry.m_object;
  this->m_screen_vertex_geometry.m_object = v47;
  if ( v48 )
  {
    v45 = v48->m_reference_count-- == 1;
    if ( v45 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v48);
  }
  this->m_enabled = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                    + 290);
}
