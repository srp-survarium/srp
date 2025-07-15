void __cdecl boost::asio::detail::socket_ops::complete_iocp_recv(
        unsigned __int8 state,
        const boost::weak_ptr<void> *cancel_token,
        bool all_empty,
        boost::system::error_code *ec,
        unsigned int bytes_transferred)
{
  const boost::system::error_category *v5; // edx
  int use_count; // [esp+0h] [ebp-40h]
  boost::asio::error::detail::misc_category *misc_category; // [esp+Ch] [ebp-34h]
  const boost::system::error_category *v8; // [esp+18h] [ebp-28h]
  const boost::system::error_category *v9; // [esp+28h] [ebp-18h]

  if ( ec->m_val == 64 )
  {
    if ( cancel_token->pn.pi_ )
      use_count = cancel_token->pn.pi_->use_count_;
    else
      use_count = 0;
    if ( use_count )
    {
      v9 = boost::system::system_category();
      ec->m_val = 10054;
      ec->m_cat = v9;
    }
    else
    {
      v5 = boost::system::system_category();
      ec->m_val = 995;
      ec->m_cat = v5;
    }
  }
  else if ( ec->m_val == 1234 )
  {
    v8 = boost::system::system_category();
    ec->m_val = 10061;
    ec->m_cat = v8;
  }
  else if ( !ec->m_val && !bytes_transferred && (state & 0x10) != 0 && !all_empty )
  {
    misc_category = boost::asio::error::get_misc_category();
    ec->m_val = 2;
    ec->m_cat = misc_category;
  }
}
