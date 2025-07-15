void __thiscall boost::asio::detail::winsock_init<2,0>::winsock_init<2,0>(
        boost::asio::detail::winsock_init<2,0> *this,
        bool allow_throw,
        char a3)
{
  LONG v3; // eax
  LONG v4; // eax
  int v5; // [esp+0h] [ebp-1A0h]
  int v6; // [esp+4h] [ebp-19Ch]
  boost::system::error_code err; // [esp+8h] [ebp-198h] BYREF
  _BYTE v8[400]; // [esp+10h] [ebp-190h] BYREF

  if ( InterlockedIncrement((volatile LONG *)&vostok::testing::suite_base<vostok::engine_test_suite>::s_suite_creation_flag.m_mutex[2] + 1) == 1 )
  {
    v3 = ((int (__stdcall *)(int, _BYTE *, int, int, int))(&off_8E3A98 + 24))(2, v8, v5, v6, err.m_val);
    InterlockedExchange(&Addend, v3);
  }
  if ( a3 )
  {
    v4 = InterlockedExchangeAdd(&Addend, 0);
    if ( v4 )
    {
      err.m_val = v4;
      err.m_cat = boost::system::system_category();
      if ( vostok::memory::process_allocator::finalize_impl )
        boost::asio::detail::do_throw_error(&err, "winsock");
    }
  }
}
