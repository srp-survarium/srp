void __userpurge survarium::game_world_ui::show_quick_slots(
        survarium::game_world_ui *this@<ecx>,
        _DWORD *a2@<esi>,
        bool b_show)
{
  int v3; // ecx
  int v4; // ecx
  survarium::flash_value b_val; // [esp+8h] [ebp-18h] BYREF

  v3 = a2[1];
  *(_DWORD *)b_val.body = 0;
  *(_DWORD *)&b_val.body[4] = 2;
  b_val.body[8] = b_show;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v3 + 264) + 4),
    "root.show_slots",
    0,
    (const Scaleform::GFx::Value *)&b_val,
    1u);
  if ( !b_show )
  {
    v4 = a2[13];
    if ( v4 != a2[14] )
      a2[14] = v4;
  }
  if ( (b_val.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)b_val.body + 8))(
      *(_DWORD *)b_val.body,
      &b_val,
      *(_DWORD *)&b_val.body[8]);
}
