void __thiscall boost::asio::detail::win_fd_set_adapter::win_fd_set_adapter(
        boost::asio::detail::win_fd_set_adapter *this)
{
  boost::asio::detail::win_fd_set_adapter::win_fd_set *v2; // eax

  this->max_descriptor_ = -1;
  this->capacity_ = 1024;
  v2 = (boost::asio::detail::win_fd_set_adapter::win_fd_set *)operator new(0x1004u);
  this->fd_set_ = v2;
  v2->fd_count = 0;
}
