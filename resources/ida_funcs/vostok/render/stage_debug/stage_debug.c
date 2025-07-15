void __usercall vostok::render::stage_debug::stage_debug(
        vostok::render::stage_debug *this@<esi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>)
{
  vostok::strings::shared::manager *v3; // ecx
  vostok::strings::shared::profile *v4; // eax
  vostok::render::backend *v5; // ecx
  volatile signed __int32 *p_m_reference_count; // edi
  vostok::shared_string name; // [esp+8h] [ebp-4h] BYREF

  this->m_context = context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_debug_vtbl *)&vostok::render::stage_debug::`vftable';
  this->m_debug_environment_probe_preview_effect.m_object = 0;
  vostok::render::sphere_geometry::sphere_geometry(
    (vostok::render::sphere_geometry *)in_renderer,
    &this->m_sphere_geometry,
    COERCE_FLOAT(32),
    0x20u);
  vostok::render::effect_manager::create_effect<vostok::render::effect_debug_environment_probe_preview>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_debug_environment_probe_preview_effect);
  v4 = vostok::strings::shared::manager::string(v3, (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  name.m_pointer.m_object = 0;
  if ( v4 )
  {
    p_m_reference_count = &v4->m_reference_count;
    name.m_pointer.m_object = v4;
    v5 = (vostok::render::backend *)_InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  this->m_preview_mip_index_parameter = vostok::render::backend::register_constant_host(
                                          v5,
                                          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                          &name,
                                          rc_int);
  if ( p_m_reference_count )
  {
    if ( !_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
}
