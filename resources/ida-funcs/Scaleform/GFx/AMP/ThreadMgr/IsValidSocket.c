char __thiscall Scaleform::GFx::AMP::ThreadMgr::IsValidSocket(Scaleform::GFx::AMP::ThreadMgr *this)
{
  Scaleform::Lock *p_StatusLock; // edi
  char IsValid; // bl

  p_StatusLock = &this->StatusLock;
  EnterCriticalSection(&this->StatusLock.cs);
  IsValid = Scaleform::GFx::AMP::Socket::IsValid(&this->Sock);
  LeaveCriticalSection(&p_StatusLock->cs);
  return IsValid;
}
