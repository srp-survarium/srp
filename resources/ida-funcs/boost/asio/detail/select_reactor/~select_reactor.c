void __thiscall boost::asio::detail::select_reactor::~select_reactor(boost::asio::detail::select_reactor *this)
{
  this->__vftable = (boost::asio::detail::select_reactor_vtbl *)&boost::asio::detail::select_reactor::`vftable';
  boost::asio::detail::select_reactor::shutdown_service(this);
  `vector destructor iterator'(
    (char *)this->fd_sets_,
    0xCu,
    3,
    (void (__thiscall *)(void *))boost::asio::detail::win_fd_set_adapter::~win_fd_set_adapter);
  `vector destructor iterator'(
    (char *)this->op_queue_,
    0x1Cu,
    4,
    (void (__thiscall *)(void *))boost::asio::detail::reactor_op_queue<unsigned int>::~reactor_op_queue<unsigned int>);
  boost::asio::detail::socket_select_interrupter::close_descriptors(&this->interrupter_);
  DeleteCriticalSection(&this->mutex_.crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->mutex_);
  this->__vftable = (boost::asio::detail::select_reactor_vtbl *)&boost::asio::io_service::service::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->key_);
}
