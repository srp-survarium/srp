unsigned int __thiscall Scaleform::GFx::AMP::ViewStats::GetViewHandle(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::Lock *p_ViewLock; // edi
  unsigned int ViewHandle; // esi

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  ViewHandle = this->ViewHandle;
  LeaveCriticalSection(&p_ViewLock->cs);
  return ViewHandle;
}
