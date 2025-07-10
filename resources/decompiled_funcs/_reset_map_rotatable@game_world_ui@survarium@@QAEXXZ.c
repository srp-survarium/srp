void __fastcall survarium::game_world_ui::reset_map_rotatable(survarium::game_world_ui *this, int a2)
{
  int v2; // eax
  survarium::flash_value b_val; // [esp+0h] [ebp-1Ch] BYREF

  b_val.body[8] = is_ui_minimap_rotable;
  v2 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)b_val.body = 0;
  *(_DWORD *)&b_val.body[4] = 2;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v2 + 264) + 4),
    "root.set_rotable",
    0,
    (const Scaleform::GFx::Value *)&b_val,
    1u);
  LOBYTE(is_ui_minimap_rotable_old) = is_ui_minimap_rotable;
  if ( (b_val.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)b_val.body + 8))(
      *(_DWORD *)b_val.body,
      &b_val,
      *(_DWORD *)&b_val.body[8]);
}
