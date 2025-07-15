void __thiscall vostok::sound::composite_sound_cook::delete_resource(
        vostok::sound::composite_sound_cook *this,
        vostok::resources::resource_base *res)
{
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))res->~vostok::resources::resource_base)(res, 0);
  vostok::memory::g_resources_unmanaged_allocator.call_free(
    &vostok::memory::g_resources_unmanaged_allocator,
    res,
    "vostok::sound::composite_sound_cook::delete_resource",
    ".\\composite_sound_cook.cpp",
    155u);
}
