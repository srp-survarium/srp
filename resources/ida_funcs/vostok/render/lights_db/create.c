void __thiscall vostok::render::lights_db::create(
        vostok::render::lights_db *this,
        const vostok::render::lights_db *operation)
{
  vostok::render::light *v2; // eax

  v2 = (vostok::render::light *)vostok::memory::doug_lea_allocator::malloc_impl(
                                  (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                  0x1A0u);
  if ( v2 )
    vostok::render::light::light(v2, operation->m_lights_tree);
}
