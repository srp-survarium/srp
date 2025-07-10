void __thiscall survarium::inventory_cook::delete_resource(
        survarium::inventory_cook *this,
        survarium::inventory *resource)
{
  vostok::memory::doug_lea_allocator *v2; // eax
  survarium::inventory *inventory; // [esp+14h] [ebp-4h] BYREF

  inventory = resource;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::inventory,vostok::memory::detail::call_destructor_predicate>(
    v2,
    (vostok::sound::sound_scene **)&inventory);
}
