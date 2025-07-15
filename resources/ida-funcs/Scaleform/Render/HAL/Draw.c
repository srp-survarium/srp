void __thiscall Scaleform::Render::HAL::Draw(
        Scaleform::Render::HAL *this,
        const Scaleform::Render::RenderQueueItem *item)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v4; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::Render::RenderQueueProcessor *v6; // eax
  Scaleform::Render::RenderQueue *p_Queue; // esi
  Scaleform::Render::RenderQueueProcessor *v8; // ebp
  Scaleform::Render::RenderQueueItem *v9; // eax
  unsigned int v10; // eax
  Scaleform::AmpStats_vtbl *v11; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v13; // [esp+8h] [ebp-10h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v4 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v13,
    v4,
    "Scaleform::Render::HAL::Draw",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  if ( item->pImpl != &Scaleform::Render::HALBeginDisplayItem::Instance && (this->HALState & 8) == 0 )
  {
    Stats = v13.Stats;
    if ( !v13.Stats )
      return;
    goto LABEL_10;
  }
  v6 = this->GetRQProcessor(this);
  p_Queue = &this->Queue;
  v8 = v6;
  v9 = Scaleform::Render::RenderQueue::ReserveHead(p_Queue);
  if ( !v9 )
  {
    Scaleform::Render::RenderQueueProcessor::ProcessQueue(v8, QPM_One);
    v9 = Scaleform::Render::RenderQueue::ReserveHead(p_Queue);
  }
  *v9 = *item;
  v10 = ++p_Queue->QueueHead;
  p_Queue->HeadReserved = 0;
  if ( v10 == p_Queue->QueueSize )
    p_Queue->QueueHead = 0;
  Scaleform::Render::RenderQueueProcessor::ProcessQueue(v8, QPM_Any);
  Stats = v13.Stats;
  if ( v13.Stats )
  {
LABEL_10:
    v11 = v13.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v11->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v13.StartTicks),
      (ProfileTicks - v13.StartTicks) >> 32);
  }
}
