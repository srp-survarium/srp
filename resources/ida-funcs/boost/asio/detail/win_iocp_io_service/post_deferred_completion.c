void __userpurge boost::asio::detail::win_iocp_io_service::post_deferred_completion(
        boost::asio::detail::win_iocp_io_service *this@<ecx>,
        int a2@<eax>,
        boost::asio::detail::win_iocp_operation *op)
{
  op->ready_ = 1;
  if ( !PostQueuedCompletionStatus(*(HANDLE *)(a2 + 20), 0, 2u, op) )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)(a2 + 48));
    boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::push(
      (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)(a2 + 76),
      op);
    InterlockedExchange((volatile LONG *)(a2 + 44), 1);
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 48));
  }
}
