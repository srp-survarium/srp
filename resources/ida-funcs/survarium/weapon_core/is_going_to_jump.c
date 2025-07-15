BOOL __usercall survarium::weapon_core::is_going_to_jump@<eax>(survarium::weapon_core *this@<ecx>, int a2@<eax>)
{
  int v2; // esi
  int v3; // eax
  int v4; // esi

  v2 = *(_DWORD *)(a2 + 304);
  v3 = *(_DWORD *)(*(_DWORD *)(v2 + 24) + 32);
  v4 = v2 + 8;
  return v3 != 3
      && v3 != 1
      && survarium::weapon_user_animations_selector::is_trying_to_jump(
           (survarium::weapon_user_animations_selector *)this,
           v4);
}
