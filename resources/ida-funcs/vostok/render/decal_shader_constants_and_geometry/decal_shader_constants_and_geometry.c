void __usercall vostok::render::decal_shader_constants_and_geometry::decal_shader_constants_and_geometry(
        vostok::render::decal_shader_constants_and_geometry *this@<ecx>,
        vostok::render::shader_constant_host **a2@<eax>)
{
  vostok::strings::shared::profile *v3; // eax
  vostok::render::backend *v4; // ecx
  volatile signed __int32 *p_m_reference_count; // edi
  vostok::strings::shared::manager *v6; // ecx
  vostok::strings::shared::profile *v7; // eax
  vostok::render::backend *v8; // ecx
  volatile signed __int32 *v9; // edi
  vostok::strings::shared::manager *v10; // ecx
  vostok::strings::shared::profile *v11; // eax
  vostok::render::backend *v12; // ecx
  volatile signed __int32 *v13; // edi
  vostok::strings::shared::manager *v14; // ecx
  vostok::strings::shared::profile *v15; // eax
  vostok::render::backend *v16; // ecx
  volatile signed __int32 *v17; // edi
  vostok::render::decal_shader_constants_and_geometry *v18; // ecx
  vostok::shared_string name; // [esp+8h] [ebp-4h] BYREF

  a2[4] = 0;
  a2[5] = 0;
  a2[6] = 0;
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_waiting_for_bind_action = (survarium::game_action_id)a2;
  v3 = vostok::strings::shared::manager::string(
         (vostok::strings::shared::manager *)this,
         (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  name.m_pointer.m_object = 0;
  if ( v3 )
  {
    p_m_reference_count = &v3->m_reference_count;
    name.m_pointer.m_object = v3;
    v4 = (vostok::render::backend *)_InterlockedExchangeAdd(&v3->m_reference_count, 1u);
  }
  *a2 = vostok::render::backend::register_constant_host(
          v4,
          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
          &name,
          rc_float);
  if ( p_m_reference_count )
  {
    v6 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF);
    if ( !v6 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v7 = vostok::strings::shared::manager::string(v6, (const char *)s_manager.m_variable);
  v9 = 0;
  name.m_pointer.m_object = 0;
  if ( v7 )
  {
    v9 = &v7->m_reference_count;
    name.m_pointer.m_object = v7;
    v8 = (vostok::render::backend *)_InterlockedExchangeAdd(&v7->m_reference_count, 1u);
  }
  a2[1] = vostok::render::backend::register_constant_host(
            v8,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v9 )
  {
    v10 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v9, 0xFFFFFFFF);
    if ( !v10 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v11 = vostok::strings::shared::manager::string(v10, (const char *)s_manager.m_variable);
  v13 = 0;
  name.m_pointer.m_object = 0;
  if ( v11 )
  {
    v13 = &v11->m_reference_count;
    name.m_pointer.m_object = v11;
    v12 = (vostok::render::backend *)_InterlockedExchangeAdd(&v11->m_reference_count, 1u);
  }
  a2[2] = vostok::render::backend::register_constant_host(
            v12,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v13 )
  {
    v14 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v13, 0xFFFFFFFF);
    if ( !v14 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v15 = vostok::strings::shared::manager::string(v14, (const char *)s_manager.m_variable);
  v17 = 0;
  name.m_pointer.m_object = 0;
  if ( v15 )
  {
    v17 = &v15->m_reference_count;
    name.m_pointer.m_object = v15;
    v16 = (vostok::render::backend *)_InterlockedExchangeAdd(&v15->m_reference_count, 1u);
  }
  a2[3] = vostok::render::backend::register_constant_host(
            v16,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v17 )
  {
    v18 = (vostok::render::decal_shader_constants_and_geometry *)_InterlockedExchangeAdd(v17, 0xFFFFFFFF);
    if ( !v18 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::render::decal_shader_constants_and_geometry::create_decal_geometry(v18, (bool)v17, a2);
}
