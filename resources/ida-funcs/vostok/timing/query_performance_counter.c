unsigned __int64 __cdecl vostok::timing::query_performance_counter()
{
  unsigned __int64 result; // [esp+0h] [ebp-8h] BYREF

  QueryPerformanceCounter((LARGE_INTEGER *)&result);
  return result;
}
