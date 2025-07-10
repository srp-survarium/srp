void __thiscall boost::asio::detail::resolver_service_base::~resolver_service_base(
        boost::asio::detail::resolver_service_base *this)
{
  boost::asio::detail::resolver_service_base::shutdown_service(this);
  boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::~scoped_ptr<boost::asio::detail::win_thread>(&this->work_thread_);
  boost::asio::detail::scoped_ptr<boost::asio::io_service::work>::~scoped_ptr<boost::asio::io_service::work>(&this->work_);
  boost::asio::detail::scoped_ptr<boost::asio::io_service>::~scoped_ptr<boost::asio::io_service>(&this->work_io_service_);
  DeleteCriticalSection(&this->mutex_.crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->mutex_);
}
