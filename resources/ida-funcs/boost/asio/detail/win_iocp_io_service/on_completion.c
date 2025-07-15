void __userpurge boost::asio::detail::win_iocp_io_service::on_completion(
        boost::asio::detail::win_iocp_io_service *this@<eax>,
        boost::asio::detail::win_iocp_operation *op@<esi>,
        unsigned int last_error,
        unsigned int bytes_transferred)
{
  op->ready_ = 1;
  op->Internal = (unsigned int)boost::system::system_category();
  op->Offset = last_error;
  op->OffsetHigh = bytes_transferred;
  if ( !PostQueuedCompletionStatus(this->iocp_.handle, 0, 2u, op) )
  {
    EnterCriticalSection(&this->dispatch_mutex_.crit_section_);
    boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::push(&this->completed_ops_, op);
    InterlockedExchange(&this->dispatch_required_, 1);
    LeaveCriticalSection(&this->dispatch_mutex_.crit_section_);
  }
}
