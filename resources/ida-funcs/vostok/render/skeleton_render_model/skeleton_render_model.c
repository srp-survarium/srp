void __usercall vostok::render::skeleton_render_model::skeleton_render_model(
        vostok::render::skeleton_render_model *this@<ecx>,
        _DWORD *a2@<eax>)
{
  vostok::strings::shared::manager *v3; // ecx
  vostok::strings::shared::profile *v4; // eax
  vostok::render::backend *v5; // ecx
  volatile signed __int32 *p_m_reference_count; // edi
  vostok::strings::shared::manager *v7; // ecx
  vostok::strings::shared::profile *v8; // eax
  vostok::render::backend *v9; // ecx
  volatile signed __int32 *v10; // edi
  vostok::shared_string name; // [esp+8h] [ebp-4h] BYREF

  vostok::render::render_model::render_model(this);
  *a2 = &vostok::render::skeleton_render_model::`vftable';
  a2[80] = 0;
  a2[81] = 0;
  a2[82] = 0;
  v4 = vostok::strings::shared::manager::string(v3, (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  name.m_pointer.m_object = 0;
  if ( v4 )
  {
    p_m_reference_count = &v4->m_reference_count;
    name.m_pointer.m_object = v4;
    v5 = (vostok::render::backend *)_InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  a2[78] = vostok::render::backend::register_constant_host(
             v5,
             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
             &name,
             rc_float);
  if ( p_m_reference_count )
  {
    v7 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF);
    if ( !v7 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v8 = vostok::strings::shared::manager::string(v7, (const char *)s_manager.m_variable);
  v10 = 0;
  name.m_pointer.m_object = 0;
  if ( v8 )
  {
    v10 = &v8->m_reference_count;
    name.m_pointer.m_object = v8;
    v9 = (vostok::render::backend *)_InterlockedExchangeAdd(&v8->m_reference_count, 1u);
  }
  a2[79] = vostok::render::backend::register_constant_host(
             v9,
             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
             &name,
             rc_float);
  if ( v10 )
  {
    if ( !_InterlockedExchangeAdd(v10, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
}
