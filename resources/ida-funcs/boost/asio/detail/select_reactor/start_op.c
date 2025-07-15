void __userpurge boost::asio::detail::select_reactor::start_op(
        boost::asio::detail::select_reactor *this@<ecx>,
        boost::asio::detail::reactor_op *op@<eax>,
        unsigned int op_type,
        unsigned int descriptor,
        boost::asio::detail::select_reactor::per_descriptor_data *__formal,
        bool a6)
{
  boost::asio::detail::win_mutex *p_mutex; // ebx
  boost::asio::detail::win_iocp_io_service *io_service; // edi
  boost::asio::detail::win_iocp_io_service *v10; // ecx
  boost::asio::detail::socket_select_interrupter *v11; // ecx
  bool v12; // [esp+17h] [ebp+Bh]

  p_mutex = &this->mutex_;
  EnterCriticalSection(&this->mutex_.crit_section_);
  if ( this->shutdown_ )
  {
    io_service = this->io_service_;
    InterlockedIncrement(&io_service->outstanding_work_);
    boost::asio::detail::win_iocp_io_service::post_deferred_completion(v10, (int)io_service, op);
  }
  else
  {
    v12 = boost::asio::detail::reactor_op_queue<unsigned int>::enqueue_operation(
            &this->op_queue_[3],
            op_type,
            (stlp_std::priv::_List_node_base *)op);
    InterlockedIncrement(&this->io_service_->outstanding_work_);
    if ( v12 )
      boost::asio::detail::socket_select_interrupter::interrupt(v11, (int)&this->interrupter_);
  }
  LeaveCriticalSection(&p_mutex->crit_section_);
}
