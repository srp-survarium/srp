Scaleform::GFx::AMP::MessageHeartbeat *__thiscall Scaleform::GFx::AMP::ThreadMgr::RetrieveMessageForSending(
        Scaleform::GFx::AMP::ThreadMgr *this)
{
  unsigned __int64 Ticks; // rax
  unsigned int v3; // ebx
  unsigned int v4; // ebp
  Scaleform::GFx::AMP::MessageHeartbeat *result; // eax
  unsigned int HeartbeatIntervalMillisecs; // edx
  unsigned int v7; // [esp+14h] [ebp-4h]

  Ticks = Scaleform::Timer::GetTicks();
  v3 = HIDWORD(Ticks);
  v7 = HIDWORD(Ticks);
  v4 = Ticks;
  result = (Scaleform::GFx::AMP::MessageHeartbeat *)Scaleform::GFx::AMP::ThreadMgr::MsgQueue::PopFront(&this->MsgCompressedQueue);
  if ( result )
    goto LABEL_6;
  HeartbeatIntervalMillisecs = this->HeartbeatIntervalMillisecs;
  if ( HeartbeatIntervalMillisecs )
  {
    if ( __PAIR64__(v3, v4) - this->LastSendHeartbeat > 1000 * HeartbeatIntervalMillisecs )
    {
      result = Scaleform::GFx::AMP::MessageTypeRegistry::CreateMessage<Scaleform::GFx::AMP::MessageHeartbeat>(this->MsgTypeRegistry.pObject);
      if ( result )
      {
        v3 = v7;
LABEL_6:
        LODWORD(this->LastSendHeartbeat) = v4;
        HIDWORD(this->LastSendHeartbeat) = v3;
        result->Version = this->MsgVersion.Value;
      }
    }
  }
  return result;
}
