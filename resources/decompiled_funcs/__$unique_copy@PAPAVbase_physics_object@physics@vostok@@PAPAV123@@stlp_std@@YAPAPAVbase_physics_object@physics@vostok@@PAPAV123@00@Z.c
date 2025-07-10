vostok::physics::base_physics_object **__cdecl stlp_std::unique_copy<vostok::physics::base_physics_object * *,vostok::physics::base_physics_object * *>(
        vostok::physics::base_physics_object **__first,
        vostok::physics::base_physics_object **__last,
        vostok::physics::base_physics_object **__result)
{
  survarium::game_camera *v4; // ecx
  vostok::physics::base_physics_object **v5; // [esp+4h] [ebp-14h]
  vostok::physics::base_physics_object **v6; // [esp+8h] [ebp-10h]
  stlp_std::equal_to<vostok::physics::base_physics_object *> result; // [esp+12h] [ebp-6h] BYREF
  vostok::physics::base_physics_object **v8; // [esp+14h] [ebp-4h]

  if ( __first == __last )
    return __result;
  stlp_std::priv::__equal_to<vostok::physics::base_physics_object *>(&result, 0);
  v5 = __result;
  v6 = __first;
  *__result = *__first;
  while ( ++v6 != __last )
  {
    if ( *v5 != *v6 )
      *++v5 = *v6;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(v5 + 1));
  v8 = v5 + 1;
  survarium::weapon_user_dead_state::finalize(v4);
  return v8;
}
