void __thiscall boost::asio::detail::timer_op::timer_op(
        boost::asio::detail::timer_op *this,
        void (__cdecl *func)(boost::asio::detail::win_iocp_io_service *, boost::asio::detail::win_iocp_operation *, const boost::system::error_code *, unsigned int))
{
  this->next_ = 0;
  this->func_ = func;
  this->Internal = 0;
  this->InternalHigh = 0;
  this->Offset = 0;
  this->OffsetHigh = 0;
  this->hEvent = 0;
  this->ready_ = 0;
  this->ec_.m_val = 0;
  this->ec_.m_cat = boost::system::system_category();
}
