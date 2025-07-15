int __usercall boost::asio::detail::socket_ops::sync_send@<eax>(
        boost::system::error_code *ec@<esi>,
        unsigned int s,
        unsigned __int8 state,
        const _WSABUF *bufs,
        unsigned int count,
        char flags)
{
  int v6; // edi
  const boost::system::error_category *v7; // eax
  int result; // eax
  boost::system::error_code v9; // [esp+8h] [ebp-14h] BYREF
  boost::system::error_code rhs; // [esp+10h] [ebp-Ch] BYREF

  if ( s == -1 )
  {
    v6 = 10009;
LABEL_3:
    v7 = boost::system::system_category();
    ec->m_val = v6;
    ec->m_cat = v7;
    return 0;
  }
  if ( flags && (state & 0x10) != 0 )
  {
    v6 = 0;
    goto LABEL_3;
  }
  result = boost::asio::detail::socket_ops::send(ec, s, bufs, count);
  if ( result < 0 )
  {
    while ( (state & 1) == 0 )
    {
      rhs.m_cat = boost::system::system_category();
      rhs.m_val = 10035;
      if ( boost::system::operator!=(ec, &rhs) )
      {
        v9.m_cat = boost::system::system_category();
        v9.m_val = 1237;
        if ( boost::system::operator!=(ec, &v9) )
          break;
      }
      if ( boost::asio::detail::socket_ops::poll_write(ec, s) < 0 )
        break;
      result = boost::asio::detail::socket_ops::send(ec, s, bufs, count);
      if ( result >= 0 )
        return result;
    }
    return 0;
  }
  return result;
}
