BOOL __usercall survarium::weapon_user_animations_selector::is_sprinting@<eax>(
        survarium::weapon_user_animations_selector *this@<ecx>,
        int a2@<eax>)
{
  int v2; // ecx

  v2 = *(_DWORD *)(a2 + 16);
  return *(_BYTE *)(v2 + 40)
      && *(_DWORD *)(v2 + 32) != 3
      && survarium::weapon_user_animations_selector::is_trying_to_sprint(
           (survarium::weapon_user_animations_selector *)v2,
           a2);
}
