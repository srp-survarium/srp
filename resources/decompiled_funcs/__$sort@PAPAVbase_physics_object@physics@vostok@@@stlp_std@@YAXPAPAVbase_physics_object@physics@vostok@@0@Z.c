void __cdecl stlp_std::sort<vostok::physics::base_physics_object * *>(
        vostok::physics::base_physics_object **__first,
        vostok::physics::base_physics_object **__last)
{
  int v2; // eax
  survarium::game_camera *v3; // ecx
  stlp_std::less<vostok::physics::base_physics_object *> *v4; // eax
  survarium::game_camera *v5; // ecx
  stlp_std::less<vostok::physics::base_physics_object *> v6; // [esp-4h] [ebp-Ch]
  stlp_std::less<vostok::physics::base_physics_object *> v7; // [esp+6h] [ebp-2h] BYREF
  stlp_std::less<vostok::physics::base_physics_object *> result; // [esp+7h] [ebp-1h] BYREF

  if ( __first != __last )
  {
    v6.gap0 = stlp_std::priv::__less<vostok::physics::base_physics_object *>(&result, 0)->gap0;
    v2 = stlp_std::priv::__lg<int>(__last - __first);
    stlp_std::priv::__introsort_loop<vostok::physics::base_physics_object * *,vostok::physics::base_physics_object *,int,stlp_std::less<vostok::physics::base_physics_object *>>(
      __first,
      __last,
      0,
      2 * v2,
      v6);
    survarium::weapon_user_dead_state::finalize(v3);
    v4 = stlp_std::priv::__less<vostok::physics::base_physics_object *>(&v7, 0);
    stlp_std::priv::__final_insertion_sort<vostok::physics::base_physics_object * *,stlp_std::less<vostok::physics::base_physics_object *>>(
      __first,
      __last,
      (stlp_std::less<vostok::physics::base_physics_object *>)v4->gap0);
    survarium::weapon_user_dead_state::finalize(v5);
  }
}
