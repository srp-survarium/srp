void __thiscall vostok::render::radiance_volume::~radiance_volume(
        vostok::render::radiance_volume *this,
        vostok::render::radiance_volume *thisa)
{
  vostok::render::res_effect *m_object; // eax
  vostok::render::render_target *v3; // eax
  bool v4; // zf
  vostok::render::res_texture *v5; // eax
  vostok::render::render_target *v6; // eax
  vostok::render::res_texture *v7; // eax
  vostok::render::res_texture *v8; // eax
  vostok::render::res_texture *v9; // eax
  vostok::render::render_target *v10; // eax
  vostok::render::render_target *v11; // eax
  vostok::render::render_target *v12; // eax
  vostok::render::res_texture *v13; // eax
  vostok::render::res_texture *v14; // eax
  vostok::render::res_texture *v15; // eax
  vostok::render::render_target *v16; // eax
  vostok::render::render_target *v17; // eax
  vostok::render::render_target *v18; // eax
  vostok::render::res_texture *v19; // eax
  vostok::render::res_texture *v20; // eax
  vostok::render::res_texture *v21; // eax
  vostok::render::render_target *v22; // eax
  vostok::render::render_target *v23; // eax
  vostok::render::render_target *v24; // eax
  vostok::render::res_texture *v25; // eax
  vostok::render::res_texture *v26; // eax
  vostok::render::res_texture *v27; // eax
  vostok::render::render_target *v28; // eax
  vostok::render::render_target *v29; // eax
  vostok::render::render_target *v30; // eax
  vostok::render::res_texture *v31; // eax
  vostok::render::res_texture *v32; // eax
  vostok::render::res_texture *v33; // eax
  vostok::render::render_target *v34; // eax
  vostok::render::render_target *v35; // eax
  vostok::render::render_target *v36; // eax
  vostok::render::box_geometry *v37; // ecx
  vostok::render::untyped_buffer *v38; // eax
  vostok::render::res_declaration *v39; // eax
  vostok::render::untyped_buffer *v40; // eax
  vostok::render::res_declaration *v41; // eax
  vostok::render::res_texture *v42; // ecx
  vostok::render::res_texture *v43; // eax
  vostok::render::render_target *v44; // eax
  vostok::render::res_texture *v45; // eax
  vostok::render::render_target *v46; // eax
  vostok::render::res_texture *v47; // eax
  vostok::render::render_target *v48; // eax
  vostok::render::res_texture *v49; // eax
  vostok::render::render_target *v50; // eax
  vostok::render::res_texture *v51; // eax
  vostok::render::render_target *v52; // eax
  vostok::render::res_texture *v53; // eax
  vostok::render::render_target *v54; // eax
  vostok::render::res_texture *v55; // eax
  vostok::render::render_target *v56; // eax
  vostok::render::res_texture *v57; // eax
  vostok::render::render_target *v58; // eax
  vostok::render::res_texture *v59; // eax
  const char *v60; // eax

  m_object = thisa->m_lpv_effect.m_object;
  if ( m_object )
  {
    this = (vostok::render::radiance_volume *)_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF);
    if ( !this )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &thisa->m_lpv_effect.m_object->vostok::resources::unmanaged_intrusive_base,
        thisa->m_lpv_effect.m_object);
  }
  v3 = thisa->m_radiance_depth_stencil.m_object;
  if ( v3 )
  {
    v4 = v3->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_radiance_depth_stencil.m_object);
  }
  v5 = thisa->m_3d_t_occluders.m_object;
  if ( v5 )
  {
    v4 = v5->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this, thisa->m_3d_t_occluders.m_object);
  }
  v6 = thisa->m_3d_rt_occluders.m_object;
  if ( v6 )
  {
    v4 = v6->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)thisa->m_3d_rt_occluders.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_occluders.m_object);
  }
  v7 = thisa->m_3d_t_accumulated_propagation_b.m_object;
  if ( v7 )
  {
    v4 = v7->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_3d_t_accumulated_propagation_b.m_object);
  }
  v8 = thisa->m_3d_t_accumulated_propagation_g.m_object;
  if ( v8 )
  {
    v4 = v8->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_3d_t_accumulated_propagation_g.m_object);
  }
  v9 = thisa->m_3d_t_accumulated_propagation_r.m_object;
  if ( v9 )
  {
    v4 = v9->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_3d_t_accumulated_propagation_r.m_object);
  }
  v10 = thisa->m_3d_rt_accumulated_propagation_b.m_object;
  if ( v10 )
  {
    v4 = v10->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_accumulated_propagation_b.m_object);
  }
  v11 = thisa->m_3d_rt_accumulated_propagation_g.m_object;
  if ( v11 )
  {
    v4 = v11->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_accumulated_propagation_g.m_object);
  }
  v12 = thisa->m_3d_rt_accumulated_propagation_r.m_object;
  if ( v12 )
  {
    v4 = v12->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)thisa->m_3d_rt_accumulated_propagation_r.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_accumulated_propagation_r.m_object);
  }
  v13 = thisa->m_3d_t_radiance_intermediate_b.m_object;
  if ( v13 )
  {
    v4 = v13->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_3d_t_radiance_intermediate_b.m_object);
  }
  v14 = thisa->m_3d_t_radiance_intermediate_g.m_object;
  if ( v14 )
  {
    v4 = v14->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_3d_t_radiance_intermediate_g.m_object);
  }
  v15 = thisa->m_3d_t_radiance_intermediate_r.m_object;
  if ( v15 )
  {
    v4 = v15->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_3d_t_radiance_intermediate_r.m_object);
  }
  v16 = thisa->m_3d_rt_radiance_intermediate_b.m_object;
  if ( v16 )
  {
    v4 = v16->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_radiance_intermediate_b.m_object);
  }
  v17 = thisa->m_3d_rt_radiance_intermediate_g.m_object;
  if ( v17 )
  {
    v4 = v17->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_radiance_intermediate_g.m_object);
  }
  v18 = thisa->m_3d_rt_radiance_intermediate_r.m_object;
  if ( v18 )
  {
    v4 = v18->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)thisa->m_3d_rt_radiance_intermediate_r.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_radiance_intermediate_r.m_object);
  }
  v19 = thisa->m_3d_t_radiance_b_apply.m_object;
  if ( v19 )
  {
    v4 = v19->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_3d_t_radiance_b_apply.m_object);
  }
  v20 = thisa->m_3d_t_radiance_g_apply.m_object;
  if ( v20 )
  {
    v4 = v20->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_3d_t_radiance_g_apply.m_object);
  }
  v21 = thisa->m_3d_t_radiance_r_apply.m_object;
  if ( v21 )
  {
    v4 = v21->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_3d_t_radiance_r_apply.m_object);
  }
  v22 = thisa->m_3d_rt_radiance_b_apply.m_object;
  if ( v22 )
  {
    v4 = v22->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_radiance_b_apply.m_object);
  }
  v23 = thisa->m_3d_rt_radiance_g_apply.m_object;
  if ( v23 )
  {
    v4 = v23->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_radiance_g_apply.m_object);
  }
  v24 = thisa->m_3d_rt_radiance_r_apply.m_object;
  if ( v24 )
  {
    v4 = v24->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)thisa->m_3d_rt_radiance_r_apply.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_radiance_r_apply.m_object);
  }
  v25 = thisa->m_3d_t_radiance_b.m_object;
  if ( v25 )
  {
    v4 = v25->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this, thisa->m_3d_t_radiance_b.m_object);
  }
  v26 = thisa->m_3d_t_radiance_g.m_object;
  if ( v26 )
  {
    v4 = v26->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this, thisa->m_3d_t_radiance_g.m_object);
  }
  v27 = thisa->m_3d_t_radiance_r.m_object;
  if ( v27 )
  {
    v4 = v27->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this, thisa->m_3d_t_radiance_r.m_object);
  }
  v28 = thisa->m_3d_rt_radiance_b.m_object;
  if ( v28 )
  {
    v4 = v28->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_radiance_b.m_object);
  }
  v29 = thisa->m_3d_rt_radiance_g.m_object;
  if ( v29 )
  {
    v4 = v29->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_radiance_g.m_object);
  }
  v30 = thisa->m_3d_rt_radiance_r.m_object;
  if ( v30 )
  {
    v4 = v30->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)thisa->m_3d_rt_radiance_r.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_radiance_r.m_object);
  }
  v31 = thisa->m_3d_t_previous_radiance_b.m_object;
  if ( v31 )
  {
    v4 = v31->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_3d_t_previous_radiance_b.m_object);
  }
  v32 = thisa->m_3d_t_previous_radiance_g.m_object;
  if ( v32 )
  {
    v4 = v32->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_3d_t_previous_radiance_g.m_object);
  }
  v33 = thisa->m_3d_t_previous_radiance_r.m_object;
  if ( v33 )
  {
    v4 = v33->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        thisa->m_3d_t_previous_radiance_r.m_object);
  }
  v34 = thisa->m_3d_rt_previous_radiance_b.m_object;
  if ( v34 )
  {
    v4 = v34->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_previous_radiance_b.m_object);
  }
  v35 = thisa->m_3d_rt_previous_radiance_g.m_object;
  if ( v35 )
  {
    v4 = v35->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_previous_radiance_g.m_object);
  }
  v36 = thisa->m_3d_rt_previous_radiance_r.m_object;
  if ( v36 )
  {
    v4 = v36->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)thisa->m_3d_rt_previous_radiance_r.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_3d_rt_previous_radiance_r.m_object);
  }
  vostok::render::box_geometry::~box_geometry((vostok::render::box_geometry *)this, (int)&thisa->m_sliced_cube_geometry);
  v38 = thisa->m_injection_geometry_from_camera.m_vertex_buffer.m_object;
  if ( v38 )
  {
    v4 = v38->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)thisa->m_injection_geometry_from_camera.m_vertex_buffer.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v39 = thisa->m_injection_geometry_from_camera.m_vertext_declaration.m_object;
  if ( v39 )
  {
    v4 = v39->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_injection_geometry_from_camera.m_vertext_declaration.m_object);
  }
  v40 = thisa->m_injection_geometry.m_vertex_buffer.m_object;
  if ( v40 )
  {
    v4 = v40->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)thisa->m_injection_geometry.m_vertex_buffer.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v41 = thisa->m_injection_geometry.m_vertext_declaration.m_object;
  if ( v41 )
  {
    v4 = v41->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_injection_geometry.m_vertext_declaration.m_object);
  }
  vostok::render::box_geometry::~box_geometry(v37, (int)&thisa->m_box_geometry);
  v43 = thisa->m_t_rms_position.m_object;
  if ( v43 )
  {
    v4 = v43->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(v42, thisa->m_t_rms_position.m_object);
  }
  v44 = thisa->m_rt_rms_position.m_object;
  if ( v44 )
  {
    v4 = v44->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v42,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_rt_rms_position.m_object);
  }
  v45 = thisa->m_t_rms_normal.m_object;
  if ( v45 )
  {
    v4 = v45->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(v42, thisa->m_t_rms_normal.m_object);
  }
  v46 = thisa->m_rt_rms_normal.m_object;
  if ( v46 )
  {
    v4 = v46->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)thisa->m_rt_rms_normal.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_rt_rms_normal.m_object);
  }
  v47 = thisa->m_t_rms_albedo.m_object;
  if ( v47 )
  {
    v4 = v47->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(v42, thisa->m_t_rms_albedo.m_object);
  }
  v48 = thisa->m_rt_rms_albedo.m_object;
  if ( v48 )
  {
    v4 = v48->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_rt_rms_albedo.m_object);
  }
  v49 = thisa->m_t_rms_position_source_temp.m_object;
  if ( v49 )
  {
    v4 = v49->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(v42, thisa->m_t_rms_position_source_temp.m_object);
  }
  v50 = thisa->m_rt_rms_position_source_temp.m_object;
  if ( v50 )
  {
    v4 = v50->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v42,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_rt_rms_position_source_temp.m_object);
  }
  v51 = thisa->m_t_rms_normal_source_temp.m_object;
  if ( v51 )
  {
    v4 = v51->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(v42, thisa->m_t_rms_normal_source_temp.m_object);
  }
  v52 = thisa->m_rt_rms_normal_source_temp.m_object;
  if ( v52 )
  {
    v4 = v52->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)thisa->m_rt_rms_normal_source_temp.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_rt_rms_normal_source_temp.m_object);
  }
  v53 = thisa->m_t_rms_albedo_source_temp.m_object;
  if ( v53 )
  {
    v4 = v53->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(v42, thisa->m_t_rms_albedo_source_temp.m_object);
  }
  v54 = thisa->m_rt_rms_albedo_source_temp.m_object;
  if ( v54 )
  {
    v4 = v54->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_rt_rms_albedo_source_temp.m_object);
  }
  v55 = thisa->m_t_rms_position_source.m_object;
  if ( v55 )
  {
    v4 = v55->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(v42, thisa->m_t_rms_position_source.m_object);
  }
  v56 = thisa->m_rt_rms_position_source.m_object;
  if ( v56 )
  {
    v4 = v56->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v42,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_rt_rms_position_source.m_object);
  }
  v57 = thisa->m_t_rms_normal_source.m_object;
  if ( v57 )
  {
    v4 = v57->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(v42, thisa->m_t_rms_normal_source.m_object);
  }
  v58 = thisa->m_rt_rms_normal_source.m_object;
  if ( v58 )
  {
    v4 = v58->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)thisa->m_rt_rms_normal_source.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_rt_rms_normal_source.m_object);
  }
  v59 = thisa->m_t_rms_albedo_source.m_object;
  if ( v59 )
  {
    v4 = v59->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(v42, thisa->m_t_rms_albedo_source.m_object);
  }
  v60 = (const char *)thisa->m_rt_rms_albedo_source.m_object;
  if ( thisa->m_rt_rms_albedo_source.m_object )
  {
    v4 = (*(_DWORD *)v60)-- == 1;
    if ( v4 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)thisa->m_rt_rms_albedo_source.m_object);
  }
}
