// attributes: thunk
DWORD __stdcall vostok::resources::correct_thread_id()
{
  return GetCurrentThreadId();
}
