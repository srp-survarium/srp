void __thiscall vostok::render::scene::add_clouds(
        vostok::render::scene *this,
        vostok::render::scene *parameters,
        vostok::render::clouds *parametersa)
{
  vostok::render::cloud_parameters *p_m_clouds; // ebx
  void *v4; // eax
  vostok::render::clouds *v5; // ecx
  int v6; // eax

  p_m_clouds = (vostok::render::cloud_parameters *)&parameters->m_clouds;
  if ( parameters->m_clouds )
  {
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::clouds,vostok::memory::detail::call_destructor_predicate>(
      (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
      &parameters->m_clouds);
    p_m_clouds->grid_width = 0;
  }
  v4 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0xAB0u);
  if ( v4 )
  {
    vostok::render::clouds::clouds(v5, (int)v4);
    p_m_clouds->grid_width = v6;
    vostok::render::clouds::initialize(parametersa, v6, (const vostok::render::cloud_parameters *)parametersa);
  }
  else
  {
    p_m_clouds->grid_width = 0;
    vostok::render::clouds::initialize(parametersa, 0, (const vostok::render::cloud_parameters *)parametersa);
  }
}
