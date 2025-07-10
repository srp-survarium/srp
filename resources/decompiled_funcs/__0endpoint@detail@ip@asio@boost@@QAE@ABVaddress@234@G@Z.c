void __thiscall boost::asio::ip::detail::endpoint::endpoint(
        boost::asio::ip::detail::endpoint *this,
        boost::asio::ip::address *addr,
        u_short port_num)
{
  u_long hostlong; // [esp+28h] [ebp-3Ch]
  std::bad_cast v5; // [esp+30h] [ebp-34h] BYREF
  in_addr::<unnamed_type_S_un> S_un; // [esp+3Ch] [ebp-28h]
  boost::array<unsigned char,16> bytes; // [esp+40h] [ebp-24h]
  boost::asio::ip::address_v6 v6_addr; // [esp+50h] [ebp-14h] BYREF

  *(_QWORD *)&this->data_.base.sa_family = 0;
  *(_QWORD *)this->data_.v6.sin6_addr.u.Byte = 0;
  *(_QWORD *)&this->data_.v6.sin6_addr.u.Word[4] = 0;
  this->data_.v6.sin6_scope_id = 0;
  if ( addr->type_ )
  {
    this->data_.base.sa_family = 23;
    this->data_.v4.sin_port = htons(port_num);
    this->data_.v4.sin_addr.S_un.S_addr = 0;
    boost::asio::ip::address::to_v6(addr, &v6_addr);
    *(_DWORD *)&bytes.elems[4] = *(_DWORD *)&v6_addr.addr_.u.Word[2];
    *(_QWORD *)&bytes.elems[8] = *(_QWORD *)&v6_addr.addr_.u.Word[4];
    *(_DWORD *)this->data_.v6.sin6_addr.u.Byte = *(_DWORD *)v6_addr.addr_.u.Byte;
    *(_DWORD *)&this->data_.v6.sin6_addr.u.Word[2] = *(_DWORD *)&bytes.elems[4];
    *(_QWORD *)&this->data_.v6.sin6_addr.u.Word[4] = *(_QWORD *)&bytes.elems[8];
    this->data_.v6.sin6_scope_id = v6_addr.scope_id_;
  }
  else
  {
    this->data_.base.sa_family = 2;
    this->data_.v4.sin_port = htons(port_num);
    if ( addr->type_ )
    {
      std::bad_cast::bad_cast(&v5, &stru_984D24.m_working_macro_list.m_buffer[1].m_store[404]);
      boost::throw_exception(&v5);
      std::bad_cast::~bad_cast(&v5);
    }
    S_un = addr->ipv4_address_.addr_.S_un;
    hostlong = ntohl(S_un.S_addr);
    this->data_.v4.sin_addr.S_un.S_addr = htonl(hostlong);
  }
}
