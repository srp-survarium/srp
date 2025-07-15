void __thiscall boost::asio::detail::reactor_op::reactor_op(
        boost::asio::detail::reactor_op *this,
        bool (__cdecl *perform_func)(boost::asio::detail::reactor_op *),
        void (__cdecl *complete_func)(boost::asio::detail::win_iocp_io_service *, boost::asio::detail::win_iocp_operation *, const boost::system::error_code *, unsigned int))
{
  this->next_ = 0;
  this->func_ = complete_func;
  this->Internal = 0;
  this->InternalHigh = 0;
  this->Offset = 0;
  this->OffsetHigh = 0;
  this->hEvent = 0;
  this->ready_ = 0;
  this->ec_.m_val = 0;
  this->ec_.m_cat = boost::system::system_category();
  this->bytes_transferred_ = 0;
  this->perform_func_ = perform_func;
}
