unsigned int __thiscall Scaleform::GFx::AMP::ViewStats::GetVersion(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::Lock *p_ViewLock; // edi
  unsigned int Version; // esi

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  Version = this->Version;
  LeaveCriticalSection(&p_ViewLock->cs);
  return Version;
}
