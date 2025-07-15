void __fastcall survarium::flash_movie::HandleChar(survarium::flash_movie *this, int a2)
{
  int v2; // ecx
  Scaleform::GFx::CharEvent ev; // [esp+0h] [ebp-14h] BYREF

  ev.WcharCode = (unsigned __int16)this;
  v2 = *(_DWORD *)(a2 + 4);
  ev.Modifiers.States = 0;
  ev.KeyboardIndex = 0;
  ev.Type = Char;
  (*(void (__thiscall **)(int, Scaleform::GFx::CharEvent *))(*(_DWORD *)v2 + 136))(v2, &ev);
}
