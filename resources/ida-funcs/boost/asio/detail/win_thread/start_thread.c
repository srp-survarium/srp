void __userpurge boost::asio::detail::win_thread::start_thread(
        boost::asio::detail::win_thread::func_base *arg@<esi>,
        boost::asio::detail::win_thread *this,
        SIZE_T stack_size)
{
  DWORD LastError; // edi
  HANDLE EventA; // eax
  DWORD v5; // edi
  HANDLE v6; // eax
  DWORD v7; // edi
  void *exit_event; // ebx
  HANDLE hObject; // [esp+Ch] [ebp-10h]
  unsigned int thrdaddr; // [esp+10h] [ebp-Ch] BYREF
  boost::system::error_code err; // [esp+14h] [ebp-8h] BYREF

  hObject = CreateEventA(0, 1, 0, 0);
  arg->entry_event_ = hObject;
  if ( !hObject )
  {
    LastError = GetLastError();
    ((void (__thiscall *)(boost::asio::detail::win_thread::func_base *, int))arg->~boost::asio::detail::win_thread::func_base)(
      arg,
      1);
    err.m_val = LastError;
    err.m_cat = boost::system::system_category();
    if ( (LastError != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
      boost::asio::detail::do_throw_error(&err, "thread.entry_event");
  }
  EventA = CreateEventA(0, 1, 0, 0);
  this->exit_event_ = EventA;
  arg->exit_event_ = EventA;
  if ( !this->exit_event_ )
  {
    v5 = GetLastError();
    ((void (__thiscall *)(boost::asio::detail::win_thread::func_base *, int))arg->~boost::asio::detail::win_thread::func_base)(
      arg,
      1);
    err.m_val = v5;
    err.m_cat = boost::system::system_category();
    if ( (v5 != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
      boost::asio::detail::do_throw_error(&err, "thread.exit_event");
  }
  thrdaddr = 0;
  v6 = _beginthreadex(
         0,
         stack_size,
         (unsigned int (__stdcall *)(void *))boost::asio::detail::win_thread_function,
         arg,
         0,
         &thrdaddr);
  this->thread_ = v6;
  if ( !v6 )
  {
    v7 = GetLastError();
    ((void (__thiscall *)(boost::asio::detail::win_thread::func_base *, int))arg->~boost::asio::detail::win_thread::func_base)(
      arg,
      1);
    if ( hObject )
      CloseHandle(hObject);
    exit_event = this->exit_event_;
    if ( exit_event )
      CloseHandle(exit_event);
    err.m_val = v7;
    err.m_cat = boost::system::system_category();
    if ( (v7 != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
      boost::asio::detail::do_throw_error(&err, "thread");
  }
  if ( hObject )
  {
    WaitForSingleObject(hObject, 0xFFFFFFFF);
    CloseHandle(hObject);
  }
}
