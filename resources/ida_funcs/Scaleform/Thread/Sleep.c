char __cdecl Scaleform::Thread::Sleep(unsigned int secs)
{
  Sleep(1000 * secs);
  return 1;
}
