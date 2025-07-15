BOOL __usercall survarium::weapon_user_animations_selector::is_trying_to_sprint@<eax>(
        survarium::weapon_user_animations_selector *this@<ecx>,
        int a2@<eax>)
{
  int v2; // esi
  survarium::base_player *v3; // ecx

  v2 = *(_DWORD *)(a2 + 60);
  return survarium::player_input::is_sprinting((survarium::player_input *)this, v2 + 744)
      && survarium::base_player::can_sprint(v3, v2);
}
