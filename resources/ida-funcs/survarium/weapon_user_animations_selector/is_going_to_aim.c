BOOL __usercall survarium::weapon_user_animations_selector::is_going_to_aim@<eax>(
        survarium::weapon_user_animations_selector *this@<ecx>,
        int a2@<eax>)
{
  survarium::weapon_user_animations_selector *v2; // ecx

  v2 = *(survarium::weapon_user_animations_selector **)(*(_DWORD *)(a2 + 16) + 32);
  return (unsigned int)v2 <= 1 && survarium::weapon_user_animations_selector::is_trying_to_aim(v2, a2);
}
