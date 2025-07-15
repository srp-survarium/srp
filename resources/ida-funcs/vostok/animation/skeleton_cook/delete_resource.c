void __thiscall vostok::animation::skeleton_cook::delete_resource(
        vostok::animation::skeleton_cook *this,
        vostok::resources::resource_base *res)
{
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))res->~vostok::resources::resource_base)(res, 0);
  vostok::memory::g_resources_unmanaged_allocator.call_free(&vostok::memory::g_resources_unmanaged_allocator, res);
}
