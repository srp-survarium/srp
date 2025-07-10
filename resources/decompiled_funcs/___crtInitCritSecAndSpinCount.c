BOOL __cdecl __crtInitCritSecAndSpinCount(_RTL_CRITICAL_SECTION *lpCriticalSection, DWORD dwSpinCount)
{
  return InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
}
