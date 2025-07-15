void __thiscall Scaleform::GFx::AMP::StatusChangedCallback::OnMsgVersionMismatch(
        Scaleform::GFx::AMP::StatusChangedCallback *this,
        int otherVersion)
{
  Scaleform::AmpServer *Instance; // ebx
  unsigned int v3; // esi
  void (__thiscall **p_SendLog)(Scaleform::AmpServer *, unsigned int, int, int); // edi
  int Length; // eax
  void *v6; // esi
  Scaleform::String v7; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v8; // [esp+10h] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink v9; // [esp+14h] [ebp-Ch] BYREF

  Scaleform::String::String(&v7);
  v9.SinkData.pStr = &v7;
  v8 = 33;
  v9.Type = tStr;
  Scaleform::Format<unsigned long,int>(
    &v9,
    "AMP message version mismatch (Server {0}, Client {1}) - full functionality may not be available",
    &v8,
    &otherVersion);
  Instance = Scaleform::AmpServer::GetInstance();
  v3 = v7.HeapTypeBits & 0xFFFFFFFC;
  p_SendLog = (void (__thiscall **)(Scaleform::AmpServer *, unsigned int, int, int))&Instance->SendLog;
  Length = Scaleform::String::GetLength(&v7);
  (*p_SendLog)(Instance, v3 + 8, Length, 135168);
  v6 = (void *)(v7.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v7.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
}
