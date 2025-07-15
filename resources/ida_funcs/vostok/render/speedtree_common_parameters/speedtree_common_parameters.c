void __usercall vostok::render::speedtree_common_parameters::speedtree_common_parameters(
        vostok::render::speedtree_common_parameters *this@<ecx>,
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
  vostok::shared_string name; // [esp+8h] [ebp-4h] BYREF

  v2 = vostok::strings::shared::manager::string(
         (vostok::strings::shared::manager *)this,
         s_manager.m_variable,
         "camera_facing_matrix_parameter");
  v4 = 0;
  name.m_pointer.m_object = 0;
  if ( v2 )
  {
    v4 = v2;
    name.m_pointer.m_object = v2;
    v3 = (vostok::render::backend *)_InterlockedExchangeAdd(&v2->m_reference_count, 1u);
  }
  *a2 = vostok::render::backend::register_constant_host(
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
  v6 = vostok::strings::shared::manager::string(v5, s_manager.m_variable, "lod_profile_parameter");
  v8 = 0;
  name.m_pointer.m_object = 0;
  if ( v6 )
  {
    v8 = v6;
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
    v9 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF);
    if ( !v9 )
      vostok::strings::shared::manager::remove(0, s_manager.m_variable, v8);
  }
  v10 = vostok::strings::shared::manager::string(v9, s_manager.m_variable, "lod_reference_position_parameter");
  v12 = 0;
  name.m_pointer.m_object = 0;
  if ( v10 )
  {
    v12 = v10;
    name.m_pointer.m_object = v10;
    v11 = (vostok::render::backend *)_InterlockedExchangeAdd(&v10->m_reference_count, 1u);
  }
  a2[2] = vostok::render::backend::register_constant_host(
            v11,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            &name,
            rc_float);
  if ( v12 )
  {
    if ( !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, s_manager.m_variable, v12);
  }
}
