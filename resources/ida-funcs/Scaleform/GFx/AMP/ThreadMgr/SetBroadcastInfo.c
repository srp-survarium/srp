void __thiscall Scaleform::GFx::AMP::ThreadMgr::SetBroadcastInfo(
        Scaleform::GFx::AMP::ThreadMgr *this,
        const __m128i *connectedApp,
        const __m128i *connectedFile)
{
  Scaleform::Lock *p_BroadcastInfoLock; // edi

  p_BroadcastInfoLock = &this->BroadcastInfoLock;
  EnterCriticalSection(&this->BroadcastInfoLock.cs);
  Scaleform::String::operator=(&this->BroadcastApp, connectedApp);
  Scaleform::String::operator=(&this->BroadcastFile, connectedFile);
  LeaveCriticalSection(&p_BroadcastInfoLock->cs);
}
