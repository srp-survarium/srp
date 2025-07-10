char __thiscall Scaleform::Waitable::Wait(Scaleform::Waitable *this, DWORD delay)
{
  unsigned int TicksMs; // ebp
  DWORD v6; // edi
  DWORD v7; // eax
  Scaleform::Waitable_SingleWaitData waitData; // [esp+4h] [ebp-34h] BYREF
  Scaleform::Event event; // [esp+Ch] [ebp-2Ch] BYREF
  char result; // [esp+3Ch] [ebp+4h]

  if ( this->IsSignaled(this) )
    return 1;
  if ( !delay )
    return 0;
  Scaleform::Event::Event(&event, 0, 0);
  waitData.pWaitable = this;
  waitData.pEvent = &event;
  if ( !Scaleform::Waitable::AddWaitHandler(
          this,
          (void (__cdecl *)(void *))Scaleform::Waitable_SingleWaitHandler,
          &waitData) )
  {
    Scaleform::Event::~Event(&event);
    return 0;
  }
  if ( this->IsSignaled(this) )
  {
    Scaleform::Waitable::RemoveWaitHandler(
      this,
      (void (__cdecl *)(void *))Scaleform::Waitable_SingleWaitHandler,
      &waitData);
    Scaleform::Event::~Event(&event);
    return 1;
  }
  else
  {
    TicksMs = 0;
    result = 0;
    v6 = delay;
    if ( delay != -1 )
      TicksMs = Scaleform::Timer::GetTicksMs();
    if ( Scaleform::Event::Wait(&event, delay) )
    {
      while ( !this->IsSignaled(this) )
      {
        if ( delay != -1 )
        {
          v7 = Scaleform::Timer::GetTicksMs() - TicksMs;
          if ( v7 >= delay )
            goto LABEL_19;
          v6 = delay - v7;
        }
        if ( !Scaleform::Event::Wait(&event, v6) )
          goto LABEL_19;
      }
      result = 1;
    }
LABEL_19:
    Scaleform::Waitable::RemoveWaitHandler(
      this,
      (void (__cdecl *)(void *))Scaleform::Waitable_SingleWaitHandler,
      &waitData);
    Scaleform::Event::~Event(&event);
    return result;
  }
}
