void __thiscall Scaleform::GFx::AMP::Server::SendCurrentState(Scaleform::GFx::AMP::Server *this)
{
  unsigned int *p_CurrentLineNumber; // ebp
  Scaleform::GFx::AMP::ViewStats *pObject; // ebx
  float v4; // edx
  Scaleform::GFx::AMP::MessageCurrentState *v5; // eax
  Scaleform::RefCountVImpl *v6; // eax
  Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats> result; // [esp+10h] [ebp-4h] BYREF

  p_CurrentLineNumber = &this->CurrentState.CurrentLineNumber;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
  Scaleform::GFx::AMP::ThreadMgr::SetBroadcastInfo(
    (Scaleform::GFx::AMP::ThreadMgr *)this->Port,
    (char *)((this->CurrentState.StateFlags & 0xFFFFFFFC) + 8),
    (char *)((this->CurrentState.ProfileLevel & 0xFFFFFFFC) + 8));
  Scaleform::GFx::AMP::Server::GetDebugPausedMovie((Scaleform::GFx::AMP::Server *)((char *)this - 8), &result);
  pObject = result.pObject;
  if ( result.pObject )
  {
    LODWORD(this->CurrentState.CurveToleranceMax) = Scaleform::GFx::AMP::ViewStats::GetActiveFile(result.pObject);
    this->CurrentState.CurveToleranceStep = v4;
    LODWORD(this->CurrentState.CurrentFileId) = Scaleform::GFx::AMP::ViewStats::GetActiveLine(pObject);
  }
  result.pObject = (Scaleform::GFx::AMP::ViewStats *)580;
  v5 = (Scaleform::GFx::AMP::MessageCurrentState *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     &this[-1].RecordingStateLock.cs.LockSemaphore,
                                                     28,
                                                     &result);
  if ( v5 )
    Scaleform::GFx::AMP::MessageCurrentState::MessageCurrentState(
      v5,
      (const Scaleform::GFx::AMP::ServerState *)&this->Scaleform::AmpServer);
  else
    v6 = 0;
  Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage((Scaleform::GFx::AMP::ThreadMgr *)this->Port, v6);
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
}
