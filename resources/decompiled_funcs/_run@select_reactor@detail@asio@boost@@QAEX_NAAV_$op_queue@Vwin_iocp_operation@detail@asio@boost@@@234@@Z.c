void __thiscall boost::asio::detail::select_reactor::run(
        boost::asio::detail::select_reactor *this,
        bool block,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *ops)
{
  bool v3; // [esp+4h] [ebp-130h]
  bool v4; // [esp+8h] [ebp-12Ch]
  int v6; // [esp+50h] [ebp-E4h]
  char v7; // [esp+DBh] [ebp-59h]
  boost::asio::detail::timer_queue_base *j; // [esp+DCh] [ebp-58h]
  int m; // [esp+100h] [ebp-34h]
  int k; // [esp+104h] [ebp-30h]
  int i; // [esp+108h] [ebp-2Ch]
  timeval tv_buf; // [esp+10Ch] [ebp-28h] BYREF
  boost::system::error_code ec; // [esp+114h] [ebp-20h] BYREF
  bool have_work_to_do; // [esp+11Fh] [ebp-15h]
  timeval *tv; // [esp+120h] [ebp-14h]
  int retval; // [esp+124h] [ebp-10h]
  unsigned int max_fd; // [esp+128h] [ebp-Ch]
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+12Ch] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
  lock.mutex_ = &this->mutex_;
  EnterCriticalSection(&this->mutex_.crit_section_);
  lock.locked_ = 1;
  if ( this->stop_thread_ )
  {
    LeaveCriticalSection(&lock.mutex_->crit_section_);
LABEL_3:
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
    return;
  }
  for ( i = 0; i < 3; ++i )
  {
    this->fd_sets_[i].fd_set_->fd_count = 0;
    this->fd_sets_[i].max_descriptor_ = -1;
  }
  boost::asio::detail::win_fd_set_adapter::set(this->fd_sets_, this->interrupter_.read_descriptor_);
  max_fd = 0;
  for ( j = this->timer_queues_.first_; j; j = j->next_ )
  {
    if ( !j->empty(j) )
    {
      v7 = 0;
      goto LABEL_13;
    }
  }
  v7 = 1;
LABEL_13:
  have_work_to_do = v7 == 0;
  for ( k = 0; k < 3; ++k )
  {
    v4 = have_work_to_do
      || (stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *)this->op_queue_[k].operations_.values_._M_impl._M_node._M_data._M_next != &this->op_queue_[k].operations_.values_;
    have_work_to_do = v4;
    boost::asio::detail::reactor_op_queue<unsigned int>::get_descriptors<boost::asio::detail::win_fd_set_adapter>(
      &this->op_queue_[k],
      &this->fd_sets_[k],
      ops);
    if ( this->fd_sets_[k].max_descriptor_ > max_fd )
      max_fd = this->fd_sets_[k].max_descriptor_;
  }
  v3 = have_work_to_do
    || (stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *)this->op_queue_[3].operations_.values_._M_impl._M_node._M_data._M_next != &this->op_queue_[3].operations_.values_;
  have_work_to_do = v3;
  boost::asio::detail::reactor_op_queue<unsigned int>::get_descriptors<boost::asio::detail::win_fd_set_adapter>(
    &this->op_queue_[3],
    &this->fd_sets_[1],
    ops);
  if ( this->fd_sets_[1].max_descriptor_ > max_fd )
    max_fd = this->fd_sets_[1].max_descriptor_;
  boost::asio::detail::reactor_op_queue<unsigned int>::get_descriptors<boost::asio::detail::win_fd_set_adapter>(
    &this->op_queue_[3],
    &this->fd_sets_[2],
    ops);
  if ( this->fd_sets_[2].max_descriptor_ > max_fd )
    max_fd = this->fd_sets_[2].max_descriptor_;
  if ( !block && !have_work_to_do )
  {
    if ( lock.locked_ )
      LeaveCriticalSection(&lock.mutex_->crit_section_);
    goto LABEL_3;
  }
  tv_buf.tv_sec = 0;
  tv_buf.tv_usec = 0;
  if ( block )
  {
    v6 = boost::asio::detail::timer_queue_set::wait_duration_usec(&this->timer_queues_, 300000000);
    tv_buf.tv_sec = v6 / (int)&off_F4240;
    tv_buf.tv_usec = v6 % (int)&off_F4240;
  }
  tv = &tv_buf;
  if ( lock.locked_ )
  {
    LeaveCriticalSection(&lock.mutex_->crit_section_);
    lock.locked_ = 0;
  }
  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  retval = boost::asio::detail::socket_ops::select(
             max_fd + 1,
             (fd_set *)this->fd_sets_[0].fd_set_,
             (fd_set *)this->fd_sets_[1].fd_set_,
             (fd_set *)this->fd_sets_[2].fd_set_,
             tv,
             &ec);
  if ( retval > 0 && __WSAFDIsSet(this->interrupter_.read_descriptor_, (fd_set *)this->fd_sets_[0].fd_set_) )
  {
    boost::asio::detail::socket_select_interrupter::reset(&this->interrupter_);
    --retval;
  }
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex>::lock(&lock);
  if ( retval > 0 )
  {
    boost::asio::detail::reactor_op_queue<unsigned int>::perform_operations_for_descriptors<boost::asio::detail::win_fd_set_adapter>(
      &this->op_queue_[3],
      &this->fd_sets_[2],
      ops);
    boost::asio::detail::reactor_op_queue<unsigned int>::perform_operations_for_descriptors<boost::asio::detail::win_fd_set_adapter>(
      &this->op_queue_[3],
      &this->fd_sets_[1],
      ops);
    for ( m = 2; m >= 0; --m )
      boost::asio::detail::reactor_op_queue<unsigned int>::perform_operations_for_descriptors<boost::asio::detail::win_fd_set_adapter>(
        &this->op_queue_[m],
        &this->fd_sets_[m],
        ops);
  }
  boost::asio::detail::timer_queue_set::get_ready_timers(&this->timer_queues_, ops);
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex>::~scoped_lock<boost::asio::detail::win_mutex>(&lock);
}
