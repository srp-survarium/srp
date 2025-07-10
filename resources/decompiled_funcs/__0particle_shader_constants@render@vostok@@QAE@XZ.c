void __usercall vostok::render::particle_shader_constants::particle_shader_constants(
        vostok::render::particle_shader_constants *this@<ecx>,
        vostok::render::shader_constant_host **a2@<edi>)
{
  vostok::strings::shared::profile *v2; // eax
  vostok::render::backend *v3; // ecx
  volatile signed __int32 *p_m_reference_count; // esi
  vostok::strings::shared::manager *v5; // ecx
  vostok::strings::shared::profile *v6; // eax
  vostok::render::backend *v7; // ecx
  volatile signed __int32 *v8; // esi
  vostok::strings::shared::manager *v9; // ecx
  vostok::strings::shared::profile *v10; // eax
  vostok::render::backend *v11; // ecx
  volatile signed __int32 *v12; // esi
  vostok::strings::shared::manager *v13; // ecx
  vostok::strings::shared::profile *v14; // eax
  vostok::render::backend *v15; // ecx
  volatile signed __int32 *v16; // esi
  vostok::strings::shared::manager *v17; // ecx
  vostok::strings::shared::profile *v18; // eax
  vostok::render::backend *v19; // ecx
  volatile signed __int32 *v20; // esi
  vostok::strings::shared::manager *v21; // ecx
  vostok::strings::shared::profile *v22; // eax
  vostok::render::backend *v23; // ecx
  volatile signed __int32 *v24; // esi
  vostok::strings::shared::manager *v25; // ecx
  vostok::strings::shared::profile *v26; // eax
  vostok::render::backend *v27; // ecx
  volatile signed __int32 *v28; // esi
  vostok::strings::shared::manager *v29; // ecx
  vostok::strings::shared::profile *v30; // eax
  vostok::render::backend *v31; // ecx
  volatile signed __int32 *v32; // esi
  vostok::shared_string name; // [esp+8h] [ebp-4h] BYREF

  *(_DWORD *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_is_active = a2;
  v2 = vostok::strings::shared::manager::string(
         (vostok::strings::shared::manager *)this,
         (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  name.m_pointer.m_object = 0;
  if ( v2 )
  {
    p_m_reference_count = &v2->m_reference_count;
    name.m_pointer.m_object = v2;
    v3 = (vostok::render::backend *)_InterlockedExchangeAdd(&v2->m_reference_count, 1u);
  }
  *a2 = vostok::render::backend::register_constant_host(
          v3,
          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
          &name,
          rc_float);
  if ( p_m_reference_count )
  {
    v5 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF);
    if ( !v5 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v6 = vostok::strings::shared::manager::string(v5, (const char *)s_manager.m_variable);
  v8 = 0;
  name.m_pointer.m_object = 0;
  if ( v6 )
  {
    v8 = &v6->m_reference_count;
    name.m_pointer.m_object = v6;
    v7 = (vostok::render::backend *)_InterlockedExchangeAdd(&v6->m_reference_count, 1u);
  }
  a2[1] = vostok::render::backend::register_constant_host(
            v7,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v8 )
  {
    v9 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v8, 0xFFFFFFFF);
    if ( !v9 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v10 = vostok::strings::shared::manager::string(v9, (const char *)s_manager.m_variable);
  v12 = 0;
  name.m_pointer.m_object = 0;
  if ( v10 )
  {
    v12 = &v10->m_reference_count;
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
    v13 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v12, 0xFFFFFFFF);
    if ( !v13 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v14 = vostok::strings::shared::manager::string(v13, (const char *)s_manager.m_variable);
  v16 = 0;
  name.m_pointer.m_object = 0;
  if ( v14 )
  {
    v16 = &v14->m_reference_count;
    name.m_pointer.m_object = v14;
    v15 = (vostok::render::backend *)_InterlockedExchangeAdd(&v14->m_reference_count, 1u);
  }
  a2[6] = vostok::render::backend::register_constant_host(
            v15,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v16 )
  {
    v17 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v16, 0xFFFFFFFF);
    if ( !v17 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v18 = vostok::strings::shared::manager::string(v17, (const char *)s_manager.m_variable);
  v20 = 0;
  name.m_pointer.m_object = 0;
  if ( v18 )
  {
    v20 = &v18->m_reference_count;
    name.m_pointer.m_object = v18;
    v19 = (vostok::render::backend *)_InterlockedExchangeAdd(&v18->m_reference_count, 1u);
  }
  a2[4] = vostok::render::backend::register_constant_host(
            v19,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v20 )
  {
    v21 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v20, 0xFFFFFFFF);
    if ( !v21 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v22 = vostok::strings::shared::manager::string(v21, (const char *)s_manager.m_variable);
  v24 = 0;
  name.m_pointer.m_object = 0;
  if ( v22 )
  {
    v24 = &v22->m_reference_count;
    name.m_pointer.m_object = v22;
    v23 = (vostok::render::backend *)_InterlockedExchangeAdd(&v22->m_reference_count, 1u);
  }
  a2[2] = vostok::render::backend::register_constant_host(
            v23,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v24 )
  {
    v25 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v24, 0xFFFFFFFF);
    if ( !v25 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v26 = vostok::strings::shared::manager::string(v25, (const char *)s_manager.m_variable);
  v28 = 0;
  name.m_pointer.m_object = 0;
  if ( v26 )
  {
    v28 = &v26->m_reference_count;
    name.m_pointer.m_object = v26;
    v27 = (vostok::render::backend *)_InterlockedExchangeAdd(&v26->m_reference_count, 1u);
  }
  a2[5] = vostok::render::backend::register_constant_host(
            v27,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v28 )
  {
    v29 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v28, 0xFFFFFFFF);
    if ( !v29 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v30 = vostok::strings::shared::manager::string(v29, (const char *)s_manager.m_variable);
  v32 = 0;
  name.m_pointer.m_object = 0;
  if ( v30 )
  {
    v32 = &v30->m_reference_count;
    name.m_pointer.m_object = v30;
    v31 = (vostok::render::backend *)_InterlockedExchangeAdd(&v30->m_reference_count, 1u);
  }
  a2[7] = vostok::render::backend::register_constant_host(
            v31,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v32 )
  {
    if ( !_InterlockedExchangeAdd(v32, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
}
