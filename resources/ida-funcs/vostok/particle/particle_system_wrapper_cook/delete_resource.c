void __thiscall vostok::particle::particle_system_wrapper_cook::delete_resource(
        vostok::particle::particle_system_wrapper_cook *this,
        vostok::resources::resource_base *resource)
{
  if ( resource )
    vostok::memory::g_resources_unmanaged_allocator.call_free(
      &vostok::memory::g_resources_unmanaged_allocator,
      resource,
      "vostok::particle::particle_system_wrapper_cook::delete_resource",
      ".\\particle_system_wrapper_cook.cpp",
      244u);
}
