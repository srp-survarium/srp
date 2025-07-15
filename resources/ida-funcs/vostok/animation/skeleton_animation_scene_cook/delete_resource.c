void __thiscall vostok::animation::skeleton_animation_scene_cook::delete_resource(
        vostok::animation::skeleton_animation_scene_cook *this,
        vostok::resources::resource_base *resource_to_delete)
{
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::resources::resource_base>(
    &vostok::memory::g_resources_unmanaged_allocator,
    &resource_to_delete,
    "vostok::animation::skeleton_animation_scene_cook::delete_resource",
    ".\\skeleton_animation_scene_cook.cpp",
    0x12Fu);
}
