void __thiscall boost::asio::detail::win_iocp_io_service::abandon_operations(
        boost::asio::detail::win_iocp_io_service *this,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *ops)
{
  _DWORD v3[2]; // [esp+4h] [ebp-14h] BYREF
  boost::asio::detail::win_iocp_operation *next; // [esp+Ch] [ebp-Ch]
  boost::asio::detail::win_iocp_operation *front; // [esp+10h] [ebp-8h]
  boost::asio::detail::win_iocp_operation *op; // [esp+14h] [ebp-4h]

  while ( 1 )
  {
    op = ops->front_;
    if ( !op )
      break;
    if ( ops->front_ )
    {
      front = ops->front_;
      next = ops->front_->next_;
      ops->front_ = next;
      if ( !ops->front_ )
        ops->back_ = 0;
      front->next_ = 0;
    }
    InterlockedDecrement(&this->outstanding_work_);
    v3[0] = 0;
    v3[1] = boost::system::system_category();
    op->func_(0, op, (const boost::system::error_code *)v3, 0);
  }
}
