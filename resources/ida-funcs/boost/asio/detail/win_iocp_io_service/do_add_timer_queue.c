void __usercall boost::asio::detail::win_iocp_io_service::do_add_timer_queue(
        boost::asio::detail::win_iocp_io_service *this@<ecx>,
        boost::asio::detail::timer_queue_base *queue@<eax>)
{
  HANDLE *v4; // edi
  HANDLE WaitableTimerA; // eax
  boost::asio::detail::win_thread *v6; // eax
  boost::asio::detail::win_thread *v7; // ebx
  boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *v8; // ecx
  boost::asio::detail::win_thread::func_base *v9; // eax
  void *handle; // [esp-18h] [ebp-40h]
  boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *v11; // [esp-4h] [ebp-2Ch]
  boost::system::error_code v12; // [esp+10h] [ebp-18h] BYREF
  LARGE_INTEGER DueTime; // [esp+18h] [ebp-10h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+20h] [ebp-8h]

  lpCriticalSection = &this->dispatch_mutex_.crit_section_;
  EnterCriticalSection(&this->dispatch_mutex_.crit_section_);
  queue->next_ = this->timer_queues_.first_;
  this->timer_queues_.first_ = queue;
  v4 = 0;
  if ( !this->waitable_timer_.handle )
  {
    WaitableTimerA = CreateWaitableTimerA(0, 0, 0);
    this->waitable_timer_.handle = WaitableTimerA;
    if ( !WaitableTimerA )
    {
      v12.m_val = GetLastError();
      v12.m_cat = boost::system::system_category();
      if ( (v12.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
        boost::asio::detail::do_throw_error(&v12, "timer");
    }
    handle = this->waitable_timer_.handle;
    DueTime.QuadPart = -3000000000LL;
    SetWaitableTimer(handle, &DueTime, (LONG)&loc_493E0, 0, 0, 0);
  }
  v12.m_val = (int)&this->timer_thread_;
  if ( !this->timer_thread_.p_ )
  {
    v6 = (boost::asio::detail::win_thread *)operator new(0xCu);
    v7 = v6;
    v8 = v11;
    if ( v6 )
    {
      v6->thread_ = 0;
      v6->exit_event_ = 0;
      v9 = (boost::asio::detail::win_thread::func_base *)operator new(0x10u);
      if ( v9 )
      {
        v9->__vftable = (boost::asio::detail::win_thread::func_base_vtbl *)&boost::asio::detail::win_thread::func<boost::asio::detail::win_iocp_io_service::timer_thread_function>::`vftable';
        v9[1].__vftable = (boost::asio::detail::win_thread::func_base_vtbl *)this;
      }
      else
      {
        v9 = 0;
      }
      boost::asio::detail::win_thread::start_thread(v9, v7, (SIZE_T)&_sbh_sizeHeaderList);
      v4 = (HANDLE *)v7;
    }
    boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::reset(v8, (HANDLE **)v12.m_val, v4);
  }
  LeaveCriticalSection(lpCriticalSection);
}
