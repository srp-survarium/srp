int __thiscall Scaleform::GFx::AMP::ViewStats::GetActiveFile(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::Lock *p_ActiveLock; // edi
  int ActiveFileId; // ebx

  p_ActiveLock = &this->ActiveLock;
  EnterCriticalSection(&this->ActiveLock.cs);
  ActiveFileId = this->ActiveFileId;
  LeaveCriticalSection(&p_ActiveLock->cs);
  return ActiveFileId;
}
