void __thiscall vostok::render::effect_manager::delete_effect_technique(
        vostok::render::effect_manager *this,
        const vostok::render::res_shader_technique *technique)
{
  if ( technique->m_registered )
  {
    if ( vostok::render::reclaim<vostok::render::res_shader_technique,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique>>(
           &this->m_techniques,
           technique) )
    {
      vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::res_shader_technique,vostok::render::effect_manager_call_destructor_predicate>(
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
        (vostok::render::res_shader_technique **)&technique);
    }
  }
}
