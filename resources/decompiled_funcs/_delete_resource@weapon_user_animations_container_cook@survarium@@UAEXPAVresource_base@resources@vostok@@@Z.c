void __thiscall survarium::weapon_user_animations_container_cook::delete_resource(
        survarium::weapon_user_animations_container_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::memory::writer>(
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
    (vostok::memory::writer **)&resource);
}
