char __thiscall Scaleform::Waitable::Wait(Scaleform::Waitable *this, DWORD delay)
{
  DWORD TicksMs; // ebp
  DWORD v6; // edi
  DWORD v7; // eax
  _DWORD v8[2]; // [esp+4h] [ebp-34h] BYREF
  Scaleform::Event v9; // [esp+Ch] [ebp-2Ch] BYREF
  char v10; // [esp+3Ch] [ebp+4h]

  if ( this->IsSignaled(this) )
    return 1;
  if ( !delay )
    return 0;
  Scaleform::Event::Event(&v9, 0, 0);
  v8[0] = this;
  v8[1] = &v9;
  if ( !Scaleform::Waitable::AddWaitHandler(this, (void (__cdecl *)(void *))Scaleform::Waitable_SingleWaitHandler, v8) )
  {
    Scaleform::Event::~Event(&v9);
    return 0;
  }
  if ( this->IsSignaled(this) )
  {
    Scaleform::Waitable::RemoveWaitHandler(this, (void (__cdecl *)(void *))Scaleform::Waitable_SingleWaitHandler, v8);
    Scaleform::Event::~Event(&v9);
    return 1;
  }
  else
  {
    TicksMs = 0;
    v10 = 0;
    v6 = delay;
    if ( delay != -1 )
      TicksMs = Scaleform::Timer::GetTicksMs();
    if ( Scaleform::Event::Wait(&v9, delay) )
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
        if ( !Scaleform::Event::Wait(&v9, v6) )
          goto LABEL_19;
      }
      v10 = 1;
    }
LABEL_19:
    Scaleform::Waitable::RemoveWaitHandler(this, (void (__cdecl *)(void *))Scaleform::Waitable_SingleWaitHandler, v8);
    Scaleform::Event::~Event(&v9);
    return v10;
  }
}
