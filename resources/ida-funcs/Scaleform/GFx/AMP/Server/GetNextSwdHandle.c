unsigned int __thiscall Scaleform::GFx::AMP::Server::GetNextSwdHandle(Scaleform::GFx::AMP::Server *this)
{
  unsigned int *p_SpinCount; // esi
  unsigned int v2; // edi

  p_SpinCount = &this->LoaderLock.cs.SpinCount;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->LoaderLock.cs.SpinCount);
  v2 = ++lastSwdHandle;
  LeaveCriticalSection((LPCRITICAL_SECTION)p_SpinCount);
  return v2;
}
