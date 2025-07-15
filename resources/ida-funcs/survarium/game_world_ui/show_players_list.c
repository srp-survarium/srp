void __userpurge survarium::game_world_ui::show_players_list(
        survarium::game_world_ui *this@<ecx>,
        int a2@<esi>,
        char b_show)
{
  int v3; // ecx
  int v4; // eax
  survarium::flash_value b_val; // [esp+8h] [ebp-18h] BYREF

  if ( *(_BYTE *)(a2 + 36) != b_show )
  {
    v3 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)b_val.body = 0;
    *(_DWORD *)&b_val.body[4] = 2;
    b_val.body[8] = b_show;
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(v3 + 264) + 4),
      "root.show_player_list",
      0,
      (const Scaleform::GFx::Value *)&b_val,
      1u);
    v4 = *(_DWORD *)&b_val.body[4] >> 6;
    *(_BYTE *)(a2 + 36) = b_show;
    if ( (v4 & 1) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)b_val.body + 8))(
        *(_DWORD *)b_val.body,
        &b_val,
        *(_DWORD *)&b_val.body[8]);
  }
}
