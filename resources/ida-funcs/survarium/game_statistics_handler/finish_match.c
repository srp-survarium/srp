void __usercall survarium::game_statistics_handler::finish_match(
        survarium::game_statistics_handler *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  survarium::shared_statistics *v3; // eax
  survarium::shared_statistics *v4; // ecx
  int v5; // ecx
  unsigned int v6; // [esp-8h] [ebp-8h]

  v2 = *(_DWORD *)(a2 + 6240);
  v6 = *(_DWORD *)(v2 + 51208);
  v3 = (survarium::shared_statistics *)survarium::game_world_core::winner_team((survarium::game_world_core *)this, v2);
  survarium::shared_statistics::finish_match(v4, a2 + 8, v3, v6);
  v5 = *(_DWORD *)(a2 + 6240);
  *(_BYTE *)(a2 + 6248) = 0;
  *(_DWORD *)(a2 + 6244) = 0;
  *(_DWORD *)(v5 + 51168) = 0;
  *(_DWORD *)(a2 + 6240) = 0;
}
