void __thiscall Scaleform::GFx::MovieImpl::NotifyMouseState(
        Scaleform::GFx::MovieImpl *this,
        float x,
        float y,
        unsigned int buttons,
        unsigned int mouseIndex)
{
  Scaleform::GFx::InputEventsQueue *p_InputEventsQueue; // ebx
  float v7; // edx
  int v8; // edi
  int v9; // [esp+0h] [ebp-14h]
  Scaleform::Render::Point<float> p; // [esp+4h] [ebp-10h] BYREF
  Scaleform::Render::Point<float> result; // [esp+Ch] [ebp-8h] BYREF

  p.x = x;
  p.y = y;
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &result, &p);
  if ( mouseIndex < this->MouseCursorCount )
  {
    p_InputEventsQueue = &this->InputEventsQueue;
    Scaleform::GFx::InputEventsQueue::AddMouseMove(&this->InputEventsQueue, mouseIndex, &result);
    v7 = *(float *)&this->mMouseState[mouseIndex].CurButtonsState;
    p.x = v7;
    v8 = 1;
    v9 = 16;
    while ( 1 )
    {
      if ( (buttons & v8) == 0 || (v8 & LODWORD(v7)) != 0 )
      {
        if ( (LODWORD(v7) & v8) != 0 && (buttons & v8) == 0 )
          Scaleform::GFx::InputEventsQueue::AddMouseButtonEvent(
            p_InputEventsQueue,
            mouseIndex,
            &result,
            LOWORD(v7) & v8,
            0x80u);
      }
      else
      {
        Scaleform::GFx::InputEventsQueue::AddMouseButtonEvent(p_InputEventsQueue, mouseIndex, &result, buttons & v8, 0);
      }
      v8 *= 2;
      if ( !--v9 )
        break;
      v7 = p.x;
    }
  }
}
