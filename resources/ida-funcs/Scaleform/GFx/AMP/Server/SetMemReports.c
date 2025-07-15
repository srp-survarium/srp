void __thiscall Scaleform::GFx::AMP::Server::SetMemReports(
        Scaleform::GFx::AMP::Server *this,
        bool memReports,
        bool lock)
{
  Scaleform::GFx::AMP::Server *v3; // esi
  unsigned int *p_CurrentLineNumber; // edi
  bool v5; // bl
  Scaleform::AtomicInt<unsigned long> *p_FontThrashing; // [esp+0h] [ebp-4h]

  p_FontThrashing = &this->FontThrashing;
  if ( !this->FontThrashing.Value || lock )
  {
    v3 = (Scaleform::GFx::AMP::Server *)((char *)this - 8);
    p_CurrentLineNumber = &this->CurrentState.CurrentLineNumber;
    EnterCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
    v5 = (v3->CurrentState.StateFlags & 0x20) != 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
    if ( memReports != v5 )
    {
      EnterCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
      Scaleform::GFx::AMP::Server::SetAmpState(v3, v3->CurrentState.StateFlags ^ 0x20, 1);
      LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
    }
    if ( lock )
      InterlockedExchange((volatile LONG *)p_FontThrashing, 1);
  }
}
