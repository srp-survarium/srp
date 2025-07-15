void __thiscall vostok::particle::particle_system_cook::deallocate_resource(
        vostok::particle::particle_system_cook *this,
        void *buffer)
{
  if ( buffer )
    vostok::memory::g_resources_unmanaged_allocator.call_free(
      &vostok::memory::g_resources_unmanaged_allocator,
      buffer,
      "vostok::particle::particle_system_cook::deallocate_resource",
      "c:\\survarium.deploy\\sources\\vostok\\particle\\sources\\particle_system_cook.h",
      39u);
}
