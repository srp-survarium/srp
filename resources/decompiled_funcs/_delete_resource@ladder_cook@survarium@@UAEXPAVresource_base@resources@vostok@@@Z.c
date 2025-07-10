void __thiscall survarium::ladder_cook::delete_resource(survarium::ladder_cook *this, survarium::ladder *resource)
{
  survarium::game_camera *v2; // ecx
  vostok::memory::doug_lea_allocator *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // eax
  survarium::landing_point *point; // [esp+20h] [ebp-8h] BYREF
  survarium::ladder *ladder_res; // [esp+24h] [ebp-4h] BYREF

  ladder_res = resource;
  while ( 1 )
  {
    point = (survarium::landing_point *)survarium::ladder::pop_landing_point(ladder_res);
    if ( !point )
      break;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&point);
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::landing_point>(v3, &point);
  }
  survarium::weapon_user_dead_state::finalize(v2);
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::inventory,vostok::memory::detail::call_destructor_predicate>(
    v4,
    (vostok::sound::sound_scene **)&ladder_res);
}
