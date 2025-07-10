void __thiscall vostok::particle::particle_world_cooker::destroy_resource(
        vostok::particle::particle_world_cooker *this,
        vostok::resources::unmanaged_resource *resource)
{
  ((void (__thiscall *)(vostok::resources::unmanaged_resource *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
}
