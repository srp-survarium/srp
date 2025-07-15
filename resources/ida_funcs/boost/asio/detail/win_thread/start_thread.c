void __thiscall boost::asio::detail::win_thread::start_thread(
        boost::asio::detail::win_thread *this,
        boost::asio::detail::win_thread::func_base *arg,
        unsigned int stack_size)
{
  const boost::system::error_category *v4; // [esp+168h] [ebp-2CCh]
  boost::system::system_error v5; // [esp+188h] [ebp-2ACh] BYREF
  const boost::system::error_category *v6; // [esp+2B8h] [ebp-17Ch]
  const boost::system::error_category *v7; // [esp+3ECh] [ebp-48h]
  boost::asio::detail::win_thread::func_base *v8; // [esp+3F0h] [ebp-44h]
  boost::asio::detail::win_thread::func_base *v9; // [esp+3F4h] [ebp-40h]
  boost::asio::detail::win_thread::func_base *v10; // [esp+3F8h] [ebp-3Ch]
  boost::asio::detail::win_thread::func_base *v11; // [esp+3FCh] [ebp-38h]
  boost::asio::detail::win_thread::func_base *v12; // [esp+400h] [ebp-34h]
  boost::asio::detail::win_thread::func_base *v13; // [esp+404h] [ebp-30h]
  boost::system::error_code err; // [esp+408h] [ebp-2Ch] BYREF
  DWORD v15; // [esp+410h] [ebp-24h]
  boost::system::error_code v16; // [esp+414h] [ebp-20h]
  DWORD LastError; // [esp+41Ch] [ebp-18h]
  boost::system::error_code ec; // [esp+420h] [ebp-14h] BYREF
  unsigned int last_error; // [esp+428h] [ebp-Ch]
  unsigned int thread_id; // [esp+42Ch] [ebp-8h] BYREF
  void *entry_event; // [esp+430h] [ebp-4h]

  entry_event = CreateEventA(0, 1, 0, 0);
  arg->entry_event_ = entry_event;
  if ( !entry_event )
  {
    last_error = GetLastError();
    v12 = arg;
    v13 = arg;
    if ( arg )
      ((void (__thiscall *)(boost::asio::detail::win_thread::func_base *, int))v13->~boost::asio::detail::win_thread::func_base)(
        v13,
        1);
    v7 = boost::system::system_category();
    ec.m_val = last_error;
    ec.m_cat = v7;
    if ( (last_error != 0
        ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
        : 0) != 0 )
      boost::asio::detail::do_throw_error(&ec, "thread.entry_event");
  }
  this->exit_event_ = CreateEventA(0, 1, 0, 0);
  arg->exit_event_ = this->exit_event_;
  if ( !this->exit_event_ )
  {
    LastError = GetLastError();
    v10 = arg;
    v11 = arg;
    if ( arg )
      ((void (__thiscall *)(boost::asio::detail::win_thread::func_base *, int))v11->~boost::asio::detail::win_thread::func_base)(
        v11,
        1);
    v6 = boost::system::system_category();
    v16.m_val = LastError;
    v16.m_cat = v6;
    if ( (LastError != 0
        ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
        : 0) != 0 )
    {
      boost::system::system_error::system_error(&v5, v16, "thread.exit_event");
      boost::throw_exception(&v5);
      boost::system::system_error::~system_error(&v5);
    }
  }
  thread_id = 0;
  this->thread_ = (void *)_beginthreadex(
                            0,
                            stack_size,
                            (unsigned int (__stdcall *)(void *))boost::asio::detail::win_thread_function,
                            arg,
                            0,
                            &thread_id);
  if ( !this->thread_ )
  {
    v15 = GetLastError();
    v8 = arg;
    v9 = arg;
    if ( arg )
      ((void (__thiscall *)(boost::asio::detail::win_thread::func_base *, int))v9->~boost::asio::detail::win_thread::func_base)(
        v9,
        1);
    if ( entry_event )
      CloseHandle(entry_event);
    if ( this->exit_event_ )
      CloseHandle(this->exit_event_);
    v4 = boost::system::system_category();
    err.m_val = v15;
    err.m_cat = v4;
    if ( (v15 != 0
        ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
        : 0) != 0 )
      boost::asio::detail::do_throw_error(&err, "thread");
  }
  if ( entry_event )
  {
    WaitForSingleObject(entry_event, 0xFFFFFFFF);
    CloseHandle(entry_event);
  }
}
