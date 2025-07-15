void __thiscall vostok::animation::animation_collection_cook::delete_resource(
        vostok::animation::animation_collection_cook *this,
        vostok::resources::resource_base *res)
{
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))res->~vostok::resources::resource_base)(res, 0);
  vostok::memory::g_resources_unmanaged_allocator.call_free(
    &vostok::memory::g_resources_unmanaged_allocator,
    res,
    "vostok::animation::animation_collection_cook::delete_resource",
    ".\\animation_collection_cook.cpp",
    209u);
}
