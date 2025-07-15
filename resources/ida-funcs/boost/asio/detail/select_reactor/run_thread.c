void __thiscall boost::asio::detail::select_reactor::run_thread(boost::asio::detail::select_reactor *this, int a2)
{
  boost::asio::detail::select_reactor *v2; // ecx
  boost::asio::detail::win_iocp_io_service *v3; // ecx
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *v4; // ecx
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *v5; // [esp+0h] [ebp-20h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+10h] [ebp-10h]
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> v7; // [esp+18h] [ebp-8h] BYREF

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)(a2 + 24);
  EnterCriticalSection((LPCRITICAL_SECTION)(a2 + 24));
  while ( !*(_BYTE *)(a2 + 208) )
  {
    LeaveCriticalSection(lpCriticalSection);
    v7.front_ = 0;
    v7.back_ = 0;
    boost::asio::detail::select_reactor::run(v2, a2, &v7, v5);
    boost::asio::detail::win_iocp_io_service::post_deferred_completions(v3, *(_DWORD *)(a2 + 20), &v7);
    EnterCriticalSection(lpCriticalSection);
    boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>(
      v4,
      (int *)&v7);
  }
  LeaveCriticalSection(lpCriticalSection);
}
