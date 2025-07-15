void __userpurge boost::asio::ip::detail::endpoint::endpoint(
        boost::asio::ip::address *addr@<eax>,
        boost::asio::ip::detail::endpoint *this,
        int port_num)
{
  u_long v4; // eax
  boost::asio::ip::address *v5; // ecx
  unsigned int scope_id; // eax
  int v7; // [esp+0h] [ebp-20h]
  int v8; // [esp+0h] [ebp-20h]
  int v9; // [esp+4h] [ebp-1Ch]
  int v10; // [esp+4h] [ebp-1Ch]
  int v11; // [esp+8h] [ebp-18h]
  int v12; // [esp+8h] [ebp-18h]
  boost::asio::ip::address_v6 v13; // [esp+Ch] [ebp-14h] BYREF

  memset(this, 0, sizeof(boost::asio::ip::detail::endpoint));
  if ( addr->type_ )
  {
    this->data_.base.sa_family = 23;
    this->data_.v4.sin_port = ((int (__stdcall *)(int, int, int, int, _DWORD))(&off_8E3A98 + 20))(
                                port_num,
                                v7,
                                v9,
                                v11,
                                *(_DWORD *)v13.addr_.u.Byte);
    this->data_.v4.sin_addr.S_un.S_addr = 0;
    boost::asio::ip::address::to_v6(v5, addr, &v13);
    scope_id = v13.scope_id_;
    *(_QWORD *)this->data_.v6.sin6_addr.u.Byte = *(_QWORD *)v13.addr_.u.Byte;
    *(_QWORD *)&this->data_.v6.sin6_addr.u.Word[4] = *(_QWORD *)&v13.addr_.u.Word[4];
    this->data_.v6.sin6_scope_id = scope_id;
  }
  else
  {
    this->data_.base.sa_family = 2;
    this->data_.v4.sin_port = ((int (__stdcall *)(int, int, int, int, _DWORD))(&off_8E3A98 + 20))(
                                port_num,
                                v7,
                                v9,
                                v11,
                                *(_DWORD *)v13.addr_.u.Byte);
    if ( addr->type_ )
    {
      std::bad_cast::bad_cast((std::bad_cast *)&v13.addr_.u.Word[4], "bad cast");
      boost::throw_exception((const std::exception *)&v13.addr_.u.Word[4]);
      std::bad_cast::~bad_cast((std::bad_cast *)&v13.addr_.u.Word[4]);
    }
    v4 = ntohl(addr->ipv4_address_.addr_.S_un.S_addr);
    this->data_.v4.sin_addr.S_un.S_addr = ((int (__stdcall *)(u_long, int, int, int, _DWORD))(&off_8E3A98 + 10))(
                                            v4,
                                            v8,
                                            v10,
                                            v12,
                                            *(_DWORD *)v13.addr_.u.Byte);
  }
}
