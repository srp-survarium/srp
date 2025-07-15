void __usercall vostok::render::speedtree_billboard_parameters::speedtree_billboard_parameters(
        vostok::render::speedtree_billboard_parameters *this@<ecx>,
        vostok::render::shader_constant_host **a2@<edi>)
{
  vostok::strings::shared::profile *v2; // eax
  vostok::render::backend *v3; // ecx
  vostok::strings::shared::profile *v4; // esi
  vostok::strings::shared::manager *v5; // ecx
  vostok::strings::shared::profile *v6; // eax
  vostok::render::backend *v7; // ecx
  vostok::strings::shared::profile *v8; // esi
  vostok::strings::shared::manager *v9; // ecx
  vostok::strings::shared::profile *v10; // eax
  vostok::render::backend *v11; // ecx
  vostok::strings::shared::profile *v12; // esi
  vostok::strings::shared::manager *v13; // ecx
  vostok::strings::shared::profile *v14; // eax
  vostok::render::backend *v15; // ecx
  vostok::strings::shared::profile *v16; // esi
  vostok::strings::shared::manager *v17; // ecx
  vostok::strings::shared::profile *v18; // eax
  vostok::render::backend *v19; // ecx
  vostok::strings::shared::profile *v20; // esi
  vostok::strings::shared::manager *v21; // ecx
  vostok::strings::shared::profile *v22; // eax
  vostok::render::backend *v23; // ecx
  vostok::strings::shared::profile *v24; // esi
  vostok::strings::shared::manager *v25; // ecx
  vostok::strings::shared::profile *v26; // eax
  vostok::render::backend *v27; // ecx
  vostok::strings::shared::profile *v28; // esi
  vostok::shared_string name; // [esp+8h] [ebp-4h] BYREF

  v2 = vostok::strings::shared::manager::string(
         (vostok::strings::shared::manager *)this,
         s_manager.m_variable,
         "billboard_dimensions_parameter");
  v4 = 0;
  name.m_pointer.m_object = 0;
  if ( v2 )
  {
    v4 = v2;
    name.m_pointer.m_object = v2;
    v3 = (vostok::render::backend *)_InterlockedExchangeAdd(&v2->m_reference_count, 1u);
  }
  a2[1] = vostok::render::backend::register_constant_host(
            v3,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v4 )
  {
    v5 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF);
    if ( !v5 )
      vostok::strings::shared::manager::remove(0, s_manager.m_variable, v4);
  }
  v6 = vostok::strings::shared::manager::string(v5, s_manager.m_variable, "camera_azimuth_trig_parameter");
  v8 = 0;
  name.m_pointer.m_object = 0;
  if ( v6 )
  {
    v8 = v6;
    name.m_pointer.m_object = v6;
    v7 = (vostok::render::backend *)_InterlockedExchangeAdd(&v6->m_reference_count, 1u);
  }
  a2[2] = vostok::render::backend::register_constant_host(
            v7,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v8 )
  {
    v9 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF);
    if ( !v9 )
      vostok::strings::shared::manager::remove(0, s_manager.m_variable, v8);
  }
  v10 = vostok::strings::shared::manager::string(v9, s_manager.m_variable, "camera_angles_parameter");
  v12 = 0;
  name.m_pointer.m_object = 0;
  if ( v10 )
  {
    v12 = v10;
    name.m_pointer.m_object = v10;
    v11 = (vostok::render::backend *)_InterlockedExchangeAdd(&v10->m_reference_count, 1u);
  }
  a2[3] = vostok::render::backend::register_constant_host(
            v11,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v12 )
  {
    v13 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF);
    if ( !v13 )
      vostok::strings::shared::manager::remove(0, s_manager.m_variable, v12);
  }
  v14 = vostok::strings::shared::manager::string(v13, s_manager.m_variable, "num360images_parameter");
  v16 = 0;
  name.m_pointer.m_object = 0;
  if ( v14 )
  {
    v16 = v14;
    name.m_pointer.m_object = v14;
    v15 = (vostok::render::backend *)_InterlockedExchangeAdd(&v14->m_reference_count, 1u);
  }
  a2[4] = vostok::render::backend::register_constant_host(
            v15,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v16 )
  {
    v17 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF);
    if ( !v17 )
      vostok::strings::shared::manager::remove(0, s_manager.m_variable, v16);
  }
  v18 = vostok::strings::shared::manager::string(v17, s_manager.m_variable, "tex_coords_360_parameter");
  v20 = 0;
  name.m_pointer.m_object = 0;
  if ( v18 )
  {
    v20 = v18;
    name.m_pointer.m_object = v18;
    v19 = (vostok::render::backend *)_InterlockedExchangeAdd(&v18->m_reference_count, 1u);
  }
  a2[5] = vostok::render::backend::register_constant_host(
            v19,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v20 )
  {
    v21 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(&v20->m_reference_count, 0xFFFFFFFF);
    if ( !v21 )
      vostok::strings::shared::manager::remove(0, s_manager.m_variable, v20);
  }
  v22 = vostok::strings::shared::manager::string(v21, s_manager.m_variable, "billboard_tangents_parameter");
  v24 = 0;
  name.m_pointer.m_object = 0;
  if ( v22 )
  {
    v24 = v22;
    name.m_pointer.m_object = v22;
    v23 = (vostok::render::backend *)_InterlockedExchangeAdd(&v22->m_reference_count, 1u);
  }
  *a2 = vostok::render::backend::register_constant_host(
          v23,
          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
          &name,
          rc_float);
  if ( v24 )
  {
    v25 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(&v24->m_reference_count, 0xFFFFFFFF);
    if ( !v25 )
      vostok::strings::shared::manager::remove(0, s_manager.m_variable, v24);
  }
  v26 = vostok::strings::shared::manager::string(v25, s_manager.m_variable, "view_location_parameter");
  v28 = 0;
  name.m_pointer.m_object = 0;
  if ( v26 )
  {
    v28 = v26;
    name.m_pointer.m_object = v26;
    v27 = (vostok::render::backend *)_InterlockedExchangeAdd(&v26->m_reference_count, 1u);
  }
  a2[6] = vostok::render::backend::register_constant_host(
            v27,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v28 )
  {
    if ( !_InterlockedExchangeAdd(&v28->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, s_manager.m_variable, v28);
  }
}
