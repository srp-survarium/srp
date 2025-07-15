void __thiscall vostok::particle::particle_world_cooker::deallocate_resource(
        vostok::particle::particle_world_cooker *this,
        void *buffer)
{
  if ( buffer )
    vostok::memory::g_resources_unmanaged_allocator.call_free(
      &vostok::memory::g_resources_unmanaged_allocator,
      buffer,
      "vostok::particle::particle_world_cooker::deallocate_resource",
      ".\\particle_world_cooker.cpp",
      37u);
}
