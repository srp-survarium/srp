int sub_7DFE20()
{
  InitializeCriticalSection(&CriticalSection);
  return atexit(cleanup);
}
