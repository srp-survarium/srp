void __thiscall vostok::particle::particle_system_cook::destroy_resource(
        vostok::particle::particle_system_cook *this,
        vostok::resources::unmanaged_resource *resource)
{
  ((void (__thiscall *)(vostok::resources::unmanaged_resource *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
}
