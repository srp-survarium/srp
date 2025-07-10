void __usercall vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(
        vostok::render::res_shader_technique *instance@<eax>)
{
  bool v1; // zf
  vostok::render::res_shader_technique *pointer; // [esp+8h] [ebp-4h] BYREF

  v1 = !instance->m_registered;
  pointer = instance;
  if ( !v1 )
  {
    if ( vostok::render::reclaim<vostok::render::res_shader_technique,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique>>(
           (vostok::render::set<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique> > *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind + 72),
           instance) )
    {
      vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::res_shader_technique,vostok::render::effect_manager_call_destructor_predicate>(
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
        &pointer);
    }
  }
}
