// attributes: thunk
DWORD __stdcall vostok::threading::current_thread_id()
{
  return GetCurrentThreadId();
}
