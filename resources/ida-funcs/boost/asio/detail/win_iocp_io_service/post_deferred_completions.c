void __userpurge boost::asio::detail::win_iocp_io_service::post_deferred_completions(
        boost::asio::detail::win_iocp_io_service *this@<ecx>,
        int a2@<esi>,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *ops)
{
  boost::asio::detail::win_iocp_operation *front; // edi

  while ( 1 )
  {
    front = ops->front_;
    if ( !ops->front_ )
      break;
    boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::pop(
      (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)this,
      (int *)ops);
    front->ready_ = 1;
    if ( !PostQueuedCompletionStatus(*(HANDLE *)(a2 + 20), 0, 2u, front) )
    {
      EnterCriticalSection((LPCRITICAL_SECTION)(a2 + 48));
      boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::push(
        (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)(a2 + 76),
        front);
      boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::push<boost::asio::detail::win_iocp_operation>(
        (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)(a2 + 76),
        ops);
      InterlockedExchange((volatile LONG *)(a2 + 44), 1);
      LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 48));
    }
  }
}
