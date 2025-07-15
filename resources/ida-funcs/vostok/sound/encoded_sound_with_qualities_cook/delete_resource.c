void __thiscall vostok::sound::encoded_sound_with_qualities_cook::delete_resource(
        vostok::sound::encoded_sound_with_qualities_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::resources::resource_base>(
    &vostok::memory::g_resources_unmanaged_allocator,
    &resource,
    "vostok::sound::encoded_sound_with_qualities_cook::delete_resource",
    ".\\encoded_sound_with_qualities_cook.cpp",
    0x21u);
}
