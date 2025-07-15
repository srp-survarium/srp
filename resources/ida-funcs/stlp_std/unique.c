vostok::physics::base_physics_object **__cdecl stlp_std::unique<vostok::physics::base_physics_object * *>(
        vostok::physics::base_physics_object **__first,
        vostok::physics::base_physics_object **__last)
{
  stlp_std::equal_to<vostok::physics::base_physics_object *> *v2; // eax
  survarium::game_camera *v3; // ecx
  stlp_std::equal_to<vostok::physics::base_physics_object *> result; // [esp+13h] [ebp-5h] BYREF
  vostok::physics::base_physics_object **v6; // [esp+14h] [ebp-4h]

  v2 = stlp_std::priv::__equal_to<vostok::physics::base_physics_object *>(&result, 0);
  v6 = stlp_std::adjacent_find<vostok::physics::base_physics_object * *,stlp_std::equal_to<vostok::physics::base_physics_object *>>(
         __first,
         __last,
         (stlp_std::equal_to<vostok::physics::base_physics_object *>)v2->stlp_std::binary_function<vostok::physics::base_physics_object *,vostok::physics::base_physics_object *,bool>);
  survarium::weapon_user_dead_state::finalize(v3);
  return stlp_std::unique_copy<vostok::physics::base_physics_object * *,vostok::physics::base_physics_object * *>(
           v6,
           __last,
           v6);
}
