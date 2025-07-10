void __thiscall survarium::weapon_ammunition_cook::delete_resource(
        survarium::weapon_ammunition_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::memory::doug_lea_allocator *v2; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::memory::writer>(
    v2,
    (vostok::memory::writer **)&resource);
}
