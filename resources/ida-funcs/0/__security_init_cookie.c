void __cdecl __security_init_cookie()
{
  unsigned int v0; // esi
  DWORD v1; // esi
  DWORD v2; // esi
  DWORD v3; // esi
  unsigned int v4; // esi
  LARGE_INTEGER PerformanceCount; // [esp+8h] [ebp-10h] BYREF
  _FILETIME SystemTimeAsFileTime; // [esp+10h] [ebp-8h] BYREF

  SystemTimeAsFileTime.dwLowDateTime = 0;
  SystemTimeAsFileTime.dwHighDateTime = 0;
  if ( __security_cookie == -1153374642 || (__security_cookie & 0xFFFF0000) == 0 )
  {
    GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
    v0 = SystemTimeAsFileTime.dwLowDateTime ^ SystemTimeAsFileTime.dwHighDateTime;
    v1 = GetCurrentProcessId() ^ v0;
    v2 = GetCurrentThreadId() ^ v1;
    v3 = GetTickCount() ^ v2;
    QueryPerformanceCounter(&PerformanceCount);
    v4 = PerformanceCount.LowPart ^ PerformanceCount.HighPart ^ v3;
    if ( v4 == -1153374642 )
    {
      v4 = -1153374641;
    }
    else if ( (v4 & 0xFFFF0000) == 0 )
    {
      v4 |= v4 << 16;
    }
    __security_cookie = v4;
    __security_cookie_complement = ~v4;
  }
  else
  {
    __security_cookie_complement = ~__security_cookie;
  }
}
