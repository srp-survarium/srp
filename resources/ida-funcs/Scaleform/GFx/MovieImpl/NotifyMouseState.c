void __thiscall Scaleform::GFx::MovieImpl::NotifyMouseState(
        Scaleform::GFx::MovieImpl *this,
        float x,
        unsigned int y,
        unsigned int buttons,
        unsigned int mouseIndex)
{
  Scaleform::GFx::InputEventsQueue *p_InputEventsQueue; // ebx
  unsigned int CurButtonsState; // edx
  int v8; // edi
  int v9; // [esp+0h] [ebp-14h]
  unsigned int lastButtons[2]; // [esp+4h] [ebp-10h] BYREF
  Scaleform::Render::Point<float> pt; // [esp+Ch] [ebp-8h] BYREF

  *(float *)lastButtons = x;
  lastButtons[1] = y;
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(
    &this->ViewportMatrix,
    &pt,
    (const Scaleform::Render::Point<float> *)lastButtons);
  if ( mouseIndex < this->MouseCursorCount )
  {
    p_InputEventsQueue = &this->InputEventsQueue;
    Scaleform::GFx::InputEventsQueue::AddMouseMove(&this->InputEventsQueue, mouseIndex, &pt);
    CurButtonsState = this->mMouseState[mouseIndex].CurButtonsState;
    lastButtons[0] = CurButtonsState;
    v8 = 1;
    v9 = 16;
    while ( 1 )
    {
      if ( (buttons & v8) == 0 || (v8 & CurButtonsState) != 0 )
      {
        if ( (CurButtonsState & v8) != 0 && (buttons & v8) == 0 )
          Scaleform::GFx::InputEventsQueue::AddMouseButtonEvent(
            p_InputEventsQueue,
            mouseIndex,
            &pt,
            CurButtonsState & v8,
            0x80u);
      }
      else
      {
        Scaleform::GFx::InputEventsQueue::AddMouseButtonEvent(p_InputEventsQueue, mouseIndex, &pt, buttons & v8, 0);
      }
      v8 *= 2;
      if ( !--v9 )
        break;
      CurButtonsState = lastButtons[0];
    }
  }
}
