void __thiscall boost::asio::detail::socket_select_interrupter::open_descriptors(
        boost::asio::detail::socket_select_interrupter *this)
{
  unsigned int v2; // [esp+4h] [ebp-208h]
  unsigned int socket; // [esp+8h] [ebp-204h]
  unsigned int v4; // [esp+40h] [ebp-1CCh]
  unsigned int v5; // [esp+A4h] [ebp-168h]
  unsigned int v6; // [esp+1A8h] [ebp-64h]
  unsigned __int8 acceptor_state; // [esp+1D3h] [ebp-39h] BYREF
  boost::asio::detail::socket_holder client; // [esp+1D4h] [ebp-38h] BYREF
  sockaddr_in addr; // [esp+1D8h] [ebp-34h] BYREF
  boost::asio::detail::socket_holder acceptor; // [esp+1E8h] [ebp-24h] BYREF
  boost::system::error_code ec; // [esp+1ECh] [ebp-20h] BYREF
  unsigned int non_blocking; // [esp+1F4h] [ebp-18h] BYREF
  unsigned __int8 client_state; // [esp+1FBh] [ebp-11h] BYREF
  int opt; // [esp+1FCh] [ebp-10h] BYREF
  unsigned __int8 server_state; // [esp+203h] [ebp-9h] BYREF
  boost::asio::detail::socket_holder server; // [esp+204h] [ebp-8h] BYREF
  unsigned int addr_len; // [esp+208h] [ebp-4h] BYREF

  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  v6 = boost::asio::detail::socket_ops::socket(2, 1, 6, &ec);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&acceptor);
  acceptor.socket_ = v6;
  if ( v6 == -1
    && (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&ec, "socket_select_interrupter");
  }
  opt = 1;
  acceptor_state = 0;
  boost::asio::detail::socket_ops::setsockopt(acceptor.socket_, &acceptor_state, 0xFFFF, 4, (const char *)&opt, 4u, &ec);
  addr_len = 16;
  memset(&addr.sin_port, 0, 14);
  addr.sin_family = 2;
  addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
  addr.sin_port = 0;
  if ( boost::asio::detail::socket_ops::bind(acceptor.socket_, (const sockaddr *)&addr, addr_len, &ec) == -1
    && (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&ec, "socket_select_interrupter");
  }
  if ( boost::asio::detail::socket_ops::getsockname(acceptor.socket_, (sockaddr *)&addr, &addr_len, &ec) == -1
    && (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&ec, "socket_select_interrupter");
  }
  addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
  if ( boost::asio::detail::socket_ops::listen(acceptor.socket_, 0x7FFFFFFF, &ec) == -1
    && (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&ec, "socket_select_interrupter");
  }
  v5 = boost::asio::detail::socket_ops::socket(2, 1, 6, &ec);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&client);
  client.socket_ = v5;
  if ( v5 == -1
    && (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&ec, "socket_select_interrupter");
  }
  if ( boost::asio::detail::socket_ops::connect(client.socket_, (const sockaddr *)&addr, addr_len, &ec) == -1
    && (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&ec, "socket_select_interrupter");
  }
  v4 = boost::asio::detail::socket_ops::accept(acceptor.socket_, 0, 0, &ec);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&server);
  server.socket_ = v4;
  if ( v4 == -1
    && (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&ec, "socket_select_interrupter");
  }
  non_blocking = 1;
  client_state = 0;
  if ( boost::asio::detail::socket_ops::ioctl(client.socket_, &client_state, -2147195266, &non_blocking, &ec)
    && (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&ec, "socket_select_interrupter");
  }
  opt = 1;
  boost::asio::detail::socket_ops::setsockopt(client.socket_, &client_state, 6, 1, (const char *)&opt, 4u, &ec);
  non_blocking = 1;
  server_state = 0;
  if ( boost::asio::detail::socket_ops::ioctl(server.socket_, &server_state, -2147195266, &non_blocking, &ec)
    && (ec.m_val != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&ec, "socket_select_interrupter");
  }
  opt = 1;
  boost::asio::detail::socket_ops::setsockopt(server.socket_, &server_state, 6, 1, (const char *)&opt, 4u, &ec);
  socket = server.socket_;
  server.socket_ = -1;
  this->read_descriptor_ = socket;
  v2 = client.socket_;
  client.socket_ = -1;
  this->write_descriptor_ = v2;
  boost::asio::detail::socket_holder::~socket_holder(&server);
  boost::asio::detail::socket_holder::~socket_holder(&client);
  boost::asio::detail::socket_holder::~socket_holder(&acceptor);
}
