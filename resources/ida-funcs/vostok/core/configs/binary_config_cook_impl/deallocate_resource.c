void __thiscall vostok::core::configs::binary_config_cook_impl::deallocate_resource(
        vostok::core::configs::binary_config_cook_impl *this,
        void *buffer)
{
  if ( buffer )
    vostok::memory::g_resources_unmanaged_allocator.call_free(
      &vostok::memory::g_resources_unmanaged_allocator,
      buffer,
      "vostok::core::configs::binary_config_cook_impl::deallocate_resource",
      ".\\configs_binary_config_cook.cpp",
      60u);
}
