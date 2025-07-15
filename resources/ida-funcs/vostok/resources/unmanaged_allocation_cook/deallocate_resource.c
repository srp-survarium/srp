void __thiscall vostok::resources::unmanaged_allocation_cook::deallocate_resource(
        vostok::resources::unmanaged_allocation_cook *this,
        void *buffer)
{
  if ( buffer )
    vostok::memory::g_resources_unmanaged_allocator.call_free(
      &vostok::memory::g_resources_unmanaged_allocator,
      buffer,
      "vostok::resources::unmanaged_allocation_cook::deallocate_resource",
      ".\\unmanaged_allocation_cook.cpp",
      65u);
}
