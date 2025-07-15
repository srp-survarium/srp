void __usercall survarium::portable_interactive_object_core::portable_interactive_object_core(
        survarium::portable_interactive_object_core *this@<ecx>,
        int a2@<esi>)
{
  survarium::hit_animations_selector *v2; // ecx
  vostok::animation::legs_ik_solver *v3; // ecx

  *(_DWORD *)a2 = &survarium::portable_interactive_object_core::`vftable';
  survarium::weapon_user_animations_selector::weapon_user_animations_selector(
    (survarium::weapon_user_animations_selector *)this,
    (survarium::weapon_user_animations_selector *)(a2 + 8));
  survarium::hit_animations_selector::hit_animations_selector(v2, a2 + 88);
  vostok::animation::legs_ik_solver::legs_ik_solver(v3, a2 + 336);
  *(_DWORD *)(a2 + 492) = 0;
}
