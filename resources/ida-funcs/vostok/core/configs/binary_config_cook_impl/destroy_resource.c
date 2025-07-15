void __thiscall vostok::core::configs::binary_config_cook_impl::destroy_resource(
        vostok::core::configs::binary_config_cook_impl *this,
        vostok::resources::unmanaged_resource *resource)
{
  ((void (__thiscall *)(vostok::resources::unmanaged_resource *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
}
