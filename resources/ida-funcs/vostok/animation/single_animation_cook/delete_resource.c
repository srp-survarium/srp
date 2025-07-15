void __thiscall vostok::animation::single_animation_cook::delete_resource(
        vostok::animation::single_animation_cook *this,
        vostok::resources::resource_base *res)
{
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))res->~vostok::resources::resource_base)(res, 0);
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::resources::resource_base>(
    &vostok::memory::g_resources_unmanaged_allocator,
    &res,
    "vostok::animation::single_animation_cook::delete_resource",
    ".\\single_animation_cook.cpp",
    0x82u);
}
