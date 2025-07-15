void __thiscall vostok::sound::single_sound_cook::delete_resource(
        vostok::sound::single_sound_cook *this,
        vostok::resources::resource_base *res)
{
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::resources::resource_base>(
    &vostok::memory::g_resources_unmanaged_allocator,
    &res,
    "vostok::sound::single_sound_cook::delete_resource",
    ".\\single_sound_cook.cpp",
    0x91u);
}
