void __thiscall Scaleform::GFx::AMP::StatusChangedCallback::OnStatusChanged(
        Scaleform::GFx::AMP::StatusChangedCallback *this,
        Scaleform::GFx::AMP::ConnStatusInterface::StatusType newStatus,
        Scaleform::GFx::AMP::ConnStatusInterface::StatusType oldStatus,
        const char *message)
{
  Scaleform::GFx::AMP::ConnStatusInterface::StatusType v4; // ebp
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v6; // eax
  Scaleform::AmpServer *v7; // eax
  Scaleform::AmpServer *v8; // eax
  Scaleform::AmpServer *v9; // ebx
  unsigned __int32 v10; // esi
  void (__thiscall **p_SendLog)(Scaleform::AmpServer *, unsigned __int32, int, int); // edi
  int Length; // eax
  void *v13; // esi
  Scaleform::Event *RefCount; // ecx

  v4 = newStatus;
  if ( newStatus != oldStatus )
  {
    Instance = Scaleform::AmpServer::GetInstance();
    ((void (__thiscall *)(Scaleform::AmpServer *, const char *, unsigned int, int))Instance->SendLog)(
      Instance,
      message,
      strlen(message),
      4096);
    if ( v4 == CS_OK )
    {
      v6 = Scaleform::AmpServer::GetInstance();
      v6->SendAppControlCaps(v6);
      v7 = Scaleform::AmpServer::GetInstance();
      v7->SendCurrentState(v7);
      v8 = Scaleform::AmpServer::GetInstance();
      if ( v8->IsPaused(v8) )
      {
        Scaleform::String::String(
          (Scaleform::String *)&newStatus,
          (const __m128i *)"AMP Server is paused and will send no frame data\n");
        v9 = Scaleform::AmpServer::GetInstance();
        v10 = newStatus & 0xFFFFFFFC;
        p_SendLog = (void (__thiscall **)(Scaleform::AmpServer *, unsigned __int32, int, int))&v9->SendLog;
        Length = Scaleform::String::GetLength((Scaleform::String *)&newStatus);
        (*p_SendLog)(v9, v10 + 8, Length, 4096);
        v13 = (void *)(newStatus & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((newStatus & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
      }
    }
    RefCount = (Scaleform::Event *)this->RefCount;
    if ( RefCount )
    {
      if ( v4 == CS_OK )
        Scaleform::Event::SetEvent(RefCount);
      else
        Scaleform::Event::ResetEvent(RefCount);
    }
  }
}
