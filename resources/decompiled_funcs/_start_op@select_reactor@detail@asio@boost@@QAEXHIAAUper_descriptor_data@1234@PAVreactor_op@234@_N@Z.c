void __thiscall boost::asio::detail::select_reactor::start_op(
        boost::asio::detail::select_reactor *this,
        int op_type,
        unsigned int descriptor,
        boost::asio::detail::select_reactor::per_descriptor_data *__formal,
        boost::asio::detail::reactor_op *op,
        bool a6)
{
  boost::asio::detail::win_iocp_io_service *io_service; // [esp+94h] [ebp-20h]
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+A8h] [ebp-Ch] BYREF
  bool first; // [esp+B3h] [ebp-1h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
  lock.mutex_ = &this->mutex_;
  EnterCriticalSection(&this->mutex_.crit_section_);
  lock.locked_ = 1;
  if ( this->shutdown_ )
  {
    io_service = this->io_service_;
    InterlockedIncrement(&io_service->outstanding_work_);
    boost::asio::detail::win_iocp_io_service::post_deferred_completion(io_service, op);
    if ( lock.locked_ )
      LeaveCriticalSection(&lock.mutex_->crit_section_);
  }
  else
  {
    first = boost::asio::detail::reactor_op_queue<unsigned int>::enqueue_operation(
              &this->op_queue_[op_type],
              descriptor,
              (stlp_std::priv::_List_node_base *)op);
    InterlockedIncrement(&this->io_service_->outstanding_work_);
    if ( first )
      boost::asio::detail::socket_select_interrupter::interrupt(&this->interrupter_);
    if ( lock.locked_ )
      LeaveCriticalSection(&lock.mutex_->crit_section_);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
}
