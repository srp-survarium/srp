void __thiscall boost::asio::detail::select_reactor::shutdown_service(boost::asio::detail::select_reactor *this)
{
  boost::asio::detail::win_mutex *p_mutex; // esi
  boost::asio::detail::socket_select_interrupter *size; // ecx
  boost::asio::detail::win_thread *v4; // ecx
  boost::asio::detail::win_thread *thread; // esi
  stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *p_values; // ebx
  stlp_std::priv::_List_iterator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::_Nonconst_traits<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > v7; // eax
  stlp_std::priv::_List_node_base *M_prev; // ecx
  boost::asio::detail::timer_queue_base *i; // esi
  stlp_std::priv::_List_node_base *v10; // esi
  boost::asio::detail::win_iocp_io_service *io_service; // edi
  volatile LONG *p_outstanding_work; // edi
  boost::asio::detail::win_iocp_operation *v13; // ecx
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> v14; // [esp-4h] [ebp-20h] BYREF
  stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *M_next; // [esp+18h] [ebp-4h]

  p_mutex = &this->mutex_;
  EnterCriticalSection(&this->mutex_.crit_section_);
  v14.size_ = (unsigned int)p_mutex;
  this->shutdown_ = 1;
  this->stop_thread_ = 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)v14.size_);
  if ( this->thread_ )
  {
    boost::asio::detail::socket_select_interrupter::interrupt(size, (int)&this->interrupter_);
    boost::asio::detail::win_thread::join(v4, (int)this->thread_);
    thread = this->thread_;
    if ( thread )
    {
      CloseHandle(thread->thread_);
      operator delete(thread);
      size = (boost::asio::detail::socket_select_interrupter *)v14.size_;
    }
    this->thread_ = 0;
  }
  v14.spares_._M_impl._M_node._M_data._M_prev = 0;
  v14.buckets_ = 0;
  p_values = &this->op_queue_[0].operations_.values_;
  v14.num_buckets_ = 4;
  do
  {
    v7._M_node = p_values->_M_impl._M_node._M_data._M_next;
    LOBYTE(size) = p_values->_M_impl._M_node._M_data._M_next != (stlp_std::priv::_List_node_base *)p_values;
    if ( (stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *)p_values->_M_impl._M_node._M_data._M_next != p_values )
    {
      while ( 1 )
      {
        M_next = (stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *)v7._M_node->_M_next;
        M_prev = v7._M_node[1]._M_prev;
        if ( M_prev )
        {
          if ( v14.buckets_ )
            v14.buckets_[2].last._M_node = M_prev;
          else
            v14.spares_._M_impl._M_node._M_data._M_prev = v7._M_node[1]._M_prev;
          v14.buckets_ = (boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::bucket_type *)v7._M_node[2]._M_next;
          v7._M_node[1]._M_prev = 0;
          v7._M_node[2]._M_next = 0;
        }
        boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::erase(
          &v14,
          (int)&p_values[-1]._M_impl._M_node._M_data._M_prev,
          v7);
        if ( M_next == p_values )
          break;
        v7._M_node = (stlp_std::priv::_List_node_base *)M_next;
      }
    }
    p_values = (stlp_std::list<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>,stlp_std::allocator<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> > > *)((char *)p_values + 28);
    --v14.num_buckets_;
  }
  while ( v14.num_buckets_ );
  for ( i = this->timer_queues_.first_; i; i = i->next_ )
    i->get_all_timers(
      i,
      (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)&v14.spares_._M_impl._M_node._M_data._M_prev);
  v10 = v14.spares_._M_impl._M_node._M_data._M_prev;
  io_service = this->io_service_;
  if ( v14.spares_._M_impl._M_node._M_data._M_prev )
  {
    p_outstanding_work = &io_service->outstanding_work_;
    do
    {
      v14.spares_._M_impl._M_node._M_data._M_prev = v10[2]._M_prev;
      if ( !v14.spares_._M_impl._M_node._M_data._M_prev )
        v14.buckets_ = 0;
      v10[2]._M_prev = 0;
      InterlockedDecrement(p_outstanding_work);
      boost::asio::detail::win_iocp_operation::destroy(v13, (int)v10);
      v10 = v14.spares_._M_impl._M_node._M_data._M_prev;
    }
    while ( v14.spares_._M_impl._M_node._M_data._M_prev );
  }
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>(
    (boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *)size,
    (int *)&v14.spares_._M_impl._M_node._M_data._M_prev);
}
