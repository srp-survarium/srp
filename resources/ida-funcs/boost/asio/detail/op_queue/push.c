void __usercall boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::push(
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *this@<ecx>,
        boost::asio::detail::win_iocp_operation *h@<eax>)
{
  boost::asio::detail::win_iocp_operation *back; // edx

  h->next_ = 0;
  back = this->back_;
  if ( back )
    back->next_ = h;
  else
    this->front_ = h;
  this->back_ = h;
}


void __usercall boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::push<boost::asio::detail::win_iocp_operation>(
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *this@<edx>,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *q@<eax>)
{
  boost::asio::detail::win_iocp_operation *front; // ecx
  boost::asio::detail::win_iocp_operation *back; // esi

  front = q->front_;
  if ( q->front_ )
  {
    back = this->back_;
    if ( back )
      back->next_ = front;
    else
      this->front_ = front;
    this->back_ = q->back_;
    q->front_ = 0;
    q->back_ = 0;
  }
}
