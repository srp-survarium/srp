void __cdecl cleanup()
{
  DeleteCriticalSection(&CriticalSection);
}
