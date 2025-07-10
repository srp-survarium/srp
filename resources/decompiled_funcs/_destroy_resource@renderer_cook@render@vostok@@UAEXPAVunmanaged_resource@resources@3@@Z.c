void __thiscall vostok::render::renderer_cook::destroy_resource(
        vostok::animation::bi_spline_skeleton_animation_baked_cook *this,
        vostok::resources::unmanaged_resource *resource)
{
  ((void (__thiscall *)(vostok::resources::unmanaged_resource *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
}
