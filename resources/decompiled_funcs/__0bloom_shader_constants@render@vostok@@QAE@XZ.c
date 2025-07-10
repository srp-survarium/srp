void __usercall vostok::render::bloom_shader_constants::bloom_shader_constants(
        vostok::render::bloom_shader_constants *this@<ecx>,
        vostok::render::shader_constant_host **a2@<edi>)
{
  vostok::strings::shared::profile *v2; // eax
  vostok::render::backend *v3; // ecx
  volatile signed __int32 *p_m_reference_count; // esi
  vostok::strings::shared::manager *v5; // ecx
  vostok::strings::shared::profile *v6; // eax
  vostok::render::backend *v7; // ecx
  volatile signed __int32 *v8; // esi
  vostok::shared_string name; // [esp+8h] [ebp-4h] BYREF

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
    if ( !_InterlockedExchangeAdd(v8, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
}
