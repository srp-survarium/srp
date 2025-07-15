void __thiscall Scaleform::GFx::AMP::ThreadMgr::UpdateValidConnection(Scaleform::GFx::AMP::ThreadMgr *this)
{
  unsigned int v2; // edi
  unsigned __int64 Ticks; // rax
  Scaleform::GFx::AMP::ConnStatusInterface::StatusType v4; // ebp
  Scaleform::Lock *p_StatusLock; // ebx
  unsigned int v6; // edi
  Scaleform::GFx::AMP::ConnStatusInterface::StatusType ConnectionStatus; // eax
  Scaleform::GFx::AMP::ConnStatusInterface *ConnectionChangedCallback; // esi
  void *v9; // esi
  bool v10; // [esp+13h] [ebp-11h]
  Scaleform::String v11; // [esp+14h] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+18h] [ebp-Ch] BYREF

  Ticks = Scaleform::Timer::GetTicks();
  v2 = Ticks;
  v10 = this->LastRcvdHeartbeat != 0;
  LODWORD(Ticks) = this->HeartbeatIntervalMillisecs;
  if ( (_DWORD)Ticks )
    v10 = __PAIR64__(HIDWORD(Ticks), v2) - this->LastRcvdHeartbeat < (unsigned int)(2000 * Ticks);
  InterlockedExchange((volatile LONG *)&this->ValidConnection, v10);
  Scaleform::String::String(&v11);
  result.Type = tStr;
  result.SinkData.pStr = &v11;
  if ( v10 )
  {
    v4 = CS_OK;
    Scaleform::SPrintF(&result, "Connection established on port %d\n", this->Port);
  }
  else
  {
    v4 = CS_Connecting;
    Scaleform::SPrintF(&result, "Lost connection after %d microseconds\n", v2 - LODWORD(this->LastRcvdHeartbeat));
    Scaleform::GFx::AMP::ThreadMgr::MsgQueue::Clear(&this->MsgSendQueue);
  }
  p_StatusLock = &this->StatusLock;
  v6 = v11.HeapTypeBits & 0xFFFFFFFC;
  EnterCriticalSection(&this->StatusLock.cs);
  ConnectionStatus = this->ConnectionStatus;
  if ( ConnectionStatus != v4 )
  {
    this->ConnectionStatus = v4;
    ConnectionChangedCallback = this->ConnectionChangedCallback;
    if ( ConnectionChangedCallback )
      ConnectionChangedCallback->OnStatusChanged(
        ConnectionChangedCallback,
        v4,
        ConnectionStatus,
        (const char *)(v6 + 8));
  }
  LeaveCriticalSection(&p_StatusLock->cs);
  v9 = (void *)(v11.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v11.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
}
