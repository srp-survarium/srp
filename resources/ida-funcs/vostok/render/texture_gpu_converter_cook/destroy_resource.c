void __thiscall vostok::render::texture_gpu_converter_cook::destroy_resource(
        vostok::render::texture_gpu_converter_cook *this,
        vostok::resources::unmanaged_resource *resource)
{
  ((void (__thiscall *)(vostok::resources::unmanaged_resource *, _DWORD))resource->~vostok::resources::unmanaged_resource)(
    resource,
    0);
  this->deallocate_resource(this, resource);
}
