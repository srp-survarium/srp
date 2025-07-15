void __thiscall boost::asio::detail::win_fd_set_adapter::~win_fd_set_adapter(
        boost::asio::detail::win_fd_set_adapter *this)
{
  operator delete(this->fd_set_);
}
