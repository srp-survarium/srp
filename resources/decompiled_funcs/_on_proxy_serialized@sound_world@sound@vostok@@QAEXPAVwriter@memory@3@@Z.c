void __thiscall vostok::sound::sound_world::on_proxy_serialized(
        vostok::sound::sound_world *this,
        vostok::memory::writer *writer)
{
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::memory::writer>(
    (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
    &writer);
}
