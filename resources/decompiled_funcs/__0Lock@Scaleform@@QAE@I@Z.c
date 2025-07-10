void __thiscall Scaleform::Lock::Lock(Scaleform::Lock *this, DWORD spinCount)
{
  HMODULE LibraryA; // eax
  BOOL (__stdcall *InitializeCriticalSectionAndSpinCount)(LPCRITICAL_SECTION, DWORD); // eax

  if ( initTried )
  {
    InitializeCriticalSectionAndSpinCount = pInitFn;
  }
  else
  {
    LibraryA = LoadLibraryA("kernel32.dll");
    InitializeCriticalSectionAndSpinCount = (BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD))GetProcAddress(
                                                                                             LibraryA,
                                                                                             "InitializeCriticalSectionAndSpinCount");
    pInitFn = InitializeCriticalSectionAndSpinCount;
    initTried = 1;
  }
  if ( InitializeCriticalSectionAndSpinCount )
    InitializeCriticalSectionAndSpinCount(&this->cs, spinCount);
  else
    InitializeCriticalSection(&this->cs);
}
