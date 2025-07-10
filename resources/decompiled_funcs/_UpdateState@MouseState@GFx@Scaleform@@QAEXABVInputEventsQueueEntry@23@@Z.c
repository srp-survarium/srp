void __thiscall Scaleform::GFx::MouseState::UpdateState(
        Scaleform::GFx::MouseState *this,
        const Scaleform::GFx::InputEventsQueueEntry *qe)
{
  unsigned int CurButtonsState; // eax
  unsigned __int16 ButtonsState; // cx
  signed __int8 KeyIsDown; // dl
  char v6; // al
  float PosY; // [esp+1Ch] [ebp-4h]

  CurButtonsState = this->CurButtonsState;
  *((_BYTE *)this + 52) |= 0x10u;
  this->PrevButtonsState = CurButtonsState;
  ButtonsState = qe->u.mouseEntry.ButtonsState;
  if ( ButtonsState )
  {
    KeyIsDown = qe->u.keyEntry.KeyIsDown;
    if ( (KeyIsDown & 0x40) != 0 || KeyIsDown >= 0 || !qe->u.mouseEntry.ButtonsState )
      this->CurButtonsState = CurButtonsState | ButtonsState;
    else
      this->CurButtonsState = CurButtonsState & ~ButtonsState;
  }
  if ( (qe->u.mouseEntry.Flags & 0x20) != 0 )
    this->WheelDelta = qe->u.mouseEntry.WheelScrollDelta;
  else
    this->WheelDelta = 0;
  if ( (int)qe->u.mouseEntry.PosX == (int)this->LastPosition.x
    && (int)qe->u.mouseEntry.PosY == (int)this->LastPosition.y )
  {
    v6 = *((_BYTE *)this + 52) & 0xF7;
  }
  else
  {
    v6 = *((_BYTE *)this + 52) | 8;
  }
  *((_BYTE *)this + 52) = v6;
  PosY = qe->u.mouseEntry.PosY;
  this->LastPosition.x = qe->u.mouseEntry.PosX;
  this->LastPosition.y = PosY;
}
