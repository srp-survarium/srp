void __thiscall Scaleform::GFx::AMP::Server::SendLog(
        Scaleform::GFx::AMP::Server *this,
        const __m128i *message,
        unsigned int msgLength,
        unsigned int msgType)
{
  char v4; // bl
  Scaleform::GFx::AMP::MessageLog *v6; // esi
  const Scaleform::String *v7; // eax
  Scaleform::RefCountVImpl *v8; // eax
  void *v9; // esi
  unsigned __int64 v10; // [esp-8h] [ebp-24h]
  int v11; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::String v12; // [esp+10h] [ebp-Ch] BYREF
  __int64 timeptr; // [esp+14h] [ebp-8h] BYREF

  v4 = 0;
  v12.pData = 0;
  timeptr = 0;
  _time64(&timeptr);
  v11 = 580;
  v6 = (Scaleform::GFx::AMP::MessageLog *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            &this[-1].RecordingStateLock.cs.LockSemaphore,
                                            36,
                                            &v11);
  if ( v6 )
  {
    v10 = timeptr;
    v4 = 1;
    Scaleform::String::String(&v12, message, msgLength);
    Scaleform::GFx::AMP::MessageLog::MessageLog(v6, v7, msgType, v10);
  }
  else
  {
    v8 = 0;
  }
  Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage((Scaleform::GFx::AMP::ThreadMgr *)this->Port, v8);
  if ( (v4 & 1) != 0 )
  {
    v9 = (void *)(v12.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v12.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  }
}
