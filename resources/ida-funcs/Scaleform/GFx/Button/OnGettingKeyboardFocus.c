void __thiscall Scaleform::GFx::Button::OnGettingKeyboardFocus(
        Scaleform::GFx::Button *this,
        char controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  bool (__thiscall *OnMouseEvent)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  _DWORD v4[3]; // [esp+0h] [ebp-14h] BYREF
  char v5; // [esp+Ch] [ebp-8h]
  char v6; // [esp+10h] [ebp-4h]
  char v7; // [esp+11h] [ebp-3h]
  char v8; // [esp+12h] [ebp-2h]
  char v9; // [esp+13h] [ebp-1h]

  if ( fmt == GFx_FocusMovedByKeyboard )
  {
    OnMouseEvent = this->OnMouseEvent;
    v4[1] = 0;
    v5 = 0;
    v6 = 0;
    v8 = 0;
    v9 = 0;
    v7 = controllerIdx;
    v4[0] = 0x2000;
    v4[2] = 9;
    OnMouseEvent(this, (const Scaleform::GFx::EventId *)v4);
  }
}
