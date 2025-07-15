void __fastcall survarium::game_world_ui::show_item_container(survarium::game_world_ui *this, int a2)
{
  int v2; // eax
  survarium::flash_value visual_id_val; // [esp+0h] [ebp-1Ch] BYREF

  *(_DWORD *)visual_id_val.body = 0;
  *(_DWORD *)&visual_id_val.body[8] = 0;
  v2 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)&visual_id_val.body[4] = 4;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v2 + 264) + 4),
    "root.show_container_icon",
    0,
    (const Scaleform::GFx::Value *)&visual_id_val,
    1u);
  if ( (visual_id_val.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)visual_id_val.body + 8))(
      *(_DWORD *)visual_id_val.body,
      &visual_id_val,
      *(_DWORD *)&visual_id_val.body[8]);
}
