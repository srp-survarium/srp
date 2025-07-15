int __usercall boost::asio::detail::socket_ops::error_wrapper<int>@<eax>(
        boost::system::error_code *ec@<esi>,
        int return_value)
{
  const boost::system::error_category *v2; // edi
  int result; // eax

  v2 = boost::system::system_category();
  ec->m_val = WSAGetLastError();
  result = return_value;
  ec->m_cat = v2;
  return result;
}
