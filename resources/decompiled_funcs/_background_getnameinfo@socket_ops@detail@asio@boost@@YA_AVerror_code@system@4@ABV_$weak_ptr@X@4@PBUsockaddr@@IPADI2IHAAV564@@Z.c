boost::system::error_code *__cdecl boost::asio::detail::socket_ops::background_getnameinfo(
        boost::system::error_code *result,
        const boost::weak_ptr<void> *cancel_token,
        const sockaddr *addr,
        socklen_t addrlen,
        char *host,
        DWORD hostlen,
        char *serv,
        DWORD servlen,
        int sock_type,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v10; // eax
  boost::system::error_code *v11; // eax
  const boost::system::error_category *m_cat; // edx
  const boost::system::error_category *v13; // eax
  boost::system::error_code *v14; // eax
  const boost::system::error_category *v15; // edx
  const boost::system::error_category *v16; // eax
  const boost::system::error_category *v17; // eax
  int use_count; // [esp+0h] [ebp-110h]
  boost::system::error_code v20; // [esp+6Ch] [ebp-A4h] BYREF
  int v21; // [esp+74h] [ebp-9Ch]
  boost::system::error_code v22; // [esp+E0h] [ebp-30h] BYREF
  int error; // [esp+E8h] [ebp-28h]
  const boost::system::error_category *v24; // [esp+ECh] [ebp-24h]
  int v25; // [esp+F0h] [ebp-20h]
  const boost::system::error_category *v26; // [esp+F4h] [ebp-1Ch]
  boost::detail::weak_count *p_pn; // [esp+F8h] [ebp-18h]
  int v28; // [esp+FCh] [ebp-14h]
  const boost::system::error_category *v29; // [esp+100h] [ebp-10h]
  int m_val; // [esp+104h] [ebp-Ch]
  const boost::system::error_category *v31; // [esp+108h] [ebp-8h]
  int flags; // [esp+10Ch] [ebp-4h]

  p_pn = &cancel_token->pn;
  if ( cancel_token->pn.pi_ )
    use_count = p_pn->pi_->use_count_;
  else
    use_count = 0;
  if ( use_count )
  {
    flags = sock_type != 2 ? 0 : 0x10;
    WSASetLastError(0);
    error = getnameinfo(addr, addrlen, host, hostlen, serv, servlen, flags);
    v11 = boost::asio::detail::socket_ops::translate_addrinfo_error(&v22, error);
    m_cat = v11->m_cat;
    ec->m_val = v11->m_val;
    ec->m_cat = m_cat;
    v13 = ec->m_cat;
    m_val = ec->m_val;
    v31 = v13;
    if ( (ec->m_val != 0
        ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
        : 0) != 0 )
    {
      WSASetLastError(0);
      v21 = getnameinfo(addr, addrlen, host, hostlen, serv, servlen, flags | 8);
      v14 = boost::asio::detail::socket_ops::translate_addrinfo_error(&v20, v21);
      v15 = v14->m_cat;
      ec->m_val = v14->m_val;
      ec->m_cat = v15;
      v16 = ec->m_cat;
      v28 = ec->m_val;
      v29 = v16;
    }
  }
  else
  {
    v10 = boost::system::system_category();
    v24 = v10;
    v25 = 995;
    v26 = v10;
    ec->m_val = 995;
    ec->m_cat = v10;
  }
  v17 = ec->m_cat;
  result->m_val = ec->m_val;
  result->m_cat = v17;
  return result;
}
