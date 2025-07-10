void __thiscall boost::asio::detail::win_iocp_operation::reset(boost::asio::detail::win_iocp_operation *this)
{
  this->Internal = 0;
  this->InternalHigh = 0;
  this->Offset = 0;
  this->OffsetHigh = 0;
  this->hEvent = 0;
  this->ready_ = 0;
}
