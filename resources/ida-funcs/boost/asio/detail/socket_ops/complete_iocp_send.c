void __usercall boost::asio::detail::socket_ops::complete_iocp_send(
        boost::system::error_code *ec@<esi>,
        boost::weak_ptr<void> *a2@<ecx>,
        int a3)
{
  int v3; // edi
  const boost::system::error_category *v4; // eax

  if ( ec->m_val == 64 )
  {
    if ( boost::weak_ptr<void>::expired(a2, a3) )
      v3 = 995;
    else
      v3 = 10054;
  }
  else
  {
    if ( ec->m_val != 1234 )
      return;
    v3 = 10061;
  }
  v4 = boost::system::system_category();
  ec->m_val = v3;
  ec->m_cat = v4;
}
