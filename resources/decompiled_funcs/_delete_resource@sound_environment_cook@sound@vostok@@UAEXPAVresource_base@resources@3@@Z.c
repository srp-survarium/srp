void __thiscall vostok::sound::sound_environment_cook::delete_resource(
        vostok::sound::sound_environment_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::memory::writer>(
    (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
    (vostok::memory::writer **)&resource);
}
