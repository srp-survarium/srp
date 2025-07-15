void __usercall boost::asio::detail::win_thread::join(boost::asio::detail::win_thread *this@<ecx>, int a2@<esi>)
{
  LONG v2; // eax
  void *v3; // [esp-8h] [ebp-10h]
  HANDLE Handles[2]; // [esp+0h] [ebp-8h] BYREF

  Handles[0] = *(HANDLE *)(a2 + 8);
  Handles[1] = *(HANDLE *)(a2 + 4);
  WaitForMultipleObjects(2u, Handles, 0, 0xFFFFFFFF);
  CloseHandle(*(HANDLE *)(a2 + 8));
  v2 = InterlockedExchangeAdd(
         &boost::asio::detail::win_thread_base<boost::asio::detail::win_thread>::terminate_threads_,
         0);
  v3 = *(void **)(a2 + 4);
  if ( v2 )
  {
    TerminateThread(v3, 0);
  }
  else
  {
    QueueUserAPC((PAPCFUNC)survarium::empty_hands::tick, v3, 0);
    WaitForSingleObject(*(HANDLE *)(a2 + 4), 0xFFFFFFFF);
  }
}
