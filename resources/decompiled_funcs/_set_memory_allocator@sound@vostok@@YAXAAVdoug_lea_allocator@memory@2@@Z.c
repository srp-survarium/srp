void __cdecl vostok::sound::set_memory_allocator(vostok::resources::unmanaged_resource *allocator)
{
  vostok::sound::g_allocator.m_object = allocator;
}
