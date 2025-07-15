unsigned int __thiscall Scaleform::GFx::AMP::ViewStats::GetActiveLine(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::Lock *p_ActiveLock; // edi
  unsigned int ActiveLineNumber; // esi

  p_ActiveLock = &this->ActiveLock;
  EnterCriticalSection(&this->ActiveLock.cs);
  ActiveLineNumber = this->ActiveLineNumber;
  LeaveCriticalSection(&p_ActiveLock->cs);
  return ActiveLineNumber;
}
