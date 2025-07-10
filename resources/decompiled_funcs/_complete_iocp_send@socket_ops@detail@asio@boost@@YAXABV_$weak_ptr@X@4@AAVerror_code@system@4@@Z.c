void __cdecl boost::asio::detail::socket_ops::complete_iocp_send(
        const boost::weak_ptr<void> *cancel_token,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v2; // edx
  int use_count; // [esp+0h] [ebp-34h]
  const boost::system::error_category *v4; // [esp+Ch] [ebp-28h]
  const boost::system::error_category *v5; // [esp+1Ch] [ebp-18h]

  if ( ec->m_val == 64 )
  {
    if ( cancel_token->pn.pi_ )
      use_count = cancel_token->pn.pi_->use_count_;
    else
      use_count = 0;
    if ( use_count )
    {
      v5 = boost::system::system_category();
      ec->m_val = 10054;
      ec->m_cat = v5;
    }
    else
    {
      v2 = boost::system::system_category();
      ec->m_val = 995;
      ec->m_cat = v2;
    }
  }
  else if ( ec->m_val == 1234 )
  {
    v4 = boost::system::system_category();
    ec->m_val = 10061;
    ec->m_cat = v4;
  }
}
