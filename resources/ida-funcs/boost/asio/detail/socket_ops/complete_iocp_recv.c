void __usercall boost::asio::detail::socket_ops::complete_iocp_recv(
        boost::system::error_code *ec@<esi>,
        boost::weak_ptr<void> *a2@<ecx>,
        unsigned __int8 state,
        const boost::weak_ptr<void> *cancel_token,
        bool all_empty,
        unsigned int bytes_transferred)
{
  int m_val; // eax
  int v7; // edi
  boost::asio::error::detail::misc_category *misc_category; // eax

  m_val = ec->m_val;
  if ( ec->m_val == 64 )
  {
    if ( boost::weak_ptr<void>::expired(a2, (int)cancel_token) )
      v7 = 995;
    else
      v7 = 10054;
    goto LABEL_4;
  }
  if ( m_val == 1234 )
  {
    v7 = 10061;
LABEL_4:
    misc_category = (boost::asio::error::detail::misc_category *)boost::system::system_category();
LABEL_13:
    ec->m_cat = misc_category;
    ec->m_val = v7;
    return;
  }
  if ( !m_val && !bytes_transferred && (state & 0x10) != 0 && !all_empty )
  {
    v7 = 2;
    misc_category = boost::asio::error::get_misc_category();
    goto LABEL_13;
  }
}
