void __cdecl boost::asio::detail::select_reactor::call_run_thread(boost::asio::detail::select_reactor *reactor)
{
  boost::asio::detail::select_reactor *v1; // ecx

  boost::asio::detail::select_reactor::run_thread(v1, (int)reactor);
}
