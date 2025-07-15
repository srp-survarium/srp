void __usercall boost::asio::detail::select_reactor::select_reactor(
        boost::asio::detail::select_reactor *this@<edi>,
        boost::asio::io_service *io_service@<eax>,
        boost::asio::detail::win_mutex *a3@<ecx>)
{
  boost::asio::detail::socket_select_interrupter *v3; // ecx
  boost::asio::detail::reactor_op_queue<unsigned int> *op_queue; // ebx
  boost::asio::detail::win_fd_set_adapter *fd_sets; // ebx
  boost::asio::detail::win_thread *v6; // eax
  boost::asio::detail::win_thread *v7; // ebx
  boost::asio::detail::win_thread::func_base *v8; // eax
  int i; // [esp+Ch] [ebp-4h]
  int j; // [esp+Ch] [ebp-4h]

  this->key_.type_info_ = 0;
  this->key_.id_ = 0;
  this->owner_ = io_service;
  this->next_ = 0;
  this->__vftable = (boost::asio::detail::select_reactor_vtbl *)&boost::asio::detail::select_reactor::`vftable';
  this->io_service_ = io_service->impl_;
  boost::asio::detail::win_mutex::win_mutex(a3, &this->mutex_);
  boost::asio::detail::socket_select_interrupter::open_descriptors(v3, &this->interrupter_.read_descriptor_);
  op_queue = this->op_queue_;
  for ( i = 3; i >= 0; --i )
    boost::asio::detail::reactor_op_queue<unsigned int>::reactor_op_queue<unsigned int>(op_queue++);
  fd_sets = this->fd_sets_;
  for ( j = 2; j >= 0; --j )
    boost::asio::detail::win_fd_set_adapter::win_fd_set_adapter(fd_sets++);
  this->timer_queues_.first_ = 0;
  this->stop_thread_ = 0;
  this->thread_ = 0;
  this->shutdown_ = 0;
  v6 = (boost::asio::detail::win_thread *)operator new(0xCu);
  v7 = v6;
  if ( v6 )
  {
    v6->thread_ = 0;
    v6->exit_event_ = 0;
    v8 = (boost::asio::detail::win_thread::func_base *)operator new(0x14u);
    if ( v8 )
    {
      v8->__vftable = (boost::asio::detail::win_thread::func_base_vtbl *)&boost::asio::detail::win_thread::func<boost::asio::detail::binder1<void (__cdecl *)(boost::asio::detail::select_reactor *),boost::asio::detail::select_reactor *>>::`vftable';
      v8[1].__vftable = (boost::asio::detail::win_thread::func_base_vtbl *)boost::asio::detail::select_reactor::call_run_thread;
      v8[1].entry_event_ = this;
    }
    else
    {
      v8 = 0;
    }
    boost::asio::detail::win_thread::start_thread(v8, v7, 0);
  }
  else
  {
    v7 = 0;
  }
  this->thread_ = v7;
}
