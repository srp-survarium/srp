BOOL __usercall survarium::weapon_core::is_going_to_sprint@<eax>(survarium::weapon_core *this@<ecx>, int a2@<eax>)
{
  int v2; // esi
  survarium::weapon_user_animations_selector *v3; // ecx

  v2 = *(_DWORD *)(a2 + 304) + 8;
  return !survarium::weapon_user_animations_selector::is_sprinting(
            (survarium::weapon_user_animations_selector *)this,
            v2)
      && *(_DWORD *)(*(_DWORD *)(v2 + 16) + 32) != 3
      && survarium::weapon_user_animations_selector::is_trying_to_sprint(v3, v2);
}
