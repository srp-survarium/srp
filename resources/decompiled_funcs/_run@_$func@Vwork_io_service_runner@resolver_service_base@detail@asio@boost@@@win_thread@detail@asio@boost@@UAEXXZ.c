void __thiscall boost::asio::detail::win_thread::func<boost::asio::detail::resolver_service_base::work_io_service_runner>::run(
        boost::asio::detail::win_thread::func<boost::asio::detail::resolver_service_base::work_io_service_runner> *this)
{
  boost::asio::io_service::run(this->f_.io_service_);
}
