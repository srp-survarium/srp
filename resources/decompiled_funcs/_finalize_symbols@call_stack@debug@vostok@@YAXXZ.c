void __cdecl vostok::debug::call_stack::finalize_symbols()
{
  HANDLE CurrentProcess; // eax

  if ( s_SymCleanup )
  {
    CurrentProcess = GetCurrentProcess();
    s_SymCleanup(CurrentProcess);
  }
}
