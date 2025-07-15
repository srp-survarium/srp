__int64 __cdecl _time64(__int64 *timeptr)
{
  __int64 result; // rax
  _FILETIME SystemTimeAsFileTime; // [esp+0h] [ebp-8h] BYREF

  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  result = (*(_QWORD *)&SystemTimeAsFileTime - 116444736000000000LL)
         / (unsigned __int64)(unsigned int)&vostok::memory::s_CRT_arena[613496];
  if ( result > 0x793406FFFLL )
    result = -1;
  if ( timeptr )
    *timeptr = result;
  return result;
}
