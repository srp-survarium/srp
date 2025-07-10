void __thiscall vostok::render::engine::world::remove_clouds(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene)
{
  vostok::render::clouds **p_m_last_fail_of_increasing_quality; // esi

  p_m_last_fail_of_increasing_quality = (vostok::render::clouds **)&in_scene->m_object[3].m_last_fail_of_increasing_quality;
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::clouds,vostok::memory::detail::call_destructor_predicate>(
    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
    p_m_last_fail_of_increasing_quality);
  *p_m_last_fail_of_increasing_quality = 0;
}
