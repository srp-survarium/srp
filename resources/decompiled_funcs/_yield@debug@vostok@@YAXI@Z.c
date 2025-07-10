void __cdecl vostok::debug::yield(DWORD milliseconds)
{
  if ( milliseconds )
  {
    Sleep(milliseconds);
  }
  else if ( !SwitchToThread() )
  {
    Sleep(0);
  }
}
