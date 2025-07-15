void __thiscall boost::asio::detail::win_iocp_io_service::~win_iocp_io_service(
        boost::asio::detail::win_iocp_io_service *this)
{
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>((boost::asio::detail::op_queue<boost::asio::detail::timer_op> *)&this->completed_ops_);
  DeleteCriticalSection(&this->dispatch_mutex_.crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->dispatch_mutex_);
  if ( this->waitable_timer_.handle )
    CloseHandle(this->waitable_timer_.handle);
  boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::~scoped_ptr<boost::asio::detail::win_thread>(&this->timer_thread_);
  if ( this->iocp_.handle )
    CloseHandle(this->iocp_.handle);
  this->__vftable = (boost::asio::detail::win_iocp_io_service_vtbl *)&boost::asio::io_service::service::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->key_);
}
