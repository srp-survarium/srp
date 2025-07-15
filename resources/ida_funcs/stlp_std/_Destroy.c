void __cdecl stlp_std::_Destroy<stlp_std::pair<unsigned int const,survarium::dictionary_item>>(
        stlp_std::pair<unsigned int const ,survarium::dictionary_item> *__pointer)
{
  survarium::dictionary_item::~dictionary_item(&__pointer->second);
}


void __cdecl stlp_std::_Destroy<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>>(
        stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *__pointer)
{
  boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation>::~op_queue<boost::asio::detail::win_iocp_operation>((boost::asio::detail::op_queue<boost::asio::detail::timer_op> *)&__pointer->second);
}


void __cdecl stlp_std::_Destroy<vostok::fs_new::virtual_path_string>()
{
  ;
}
