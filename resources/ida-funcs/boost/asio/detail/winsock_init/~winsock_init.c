void __thiscall boost::asio::detail::winsock_init<2,0>::~winsock_init<2,0>(
        boost::asio::detail::winsock_init<2,0> *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6)
{
  if ( !InterlockedDecrement((volatile LONG *)&vostok::testing::suite_base<vostok::engine_test_suite>::s_suite_creation_flag.m_mutex[2] + 1) )
    ((void (__stdcall *)(int, int, int, int, int))(&off_8E3A98 + 9))(a2, a3, a4, a5, a6);
}
