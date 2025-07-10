char __thiscall Scaleform::GFx::Button::OnLosingKeyboardFocus(
        Scaleform::GFx::Button *this,
        Scaleform::GFx::InteractiveObject *__formal,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType a4)
{
  bool (__thiscall *OnMouseEvent)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  _DWORD v6[3]; // [esp+8h] [ebp-14h] BYREF
  char v7; // [esp+14h] [ebp-8h]
  char v8; // [esp+18h] [ebp-4h]
  char v9; // [esp+19h] [ebp-3h]
  char v10; // [esp+1Ah] [ebp-2h]
  char v11; // [esp+1Bh] [ebp-1h]

  if ( this->pASRoot->pMovieImpl->FocusGroups[this->pASRoot->pMovieImpl->FocusGroupIndexes[controllerIdx]].FocusRectShown )
  {
    v6[1] = 0;
    v7 = 0;
    v8 = 0;
    v10 = 0;
    v11 = 0;
    OnMouseEvent = this->OnMouseEvent;
    v6[0] = 0x4000;
    v6[2] = 9;
    v9 = controllerIdx;
    OnMouseEvent(this, (const Scaleform::GFx::EventId *)v6);
  }
  return 1;
}
