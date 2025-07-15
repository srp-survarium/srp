void __usercall vostok::threading::yield(DWORD yield_time_in_ms@<esi>)
{
  if ( yield_time_in_ms )
  {
    vostok::tasks::on_current_thread_locks();
    Sleep(yield_time_in_ms);
  }
  else
  {
    if ( SwitchToThread() )
      return;
    Sleep(0);
  }
  if ( yield_time_in_ms )
    vostok::tasks::on_current_thread_unlocks();
}
