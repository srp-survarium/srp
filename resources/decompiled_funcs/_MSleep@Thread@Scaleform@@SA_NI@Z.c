char __cdecl Scaleform::Thread::MSleep(DWORD msecs)
{
  Sleep(msecs);
  return 1;
}
