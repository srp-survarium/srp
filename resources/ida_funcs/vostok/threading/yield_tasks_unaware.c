void __cdecl vostok::threading::yield_tasks_unaware()
{
  if ( !SwitchToThread() )
    Sleep(0);
}
