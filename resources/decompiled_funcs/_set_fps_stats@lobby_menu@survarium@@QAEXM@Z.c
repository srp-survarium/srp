void __thiscall survarium::lobby_menu::set_fps_stats(survarium::lobby_menu *this, float fps, float fpsa)
{
  int v3; // ecx
  survarium::flash_value f_val; // [esp+0h] [ebp-1Ch] BYREF

  *(_DWORD *)&f_val.body[8] = (unsigned __int16)(int)fpsa;
  v3 = *(_DWORD *)(LODWORD(fps) + 212);
  *(_DWORD *)f_val.body = 0;
  *(_DWORD *)&f_val.body[4] = 4;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v3 + 264) + 4),
    "root.set_fps",
    0,
    (const Scaleform::GFx::Value *)&f_val,
    1u);
  if ( (f_val.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)f_val.body + 8))(
      *(_DWORD *)f_val.body,
      &f_val,
      *(_DWORD *)&f_val.body[8]);
}
